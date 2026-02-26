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
#include "Components.h"


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

	Entity World::GetActiveCamera() const
	{
		for (auto e : m_entities) {
			if (Has<Comp_Camera>(e) && Has<Tag_ActiveCam>(e)) { return e; }
		}
		return INVALID_ENTITY;
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

		// 当たり判定の実装
		CollisionUpdate(deltaTime);
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

	void World::CollisionUpdate(float dt)
	{
		std::vector<Entity> list;

		ForEach<Comp_Transform, Comp_Collision_AABB, Tag_Collison>(
			[&](Entity e, Comp_Transform&, Comp_Collision_AABB&, Tag_Collison&) {
				list.push_back(e);
			});
		for (size_t i = 0; i < list.size(); ++i) {
			for (size_t j = i + 1; j < list.size(); ++j) {
				if (CheckAABB(list[i], list[j])) 
				{
					// 衝突処理
					OutputDebugStringA("\n--- On Collision !! ");
				}
			}
		}

	}

	bool World::CheckAABB(Entity a, Entity b)
	{
		auto* tA = TryGet<Comp_Transform>(a);
		auto* bA = TryGet<Comp_Collision_AABB>(a);

		auto* tB = TryGet<Comp_Transform>(b);
		auto* bB = TryGet<Comp_Collision_AABB>(b);

		if (tA && bA && tB && bB) {

			float dx = fabs(tA->position.x - tB->position.x);
			float dy = fabs(tA->position.y - tB->position.y);
			float dz = fabs(tA->position.z - tB->position.z);

			if (dx > (bA->half.x + bB->half.x)) return false;
			if (dy > (bA->half.y + bB->half.y)) return false;
			if (dz > (bA->half.z + bB->half.z)) return false;

			return true;
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


