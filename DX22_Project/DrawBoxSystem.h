/*****************************************************************//**
* \file   DrawBoxSystem.h 
* \brief  ボックス表示のシステム.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/10 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include <DirectXMath.h>


namespace ECS {

	struct Sys_DrawBox : Behaviour {
		DirectX::XMFLOAT4X4 wvp[3];
		DirectX::XMMATRIX trans;
		DirectX::XMMATRIX scale;
		DirectX::XMMATRIX rotate;
		DirectX::XMMATRIX rX;
		DirectX::XMMATRIX rY;
		DirectX::XMMATRIX rZ;

		const DirectX::XMFLOAT3 ROTATE = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
		const DirectX::XMFLOAT3 SCALE = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
		
		Sys_DrawBox() : wvp{}, trans(), scale(), rotate(),
			rX(), rY(), rZ(){ }
		void OnUpdate(World& w, Entity self, float dt) override;

		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Draw;
		}
	};

}	// namespace ECS