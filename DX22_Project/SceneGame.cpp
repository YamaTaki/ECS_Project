/*****************************************************************//**
* \file   SceneGame.cpp 
* \brief  ƒQ[ƒ€•”•ªŽÀ‘•.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#include "SceneGame.h"
#include "Input.h"


using namespace ECS;

SceneGame::SceneGame():
	box()
{
	


}

SceneGame::~SceneGame()
{
}

void SceneGame::Update()
{
	if (IsKeyRelease(VK_LBUTTON)) {
		m_sceneChange->Change(E_Scene::Result);
	}
}

void SceneGame::Draw()
{
}
