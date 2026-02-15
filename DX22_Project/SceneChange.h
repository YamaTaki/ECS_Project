/*****************************************************************//**
* \file   SceneRequest.h 
* \brief  シーン遷移をリクエストするコンポーネントを作成.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/9 - begin
*********************************************************************/
#pragma once
#include "Components.h"


enum class E_Scene {
	Title,
	Game,
	Result,
	Max,
};

class SceneChange {
public:
	SceneChange(E_Scene init) : m_scene(init) {}
	~SceneChange() {}

	inline void Change(E_Scene next) { m_scene = next;	}
	inline E_Scene GetScene() { return m_scene; }

private:
	E_Scene m_scene;

};
