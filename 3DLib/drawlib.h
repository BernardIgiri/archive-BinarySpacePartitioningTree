#ifndef __INCLUDED_DRAWLIB_H__
#define __INCLUDED_DRAWLIB_H__

struct VERTEX
{
	float x,y,z;
};

struct PLANE2
{
	VERTEX normal;
	float distance;
};

struct PLANE
{
	VERTEX PointOnPlane;
	VERTEX Normal;
}

#endif//__INCLUDED_DRAWLIB_H__