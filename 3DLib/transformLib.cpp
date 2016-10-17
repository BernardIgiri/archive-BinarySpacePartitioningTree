#include <memory.h>
#include "matrixlib.h"
#include "transformLib.h"

void Rotate(VERTEX *dest,VERTEX *source,int nVectors,int axis,float angle)
{
	static matrix4x4_t matrix1, matrix2;
	VERTEX *pS=source, *pD=dest;
	if (nVectors<=0)
		return;
	switch (axis)
	{
	case TLIB_XAXIS:
		while (nVectors--)
		{
			matrix1.LoadTranslation((float *)pS);
			matrix2.LoadXRotation(angle);
			matrix1=matrix2*matrix1;
			memcpy(pD,&matrix1.matrix[12],sizeof(VERTEX));
			pS++;
			pD++;
		}
		break;
	case TLIB_YAXIS:
		while (nVectors--)
		{
			matrix1.LoadTranslation((float *)pS);
			matrix2.LoadYRotation(angle);
			matrix1=matrix2*matrix1;
			memcpy(pD,&matrix1.matrix[12],sizeof(VERTEX));
			pS++;
			pD++;
		}
		break;
	case TLIB_ZAXIS:
		while (nVectors--)
		{
			matrix1.LoadTranslation((float *)pS);
			matrix2.LoadZRotation(angle);
			matrix1=matrix2*matrix1;
			memcpy(pD,&matrix1.matrix[12],sizeof(VERTEX));
			pS++;
			pD++;
		}
		break;
	default:
		break;
	};
}

void Scale(VERTEX *dest,VERTEX *source,int nVectors,float x,float y,float z)
{
	VERTEX *pS=source, *pD=dest;
	if (nVectors<=0)
		return;
	while (nVectors--)
	{
		pD->x=pS->x*x;
		pD->y=pS->y*y;
		pD->z=pS->z*z;
		pD++;
		pS++;
	}
}

void Scale(VERTEX *dest,VERTEX *source,int nVectors,float *v)
{
	VERTEX *pS=source, *pD=dest;
	if (nVectors<=0)
		return;
	while (nVectors--)
	{
		pD->x=pS->x*v[0];
		pD->y=pS->y*v[1];
		pD->z=pS->z*v[2];
		pD++;
		pS++;
	}
}

void Translate(VERTEX *dest,VERTEX *source,int nVectors,float x,float y,float z)
{
	VERTEX *pS=source, *pD=dest;
	if (nVectors<=0)
		return;
	while (nVectors--)
	{
		pD->x=pS->x+x;
		pD->y=pS->y+y;
		pD->z=pS->z+z;
		pD++;
		pS++;
	}
}

void Translate(VERTEX *dest,VERTEX *source,int nVectors,float *v)
{
	VERTEX *pS=source, *pD=dest;
	if (nVectors<=0)
		return;
	while (nVectors--)
	{
		pD->x=pS->x+v[0];
		pD->y=pS->y+v[1];
		pD->z=pS->z+v[2];
		pD++;
		pS++;
	}
}

void FindCenter(VERTEX *center,VERTEX *source,int nVectors)
{
	VERTEX *pS=source, vMax,vMin;
	vMax.y=vMax.z=vMax.x=-999999.0f;
	vMin.y=vMin.z=vMin.x= 999999.0f;
	if (nVectors<=0)
		return;
	while (nVectors--)
	{
		if (pS->x>vMax.x)
			vMax.x=pS->x;
		if (pS->y>vMax.y)
			vMax.y=pS->y;
		if (pS->z>vMax.z)
			vMax.z=pS->z;
		if (pS->x<vMin.x)
			vMin.x=pS->x;
		if (pS->y<vMin.y)
			vMin.y=pS->y;
		if (pS->z<vMin.z)
			vMin.z=pS->z;
		pS++;
	}
	center->x=(vMax.x+vMin.x)/2.0f;
	center->y=(vMax.y+vMin.y)/2.0f;
	center->z=(vMax.z+vMin.z)/2.0f;
}

C3DTransform::C3DTransform()
{
	LoadIdentity();
}
C3DTransform::~C3DTransform()
{
}
void C3DTransform::LoadIdentity()
{
	((matrix4x4_t*)matrix1)->LoadIdentity();
}
void C3DTransform::Rotate(int axis,float angle)
{
	switch (axis)
	{
	case TLIB_XAXIS:
		((matrix4x4_t *)matrix2)->LoadXRotation(angle);
		(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
		break;
	case TLIB_YAXIS:
		((matrix4x4_t *)matrix2)->LoadYRotation(angle);
		(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
		break;
	case TLIB_ZAXIS:
		((matrix4x4_t *)matrix2)->LoadZRotation(angle);
		(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
		break;
	default:
		break;
	};
}
void C3DTransform::Scale(float x,float y,float z)
{
	((matrix4x4_t*)matrix2)->LoadScale(x,y,z);
	(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
}
void C3DTransform::Scale(float *v)
{
	((matrix4x4_t*)matrix2)->LoadScale(v);
	(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
}
void C3DTransform::Translate(float x,float y,float z)
{
	((matrix4x4_t*)matrix2)->LoadTranslation(x,y,z);
	(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
}
void C3DTransform::Translate(float *v)
{
	((matrix4x4_t*)matrix2)->LoadTranslation(v);
	(*((matrix4x4_t *)matrix1))=(*((matrix4x4_t *)matrix2))*(*((matrix4x4_t *)matrix1));
}
void C3DTransform::ApplyMatrix(VERTEX *dest,VERTEX *source,int nVectors)
{
	VERTEX *pS=source, *pD=dest;
	while (nVectors--)
	{
		((matrix4x4_t*)matrix2)->LoadTranslation((float *)pS);
		(*((matrix4x4_t*)matrix2))=(*((matrix4x4_t*)matrix1))*(*((matrix4x4_t*)matrix2));
		memcpy(pD,&((matrix4x4_t*)matrix2)->matrix[12],sizeof(VERTEX));
		pS++;
		pD++;
	}
}


//C3DTransform::Scale(VERTEX *dest,VERTE