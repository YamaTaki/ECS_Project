/*****************************************************************//**
* \file   SceneGame.cpp 
* \brief  ƒQ[ƒ€•”•ªŽÀ‘•.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/03 - begin
*		 2026/02/16 - Add World::Draw function.
*********************************************************************/
#include "SceneGame.h"
#include "Input.h"
#include "CameraDebug.h"
#include "CameraSystem.h"
#include "DrawBoxSystem.h"

using namespace ECS;
using namespace DirectX;

SceneGame::SceneGame():
	box(),
	camera()
{
	

}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	EntityInit();
}

void SceneGame::Update()
{
	if (IsKeyRelease(VK_LBUTTON)) {
		m_sceneChange->Change(E_Scene::Result);
	}

	m_pWorld->Update();
}

void SceneGame::Draw()
{


	m_pWorld->Draw();

}

void SceneGame::EntityInit()
{
	box = m_pWorld->Create()
		.With<Transform>(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(5.0f, 5.0f, 5.0f))
		.With<DebugTag>()
		.With<DrawBoxSystem>()
		.Build();

	camera = m_pWorld->Create()
		.With<Transform>(XMFLOAT3(10.0f, 10.0f, 5.0f))
		.With<Camera>(XMFLOAT3(0.0f, 0.0f, 0.0f))
		.With<ActiveCamTag>()
		.With<CameraSystem>()
		.Build();

}
