#include "Geometry.h"

#define MAX_VERTEX	(36)
#define DATA_SIZE	(20)

void Geometry::MakeBox()
{
	//--- 頂点の作成
	Vertex vtx[] = {
		// -z面 - ok
		{{ -0.5f,  0.5f, -0.5f },{ 0.0f, 0.0f }},	// -x::2, +y::2
		{{  0.5f,  0.5f, -0.5f },{ 1.0f, 0.0f }},	// +x::1, +y::1
		{{ -0.5f, -0.5f, -0.5f },{ 0.0f, 1.0f }},	// -x::4, -y::1
		{{  0.5f, -0.5f, -0.5f },{ 1.0f, 1.0f }},	// +x::3, -y::2
		// +z面 - ok
		{{  0.5f,  0.5f,  0.5f },{ 0.0f, 0.0f }},
		{{ -0.5f,  0.5f,  0.5f },{ 1.0f, 0.0f }},
		{{  0.5f, -0.5f,  0.5f },{ 0.0f, 1.0f }},
		{{ -0.5f, -0.5f,  0.5f },{ 1.0f, 1.0f }},
		// -x面 - ok
		{{ -0.5f,  0.5f,  0.5f },{ 0.0f, 0.0f }},
		{{ -0.5f,  0.5f, -0.5f },{ 1.0f, 0.0f }},
		{{ -0.5f, -0.5f,  0.5f },{ 0.0f, 1.0f }},
		{{ -0.5f, -0.5f, -0.5f },{ 1.0f, 1.0f }},
		// +x面 - ok
		{{  0.5f,  0.5f, -0.5f },{ 0.0f, 0.0f }},
		{{  0.5f,  0.5f,  0.5f },{ 1.0f, 0.0f }},
		{{  0.5f, -0.5f, -0.5f },{ 0.0f, 1.0f }},
		{{  0.5f, -0.5f,  0.5f },{ 1.0f, 1.0f }},
		// -y面 - 
		{{ -0.5f, -0.5f, -0.5f },{ 0.0f, 0.0f }},
		{{  0.5f, -0.5f, -0.5f },{ 1.0f, 0.0f }},
		{{ -0.5f, -0.5f,  0.5f },{ 0.0f, 1.0f }},
		{{  0.5f, -0.5f,  0.5f },{ 1.0f, 1.0f }},
		// +y面 - ok
		{{  0.5f,  0.5f, -0.5f },{ 0.0f, 0.0f }},
		{{ -0.5f,  0.5f, -0.5f },{ 1.0f, 0.0f }},
		{{  0.5f,  0.5f,  0.5f },{ 0.0f, 1.0f }},
		{{ -0.5f,  0.5f,  0.5f },{ 1.0f, 1.0f }},
	};

	//--- インデックスの作成
	int idx[] = {
		 0,  1,  2,  1,  3,  2,	// -z面
		 4,  5,  6,  5,  7,  6,	// z面
		 8,  9, 10,  9, 11, 10,	// -x面
		12, 13, 14, 13, 15, 14,	// x面
		16, 17, 18, 17, 19, 18,	// -y面
		20, 21, 22, 21, 23, 22,	// y面
	};

	// バッファの作成
	MeshBuffer::Description desc = {};
	desc.pVtx = vtx;
	desc.vtxCount = sizeof(idx) / sizeof(int);	// 36
	desc.vtxSize = DATA_SIZE;
	desc.pIdx = idx;
	desc.idxCount = sizeof(idx) / sizeof(int);
	desc.idxSize = sizeof(long);
	desc.topology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	m_pBox = new MeshBuffer();
	m_pBox->Create(desc);
}

void Geometry::MakeCylinder()
{
	//--- 頂点の作成
	// 天面、底面

	// 側面

	//--- インデックスの作成
	// 天面、底面

	// 側面


	//--- バッファの作成
}

void Geometry::MakeSphere()
{
	//--- 頂点の作成

	//--- インデックスの作成

	// バッファの作成
}