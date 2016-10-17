#define WIN32_LEAN_AND_MEAN   // get rid of Windows things we don't need

#include <windows.h>          // included in all Windows apps
#include <winuser.h>          // Windows constants
#include <stdio.h>
#include <gl/gl.h>            // OpenGL include
#include <gl/glu.h>           // OpenGL utilty library
#include <gl/glaux.h>
#include "matrixlib.h"
#include "vectorlib.h"
#include "3dmath.h"
#include "transformlib.h"

void CalcViewClipPlanes(PLANE2 *planes)
{
	matrix4x4_t projMatrix,viewMatrix,viewProj;
	glGetFloatv(GL_MODELVIEW_MATRIX,projMatrix.matrix);
	glGetFloatv(GL_PROJECTION_MATRIX,projMatrix.matrix);
	viewProj=viewMatrix*projMatrix;

	// left
	planes[0].normal.x = -(viewProj.matrix[12] + viewProj.matrix[0]);
	planes[0].normal.y = -(viewProj.matrix[13] + viewProj.matrix[1]);
	planes[0].normal.z = -(viewProj.matrix[14] + viewProj.matrix[2]);
	planes[0].distance = -(viewProj.matrix[15] + viewProj.matrix[3]);
	// right
	planes[1].normal.x = -(viewProj.matrix[12] - viewProj.matrix[0]);
	planes[1].normal.y = -(viewProj.matrix[13] - viewProj.matrix[1]);
	planes[1].normal.z = -(viewProj.matrix[14] - viewProj.matrix[2]);
	planes[1].distance = -(viewProj.matrix[15] - viewProj.matrix[3]);
	// top
	planes[2].normal.x = -(viewProj.matrix[12] - viewProj.matrix[4]);
	planes[2].normal.y = -(viewProj.matrix[13] - viewProj.matrix[5]);
	planes[2].normal.z = -(viewProj.matrix[14] - viewProj.matrix[6]);
	planes[2].distance = -(viewProj.matrix[15] - viewProj.matrix[7]);
	// bottom
	planes[3].normal.x = -(viewProj.matrix[12] + viewProj.matrix[4]);
	planes[3].normal.y = -(viewProj.matrix[13] + viewProj.matrix[5]);
	planes[3].normal.z = -(viewProj.matrix[14] + viewProj.matrix[6]);
	planes[3].distance = -(viewProj.matrix[15] + viewProj.matrix[7]);
	// near
	planes[4].normal.x = -(viewProj.matrix[12] + viewProj.matrix[8]);
	planes[4].normal.y = -(viewProj.matrix[13] + viewProj.matrix[9]);
	planes[4].normal.z = -(viewProj.matrix[14] + viewProj.matrix[10]);
	planes[4].distance = -(viewProj.matrix[15] + viewProj.matrix[11]);
	// far
	planes[5].normal.x = -(viewProj.matrix[12] - viewProj.matrix[8]);
	planes[5].normal.y = -(viewProj.matrix[13] - viewProj.matrix[9]);
	planes[5].normal.z = -(viewProj.matrix[14] - viewProj.matrix[10]);
	planes[5].distance = -(viewProj.matrix[15] - viewProj.matrix[11]);

	int count=6;
	while (count--)
		((vector3_t *)&planes[count].normal)->Normalize();
}

void CalculateNormal(float point1[3], float point2[3], float point3[3],float normal[3])
{
	//cross product
	float vector1[3]={0},vector2[3]={0};
	vector1[0] = point1[0] - point2[0];
	vector1[1] = point1[1] - point2[1];
	vector1[1] = point1[2] - point2[2];
	vector2[0] = point2[0] - point3[0];
	vector2[1] = point2[1] - point3[1];
	vector2[1] = point2[2] - point3[2];
	normal[0] = vector1[1]*vector2[2] - vector1[2]*vector2[2];
	normal[1] = vector1[2]*vector2[0] - vector1[0]*vector2[2];
	normal[2] = vector1[0]*vector2[1] - vector1[1]*vector2[0];
	//normalize
	double length = sqrt(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2]);
	for(int idx = 0; idx <3; idx++)
		normal[idx]/=(float)length;
}

void CalcViewBox(VERTEX &left,VERTEX &top,VERTEX &right,VERTEX &bottom, VERTEX *box, float angle)
{
	static VERTEX newBox[4];
	static VERTEX *pBoxV=newBox;
	Rotate(newBox,box,4,TLIB_YAXIS,angle);
	/*left.x=left.y=left.z= top.x=top.y=top.z= 999999.0f;
	right.x=right.y=right.z= bottom.x=bottom.y=bottom.z= -999999.0f;*/
	memcpy(&top,&box[2],sizeof(VERTEX));
	memcpy(&right,&box[0],sizeof(VERTEX));
	memcpy(&left,&box[3],sizeof(VERTEX));
	memcpy(&bottom,&box[1],sizeof(VERTEX));
	return;/*
	int count=4;
	while (count--)
	{
		if (pBoxV->x>right.x&&pBoxV->z>bottom.z)
			memcpy(&right,pBoxV,sizeof(VERTEX));
		if (pBoxV->x<left.x&&pBoxV->z<top.z)
			memcpy(&left,pBoxV,sizeof(VERTEX));
		if (pBoxV->z<top.z)
			memcpy(&top,pBoxV,sizeof(VERTEX));
		if (pBoxV->z>bottom.z)
			memcpy(&bottom,pBoxV,sizeof(VERTEX));
		pBoxV++;
	}*/
}


