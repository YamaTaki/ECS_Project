/*****************************************************************//**
* \file   World.h 
* \brief  ECSの中核となるクラス.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/2 - begin
*********************************************************************/
#pragma once
#include "Entity.h"
#include <vector>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <functional>
#include <iostream>
#include <algorithm>

namespace ECS {

	class World
	{
	public:
		enum class Cause {
			Manual,
			Collision,
			OutOfBounds,
			TimedOut,
			HealthZero,
		};

		class EntityBuilder {
		public:
			EntityBuilder(World* world, Entity entity)
				:world_(world), entity_(entity) {
			}


			template<typename T, typename...Args>
			EntityBuilder& With(Args&&... args) {
				world_->Add<T>(entity_, T(std::forward<Args>(args)...));
				return *this;
			}

			Entity Build() {
				return entity_;
			}

		private:
			World* world_;
			Entity entity_;

		};

	public:
		World();
		~World();

		//-----エンティティ管理-----

		Entity CreateEntity();

		EntityBuilder Create();

		void DestroyEntity(Entity entity);

		void DestroyEntityWithCause(Entity entity, Cause cause);

		bool IsValid(Entity entity) const;

		//-----コンポーネント管理-----

		template<typename T>
		void Add(Entity entity, const T& component);

		template<typename T>
		T* TryGet(Entity entity);

		template<typename T>
		const T* TryGet(Entity entity) const;

		template<typename T>
		bool Has(Entity entity) const;

		template<typename T>
		void Remove(Entity entity);


		//-----一括管理-----

		template<typename T>
		void ForEach(std::function<void(Entity, T&)> func);

		template<typename T1, typename T2>
		void ForEach(std::function<void(Entity, T1&, T2&)> func);

		template<typename T1, typename T2, typename T3>
		void ForEach(std::function<void(Entity, T1&, T2&, T3&)> func);


		//-----システム更新-----

		void Update(float deltaTime);

	private:
		Entity nextEntityID_;
		std::vector<Entity> entities_;
		std::unordered_map<Entity, std::unordered_map
			<std::type_index, std::shared_ptr<IComponent>>> components_;
		std::vector<std::pair<Entity, std::shared_ptr<Behaviour>>> behaviours_;

		const char* CauseToString(Cause cause) const;

		template<typename T>
		std::unordered_map<Entity, std::shared_ptr<T>>& GetComponentStorage();

		template<typename T>
		const std::unordered_map<Entity, std::shared_ptr<T>>& GetComponentStorage() const;

		std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<IComponent>>> componentStrage_;

	};


	//=====テンプレート実装=====

	template<typename T>
	void World::Add(Entity entity, const T& component)
	{
		auto typeIndex = std::type_index(typeid(T));
		auto componentPtr = std::make_shared<T>(component);

		// コンポーネントストレージに追加
		components_[entity][typeIndex] = componentPtr;

		// Behaviourの場合は別途リストに追加
		// dynamic_castを使用してBehaviouかどうかを判定
		Behaviour* behaviourPtr = dynamic_cast<Behaviour*>(componentPtr.get());
		if (behaviourPtr != nullptr) {
			behaviours_.push_back({ entity, std::shared_ptr<Behaviour>(componentPtr, behaviourPtr) });
		}
	}

	template<typename T>
	T* World::TryGet(Entity entity)
	{
		auto it = components_.find(entity);
		if (it == components_.end()) {
			return nullptr;
		}

		auto typeIndex = std::type_index(typeid(T));
		auto compIt = it->second.find(typeIndex);
		if (compIt == it->second.end()) {
			return nullptr;
		}

		return static_cast<T*>(compIt->second.get());
	}

	template<typename T>
	const T* World::TryGet(Entity entity) const
	{
		auto it = components_.find(entity);
		if (it == components_.end()) {
			return nullptr;
		}

		auto typeIndex = std::type_index(typeid(T));
		auto compIt = it->second.find(typeIndex);
		if (compIt == it->second.end()) {
			return nullptr;
		}

		return static_cast<const T*>(compIt->second.get());
	}

	template<typename T>
	bool World::Has(Entity entity) const
	{
		return TryGet<T>(entity) != nullptr;
	}

	template<typename T>
	void World::Remove(Entity entity)
	{
		auto it = components_.find(entity);
		if (it == components_.end()) {
			return;
		}

		auto typeIndex = std::type_index(typeid(T));

		// コンポーネントを取得してBehaviourかチェック
		auto compIt = it->second.find(typeIndex);
		if (compIt != it->second.end()) {
			// Behaviourの場合はリストからも削除
			Behaviour* behaviourPtr = dynamic_cast<Behaviour*>(compIt->second.get());
			if (behaviourPtr != nullptr) {
				behaviours_.erase(
					std::remove_if(behaviours_.begin(), behaviours_.end(),
						[entity, behaviourPtr](const std::pair<Entity, std::shared_ptr<Behaviour>>& pair) {
							return pair.first == entity && pair.second.get() == behaviourPtr;
						}),
					behaviours_.end()
				);
			}
		}
		// コンポーネントストレージから削除
		it->second.erase(typeIndex);
	}

	template<typename T>
	void World::ForEach(std::function<void(Entity, T&)> func)
	{
		for (auto& entity : entities_) {
			T* component = TryGet<T>(entity);
			if (component) {
				func(entity, *component);
			}
		}
	}

	template<typename T1, typename T2>
	void World::ForEach(std::function<void(Entity, T1&, T2&)> func)
	{
		for (auto& entity : entities_) {
			T1* c1 = TryGet<T1>(entity);
			T2* c2 = TryGet<T2>(entity);
			if (c1 && c2) {
				func(entity, *c1, *c2);
			}
		}
	}

	template<typename T1, typename T2, typename T3>
	void World::ForEach(std::function<void(Entity, T1&, T2&, T3&)> func)
	{
		for (auto& entity : entities_) {
			T1* c1 = TryGet<T1>(entity);
			T2* c2 = TryGet<T2>(entity);
			T3* c3 = TryGet<T3>(entity);
			if (c1 && c2) {
				func(entity, *c1, *c2, *c3);
			}
		}
	}


};	// namespace ECS
