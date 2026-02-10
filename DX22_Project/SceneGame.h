/*****************************************************************//**
* \file   SceneGame.h 
* \brief  ÉQÅ[ÉÄÉVÅ[Éì.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#ifndef __SCENE_GAME_H__
#define __SCENE_GAME_H__

#include "Scene.h"
#include "Entity.h"
#include "World.h"

class SceneGame : 
	public Scene
{
public:
	SceneGame();
	~SceneGame();

	void Update() final;
	void Draw() final;


private:
	ECS::Entity box;

};

#endif // __SCENE_GAME_H__