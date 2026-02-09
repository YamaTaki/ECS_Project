/*****************************************************************//**
* \file   SceneResult.h 
* \brief  リザルトを表示するシーン.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#pragma once
#include "Scene.h"

class SceneResult :
    public Scene
{
public:
    SceneResult();
    ~SceneResult();

    void Init();
    void Update();
    void Draw();


};

