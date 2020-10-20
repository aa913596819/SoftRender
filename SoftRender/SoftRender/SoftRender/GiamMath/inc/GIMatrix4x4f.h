//
//  GIMatrix4x4f.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/31.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIMATRIX4x4F_H
#define GIMATRIX4x4F_H
#include "GIVector3.h"
#include "GIVector4.h"
#include"GIMatrix3x3f.h"


///
namespace GiamEngine
{
class Matrix4x4f
{
public:
    float m_Data[16];
    Matrix4x4f(){SetZero();}
    Matrix4x4f(float);
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
    Matrix4x4f operator*(const Matrix4x4f& mat4);
    Matrix4x4f& operator*=(const Matrix4x4f& mat4);
    Vector4f operator*(const Vector4f vec4);
    //
    void SetScale(const Vector3f& scaleVec);
    static Matrix4x4f Rotate(float radians,const Vector3f& axis);
    static Matrix4x4f Scale(const Vector3f& scalar);
    static Matrix4x4f Translate(const Vector3f& scalar);
    static Matrix4x4f Perspective(float fov,float aspect,float nearClip,float farClip);
    static Matrix4x4f LookAt(const Vector3f& pos,const Vector3f& cameraFront,const Vector3f& worldUp);
    static Matrix4x4f LookAt(const Vector3f& pos,const Vector3f& cameraFront,const Vector3f& cameraUp,const Vector3f& cameraRight);
};
Vector4f mul(const Matrix4x4f& mat4, const Vector4f& vec4);

}


#endif /* GIMATRIX4x4f_H */
