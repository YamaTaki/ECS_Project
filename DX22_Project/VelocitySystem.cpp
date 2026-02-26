/*****************************************************************//**
* \file   VelocitySystem.cpp 
* \brief  é¿ëï.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/19 - begin
*********************************************************************/
#include "VelocitySystem.h"
#include <DirectXMath.h>
#include "DirectXMathExpansion.hpp"
#include "Components.h"

N_ECS{

	void Sys_Velocity::OnUpdate(World & w, Entity self, float dt)
	{
		auto* trans = w.TryGet<Comp_Transform>(self);
		auto* vel = w.TryGet<Comp_Velocity>(self);

		if (trans && vel) {

			if (vel->velocity.y < 0.0f)
				vel->velocity.y = 0.0f;

			trans->position += vel->velocity * dt;

		}

	}

}

