/*****************************************************************//**
* \file   SceneTitle.cpp 
* \brief  タイトルの実装.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - 滝谷昌平
* --------------------------------------------------------------
* \date   2026/2/3 - begin
*********************************************************************/
#include "SceneTitle.h"
#include "Defines.h"
#include "Input.h"


SceneTitle::SceneTitle()
	:m_upLogo(nullptr)
{
	m_upLogo = std::make_unique<Texture>();
	if (FAILED(m_upLogo->Create("Assets/Texture/Title_prov.png"))) {
		MessageBox(NULL, "Title texture load failed.", "Texture Error", MB_OK);
	}

	m_LogoPos = { 0.0f, 0.0f };
	m_LogoSize = { SCREEN_WIDTH, SCREEN_HEIGHT };

}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{

}

void SceneTitle::Update()
{
	if (IsKeyRelease(VK_LBUTTON)) {
		m_sceneChange->Change(E_Scene::Game);
	}
}

void SceneTitle::Draw()
{
	// 変数定義
	DirectX::XMFLOAT4X4 world, view, proj;
	// 各行列の作成(2DのためIdentiny)
	DirectX::XMStoreFloat4x4(&world, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&view, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&proj,
		DirectX::XMMatrixOrthographicLH(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f));
	// 適応
	Sprite::SetWorld(world);
	Sprite::SetView(view);
	Sprite::SetProjection(proj);

	// テクスチャのセット
	Sprite::SetTexture(m_upLogo.get());

	// 位置、サイズ、色設定
	Sprite::SetOffset(m_LogoPos);
	Sprite::SetSize(m_LogoSize);
	Sprite::SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	Sprite::SetUVPos({ 0.0f, 0.0f });
	Sprite::SetUVScale({ 1.0f, 1.0f });

	Sprite::Draw();
}
