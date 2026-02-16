/*****************************************************************//**
* \file   DebugCamMoveSystem.cpp 
* \brief  実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/16 - begin
*********************************************************************/
#include "DebugCamMoveSystem.h"
#include "Components.h"
#include "World.h"
#include "Input.h"

namespace ECS {

	void Sys_DebugCamMove::OnUpdate(World& w, Entity self, float dt)
	{
		auto* trans = w.TryGet<Comp_Transform>(self);
		auto* cam = w.TryGet<Comp_Camera>(self);
		auto* active = w.TryGet<Tag_ActiveCam>(self);

		if (trans && cam && active) {
			// カメラ距離の移動
		// 回り込みの処理
			if (IsKeyPress('A')) { m_radXZ += ROTATE; }
			if (IsKeyPress('D')) { m_radXZ -= ROTATE; }
			if (IsKeyPress('W')) { m_radY += ROTATE; }
			if (IsKeyPress('S')) { m_radY -= ROTATE; }

			if (IsKeyPress('E')) { m_radius += ROTATE; }
			if (IsKeyPress('Q')) { m_radius -= ROTATE; }

			if (m_radius == 0) {
				m_radius = 1;
			}

			// カメラ位置の計算
			trans->position.x = cosf(m_radY) * sinf(m_radXZ) * m_radius + cam->m_target.x;
			trans->position.y = sinf(m_radY) * m_radius + cam->m_target.y;
			trans->position.z = cosf(m_radY) * cosf(m_radXZ) * m_radius + cam->m_target.z;
		}
	}
}