#ifndef __INCLUDED_POLYGON_h__
#define __INCLUDED_POLYGON_h__

#include "3DLib\vectorlib.h"

struct VERTEX
{
	float x,y,z;
};

struct POLYGON
{
	VERTEX *VertexList;
	vector3_t Normal;
	WORD NumberOfVertices;
	WORD NumberOfIndices;
	WORD *Indices;
	POLYGON *Next;
	bool BeenUsedAsSplitter;
	long TextureIndex;
};

#endif//__INCLUDED_POLYGON_h__