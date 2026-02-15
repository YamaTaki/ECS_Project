/*****************************************************************//**
* \file   GravitySystem.h 
* \brief  d—Íİ’è.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#pragma once
#include "Entity.h"

namespace ECS {

	struct GravitySystem : Behaviour
	{

		GravitySystem(){}
		void OnUpdate(World& w, Entity self, float dt);
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}
	};

}
