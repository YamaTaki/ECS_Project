#ifndef __SCENE_H__
#define __SCENE_H__

#include "World.h"
#include "SceneChange.h"

class Scene
{
public:
	void RootUpdate();
	void RootDraw();

	Scene();
	virtual ~Scene();
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual void SetWorld(ECS::World* w);
	virtual void SetScene(SceneChange* s);

protected:
	SceneChange* m_sceneChange;
	ECS::World* m_pWorld;

};

#endif // __SCENE_H__