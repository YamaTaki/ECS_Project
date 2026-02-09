/*****************************************************************//**
* \file   SceneManager.cpp 
* \brief  シーン管理の実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#include "SceneManager.h"
#include "Defines.h"

SceneManager::SceneManager()
	:m_upScene(nullptr)
	, m_pCurrentScene(nullptr)
	, m_scenes{}
{
	// 各シーンの初期化
	m_scenes.push_back(ScenePair(
		E_Scene::Title,
		std::make_unique<SceneTitle>()
	));
	m_scenes.push_back(ScenePair(
		E_Scene::Game,
		std::make_unique<SceneGame>()
	));
	m_scenes.push_back(ScenePair(
		E_Scene::Result,
		std::make_unique<SceneResult>()
	));

	// 開始時のシーンを指定 
	m_upScene = std::make_unique<SceneChange>(
		E_Scene::Title
	);

	// DI形式のセッター呼び出し
	for (int i = 0; i < static_cast<int>(E_Scene::Max); ++i) {
		m_scenes[i].second->SetScene(m_upScene.get());
		m_scenes[i].second->SetWorld(&m_world);
	}

}

SceneManager::~SceneManager()
{
	m_pCurrentScene = nullptr;

}

void SceneManager::Init() 
{
	//switch (m_upScene->GetScene())
	//{
	//case E_Scene::Title:	
	//	m_pCurrentScene = m_scenes[static_cast<int>(E_Scene::Title)].second.get();
	//	break;
	//case E_Scene::Game:		
	//	m_pCurrentScene = m_scenes[static_cast<int>(E_Scene::Game)].second.get();
	//	break;
	//case E_Scene::Result:	
	//	m_pCurrentScene = m_scenes[static_cast<int>(E_Scene::Result)].second.get();;
	//	break;
	//default: break;
	//}

	for (int i = 0; i < static_cast<int>(E_Scene::Max); ++i) {
		if (m_upScene->GetScene() == m_scenes[i].first) {
			m_pCurrentScene = m_scenes[i].second.get();
		}
	}

}

void SceneManager::Update()
{
	if (!m_pCurrentScene) return;

	TimeUpdate();


	m_pCurrentScene->RootUpdate();




	static E_Scene old;
	if (old != m_upScene->GetScene()) {
		ChangeScene();
	}

	old = m_upScene->GetScene();
}

void SceneManager::Draw()
{
	if (!m_pCurrentScene) return;

	m_pCurrentScene->RootDraw();
}

void SceneManager::TimeUpdate()
{
	if (m_deltaTime > 1000.0f / fFPS) {
		m_deltaTime = 0.0f;
		m_nowTime += 1.0f;
	} else {
		m_deltaTime++;
	}
}

void SceneManager::ChangeScene()
{
	for (int i = 0; i < static_cast<int>(E_Scene::Max); ++i) {
		if (m_upScene->GetScene() == m_scenes[i].first) {
			m_pCurrentScene = m_scenes[i].second.get();
		}
	}
}
