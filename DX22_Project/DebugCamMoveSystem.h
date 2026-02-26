/*****************************************************************//**
* \file   DebugCamMoveSystem.h 
* \brief  デバッグ用のカメラ移動.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/16 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include <DirectXMath.h>

namespace ECS {

	struct Sys_DebugCamMove : Behaviour {
		
		float m_radY;
		float m_radXZ;
		float m_radius;

		const float MOVESPEED = 1.0f;
		const float ROTATE = DirectX::XMConvertToRadians(3);

		Sys_DebugCamMove()
			:m_radXZ(0.0f), m_radY(0.0f), m_radius(7.0f) { }
		
		void OnUpdate(World& w, Entity self, float dt) override;
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}
	};

}
