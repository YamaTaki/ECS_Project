/*****************************************************************//**
* \file   PhysicsMovementSystem.cpp 
* \brief  実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#include "PhysicsMovementSystem.h"
#include "World.h"
#include "Components.h"

namespace ECS {

	void Sys_PhysicsMovement::OnUpdate(World& w, Entity self, float dt)
	{
		auto* vel = w.TryGet<Comp_Velocity>(self);
			auto* t = w.TryGet<Comp_Transform>(self);

			if (vel && t) {
				// 速度に基づいて位置を更新
				t->position.x += vel->velocity.x * dt;
				t->position.y += vel->velocity.y * dt;
				t->position.z += vel->velocity.z * dt;
			}
	}

}	// namespace ECS

