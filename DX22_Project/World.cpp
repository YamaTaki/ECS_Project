/*****************************************************************//**
* \file   World.cpp 
* \brief  実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/2 - begin
*********************************************************************/
#include "World.h"
#include <algorithm>


namespace ECS {
	//=====エンティティ管理実装=====


	World::World()
		:nextEntityID_(1)
	{
	}

	World::~World()
	{
		// 全てのエンティティを削除
		entities_.clear();
		components_.clear();
		behaviours_.clear();
	}

	Entity World::CreateEntity()
	{
		Entity entity = nextEntityID_++;
		entities_.push_back(entity);
		return entity;
	}

	World::EntityBuilder World::Create()
	{
		Entity entity = CreateEntity();
		return EntityBuilder(this, entity);
	}

	void World::DestroyEntity(Entity entity)
	{
		DestroyEntityWithCause(entity, Cause::Manual);
	}

	void World::DestroyEntityWithCause(Entity entity, Cause cause)
	{
		// デバッグ出力
		std::cout << "[World] Entity " << entity
			<< " destroyed. Cause: " << CauseToString(cause) << std::endl;

		entities_.erase(
			std::remove(entities_.begin(), entities_.end(), entity),
			entities_.end()
		);

		// コンポーネントを削除
		components_.erase(entity);

		// Behaviourリストから削除
		behaviours_.erase(
			std::remove_if(behaviours_.begin(), behaviours_.end(),
				[entity](const std::pair<Entity, std::shared_ptr<Behaviour>>& pair) {
					return pair.first == entity;
				}),
			behaviours_.end()
		);
	}

	bool World::IsValid(Entity entity) const
	{
		return std::find(entities_.begin(), entities_.end(), entity) != entities_.end();
	}

	void World::Update(float deltaTime)
	{
		// 全てのBehaviourを更新
		// イテレータ中のエンティティ削除を考慮し、インデックスベースでループ
		for (size_t i = 0; i < behaviours_.size(); ) {
			Entity entity = behaviours_[i].first;
			auto& behaviour = behaviours_[i].second;

			// エンティティが有効な場合のみ更新
			if (IsValid(entity)) {
				behaviour->OnUpdate(*this, entity, deltaTime);
				++i;	// 次の要素へ
			}
			else {
				// 無効なエンティティは削除
				behaviours_.erase(behaviours_.begin() + i);
				// インデックスはそのまま(次の要素が現在の位置に来る)
			}
		}
	}

	const char* World::CauseToString(Cause cause) const
	{
		switch (cause)
		{
		case ECS::World::Cause::Manual:
			return "Manual";
			break;
		case ECS::World::Cause::Collision:
			return "Collision";
			break;
		case ECS::World::Cause::OutOfBounds:
			return "OutOfBounds";
			break;
		case ECS::World::Cause::TimedOut:
			return "TimedOut";
			break;
		case ECS::World::Cause::HealthZero:
			return "HealthZero";
			break;
		default:
			return "Unknown";
			break;
		}
	}


}	// namespace ECS


