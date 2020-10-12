//
//  GIVector3.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/10.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIVECTOR3_H
#define GIVECTOR3_H
#include <cmath>
#include<iostream>
namespace GiamEngine
{
template<typename T>
class Vector3
{
public:
    T x,y,z;
    Vector3()
    {
    }
    Vector3(T inX, T inY, T inZ):x(inX),y(inY),z(inZ)
    {
    }
    //Copy constructor
    //这么写是错的，应该在成员初始化列表中初始化，否则仍然会先执行默认构造函数
    //Vector3f::Vector3f(const Vector3f& vec)
    //{
    //    x = vec.x;
    //    y = vec.y;
    //    z = vec.z;
    //}
    Vector3(const Vector3<T>& vec):x(vec.x),y(vec.y),z(vec.z)
    {
    }
    Vector3<T>& operator=(const Vector3<T> &vec);
    bool operator==(const Vector3<T> &vec);
    bool operator!=(const Vector3<T> &vec);
    Vector3<T> operator+(const Vector3<T> &vec)const;
    Vector3<T> operator-(const Vector3<T> &vec)const;
    //注意这里仅仅实现了标量的右乘
    Vector3<T> operator*(T s)const;
    Vector3<T> operator/(T s)const;
    Vector3<T>& operator+=(const Vector3<T> &vec);
    Vector3<T>& operator-=(const Vector3<T> &vec);
    Vector3<T>& operator*=(T s);
    Vector3<T>& operator/=(T s);
    Vector3<T> operator-()const;
    T& operator[](const int index);
    const T& operator[](const int index)const;
    void Zero();
    void Normalize();
};

template<typename T>
inline Vector3<T> operator*(T s, Vector3<T>& vec)
{
    return vec*s;
}

template<typename T>
inline Vector3<T> operator*(const Vector3<T>& vec0,const Vector3<T>& vec1)
{
    return Vector3<T>(vec0.x * vec1.x, vec0.y * vec1.y, vec0.z *vec1.z);
}

template<typename T>
inline Vector3<T> Inverse(const Vector3<T>& vec)
{
    return Vector3f(1.0f/vec.x, 1.0f/vec.y, 1.0f/vec.z);
}

template<typename T>
inline float Dot(const Vector3<T>& vec0,const Vector3<T>& vec1)
{
    return vec0.x * vec1.x + vec0.y * vec1.y + vec0.z * vec1.z;
}


//求模长
template<typename T>
inline float Magnitude(const Vector3<T>& vec)
{
    return std::sqrt(vec.x*vec.x +vec.y+vec.y+ vec.z*vec.z);
}

template<typename T>
inline Vector3<T> Normalize(const Vector3<T>& vec)
{
    using namespace std;
    
    Vector3<T> tempVec;
    tempVec = vec;
    float maxComp = max(max(vec.x,vec.y),vec.z);
    tempVec *=(1.0/maxComp);
    float temp = tempVec.x*tempVec.x+tempVec.y*tempVec.y+tempVec.z*tempVec.z;
    float inverseTemp = 1.0f/std::sqrt(temp);
    return tempVec/inverseTemp;
}


//叉乘

template<typename T>
inline Vector3<T> Cross(const Vector3<T>& vec0,const Vector3<T>& vec1)
{
    return Vector3<T>(vec0.y*vec1.z - vec0.z*vec1.y,
                    vec0.z*vec1.x - vec0.x*vec1.z,
                    vec0.x*vec1.y - vec0.y*vec1.x);
}

template<typename T>
inline float Distance(Vector3<T>& vec0,Vector3<T>& vec1)
{
    float dx = vec0.x -vec1.x;
    float dy = vec0.y -vec1.y;
    float dz = vec0.z -vec1.z;
    return std::sqrt(dx*dx+dy*dy+dz*dz);
}

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;


template<typename T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T> &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

template<typename T>
bool Vector3<T>::operator==(const Vector3<T> &vec)
{
    return x == vec.x&& y == vec.y&& z ==vec.z;
}

template<typename T>
bool Vector3<T>::operator!=(const Vector3<T> &vec)
{
    return x != vec.x|| y != vec.y || z !=vec.z;
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &vec)const
{
    return Vector3<T>(x+vec.x, y+vec.y, z+vec.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &vec)const
{
    return Vector3<T>(x-vec.x, y-vec.y, z-vec.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(T s)const
{
    return Vector3<T>(x*s,y*s,z*s);
}
//这么做是有问题，可以将分母的倒数求出来，避免做三次除法
//同时不应该在这里做分母的非0检测 这是不符合逻辑的
//Vector3f Vector3f::operator/(float s)const
//{
//    return Vector3f(x/s,y/s,z/s);
//}

template<typename T>
Vector3<T> Vector3<T>::operator/(T s)const
{
    float temp = 1.0f/s;
    return this->operator*(temp);
}

template<typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}


template<typename T>
Vector3<T>& Vector3<T>::operator*=(T s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(T s)
{
    float temp = 1.0f/s;
    x *= temp;
    y *= temp;
    z *= temp;
    return *this;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-()const
{
    return Vector3f(-x,-y,-z);
}

template<typename T>
inline void Vector3<T>::Zero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

template<typename T>
void Vector3<T>::Normalize()
{
    GiamEngine::Normalize(*this);
}

template<typename T>
inline T& Vector3<T>::operator[](const int i)
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
    else
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return z;
    }
}

template<typename T>
const inline T& Vector3<T>::operator[](const int i)const
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
    else
    {
        std::cerr<<"ERROR:Index Out of Range"<<std::endl;
        return z;
    }
}
}
#endif /* GIVECTOR3_H */
    
