/*****************************************************************//**
* \file   SceneTitle.h 
* \brief  タイトルの表示を行う.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*         2026/2/9 - Pro title texture (仮タイトル画像の実装)
*********************************************************************/
#pragma once
#include "Scene.h"
#include "Texture.h"
#include "Sprite.h"
#include <memory>
#include "DirectXMath.h"
#include "Entity.h"
#include "World.h"
#include "SceneChange.h"

class SceneTitle :
    public Scene
{
public:
    SceneTitle();
    ~SceneTitle();

    void Update() final;
    void Draw() final;

    
private:
    std::unique_ptr<Texture> m_upLogo;
    DirectX::XMFLOAT2 m_LogoPos;
    DirectX::XMFLOAT2 m_LogoSize;
    

};

