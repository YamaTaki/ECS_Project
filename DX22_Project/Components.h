/*****************************************************************//**
* \file   Components.h 
* \brief  コンポーネントを管理.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/02/02 - begin
*		 2026/02/15 - Add Camera Conmpnent
*********************************************************************/
#pragma once
#include "Entity.h"
#include <DirectXMath.h>
#include "Components.h"
#include "Defines.h"

using namespace DirectX;

namespace ECS {

	/**
	* 3D空間に存在するオブジェクト.
	* \param XMFLOAT3 position：位置
	* \param XMFLOAT3 rotation：回転量 = ( 0.0f, 0.0f, 0.0f )
	* \param XMFLOAT3 scale：大きさ = ( 1.0f, 1.0f, 1.0f )
	*/
	struct Comp_Transform : IComponent {
		XMFLOAT3 position = XMFLOAT3();
		XMFLOAT3 rotation = XMFLOAT3();
		XMFLOAT3 scale = { 1.0f, 1.0f, 1.0f };

		Comp_Transform(const XMFLOAT3& pos, const XMFLOAT3& scl = XMFLOAT3(1.0f, 1.0f, 1.0f), const XMFLOAT3& rot = XMFLOAT3(0.0f, 0.0f, 0.0f))
			:position(pos), rotation(rot), scale(scl) {}
	private:
		Comp_Transform() = default;
	};

	struct Comp_Velocity : IComponent {
		XMFLOAT3 velocity = XMFLOAT3();

		Comp_Velocity(const XMFLOAT3& vel) : velocity(vel) {}
	private:
		Comp_Velocity() = default;
	};

	struct Comp_Mesh : IComponent {
		XMFLOAT3 color = XMFLOAT3();

		Comp_Mesh(const XMFLOAT3& col) : color(col){}
	private:
		Comp_Mesh() = default;
	};

	struct Comp_Collision : IComponent {
		XMFLOAT3 center = XMFLOAT3();
		XMFLOAT3 size = { 1.0f, 1.0f, 1.0f };

		Comp_Collision(const XMFLOAT3& pos, const XMFLOAT3& siz)
			:center(pos), size(siz) {}
	private:
		Comp_Collision() = default;
	};

	struct Comp_Gravity : IComponent {
		float acceleration = -9.8f;

		Comp_Gravity(float acc = -9.8f) : acceleration(acc) {}
	private:
		Comp_Gravity() = default;
	};

	struct Comp_Camera : IComponent {
		float m_fovy = DirectX::XMConvertToRadians(60);	// 画角
		float m_aspect = 16.0f / 9.0f;	// アスペクト比
		float m_near = CMETER(0.1f);	// ニアクリップ
		float m_far = METER(1000.0f);	// ファークリップ

		XMFLOAT3 m_target = {0.0f, 0.0f, 0.0f};	// 注視方向ベクトル
		XMFLOAT3 m_up = {0.0f, 1.0f, 0.0f};		// 上方向ベクトル

		Comp_Camera(const XMFLOAT3& target, const XMFLOAT3& up = XMFLOAT3(0.0f, 1.0f, 0.0f))
			:m_target(target), m_up(up) { }
	private:
		Comp_Camera() = default;
	};


	//-----タグ作成-----

	// プレイヤータグ
	struct Tag_Player : IComponent {};

	// オブジェクトタグ
	struct Tag_Object : IComponent {};

	// カメラタグ
	struct Tag_ActiveCam : IComponent {};

	// デバッグタグ
	struct Tag_Debug : IComponent {};



}	// namespace ECS
