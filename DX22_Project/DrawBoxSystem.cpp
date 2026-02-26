/*****************************************************************//**
* \file   DrawBoxSystem.cpp 
* \brief  é¿ëï.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/10 - begin
*********************************************************************/
#include "DrawBoxSystem.h"
#include "Components.h"
#include "World.h"
#include "DirectXMathExpansion.hpp"
#include "Geometry.h"

namespace ECS {

	void Sys_DrawBox::OnUpdate(World& w, Entity self, float dt)
	{
		auto* obj = w.TryGet<Comp_Transform>(self);
		auto* tag = w.TryGet<Tag_Debug>(self);
		auto* ctx = w.GetEngineContext();

		if (obj && ctx && tag) {
			auto* renderer = ctx->renderer;

			trans = DirectX::XMMatrixTranslation(obj->position.x, obj->position.y, obj->position.z);
			if (obj->rotation != ROTATE) {	// èâä˙ílÇ≈Ç»ÇØÇÍÇŒ
				rX = DirectX::XMMatrixRotationX(DirectX::XMConvertToRadians(obj->rotation.x));
				rY = DirectX::XMMatrixRotationY(DirectX::XMConvertToRadians(obj->rotation.y));
				rZ = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(obj->rotation.z));
				rotate = rX * rY * rZ;
			}
			else {
				rX = DirectX::XMMatrixRotationX(DirectX::XMConvertToRadians(ROTATE.x));
				rY = DirectX::XMMatrixRotationY(DirectX::XMConvertToRadians(ROTATE.y));
				rZ = DirectX::XMMatrixRotationZ(DirectX::XMConvertToRadians(ROTATE.z));
				rotate = rX * rY * rZ;
			}
			if (obj->scale != SCALE) {
				scale = DirectX::XMMatrixScaling(obj->scale.x, obj->scale.y, obj->scale.z);
			}
			else {
				scale = DirectX::XMMatrixScaling(SCALE.x, SCALE.y, SCALE.z);
			}
			DirectX::XMMATRIX world = scale * rotate * trans;
			DirectX::XMStoreFloat4x4(&wvp[0], DirectX::XMMatrixTranspose(world));

			DirectX::XMMATRIX view = renderer->GetView();
			DirectX::XMMATRIX proj = renderer->GetProjction();
			view = DirectX::XMMatrixTranspose(view);
			proj = DirectX::XMMatrixTranspose(proj);

			DirectX::XMStoreFloat4x4(&wvp[1], view);
			DirectX::XMStoreFloat4x4(&wvp[2], proj);

			SetDepthTest(true);
			Geometry::SetWorld(wvp[0]);
			Geometry::SetView(wvp[1]);
			Geometry::SetProjection(wvp[2]);
			Geometry::DrawBox();
			SetDepthTest(false);
		}
	}
}	// namespace ECS
