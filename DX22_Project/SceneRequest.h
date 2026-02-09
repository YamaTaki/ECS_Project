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

struct SceneChangeRequest : ECS::IComponent {
	E_Scene next;
};

