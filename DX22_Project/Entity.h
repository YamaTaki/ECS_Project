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

#define N_ECS namespace ECS

namespace ECS {

	/**
	* エンティティを表す一意のID.
	*/
	using Entity = uint32_t;

	// 無効なエンティティを示す定数
	static constexpr Entity INVALID_ENTITY = 0;

	struct IComponent {
		virtual ~IComponent() = default;
	};

	// 前方宣言
	class World;

	enum class BehaviourPhase {
		Update,	// 更新フェーズ
		Draw	// 描画フェーズ
	};

	struct Behaviour
		: IComponent {
		virtual BehaviourPhase GetPhase() const = 0;
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
