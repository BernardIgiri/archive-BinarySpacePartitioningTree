#ifndef __INCLUDED_TRANSFORMLIB_H__
#define __INCLUDED_TRANSFORMLIB_H__

#include "drawlib.h"

#define TLIB_XAXIS 0
#define TLIB_YAXIS 1
#define TLIB_ZAXIS 2

void Rotate(VERTEX *dest,VERTEX *source,int nVectors,int axis,float angle);
void Scale(VERTEX *dest,VERTEX *source,int nVectors,float x,float y,float z);
void Scale(VERTEX *dest,VERTEX *source,int nVectors,float *v);
void Translate(VERTEX *dest,VERTEX *source,int nVectors,float x,float y,float z);
void Translate(VERTEX *dest,VERTEX *source,int nVectors,float *v);
void FindCenter(VERTEX *dest,VERTEX *source,int nVectors);
class C3DTransform
{
public:
	C3DTransform();
	~C3DTransform();
	void LoadIdentity();
	void Rotate(int axis,float angle);
	void Scale(float x,float y,float z);
	void Scale(float *v);
	void Translate(float x,float y,float z);
	void Translate(float *v);
	void ApplyMatrix(VERTEX *center,VERTEX *source,int nVectors);
protected:
	float matrix1[16],matrix2[16];
};

#endif//__INCLUDED_TRANSFORMLIB_H__