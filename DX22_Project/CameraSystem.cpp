/*****************************************************************//**
* \file   CameraSystem.cpp 
* \brief  é¿ëï.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*		 2026/02/15 - change system to LookAtLH
*********************************************************************/
#include "CameraSystem.h"
#include "World.h"
#include "Components.h"
#include "DirectXMathExpansion.hpp"

namespace ECS {

	void CameraSystem::OnUpdate(World& w, Entity self, float dt)
	{
		auto* cam = w.TryGet<Camera>(self);
		auto* trans = w.TryGet<Transform>(self);
		auto* active = w.TryGet<ActiveCamTag>(self);

		if (cam && trans && active) {
			using namespace DirectX;

			XMVECTOR pos	= XMLoadFloat3(&trans->position);
			XMVECTOR target	= XMLoadFloat3(&cam->m_target);
			XMVECTOR up		= XMLoadFloat3(&cam->m_up);

			up = XMVector3Normalize(up);

			XMMATRIX view = XMMatrixLookAtLH(pos, target, up);
			
			XMMATRIX proj = XMMatrixPerspectiveFovLH(
				cam->m_fovy,
				cam->m_aspect,
				cam->m_near,
				cam->m_far
			);

			auto* ctx = w.GetEngineContext();
			if (!ctx) return;

			ctx->renderer->SetView(view);
			ctx->renderer->SetProjection(proj);
		}
	}

}	// namespace ECS

