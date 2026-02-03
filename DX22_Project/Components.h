/*****************************************************************//**
* \file   Components.h 
* \brief  コンポーネントを管理.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/2 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include <DirectXMath.h>
#include "Components.h"

using namespace DirectX;

namespace ECS {

	struct Transform : IComponent {
		XMFLOAT3 position = XMFLOAT3();
		XMFLOAT3 rotation = XMFLOAT3();
		XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };

		Transform() = default;
		Transform(const XMFLOAT3& pos, const XMFLOAT3& rot, const XMFLOAT3& scl)
			:position(pos), rotation(rot), scale(scl) {}
	};

	struct Velocity : IComponent {
		XMFLOAT3 velocity = XMFLOAT3();

		Velocity() = default;
		Velocity(const XMFLOAT3& vel) : velocity(vel) {}
	};

	struct Mesh : IComponent {
		XMFLOAT3 color = XMFLOAT3();

		Mesh() = default;
		Mesh(const XMFLOAT3& col) : color(col){}
	};

	struct Collision : IComponent {
		XMFLOAT3 center = XMFLOAT3();
		XMFLOAT3 size = { 1.0f, 1.0f, 1.0f };

		Collision() = default;
		Collision(const XMFLOAT3& pos, const XMFLOAT3& siz)
			:center(pos), size(siz) {}
	};

	struct Gravity : IComponent {
		float acceleration = -9.8f;

		Gravity() = default;
		Gravity(float acc = -9.8f) : acceleration(acc) {}
	};


	//-----タグ作成-----

	// プレイヤータグ
	struct PlayerTag : IComponent {};

	// オブジェクトタグ
	struct ObjectTag : IComponent {};



}	// namespace ECS
