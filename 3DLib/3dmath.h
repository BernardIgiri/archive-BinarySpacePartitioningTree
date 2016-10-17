#ifndef __INCLUDED_3DMATH_H__
#define __INCLUDED_3DMATH_H__
#include "drawlib.h"

void CalcViewClipPlanes(PLANE2 *planes);
void CalculateNormal(float point1[3], float point2[3], float point3[3],float normal[3]);
void CalcViewBox(VERTEX &left,VERTEX &top,VERTEX &right,VERTEX &bottom, VERTEX *box, float angle);
//void CircleClamp(float &angle,float limit);
inline void CircleClamp(float &angle,float limit)
{
	if (angle<0.0f)
		angle=angle-(float)((int)(angle/limit))+limit;
	if (angle>limit)
		angle=angle-limit*(float)((int)(angle/limit));
}

#endif//__INCLUDED_3DMATH_H__