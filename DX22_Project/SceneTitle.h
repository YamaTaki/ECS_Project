/*****************************************************************//**
* \file   SceneTitle.h 
* \brief  タイトルの表示を行う.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#pragma once
#include "Scene.h"


class SceneTitle :
    public Scene
{
public:
    SceneTitle();
    ~SceneTitle();

    void Init();
    void Update();
    void Draw();

};

