#include "CameraDebug.h"

CameraDebug::CameraDebug()
	:m_radXZ(0.0f)
	,m_radY(0.0f)
	,m_radius(7.0f)
{
}

void CameraDebug::Update()
{
	// カメラ距離の移動
	// 回り込みの処理
	if (IsKeyPress('A')) { m_radXZ += ROTATE; }
	if (IsKeyPress('D')) { m_radXZ -= ROTATE; }
	if (IsKeyPress('W')) { m_radY += ROTATE; }
	if (IsKeyPress('S')) { m_radY -= ROTATE; }

	if (IsKeyPress('E')) { m_radius += ROTATE; }
	if (IsKeyPress('Q')) { m_radius -= ROTATE; }

	if (m_radius == 0) {
		m_radius = 1;
	}

	// カメラ位置の計算
	m_pos.x = cosf(m_radY) * sinf(m_radXZ) * m_radius + m_look.x;
	m_pos.y = sinf(m_radY) * m_radius + m_look.y;
	m_pos.z = cosf(m_radY) * cosf(m_radXZ) * m_radius + m_look.z;



}
