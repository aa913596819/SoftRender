//
//  GIMatrix4x4f.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/31.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "GIMatrix3x3f.h"
#include "GIMatrix4x4f.h"
#include "GIFloatConversion.h"
#include <cmath>
#include"GIMacro.h"
NAMESPACE_GIAM_ENGINE_USING
Vector4f GiamEngine::mul(const Matrix4x4f& mat4, const Vector4f& vec4)
{
    float x = mat4.m_Data[0] * vec4.x + mat4.m_Data[1] * vec4.y + mat4.m_Data[2] * vec4.z + mat4.m_Data[3] * vec4.w;
    float y = mat4.m_Data[4] * vec4.x + mat4.m_Data[5] * vec4.y + mat4.m_Data[6] * vec4.z + mat4.m_Data[7] * vec4.w;
    float z = mat4.m_Data[8] * vec4.x + mat4.m_Data[9] * vec4.y + mat4.m_Data[10] * vec4.z + mat4.m_Data[11] * vec4.w;
    float w = mat4.m_Data[12] * vec4.x + mat4.m_Data[13] * vec4.y + mat4.m_Data[14] * vec4.z + mat4.m_Data[15] * vec4.w;
    return Vector4f(x,y,z,w);
}


void MultiplyMatrix4x4f(const Matrix4x4f& lhs,const Matrix4x4f& rhs,Matrix4x4f& res)
{
    for(int i = 0; i < 4; i++)
    {
        res[i] = rhs[i] * lhs[0] + rhs[i+4] * lhs[1] + rhs[i+8] * lhs[2] + rhs[i+12] * lhs[3];
        res[i+4] = rhs[i] * lhs[4] + rhs[i+4] * lhs[5] + rhs[i+8] * lhs[6] + rhs[i+12] * lhs[7];
        res[i+8] = rhs[i] * lhs[8] + rhs[i+4] * lhs[9] + rhs[i+8] * lhs[10] + rhs[i+12] * lhs[11];
        res[i+12] = rhs[i] * lhs[12] + rhs[i+4] * lhs[13] + rhs[i+8] * lhs[14] + rhs[i+12] * lhs[15];
    }
}



Matrix4x4f::Matrix4x4f(float data[16])
{
    for(int i = 0; i < 16; i++)
    {
        m_Data[i] = data[i];
    }
}

Matrix4x4f::Matrix4x4f(float data)
{
    m_Data[0] = data;
    m_Data[1] = 0.0f;
    m_Data[2] = 0.0f;
    m_Data[3] = 0.0f;
    
    m_Data[4] = 0.0f;
    m_Data[5] = data;
    m_Data[6] = 0.0f;
    m_Data[7] = 0.0f;
    
    m_Data[8] = 0.0f;
    m_Data[9] = 0.0f;
    m_Data[10] = data;
    m_Data[11] = 0.0f;

    m_Data[12] = 0.0f;
    m_Data[13] = 0.0f;
    m_Data[14] = 0.0f;
    m_Data[15] = data;
}

Matrix4x4f::Matrix4x4f(float m00,float m01,float m02,float m03,float m10,float m11,float m12,float m13,
    float m20,float m21,float m22,float m23,float m30,float m31,float m32,float m33)
{
    m_Data[0] = m00;
    m_Data[1] = m01;
    m_Data[2] = m02;
    m_Data[3] = m03;
    
    m_Data[4] = m10;
    m_Data[5] = m11;
    m_Data[6] = m12;
    m_Data[7] = m13;
    
    m_Data[8] = m20;
    m_Data[9] = m21;
    m_Data[10] = m22;
    m_Data[11] = m23;

    m_Data[12] = m30;
    m_Data[13] = m31;
    m_Data[14] = m32;
    m_Data[15] = m33;
}
Matrix4x4f::Matrix4x4f(const class Matrix3x3f mat3)
{
    m_Data[0] = mat3.m_Data[0];
    m_Data[1] = mat3.m_Data[1];
    m_Data[2] = mat3.m_Data[2];
    m_Data[3] = .0f;
    
    m_Data[4] = mat3.m_Data[3];
    m_Data[5] = mat3.m_Data[4];
    m_Data[6] = mat3.m_Data[5];
    m_Data[7] = .0f;
    
    m_Data[8] = mat3.m_Data[6];
    m_Data[9] = mat3.m_Data[7];
    m_Data[10] = mat3.m_Data[8];
    m_Data[11] = .0f;

    m_Data[12] = .0f;
    m_Data[13] = .0f;
    m_Data[14] = .0f;
    m_Data[15] = 1.0f;

}

