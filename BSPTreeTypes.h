#ifndef __INCLUDED_BSPTREE_TYPES_h
#define __INCLUDED_BSPTREE_TYPES_h

#include "3DLib\vectorlib.h"

struct NODE
{
	unsigned char IsLeaf;
	unsigned long Plane;
	unsigned long Front;
	signed long Back;
	BOUNDINGBOX BoundingBox;
};

struct LEAF
{
	long StartPolygon;
	long EndPolygon;
	long PortalIndexList[50];
	long NumberOfPortals;
	long PVSIndex;
	BOUNDINGBOX BoundingBox;
};

struct PLANE
{
	vector3_t PointOnPlane;
	vector3_t Normal;
};

struct PLANE2
{
	vector3_t normal;
	float distance;
};

#endif//__INCLUDED_BSPTREE_TYPES_h