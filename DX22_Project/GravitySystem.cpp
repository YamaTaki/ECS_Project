/*****************************************************************//**
* \file   GravitySystem.cpp 
* \brief  À‘•.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#include "GravitySystem.h"
#include "Components.h"
#include "World.h"

namespace ECS {

	void Sys_Gravity::OnUpdate(World& w, Entity self, float dt) {
		// Gravity‚ÆVelocity‚ğæ“¾
		auto* gravity = w.TryGet<Comp_Gravity>(self);
		auto* vel = w.TryGet<Comp_Velocity>(self);
		auto* trans = w.TryGet<Comp_Transform>(self);

		if (gravity && vel) {
			// d—Í‰Á‘¬“x‚ğY•ûŒü‚Ì‘¬“x‚É‰ÁZ
			vel->velocity.y += gravity->acceleration * dt;

			if (trans->position.y < 0.0f)
				vel->velocity.y = 0.0f;

			trans->position.y += vel->velocity.y;
		}

	}

}
