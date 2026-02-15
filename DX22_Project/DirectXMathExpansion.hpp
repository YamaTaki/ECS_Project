/*****************************************************************//**
* \file   DirectXMathExpansion.hpp 
* \brief  DirectXMathÇÃägí£.
* 
* --------------------------------------------------------------
* \author Shohei Takitani - ëÍíJèπïΩ
* --------------------------------------------------------------
* \date   2026/02/10 - begin
*********************************************************************/
#pragma once

#include <DirectXMath.h>

using namespace DirectX;

// XMFLOAT3ìØémÇÃélë•ââéZ
inline XMFLOAT3 operator+(const XMFLOAT3& a, const XMFLOAT3& b) { return XMFLOAT3(a.x + b.x, a.y + b.y, a.z + a.z); }
inline XMFLOAT3 operator-(const XMFLOAT3& a, const XMFLOAT3& b) { return XMFLOAT3(a.x - b.x, a.y - b.y, a.z - a.z); }
inline XMFLOAT3 operator*(const XMFLOAT3& a, const XMFLOAT3& b) { return XMFLOAT3(a.x * b.x, a.y * b.y, a.z * a.z); }
inline XMFLOAT3 operator/(const XMFLOAT3& a, const XMFLOAT3& b) { return XMFLOAT3(a.x / b.x, a.y / b.y, a.z / a.z); }

// XMFLOAT3Ç∆floatÇÃélë•ââéZ
inline XMFLOAT3 operator+(const XMFLOAT3& a, float s) {	return XMFLOAT3(a.x + s, a.y + s, a.z + s); }
inline XMFLOAT3 operator-(const XMFLOAT3& a, float s) {	return XMFLOAT3(a.x - s, a.y - s, a.z - s); }
inline XMFLOAT3 operator*(const XMFLOAT3& a, float s) {	return XMFLOAT3(a.x * s, a.y * s, a.z * s); }
inline XMFLOAT3 operator/(const XMFLOAT3& a, float s) {	return XMFLOAT3(a.x / s, a.y / s, a.z / s); }

// XMFLOAT3ìØémÇÃï°çáë„ì¸ââéZéq
inline XMFLOAT3& operator+=(XMFLOAT3& a, const XMFLOAT3& b) { a.x += b.x; a.y += b.y; a.z += b.z;	return a; }
inline XMFLOAT3& operator-=(XMFLOAT3& a, const XMFLOAT3& b) { a.x -= b.x; a.y -= b.y; a.z -= b.z;	return a; }
inline XMFLOAT3& operator*=(XMFLOAT3& a, const XMFLOAT3& b) { a.x *= b.x; a.y *= b.y; a.z *= b.z;	return a; }
inline XMFLOAT3& operator/=(XMFLOAT3& a, const XMFLOAT3& b) { a.x /= b.x; a.y /= b.y; a.z /= b.z;	return a;}

// XMFLOAT3Ç∆floatÇÃï°çáë„ì¸ââéZéq
inline XMFLOAT3& operator+=(XMFLOAT3& a, float s) {	a.x += s; a.y += s; a.z += s; return a; }
inline XMFLOAT3& operator-=(XMFLOAT3& a, float s) {	a.x -= s; a.y -= s; a.z -= s; return a; }
inline XMFLOAT3& operator*=(XMFLOAT3& a, float s) {	a.x *= s; a.y *= s; a.z *= s; return a; }
inline XMFLOAT3& operator/=(XMFLOAT3& a, float s) {	a.x /= s; a.y /= s; a.z /= s; return a; }

// XMFLOAT3ìØémÇÃî‰är
inline bool operator==(const XMFLOAT3& a, const XMFLOAT3& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }
inline bool operator!=(const XMFLOAT3& a, const XMFLOAT3& b) { return a.x != b.x || a.y != b.y || a.z != b.z; }
