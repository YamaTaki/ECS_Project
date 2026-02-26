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
	// ワールド情報の初期化
	m_upWorld = std::make_unique<ECS::World>();
	m_renderer = std::make_unique<RenderContext>();

	m_engineContext.renderer = m_renderer.get();
	m_upWorld->SetEngineContext(&m_engineContext);


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
	m_currentSceneType = m_upScene->GetScene();

	// DI形式のセッター呼び出し
	for (int i = 0; i < static_cast<int>(E_Scene::Max); ++i) {
		m_scenes[i].second->SetScene(m_upScene.get());
		m_scenes[i].second->SetWorld(m_upWorld.get());
		m_scenes[i].second->Init();
	}


	ChangeScene();

}

SceneManager::~SceneManager()
{
	
}

void SceneManager::Update()
{

	if (!m_pCurrentScene) return;

	TimeUpdate();


	m_pCurrentScene->RootUpdate();


	E_Scene next = m_upScene->GetScene();
	if (next != m_currentSceneType) {
		ChangeScene();
		m_currentSceneType = next;
	}
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
