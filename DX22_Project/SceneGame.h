/*****************************************************************//**
* \file   SceneGame.h 
* \brief  ÉQÅ[ÉÄÉVÅ[Éì.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*		 2026/2/15 - Add Init function
*********************************************************************/
#ifndef __SCENE_GAME_H__
#define __SCENE_GAME_H__

#include <memory>
#include "Scene.h"
#include "Entity.h"
#include "World.h"

class SceneGame : 
	public Scene
{
public:
	SceneGame();
	~SceneGame();

	void Init() final;
	void Update() final;
	void Draw() final;

private:
	void EntityInit();

private:
	ECS::Entity box;
	ECS::Entity camera;
	ECS::Entity other;

};

#endif // __SCENE_GAME_H__