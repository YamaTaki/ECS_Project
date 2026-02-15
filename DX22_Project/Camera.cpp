#include "Camera.h"

dCamera::dCamera()
	: m_pos(7.0f, 7.0f, 7.0f)
	, m_look(0.0f, 0.0f, 0.0f)
	,m_up(0.0f, 1.0f, 0.0f)
	,m_fovy(DirectX::XMConvertToRadians(60))
	,m_aspect(16.0f / 9.0f)
	,m_near(CMETER(0.1f))
	,m_far(METER(1000.0f))
{
}

DirectX::XMFLOAT4X4 dCamera::GetViewMatrix(bool transpose)
{
	DirectX::XMFLOAT4X4 mat;
	DirectX::XMMATRIX view;
	view = DirectX::XMMatrixLookAtLH(
		DirectX::XMVectorSet(m_pos.x, m_pos.y, m_pos.z, 0.0f),		// EyePosition
		DirectX::XMVectorSet(m_look.x, m_look.y, m_look.z, 0.0f),	// FocusPosition
		DirectX::XMVectorSet(m_up.x, m_up.y, m_up.z, 0.0f)			// UpDirection
	);
	if (transpose) {
		view = DirectX::XMMatrixTranspose(view);	// “]’u
	}
	DirectX::XMStoreFloat4x4(&mat, view);

	return mat;
}

DirectX::XMFLOAT4X4 dCamera::GetProjectionMatrix(bool transpose)
{
	DirectX::XMFLOAT4X4 mat;
	DirectX::XMMATRIX proj;
	proj = DirectX::XMMatrixPerspectiveFovLH(m_fovy, m_aspect, m_near, m_far);
	if (transpose) {
		proj = DirectX::XMMatrixTranspose(proj);
	}
	DirectX::XMStoreFloat4x4(&mat, proj);

	return mat;
}


