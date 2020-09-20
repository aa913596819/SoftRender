//
//  GIQuaternion.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/9/7.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "GIQuaternion.h"
#include <math.h>
using namespace GiamEngine;
Quaternion::Quaternion(float inX, float inY, float inZ, float inW):x(inX),y(inY),z(inZ),w(inW)
{
}
Quaternion::Quaternion(const float data[4]):x(data[0]),y(data[1]),z(data[2]),w(data[3])
{
}

float* Quaternion::GetPtr()
{
    return &x;
}

const float* Quaternion::GetPtr()const
{
    return &x;
}
const float& Quaternion::operator[](int index)const
{
    return GetPtr()[index];
}
float& Quaternion::operator[](int index)
{
    return GetPtr()[index];
}

void Quaternion::Set(float inX, float inY, float inZ, float inW)
{
    x = inX;
    y = inY;
    z = inZ;
    w = inW;
}
void Quaternion::Set(const float data[4])
{
//    for(int i =0;i<4;i++)
//    {
//        GetPtr()[i] =data[i];
//    }
    x = data[0];
    y = data[1];
    z = data[2];
    w = data[3];
}

bool Quaternion::operator==(const Quaternion &q)const
{
    return x==q.x && y==q.y && z==q.z && w==q.w;
}

bool Quaternion::operator!=(const Quaternion &q)const
{
    return x!=q.x || y!=q.y || z!=q.z || w!=q.w;
}

Quaternion& Quaternion::operator+=(const Quaternion &q)
{
    x +=q.x;
    y +=q.y;
    z +=q.z;
    w +=q.w;
    return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion &q)
{
    x -=q.x;
    y -=q.y;
    z -=q.z;
    w -=q.w;
    return *this;
}

Quaternion& Quaternion::operator*=(const float scalar)
{
    x *=scalar;
    y *=scalar;
    z *=scalar;
    w *=scalar;
    return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
    float tempX = w * q.x + x * q.w + y * q.z - z * q.y;
    float tempY = w * q.y + y * q.w + z * q.x - x * q.z;
    float tempZ = w * q.z + z * q.w + x * q.y - y * q.x;
    float tempW = w * q.w - x * q.x - y * q.y - z * q.z;
    x = tempX;
    y = tempY;
    z = tempZ;
    w = tempW;
    return *this;
}

Quaternion& Quaternion::operator/=(const float scalar)
{
    
    x /=scalar;
    y /=scalar;
    z /=scalar;
    w /=scalar;
    return *this;
}

const Quaternion Quaternion::Zero(0.0f,0.0f,0.0f,0.0f);
const Quaternion Quaternion::Indentity(0.0f,0.0f,0.0f,1.0f);
