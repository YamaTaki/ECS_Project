/*****************************************************************//**
* \file   PhysicsShotSystem.h 
* \brief  DX22授業内で実装した、オブジェクトを吹っ飛ばすシステム.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/16 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include "World.h"
#include "Components.h"
#include <DirectXMath.h>

namespace ECS {

	struct Sys_PhysicsShot : Behaviour {
		
		enum E_ShotStep {
			SHOT_WAIT,
			SHOT_KEEP,
			SHOT_RELEASE,
		};

		const float CHARGE_POWER = 0.02f;

		float m_power = 0.0f;
		int m_shotStep = 0;
		DirectX::XMFLOAT3 m_move;
		bool m_isStop = false;
		bool m_isGround = false;


		Sys_PhysicsShot()
			: m_power(0.0f), m_shotStep(0), m_move{}, 
			m_isStop(false), m_isGround(false) {}
		void OnUpdate(World& w, Entity self, float dt) override;
		inline BehaviourPhase GetPhase() const override {
			return BehaviourPhase::Update;
		}

	private:
		void UpdateShot(Comp_Transform& trans, Comp_Transform& camera);
		void UpdateMove(Comp_Velocity& vel);
	};

}
