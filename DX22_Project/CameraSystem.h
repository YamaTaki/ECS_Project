/*****************************************************************//**
* \file   CameraSystem.h 
* \brief  ÉJÉÅÉâ.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include <DirectXMath.h>

namespace ECS {

	struct CameraSystem : Behaviour 
	{
		DirectX::XMFLOAT4X4 fmat;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX proj;
		
		CameraSystem() : fmat(), view(), proj() {}
		void OnUpdate(World& w, Entity self, float dt) override;
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update; 
		}

	};


}