float& Matrix4x4f::Get(int row, int colum)
{
    return m_Data[row*4 + colum];
}

const float& Matrix4x4f::Get(int row, int colum)const
{
    return m_Data[row*4 + colum];
}

float& Matrix4x4f::operator[](int index)
{
    return m_Data[index];
}

float Matrix4x4f::operator[](int index)const
{
    return m_Data[index];
}

Vector4f Matrix4x4f::GetColumn(int colum)
{
    return Vector4f(m_Data[colum],m_Data[colum+4],m_Data[colum +8],m_Data[colum+12]);
}   

void Matrix4x4f::SetZero()
{
    for(int i = 0; i < 16; i++)
    {
        m_Data[i] = 0;
    }
}

void Matrix4x4f::SetIdentity()
{
    m_Data[0] = 1.0f;
    m_Data[1] = .0f;
    m_Data[2] = .0f;
    m_Data[3] = .0f;
    
    m_Data[4] = 0.0f;
    m_Data[5] = 1.0f;
    m_Data[6] = 0.0f;
    m_Data[7] = 0.0f;
    
    m_Data[8] = 0.0f;
    m_Data[9] = 0.0f;
    m_Data[10] =1.0f;
    m_Data[11] =0.0f;

    m_Data[12] =0.0f;
    m_Data[13] =0.0f;
    m_Data[14] =0.0f;
    m_Data[15] = 1.0f;
}

void Matrix4x4f::SetScale(const Vector3f &scaleVec)
{
    m_Data[0] *=scaleVec[0];
    m_Data[4] *=scaleVec[0];
    m_Data[8] *=scaleVec[0];
    m_Data[12] *=scaleVec[0];

    m_Data[1] *=scaleVec[1];
    m_Data[5] *=scaleVec[1];
    m_Data[9] *=scaleVec[1];
    m_Data[13] *=scaleVec[1];

    m_Data[2] *=scaleVec[2];
    m_Data[6] *=scaleVec[2];
    m_Data[10] *=scaleVec[2];
    m_Data[14] *=scaleVec[2];
    

}

Matrix4x4f Matrix4x4f::Scale(const Vector3f& scalar)
{
    Matrix4x4f mat4;
    mat4.SetIdentity();
    mat4.SetScale(scalar);
    return mat4;
}

Matrix4x4f Matrix4x4f::Translate(const Vector3f& scalar)
{
    Matrix4x4f mat4;
    mat4.SetIdentity();
    mat4.Get(0, 3) = scalar.x;
    mat4.Get(1, 3) = scalar.y;
    mat4.Get(2, 3) = scalar.z;
    return mat4;
}

