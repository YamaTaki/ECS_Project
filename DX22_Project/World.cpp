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
		:m_nextEntityID(1)
	{
	}

	World::~World()
	{
		// 全てのエンティティを削除
		m_entities.clear();
		m_components.clear();
		m_updateBehaviours.clear();
		m_drawBehaviours.clear();
	}

	Entity World::CreateEntity()
	{
		Entity entity = m_nextEntityID++;
		m_entities.push_back(entity);
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

		m_entities.erase(
			std::remove(m_entities.begin(), m_entities.end(), entity),
			m_entities.end()
		);

		// コンポーネントを削除
		m_components.erase(entity);

		// 両方のBehaviourリストから削除
		auto removeEntity = [entity](auto& list) {
			list.erase(
				std::remove_if(list.begin(), list.end(),
					[entity](const std::pair<Entity, std::shared_ptr<Behaviour>>& pair) {
						return pair.first == entity;
					}),
				list.end()
			);
		};

		removeEntity(m_updateBehaviours);
		removeEntity(m_drawBehaviours);

	/*	m_behaviours.erase(
			std::remove_if(m_behaviours.begin(), m_behaviours.end(),
				[entity](const std::pair<Entity, std::shared_ptr<Behaviour>>& pair) {
					return pair.first == entity;
				}),
			m_behaviours.end()
		);*/
	}

	bool World::IsValid(Entity entity) const
	{
		return std::find(m_entities.begin(), m_entities.end(), entity) != m_entities.end();
	}

	void World::Update(float deltaTime)
	{
		// 全てのBehaviourを更新
		// イテレータ中のエンティティ削除を考慮し、インデックスベースでループ
		for (size_t i = 0; i < m_updateBehaviours.size(); ) {
			Entity entity = m_updateBehaviours[i].first;
			auto& behaviour = m_updateBehaviours[i].second;

			// エンティティが有効な場合のみ更新
			if (IsValid(entity)) {
				behaviour->OnUpdate(*this, entity, deltaTime);
				++i;	// 次の要素へ
			}
			else {
				// 無効なエンティティは削除
				m_updateBehaviours.erase(m_updateBehaviours.begin() + i);
				// インデックスはそのまま(次の要素が現在の位置に来る)
			}
		}
	}

	void World::Draw()
	{
		for (size_t i = 0; i < m_drawBehaviours.size(); ) {
			Entity entity = m_drawBehaviours[i].first;
			auto& behaviour = m_drawBehaviours[i].second;

			// エンティティが有効な場合のみ描画
			if (IsValid(entity)) {
				behaviour->OnUpdate(*this, entity, 0.0f);
				++i;
			} else {
				// 無効なエンティティは削除
				m_drawBehaviours.erase(m_drawBehaviours.begin() + i);
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


