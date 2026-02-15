/*****************************************************************//**
* \file   RenderContext.h 
* \brief  ï`âÊèàóù.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/12 - begin
*********************************************************************/
#pragma once
#include <DirectXMath.h>

class RenderContext
{
public:
	RenderContext() 
		: m_view(), m_proj() {
	
	}
	~RenderContext(){}

	inline void SetView(const DirectX::XMMATRIX& v)			{ m_view = v; }
	inline void SetProjection(const DirectX::XMMATRIX& p)	{ m_proj = p; }

	inline const DirectX::XMMATRIX& GetView() const		{ return m_view; }
	inline const DirectX::XMMATRIX& GetProjction() const	{ return m_proj; }
	
private:
	DirectX::XMMATRIX m_view = DirectX::XMMatrixIdentity();
	DirectX::XMMATRIX m_proj = DirectX::XMMatrixIdentity();

};