Matrix4x4f Matrix4x4f::Rotate(float radians,const Vector3f& axis)
{
    Matrix4x4f mat4;
    Vector3f normalizeAxis = GiamEngine::Normalize(axis);
    mat4.SetIdentity();
    float rad = Deg2Rad(radians);
    float c = cos(rad);
    float s = sin(rad);
    mat4.Get(0, 0) = normalizeAxis.x*normalizeAxis.x +(1.0-normalizeAxis.x*normalizeAxis.x)*c;
    mat4.Get(0, 1) = normalizeAxis.x*normalizeAxis.y*(1.0f-c) - normalizeAxis.z *s;
    mat4.Get(0, 2) = normalizeAxis.x*normalizeAxis.z*(1.0f-c) + normalizeAxis.y *s;
    mat4.Get(0, 3) = 0.0F;

    mat4.Get(1, 0) = normalizeAxis.x*normalizeAxis.y*(1.0f-c)+normalizeAxis.z*s;
    mat4.Get(1, 1) = normalizeAxis.y*normalizeAxis.y+(1.0f-normalizeAxis.y*normalizeAxis.y)*c;
    mat4.Get(1, 2) = normalizeAxis.y*normalizeAxis.z*(1.0f -c)-normalizeAxis.x*s;
    mat4.Get(1, 3) =0.0f;

    mat4.Get(2, 0) = normalizeAxis.x*normalizeAxis.z*(1.0f-c)+normalizeAxis.z*s;
    mat4.Get(2, 1) = normalizeAxis.y*normalizeAxis.z*(1.0f-c) + normalizeAxis.x*s;
    mat4.Get(2, 2) = normalizeAxis.z*normalizeAxis.z+(1.0 -normalizeAxis.z*normalizeAxis.z)*c;
    mat4.Get(2, 3) = 0.0f;

    mat4.Get(3, 0) = 0.0f;
    mat4.Get(3, 1) = 0.0f;
    mat4.Get(3, 2) = 0.0f;
    mat4.Get(3, 3) = 1.0f;

    
    return mat4;
}

Matrix4x4f Matrix4x4f::Perspective(float fov,float aspect,float nearClip,float farClip)
{
    Matrix4x4f mat4;
    mat4.SetIdentity();
    float halfFov_rad = Deg2Rad(fov/2.0f);
    float cot = cos(halfFov_rad)/sin(halfFov_rad);
//    float cot =  1 / (float)tan(halfFov_rad);
    mat4.Get(0, 0) = cot/aspect;

    mat4.Get(1, 1) = cot;

    mat4.Get(2, 2) = -(farClip+nearClip)/(farClip-nearClip);
    mat4.Get(2, 3) = -(2.0f*nearClip*farClip)/(farClip-nearClip);

    mat4.Get(3, 2) = -1.0f;
    mat4.Get(3, 3) = 0.0f;

    return mat4;
}

/*
*
*旋转矩阵是正交矩阵，所以直接用转置矩阵即可
*
* see http://www.songho.ca/opengl/gl_camera.html
*/

Matrix4x4f Matrix4x4f::LookAt(const Vector3f &pos, const Vector3f &cameraFront, const Vector3f &cameraUp, const Vector3f &cameraRight)
{
    Matrix4x4f matrix;
    matrix.SetIdentity();
    matrix.m_Data[0] = cameraRight.x;
    matrix.m_Data[4] = cameraRight.y;
    matrix.m_Data[8] = cameraRight.z;
    
    matrix.m_Data[1] = cameraUp.x;
    matrix.m_Data[5] = cameraUp.y;
    matrix.m_Data[9] = cameraUp.z;
    
    matrix.m_Data[2] = cameraFront.x;
    matrix.m_Data[6] = cameraFront.y;
    matrix.m_Data[10] = cameraFront.z;
    
//    matrix.m_Data[12] = Dot(pos, -cameraRight);
//    matrix.m_Data[13] = Dot(pos, -cameraUp);
//    matrix.m_Data[14] = Dot(pos, -cameraFront);
    
    matrix.m_Data[12] = -cameraRight.x * pos.x - cameraRight.y * pos.y - cameraRight.z *pos.z;
    matrix.m_Data[13] = -cameraUp.x * pos.x - cameraUp.y * pos.y - cameraUp.z *pos.z;
    matrix.m_Data[14] = -cameraFront.x * pos.x - cameraFront.y * pos.y - cameraFront.z *pos.z;
    
    return matrix;
}


Matrix4x4f Matrix4x4f::LookAt(const Vector3f &pos, const Vector3f &cameraFront, const Vector3f &worldUp)
{
    Matrix4x4f a;
    return a;
}
Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f &mat4)
{
    Matrix4x4f temp;
    MultiplyMatrix4x4f(*this, mat4, temp);
    return temp;
}
Matrix4x4f& Matrix4x4f::operator*=(const Matrix4x4f &mat4)
{
    Matrix4x4f temp;
    MultiplyMatrix4x4f(*this, mat4, temp);
    *this =temp;
    return *this;
}


