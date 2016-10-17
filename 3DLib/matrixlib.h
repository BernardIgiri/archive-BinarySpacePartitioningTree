#ifndef __INCLUDED_MATRIXLIB_H__
#define __INCLUDED_MATRIXLIB_H__
#include <math.h>
#include "angleMath.h"

struct matrix4x4_t
{
	matrix4x4_t(matrix4x4_t &m) { *this=m; };
	matrix4x4_t() { LoadIdentity(); };
	void LoadZero()
	{
		for (int i=0;i<15;i++)
			matrix[i]=0.0f;
	}
	void LoadIdentity()
	{
		matrix[0] =1.0f; matrix[1] =0.0f; matrix[2] =0.0f; matrix[3] =0.0f;
		matrix[4] =0.0f; matrix[5] =1.0f; matrix[6] =0.0f; matrix[7] =0.0f;
		matrix[8] =0.0f; matrix[9] =0.0f; matrix[10]=1.0f; matrix[11]=0.0f;
		matrix[12]=0.0f; matrix[13]=0.0f; matrix[14]=0.0f; matrix[15]=1.0f;
	}
	void LoadTranslation(float tx,float ty,float tz)
	{
		matrix[0] =1.0f; matrix[1] =0.0f; matrix[2] =0.0f; matrix[3] =0.0f;
		matrix[4] =0.0f; matrix[5] =1.0f; matrix[6] =0.0f; matrix[7] =0.0f;
		matrix[8] =0.0f; matrix[9] =0.0f; matrix[10]=1.0f; matrix[11]=0.0f;
		matrix[12]=tx;   matrix[13]=ty;   matrix[14]=tz;   matrix[15]=1.0f;
	}
	void LoadTranslation(float *v)
	{
		matrix[0] =1.0f; matrix[1] =0.0f; matrix[2] =0.0f; matrix[3] =0.0f;
		matrix[4] =0.0f; matrix[5] =1.0f; matrix[6] =0.0f; matrix[7] =0.0f;
		matrix[8] =0.0f; matrix[9] =0.0f; matrix[10]=1.0f; matrix[11]=0.0f;
		matrix[12]=v[0]; matrix[13]=v[1]; matrix[14]=v[2]; matrix[15]=1.0f;
	}
	void LoadXRotation(float angle)
	{
		float rad = TORADIANS(angle);
		matrix[0] =1.0f;matrix[1] =0.0f;		   matrix[2] =0.0f;			   matrix[3] =0.0f;
		matrix[4] =0.0f;matrix[5] =(float)cos(rad);matrix[6] =-(float)sin(rad);matrix[7] =0.0f;
		matrix[8] =0.0f;matrix[9] =(float)sin(rad);matrix[10]=(float)cos(rad); matrix[11]=0.0f;
		matrix[12]=0.0f;matrix[13]=0.0f;		   matrix[14]=0.0f;			   matrix[15]=1.0f;
	}
	void LoadYRotation(float angle)
	{
		float rad = TORADIANS(angle);
		matrix[0] =(float)cos(rad); matrix[1] =0.0f;matrix[2] =(float)sin(rad);matrix[3] =0.0f;
		matrix[4] =0.0f;			matrix[5] =1.0f;matrix[6] =0.0f;		   matrix[7] =0.0f;
		matrix[8] =-(float)sin(rad);matrix[9] =0.0f;matrix[10]=(float)cos(rad);matrix[11]=0.0f;
		matrix[12]=0.0f;			matrix[13]=0.0f;matrix[14]=0.0f;		   matrix[15]=1.0f;
	}
	void LoadZRotation(float angle)
	{
		float rad = TORADIANS(angle);
		matrix[0] =(float)cos(rad);matrix[1] =-(float)sin(rad);matrix[2] =0.0f;matrix[3] =0.0f;
		matrix[4] =(float)sin(rad);matrix[5] =(float)cos(rad); matrix[6] =0.0f;matrix[7] =0.0f;
		matrix[8] =0.0f;		   matrix[9] =0.0f;			   matrix[10]=1.0f;matrix[11]=0.0f;
		matrix[12]=0.0f;		   matrix[13]=0.0f;			   matrix[14]=0.0f;matrix[15]=1.0f;
	}
	void LoadScale(float sx,float sy,float sz)
	{
		matrix[0] =sx;	 matrix[1] =0.0f; matrix[2] =0.0f; matrix[3] =0.0f;
		matrix[4] =0.0f; matrix[5] =sy;	  matrix[6] =0.0f; matrix[7] =0.0f;
		matrix[8] =0.0f; matrix[9] =0.0f; matrix[10]=sz;   matrix[11]=0.0f;
		matrix[12]=0.0f; matrix[13]=0.0f; matrix[14]=0.0f; matrix[15]=1.0f;
	}
	void LoadScale(float *v)
	{
		matrix[0] =v[0]; matrix[1] =0.0f; matrix[2] =0.0f; matrix[3] =0.0f;
		matrix[4] =0.0f; matrix[5] =v[1]; matrix[6] =0.0f; matrix[7] =0.0f;
		matrix[8] =0.0f; matrix[9] =0.0f; matrix[10]=v[2]; matrix[11]=0.0f;
		matrix[12]=0.0f; matrix[13]=0.0f; matrix[14]=0.0f; matrix[15]=1.0f;
	}
	matrix4x4_t operator+ (const matrix4x4_t &m) const
	{
		matrix4x4_t result;
		result.matrix[0]= matrix[0]+m.matrix[0];
		result.matrix[1]= matrix[1]+m.matrix[1];
		result.matrix[2]= matrix[2]+m.matrix[2];
		result.matrix[3]= matrix[3]+m.matrix[3];
		result.matrix[4]= matrix[4]+m.matrix[4];
		result.matrix[5]= matrix[5]+m.matrix[5];
		result.matrix[6]= matrix[6]+m.matrix[6];
		result.matrix[7]= matrix[7]+m.matrix[7];
		result.matrix[8]= matrix[8]+m.matrix[8];
		result.matrix[9]= matrix[9]+m.matrix[9];
		result.matrix[10]=matrix[10]+m.matrix[10];
		result.matrix[11]=matrix[11]+m.matrix[11];
		result.matrix[12]=matrix[12]+m.matrix[12];
		result.matrix[13]=matrix[13]+m.matrix[13];
		result.matrix[14]=matrix[14]+m.matrix[14];
		result.matrix[15]=matrix[15]+m.matrix[15];
		return result;
	}
	matrix4x4_t operator- (const matrix4x4_t &m) const
	{
		matrix4x4_t result;
		result.matrix[0]= matrix[0]-m.matrix[0];
		result.matrix[1]= matrix[1]-m.matrix[1];
		result.matrix[2]= matrix[2]-m.matrix[2];
		result.matrix[3]= matrix[3]-m.matrix[3];
		result.matrix[4]= matrix[4]-m.matrix[4];
		result.matrix[5]= matrix[5]-m.matrix[5];
		result.matrix[6]= matrix[6]-m.matrix[6];
		result.matrix[7]= matrix[7]-m.matrix[7];
		result.matrix[8]= matrix[8]-m.matrix[8];
		result.matrix[9]= matrix[9]-m.matrix[9];
		result.matrix[10]=matrix[10]-m.matrix[10];
		result.matrix[11]=matrix[11]-m.matrix[11];
		result.matrix[12]=matrix[12]-m.matrix[12];
		result.matrix[13]=matrix[13]-m.matrix[13];
		result.matrix[14]=matrix[14]-m.matrix[14];
		result.matrix[15]=matrix[15]-m.matrix[15];
		return result;
	}
	matrix4x4_t operator* (const float scalar) const
	{
		matrix4x4_t result;
		result.matrix[0]= matrix[0]*scalar;
		result.matrix[1]= matrix[1]*scalar;
		result.matrix[2]= matrix[2]*scalar;
		result.matrix[3]= matrix[3]*scalar;
		result.matrix[4]= matrix[4]*scalar;
		result.matrix[5]= matrix[5]*scalar;
		result.matrix[6]= matrix[6]*scalar;
		result.matrix[7]= matrix[7]*scalar;
		result.matrix[8]= matrix[8]*scalar;
		result.matrix[9]= matrix[9]*scalar;
		result.matrix[10]=matrix[10]*scalar;
		result.matrix[11]=matrix[11]*scalar;
		result.matrix[12]=matrix[12]*scalar;
		result.matrix[13]=matrix[13]*scalar;
		result.matrix[14]=matrix[14]*scalar;
		result.matrix[15]=matrix[15]*scalar;
		return result;
	}
	matrix4x4_t operator* (const matrix4x4_t &m) const
	{
		matrix4x4_t result;

		result.matrix[0]= (matrix[0]*m.matrix[0])+(matrix[4]*m.matrix[1])+(matrix[8]*m.matrix[2])+(matrix[12]*m.matrix[3]);
		result.matrix[4]= (matrix[0]*m.matrix[4])+(matrix[4]*m.matrix[5])+(matrix[8]*m.matrix[6])+(matrix[12]*m.matrix[7]);
		result.matrix[8]= (matrix[0]*m.matrix[8])+(matrix[4]*m.matrix[9])+(matrix[8]*m.matrix[10])+(matrix[12]*m.matrix[11]);
		result.matrix[12]= (matrix[0]*m.matrix[12])+(matrix[4]*m.matrix[13])+(matrix[8]*m.matrix[14])+(matrix[12]*m.matrix[15]);
	
		result.matrix[1]= (matrix[1]*m.matrix[0])+(matrix[5]*m.matrix[1])+(matrix[9]*m.matrix[2])+(matrix[13]*m.matrix[3]);
		result.matrix[5]= (matrix[1]*m.matrix[4])+(matrix[5]*m.matrix[5])+(matrix[9]*m.matrix[6])+(matrix[13]*m.matrix[7]);
		result.matrix[9]= (matrix[1]*m.matrix[8])+(matrix[5]*m.matrix[9])+(matrix[9]*m.matrix[10])+(matrix[13]*m.matrix[11]);
		result.matrix[13]= (matrix[1]*m.matrix[12])+(matrix[5]*m.matrix[13])+(matrix[9]*m.matrix[14])+(matrix[13]*m.matrix[15]);

		result.matrix[2]= (matrix[2]*m.matrix[0])+(matrix[6]*m.matrix[1])+(matrix[10]*m.matrix[2])+(matrix[14]*m.matrix[3]);
		result.matrix[6]= (matrix[2]*m.matrix[4])+(matrix[6]*m.matrix[5])+(matrix[10]*m.matrix[6])+(matrix[14]*m.matrix[7]);
		result.matrix[10]= (matrix[2]*m.matrix[8])+(matrix[6]*m.matrix[9])+(matrix[10]*m.matrix[10])+(matrix[14]*m.matrix[11]);
		result.matrix[14]= (matrix[2]*m.matrix[12])+(matrix[6]*m.matrix[13])+(matrix[10]*m.matrix[14])+(matrix[14]*m.matrix[15]);

		result.matrix[3]= (matrix[3]*m.matrix[0])+(matrix[7]*m.matrix[1])+(matrix[11]*m.matrix[2])+(matrix[15]*m.matrix[3]);
		result.matrix[7]= (matrix[3]*m.matrix[4])+(matrix[7]*m.matrix[5])+(matrix[11]*m.matrix[6])+(matrix[15]*m.matrix[7]);
		result.matrix[11]= (matrix[3]*m.matrix[8])+(matrix[7]*m.matrix[9])+(matrix[11]*m.matrix[10])+(matrix[15]*m.matrix[11]);
		result.matrix[15]= (matrix[3]*m.matrix[12])+(matrix[7]*m.matrix[13])+(matrix[11]*m.matrix[14])+(matrix[15]*m.matrix[15]);

		return result;
	}
	float matrix[16];
};

#endif//__INCLUDED_MATRIXLIB_H__