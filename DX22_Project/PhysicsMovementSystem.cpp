/*****************************************************************//**
* \file   PhysicsMovementSystem.cpp 
* \brief  é¿ëï.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#include "PhysicsMovementSystem.h"
#include "World.h"
#include "Components.h"
#include "Input.h"

namespace ECS {

	void Sys_PhysicsMovement::OnUpdate(World& w, Entity self, float dt)
	{
		auto* vel = w.TryGet<Comp_Velocity>(self);

		if (vel) {
			
			float moveX = 0.0f;
			float moveZ = 0.0f;

			if (IsKeyPress(VK_UP))		moveZ--;
			if (IsKeyPress(VK_DOWN))	moveZ++;
			if (IsKeyPress(VK_RIGHT))	moveX--;
			if (IsKeyPress(VK_LEFT))	moveX++;
			
			vel->velocity = DirectX::XMFLOAT3(moveX, 0.0f, moveZ);
		}
	}

}	// namespace ECS

