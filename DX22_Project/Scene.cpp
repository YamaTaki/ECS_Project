#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::RootUpdate()
{
	Update();
}

void Scene::RootDraw()
{
	Draw();
}

void Scene::SetWorld(ECS::World* w)
{
	m_pWorld = w;
}

void Scene::SetScene(SceneChange* s)
{
	m_sceneChange = s;
}
