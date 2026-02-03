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

#define DEFINE_DATA_COMPONENT(Name, ...)\
	struct Name : ECS::IComponent {\
		__VA_ARGS__ \
	};

#define DEFINE_BEHAVIOUR(Name, Data, Update)\
	struct Name : ECS::Behaviour {\
		Data \
		void OnUpdate(ECS::World& w, ECS::Entity self, float dt) override {\
			Update \
		} \
	};

}	// namespace ECS
