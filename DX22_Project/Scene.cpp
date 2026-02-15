#include "Scene.h"

Scene::Scene()
	: m_sceneChange(nullptr)
	, m_pWorld(nullptr)
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
