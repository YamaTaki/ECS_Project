/*****************************************************************//**
* \file   SceneGame.cpp 
* \brief  ƒQ[ƒ€•”•ªŽÀ‘•.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/03 - begin
*		 2026/02/16 - Add World::Draw function.
*		 2026/02/26 - Add "other" object
*********************************************************************/
#include "SceneGame.h"
#include "Input.h"
#include "CameraDebug.h"
#include "Behaviours.h"

using namespace ECS;
using namespace DirectX;

SceneGame::SceneGame():
	box(),
	camera(),
	other()
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
		.With<Comp_Transform>(XMFLOAT3(0.0f, 1.0f, 0.0f), XMFLOAT3(2.0f, 2.0f, 2.0f))
		.With<Comp_Velocity>(XMFLOAT3())
		.With<Comp_Collision_AABB>(XMFLOAT3(2.0f, 2.0f, 2.0f))
		.With<Comp_PhysicsShot>()
		.With<Tag_Debug>()
		.With<Tag_Collison>()
		.With<Sys_DrawBox>()
		.With<Sys_PhysicsMovement>()
		.With<Sys_PhysicsShot>()
		.With<Sys_Velocity>()
		.Build();

	camera = m_pWorld->Create()
		.With<Comp_Transform>(XMFLOAT3(10.0f, 10.0f, 5.0f))
		.With<Comp_Camera>(XMFLOAT3(0.0f, 0.0f, 0.0f))
		.With<Tag_ActiveCam>()
		.With<Sys_Camera>()
		.With<Sys_DebugCamMove>()
		.Build();

	other = m_pWorld->Create()
		.With<Comp_Transform>(XMFLOAT3(4.0f, 0.0f, 0.0f))
		.With<Comp_Collision_AABB>(XMFLOAT3(1.0f, 1.0f, 1.0))
		.With<Tag_Collison>()
		.With<Tag_Debug>()
		.With<Sys_DrawBox>()
		.Build();

}
