//
//  GIMatrix4x4f.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/31.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "GIMatrix4x4f.h"
#include "GIMatrix3x3.h"
using namespace GiamEngine;
Matrix4x4f::Matrix4x4f(float data[16])
{
    for(int i = 0; i < 16; i++)
    {
        m_Data[i] = data[i];
    }
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
    return m_Data[row + colum*4];
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
    return Vector4f(m_Data[0+colum*4],m_Data[1+colum*4],m_Data[2+colum*4],m_Data[3+colum*4]);
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

void Matrix4x4f::Scale(const Vector4f &scaleVec)
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
    
    m_Data[3] *=scaleVec[3];
    m_Data[7] *=scaleVec[3];
    m_Data[11] *=scaleVec[3];
    m_Data[15] *=scaleVec[3];

}
