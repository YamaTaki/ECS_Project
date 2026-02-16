/*****************************************************************//**
* \file   PhysicsMovementSystem.h 
* \brief  •¨—Šw“I‚ÈˆÚ“®•û–@.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ‘ê’J¹•½
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#include "Entity.h"

namespace ECS {

	struct Sys_PhysicsMovement : Behaviour 
	{

		Sys_PhysicsMovement(){ }
		void OnUpdate(World& w, Entity self, float dt);
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}
	};

}	// namespace ECS
