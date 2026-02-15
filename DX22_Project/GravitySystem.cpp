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

	void GravitySystem::OnUpdate(World& w, Entity self, float dt) {
		// Gravity‚ÆVelocity‚ğæ“¾
		auto* gravity = w.TryGet<Gravity>(self);
		auto* vel = w.TryGet<Velocity>(self);

		if (gravity && vel) {
			// d—Í‰Á‘¬“x‚ğY•ûŒü‚Ì‘¬“x‚É‰ÁZ
			vel->velocity.y += gravity->acceleration * dt;
		}

	}

}
