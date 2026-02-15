/*****************************************************************//**
* \file   CollisionSystem.h 
* \brief  “–‚½‚è”»’è‚Ìì¬.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#pragma once
#include "Entity.h"

namespace ECS {

	struct CollisionSystem : Behaviour
	{

		CollisionSystem(){}
		void OnUpdate(World& w, Entity self, float dt);

		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}
	};
	

}	// namespace ECS

