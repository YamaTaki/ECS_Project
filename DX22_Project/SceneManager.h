/*****************************************************************//**
* \file   SceneManager.h 
* \brief  シーンを全体管理するマネージャー.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#pragma once
#include <vector>
#include <memory>

#include "Scene.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"

#include "SceneChange.h"

#include "Entity.h"
#include "World.h"
#include "EngineContext.h"


class SceneManager
{
private:
	using ScenePair = std::pair<E_Scene, std::unique_ptr<Scene>>;

public:
	SceneManager();
	~SceneManager();

	void Update();
	void Draw();


private:
	/**
	* void TimeUpdate : SceneManager.h
	* 時間の更新.
	*/
	void TimeUpdate();

	/**
	* void ChangeScene : SceneManager.h
	* シーン遷移した際、シーンを適切な値に変更する.
	*/
	void ChangeScene();


private:
	std::unique_ptr<SceneChange> m_upScene;
	E_Scene m_currentSceneType;
	// 各シーン
	Scene* m_pCurrentScene;	// 現在のシーン
	std::vector<ScenePair> m_scenes;

	//-----time-----
	float m_nowTime;
	float m_deltaTime;


	//-----ECS-----
	ECS::World m_world;

	//-----描画処理-----
	EngineContext m_engineContext;
	std::unique_ptr<RenderContext> m_renderer;

};

