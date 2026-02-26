/*****************************************************************//**
* \file   PhysicsShotSystem.cpp 
* \brief  実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/17 - begin
*		 2026/02/24 - complate ( Stop process changed. )
*********************************************************************/
#include "PhysicsShotSystem.h"
#include "Input.h"
#include "DirectXMathExpansion.hpp"

#define DEBUGTEXT(str) {OutputDebugStringA("--- DEBUG TEXT : str")}

N_ECS{
	using namespace DirectX;

	void Sys_PhysicsShot::OnUpdate(World& w, Entity self, float dt)
	{
		auto* trans = w.TryGet<Comp_Transform>(self);
		auto* velo = w.TryGet<Comp_Velocity>(self);
		auto* shot = w.TryGet<Comp_PhysicsShot>(self);
		auto ActiveCam = w.GetActiveCamera();

		// アクティブなカメラが存在しなけば処理しない
		if (ActiveCam == INVALID_ENTITY) return;

		// カメラのデータから必要なデータを抜き出して格納
		auto* cam = w.TryGet<Comp_Transform>(ActiveCam);

		if (trans && velo && shot) {

			if (m_isStop) {
				UpdateShot(*trans, *cam);
			} else {
				UpdateMove(*velo);
			}

		}
	}

	void Sys_PhysicsShot::UpdateShot(Comp_Transform& trans, Comp_Transform& camera)
	{
		switch (m_shotStep)
		{
		case SHOT_WAIT:
			if (IsKeyTrigger('Z')) {
				m_power = 0.0f;
				m_shotStep = SHOT_KEEP;
			}
			break;
		case SHOT_KEEP:
			m_power += CHARGE_POWER;
			if (m_power > 1.0f)
				m_power = 1.0f;

			if (IsKeyRelease('Z')) {
				m_shotStep = SHOT_RELEASE;
			}
			break;
		case SHOT_RELEASE:
			XMVECTOR vCamPos = XMLoadFloat3(&camera.position);
			XMVECTOR vPos = XMLoadFloat3(&trans.position);
			XMVECTOR vec = XMVectorSubtract(vPos, vCamPos);
			vec = XMVector2Normalize(vec);
			vec = XMVectorScale(vec, m_power / 2.0f);
			XMStoreFloat3(&m_move, vec);

			m_isStop = false;
			m_isGround = false;
			m_shotStep = SHOT_WAIT;
			break;
		default:
			OutputDebugStringA("\n--- DEBUG TEXT : shot step error");
			break;
		}
	}
	
	void Sys_PhysicsShot::UpdateMove(Comp_Velocity& vel)
	{
		vel.velocity.x += m_move.x;
		vel.velocity   *= 0.99f;
		vel.velocity.z += m_move.z;


		float speed;
		XMVECTOR vMove = XMLoadFloat3(&m_move);
		speed = XMVectorGetX(XMVector3Length(vMove));

		if (speed < 0.5f) {
			m_move = {};
			m_isStop = true;
			m_shotStep = SHOT_WAIT;
		}

		m_move *= 0.99f;

	}

}