// CameraDebug.h

#ifndef ___CAMERADEBUG_H___
#define ___CAMERADEBUG_H___

#include "Camera.h"
#include "Input.h"


class CameraDebug
	:public dCamera
{
public:
	CameraDebug();
	~CameraDebug() {}

	void Update() final;

private:
	const float MOVESPEED = 1.0f;
	const float ROTATE = DirectX::XMConvertToRadians(3);

	float m_radXZ;	// カメラの横移動
	float m_radY;	// カメラの縦移動
	float m_radius;	// カメラと注視点の距離

};


#endif // !___CAMERADEBUG_H___


