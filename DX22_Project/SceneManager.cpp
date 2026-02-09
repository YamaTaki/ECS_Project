/*****************************************************************//**
* \file   SceneManager.cpp 
* \brief  ƒV[ƒ“ŠÇ—‚ÌÀ‘•.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#include "SceneManager.h"

SceneManager::SceneManager()
	:m_scene(E_Scene::Title)
	, m_pCurrentScene(nullptr)
	, m_upTitle(nullptr)
	, m_upGame(nullptr)
	, m_upResult(nullptr)
{
	m_upTitle	= std::make_unique<SceneTitle>();
	m_upGame	= std::make_unique<SceneGame>();
	m_upResult	= std::make_unique<SceneResult>();

}

SceneManager::~SceneManager()
{
	m_pCurrentScene = nullptr;

}

void SceneManager::Init() 
{
	switch (m_scene)
	{
	case E_Scene::Title:	m_pCurrentScene = m_upTitle.get();	break;
	case E_Scene::Game:		m_pCurrentScene = m_upGame.get();	break;
	case E_Scene::Result:	m_pCurrentScene = m_upResult.get();	break;
	default: break;
	}

	// ‰Šú‰»
	if (m_pCurrentScene) {
		m_pCurrentScene->Init();
	}
}

void SceneManager::Update()
{
	if (!m_pCurrentScene) return;
	
	m_pCurrentScene->RootUpdate();
}

void SceneManager::Draw()
{
	if (!m_pCurrentScene) return;

	m_pCurrentScene->RootDraw();
}

void SceneManager::ChangeScene(E_Scene scene)
{
	m_scene = scene;
}
