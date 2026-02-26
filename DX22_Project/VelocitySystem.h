/*****************************************************************//**
* \file   VelocitySystem.h 
* \brief  物理学的な移動用更新処理.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/19 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include "World.h"

N_ECS{

	struct Sys_Velocity : Behaviour {
		

		Sys_Velocity() {}

		void OnUpdate(World& w, Entity self, float dt) override;
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}
	};

}
