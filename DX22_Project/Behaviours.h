/*****************************************************************//**
* \file   Behaviours.h 
* \brief  システムを管理.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/2 - begin
*********************************************************************/
#pragma once

#include "Entity.h"
#include "World.h"
#include "Components.h"
#include <DirectXMath.h>
#include <cmath>

namespace ECS {

	DEFINE_BEHAVIOUR(PhysicsMovement,
		/* データなし */
		,
			auto* vel = w.TryGet<Velocity>(self);
			auto* t = w.TryGet<Transform>(self);

			if (vel && t) {
				// 速度に基づいて位置を更新
				t->position.x += vel->velocity.x * dt;
				t->position.y += vel->velocity.y * dt;
				t->position.z += vel->velocity.z * dt;
			}
	);

	DEFINE_BEHAVIOUR(GravitySystem,
		/* データメンバーなし */
		,
			// GravityとVelocityを取得
			auto* gravity = w.TryGet<Gravity>(self);
			auto* vel = w.TryGet<Velocity>(self);

			if (gravity && vel) {
				// 重力加速度をY方向の速度に加算
				vel->velocity.y += gravity->acceleration * dt;
			}
	);

	DEFINE_BEHAVIOUR(CollisionSystem,
		// データメンバーなし
		,
			auto* center = w.TryGet<Transform>(self);

			if (center) {
		
			}
	);



}
