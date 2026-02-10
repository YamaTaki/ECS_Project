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
#include "Texture.h"
#include "SceneChange.h"
#include <DirectXMath.h>

class SceneResult :
    public Scene
{
public:
    SceneResult();
    ~SceneResult();

    void Update() final;
    void Draw() final;

    
private:
    SceneChange* m_sceneChange;

    std::unique_ptr<Texture> m_upLogo;
    DirectX::XMFLOAT2 m_LogoPos;
    DirectX::XMFLOAT2 m_LogoSize;


};

