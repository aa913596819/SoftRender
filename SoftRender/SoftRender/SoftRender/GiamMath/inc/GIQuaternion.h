//
//  GIQuaternion.h
//  SoftRender
//
//  Created by linweifeng on 2020/9/7.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIQUATERNION_H
#define GIQUATERNION_H
#include<math.h>
namespace GiamEngine
{
class Quaternion
{
public:
    //w为实数部
    float x,y,z,w;
    Quaternion(){}
    Quaternion(float inX, float inY, float inZ, float inW);
    explicit Quaternion(const float data[4]);
    const float& operator[](int index)const;
    float& operator[](int index);
    void Set(float inX, float inY, float inZ, float inW);
    void Set(const float data[4]);
    bool operator== (const Quaternion& q)const;
    bool operator!= (const Quaternion& q)const;
    Quaternion& operator+=(const Quaternion& q);
    Quaternion& operator-=(const Quaternion& q);
    Quaternion& operator*=(const float scalar);
    /**
    * @brief  该四元数右乘q
    *
    * @param q 右乘的四元数.
    * @return  乘积.
    */
    Quaternion& operator*=(const Quaternion& q);
    Quaternion& operator/=(const float scalar);
    

    float* GetPtr();
    const float* GetPtr()const;
    static const  Quaternion Zero;
    static const Quaternion Indentity;
};

Quaternion operator+(const Quaternion& q0, const Quaternion&q1);

Quaternion operator-(const Quaternion& q0, const Quaternion&q1);

/**
* @brief  q1左乘q0
*
* @param q0 q1.
* @return  乘积.
*/
Quaternion operator*(const Quaternion& q0, const Quaternion&q1);

Quaternion operator/(const Quaternion& q0, float scalar);
float Magnitude(const Quaternion& q);
Quaternion Normalize(const Quaternion& q);
/**
* @brief 求输入四元数的共轭.
*
* @param q 输入四元数.
* @return 输入四元数的共轭四元数.
*/
Quaternion Conjugate(const Quaternion& q);

Quaternion SqrMagnitude();

/**
* @brief 求输入四元数的逆.
*
* @param q 输入四元数.
* @return 输入四元数的逆.
*/
Quaternion Inverse(const Quaternion& q);

inline Quaternion operator+(const Quaternion& q0, const Quaternion&q1)
{
    return Quaternion(q0.x+q1.x,q0.y+q1.y,q0.z+q1.z,q0.w+q1.w);
}
inline Quaternion operator-(const Quaternion& q0, const Quaternion&q1)
{
    return Quaternion(q0.x-q1.x,q0.y-q1.y,q0.z-q1.z,q0.w-q1.w);
}

inline Quaternion operator*(const Quaternion& q0, const Quaternion&q1)
{
    float x = q0.w * q1.x + q0.x * q1.w + q0.y * q1.z - q0.z * q1.y;
    float y = q0.w * q1.y + q0.y * q1.w + q0.z * q1.x - q0.x * q1.z;
    float z = q0.w * q1.z + q0.z * q1.w + q0.x * q1.y - q0.y * q1.x;
    float w = q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z;
    return Quaternion(x,y,z,w);
}
inline Quaternion operator/(const Quaternion& q0, float scalar)
{
    float x = q0.x/scalar;
    float y = q0.y/scalar;
    float z = q0.z/scalar;
    float w = q0.w/scalar;
    return Quaternion(x,y,z,w);
}


inline float Magnitude(const Quaternion& q)
{
    return sqrt(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
}

inline float SqrMagnitude(const Quaternion& q)
{
    return sqrt(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
}

inline Quaternion Normalize(const Quaternion& q)
{
    return q/Magnitude(q);
}

inline Quaternion Conjugate(const Quaternion& q)
{
    return Quaternion(-q.x,-q.y,-q.z,q.w);
}

/**
* @brief 求输入四元数的逆.
*
* @param q 输入四元数.
* @return 输入四元数的逆.
*/

inline Quaternion Inverse(const Quaternion& q)
{
    Quaternion conju = Conjugate(q);
    return conju/(SqrMagnitude(q));
}



}
#endif /* GIQuaternion_h */
