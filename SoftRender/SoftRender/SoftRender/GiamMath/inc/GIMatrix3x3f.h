//
//  GIMatrix3x3f.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/28.
//  Copyright © 2020 linweifeng. All rights reserved.
//

//
#ifndef GIMATRIX3X3F_H
#define GIMATRIX3X3F_H
//#include"GIMatrix4x4f.h"
#include"GIVector3.h"
namespace GiamEngine
{
class Matrix4x4f;
class Matrix3x3f
{
public:
    float m_Data[9];
    Matrix3x3f(){}
    float& Get(int row,int colum);
    const float& Get(int row,int colum)const;
    Matrix3x3f(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
    explicit Matrix3x3f(const class Matrix4x4f& mat4);
    explicit Matrix3x3f(const float data[9]);
    float& operator[](int row);
    float operator[](int row)const;
    Vector3f GetColumn(int colum)const;
    void SetIdentity();
    void SetZero();
    void Scale(const Vector3f& scaleVec);
    
    /**
     * @brief 矩阵求转置
     *
     * @return 返回该矩阵转置之后的引用
     */
    Matrix3x3f& Transpose();
    /**
     * @brief 矩阵求拟
     *
     * @return true 矩阵可逆，并求拟成功
     * @return false 矩阵不可逆，并求拟失败
     */
    bool Invert();
    
    
    static const Matrix3x3f& zero();
    static const Matrix3x3f& identity();
    static const Matrix3x3f Zero;
};

//Vector3f mul(const Matrix3x3f& mat3, const Vector3f& vec3);

Matrix3x3f ElurToMatrix();
Vector3f MatrixToEuler();
}
#endif /* GIMatrix3x3_hpp */
