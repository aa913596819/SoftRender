//
//  GIMatrix4x4f.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/31.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIMATRIX4x4f_H
#define GIMATRIX4x4f_H
#include "GIVector4.h"
namespace GiamEngine
{
class Matrix4x4f
{
public:
    float m_Data[16];
    Matrix4x4f(){}
    Matrix4x4f(float data[16]);
    Matrix4x4f(float m00,float m01,float m02,float m03,float m10,float m11,float m12,float m13,
               float m20,float m21,float m22,float m23,float m30,float m31,float m32,float m33);
    Matrix4x4f(const class Matrix3x3f);
    float& Get(int row,int colum);
    const float& Get(int row,int colum)const;
    float& operator[](int index);
    float operator[](int index)const;
    Vector4f GetColumn(int colum);
    void SetIdentity();
    void SetZero();
    void Scale(const Vector4f& scaleVec);
};
}


#endif /* GIMATRIX4x4f_H */
