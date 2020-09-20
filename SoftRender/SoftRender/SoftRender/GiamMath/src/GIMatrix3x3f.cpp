//
//  GIMatrix3x3.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/28.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "GIMatrix3x3f.h"
#include "GIMatrix4x4f.h"
using namespace GiamEngine;
float& Matrix3x3f::Get(int row, int colum)
{
    return m_Data[row + (colum*3)];
}

const float& Matrix3x3f::Get(int row, int colum)const
{
    return m_Data[row + (colum*3)];
}
Matrix3x3f::Matrix3x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
    Get(0, 0) = m00;
    Get(1, 0) = m10;
    Get(2, 0) = m20;
    Get(0, 1) = m01;
    Get(1, 1) = m11;
    Get(2, 1) = m21;
    Get(0, 2) = m02;
    Get(1, 2) = m12;
    Get(2, 2) = m22;
}

void Matrix3x3f::Scale(const Vector3f &scaleVec)
{
    Get(0, 0) *=scaleVec[0];
    Get(1, 0) *=scaleVec[0];
    Get(2, 0) *=scaleVec[0];

    Get(0, 1) *=scaleVec[1];
    Get(1, 1) *=scaleVec[1];
    Get(2, 1) *=scaleVec[1];

    Get(0, 2) *=scaleVec[2];
    Get(1, 2) *=scaleVec[2];
    Get(2, 2) *=scaleVec[2];

}

Matrix3x3f& Matrix3x3f::Transpose()
{
    std::swap(m_Data[1], m_Data[3]);
    std::swap(m_Data[2], m_Data[6]);
    std::swap(m_Data[5], m_Data[7]);
    return *this;
}

float& Matrix3x3f::operator[](int row)
{
    return m_Data[row];
}

float Matrix3x3f::operator[](int row)const
{
    return m_Data[row];
}

Vector3f Matrix3x3f::GetColumn(int colum)const
{
    return Vector3f(Get(0, colum),Get(1, colum),Get(2, colum));
}

Matrix3x3f::Matrix3x3f(const float data[9])
{
    for(int i =0;i<9;i++)
    {
        m_Data[i] = data[i];
    }
}

void Matrix3x3f::SetIdentity()
{
    m_Data[0]=1.0f;
    m_Data[1]=0.0f;
    m_Data[2]=0.0f;

    m_Data[3]=0.0f;
    m_Data[4]=1.0f;
    m_Data[5]=0.0f;

    m_Data[6]=0.0f;
    m_Data[7]=0.0f;
    m_Data[8]=1.0f;

}

void Matrix3x3f::SetZero()
{
    for(int i =0 ; i < 9; i++)
    {
        m_Data[i] = 0.0f;
    }
}

Matrix3x3f::Matrix3x3f(const class Matrix4x4f& mat4)
{
    m_Data[0] = mat4.m_Data[0];
    m_Data[1] = mat4.m_Data[1];
    m_Data[2] = mat4.m_Data[2];
    
    m_Data[3] = mat4.m_Data[4];
    m_Data[4] = mat4.m_Data[5];
    m_Data[5] = mat4.m_Data[6];

    m_Data[6] = mat4.m_Data[8];
    m_Data[7] = mat4.m_Data[9];
    m_Data[8] = mat4.m_Data[10];
}

const Matrix3x3f& Matrix3x3f::zero()
{
//    auto lam =[](){Matrix3x3f m; m.SetZero();return m; };
//    static const  Matrix3x3f m = lam();
//    return m;
//    也可以直接写成如下形式：
      static const Matrix3x3f& lam =[](){Matrix3x3f m; m.SetZero();return m; }();
      return lam;
}
const Matrix3x3f& Matrix3x3f::identity()
{
      static const Matrix3x3f& lam =[](){Matrix3x3f m; m.SetIdentity();return m; }();
      return lam;
}

bool Matrix3x3f::Invert()
{
    
    return true;
}

//Vector3f mul(const Matrix3x3f& mat3, const Vector3f& vec3)
//{
//    float x = mat3.m_Data[0] * vec3.x + mat3.m_Data[1] * vec3.y + mat3.m_Data[2] * vec3.z;
//    float y = mat3.m_Data[3] * vec3.x + mat3.m_Data[4] * vec3.y + mat3.m_Data[5] * vec3.z;
//    float z = mat3.m_Data[6] * vec3.x + mat3.m_Data[7] * vec3.y + mat3.m_Data[8] * vec3.z;
//    return Vector3f(x,y,z);
//}
