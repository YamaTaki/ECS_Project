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

#include "SceneRequest.h"


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void Draw();

private:
	void ChangeScene(E_Scene scene);

private:
	E_Scene m_scene;
	// 各シーン
	Scene* m_pCurrentScene;	// 現在のシーン
	std::unique_ptr<SceneTitle> m_upTitle;	// タイトル
	std::unique_ptr<SceneGame> m_upGame;	// ゲーム
	std::unique_ptr<SceneResult> m_upResult;// リザルト



};

