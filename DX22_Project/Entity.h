/*****************************************************************//**
* \file   Entity.h 
* \brief  ECSに準拠した基底型を定義.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/2 - begin
*********************************************************************/
#pragma once
#include <cstdint>

namespace ECS {

	/**
	* エンティティを表す一意のID.
	*/
	using Entity = uint32_t;

	// 無効なエンティティを示す定数
	constexpr Entity INVALID_ENTITY = 0;

	struct IComponent {
		virtual ~IComponent() = default;
	};

	// 前方宣言
	class World;

	struct Behaviour
		: IComponent {
		virtual void OnUpdate(World& w, Entity self, float dt) = 0;

		virtual ~Behaviour() = default;
	};

#define DEFINE_DATA_COMPONENT(NAME, ...) \
	struct NAME : ECS::IComponent { \
		__VA_ARGS__ \
	};

#define DEFINE_BEHAVIOUR(NAME, DATA, UPDATE) \
	struct NAME : ECS::Behaviour { \
		DATA \
		void OnUpdate(ECS::World& w, ECS::Entity self, float dt) override{ \
			UPDATE \
		} \
	}

}	// namespace ECS
