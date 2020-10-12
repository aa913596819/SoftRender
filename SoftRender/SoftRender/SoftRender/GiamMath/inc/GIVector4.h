//
//  GIVector4.h
//  SoftRender
//
//  Created by linweifeng on 2020/9/4.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIVECTOR4_H
#define GIVECTOR4_H

#include <cmath>
#include<iostream>
#include"GIVector3.h"
namespace GiamEngine
{
template<typename T>
class Vector4
{
public:
    T x,y,z,w;
    Vector4()
    {
    }
    Vector4(Vector3<T> vec3):x(vec3.x),y(vec3.y),z(vec3.z),w(1)
    {
    }
    Vector4(T inX, T inY, T inZ, T inW):x(inX),y(inY),z(inZ),w(inW)
    {
    }
    Vector4(const Vector4<T>& vec):x(vec.x),y(vec.y),z(vec.z),w(vec.w)
    {
    }
    Vector4<T>& operator=(const Vector4<T> &vec);
    bool operator==(const Vector4<T> &vec);
    bool operator!=(const Vector4<T> &vec);
    Vector4<T> operator+(const Vector4<T> &vec)const;
    Vector4<T> operator-(const Vector4<T> &vec)const;
    //注意这里仅仅实现了标量的右乘
    Vector4<T> operator*(T s)const;
    Vector4<T> operator/(T s)const;
    Vector4<T>& operator+=(const Vector4<T> &vec);
    Vector4<T>& operator-=(const Vector4<T> &vec);
    Vector4<T>& operator*=(T s);
    Vector4<T>& operator/=(T s);
    Vector4<T> operator-()const;
    T& operator[](const int index);
    const T& operator[](const int index)const;
    void Zero();
    void Normalize();
    void PresDivision();
};
template<typename T>
void Vector4<T>::PresDivision()
{
    x /=w;
    y /=w;
    z /=w;
//    w = 1.0f/w;

}


template<typename T>
inline Vector4<T> operator*(T s, Vector4<T>& vec)
{
    return vec*s;
}

template<typename T>
inline Vector4<T> operator*(const Vector4<T>& vec0,const Vector4<T>& vec1)
{
    return Vector4<T>(vec0.x * vec1.x, vec0.y * vec1.y, vec0.z *vec1.z, vec0.w *vec1.w);
}

template<typename T>
inline Vector4<T> Inverse(const Vector4<T>& vec)
{
    return Vector4f(1.0f/vec.x, 1.0f/vec.y, 1.0f/vec.z, 1.0f/vec.w);
}

template<typename T>
inline float Dot(const Vector4<T>& vec0,const Vector4<T>& vec1)
{
    return vec0.x * vec1.x + vec0.y * vec1.y + vec0.z * vec1.z + vec0.w * vec1.w;
}


//求模长
template<typename T>
inline float Magnitude(const Vector4<T>& vec)
{
    return std::sqrt(vec.x*vec.x +vec.y+vec.y+ vec.z*vec.z + vec.w*vec.w);
}




template<typename T>
inline Vector4<T> Normalize(Vector4<T>& vec)
{
    using namespace std;
    float maxComp = max(max(max(vec.x,vec.y),vec.z),vec.w);
    vec *=(1.0/maxComp);
    float temp = vec.x*vec.x+vec.y*vec.y+vec.z*vec.z+vec.w*vec.w;
    float inverseTemp = 1.0f/std::sqrt(temp);
    return vec/inverseTemp;
}




typedef Vector4<float> Vector4f;
typedef Vector4<int> Vector4i;


template<typename T>
Vector4<T>& Vector4<T>::operator=(const Vector4<T> &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
    return *this;
}

template<typename T>
bool Vector4<T>::operator==(const Vector4<T> &vec)
{
    return x == vec.x&& y == vec.y&& z ==vec.z&&w == vec.w;
}

template<typename T>
bool Vector4<T>::operator!=(const Vector4<T> &vec)
{
    return x != vec.x|| y != vec.y || z !=vec.z|| w !=vec.w;
}

template<typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T> &vec)const
{
    return Vector4<T>(x+vec.x, y+vec.y, z+vec.z, w+vec.w);
}

template<typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T> &vec)const
{
    return Vector4<T>(x-vec.x, y-vec.y, z-vec.z, w-vec.w);
}

template<typename T>
Vector4<T> Vector4<T>::operator*(T s)const
{
    return Vector4<T>(x*s,y*s,z*s,w*s);
}
//这么做是有问题，可以将分母的倒数求出来，避免做三次除法
//同时不应该在这里做分母的非0检测 这是不符合逻辑的
//Vector4f Vector4f::operator/(float s)const
//{
//    return Vector4f(x/s,y/s,z/s);
//}

template<typename T>
Vector4<T> Vector4<T>::operator/(T s)const
{
    float temp = 1.0f/s;
    return this->operator*(temp);
}

template<typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;
    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator*=(T s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

template<typename T>
Vector4<T>& Vector4<T>::operator/=(T s)
{
    float temp = 1.0f/s;
    x *= temp;
    y *= temp;
    z *= temp;
    w *= temp;
    return *this;
}

template<typename T>
inline Vector4<T> Vector4<T>::operator-()const
{
    return Vector4f(-x,-y,-z,-w);
}

template<typename T>
inline void Vector4<T>::Zero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

template<typename T>
void Vector4<T>::Normalize()
{
    Normalize(this);
}

template<typename T>
inline T& Vector4<T>::operator[](const int i)
{

    if(i==0)
    {
        return x;
    }
    else if(i==1)
    {
        return y;
    }
    else if(i==2)
    {
        return z;
    }
    else if(i==3)
    {
        return w;
    }
    else if(i<0)
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return x;
    }
    else
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return w;
    }
}

template<typename T>
const inline T& Vector4<T>::operator[](const int i)const
{
    if(i==0)
    {
        return x;
    }
    else if(i==1)
    {
        return y;
    }
    else if(i==2)
    {
        return z;
    }
    else if(i==3)
    {
        return w;
    }
    else if(i<0)
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return x;
    }
    else
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return w;
    }
}
}

#endif /* GIVECTOR4_H */
