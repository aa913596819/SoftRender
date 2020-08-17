//
//  Vector2.h
//  SoftRender
//
//  Created by bytedance on 2020/8/9.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef VECTOR2_H
#define VECTOR2_H
#include<cmath>
template<typename T>
class Vector2
{
public:
    T x,y;
    Vector2(T inputX,T inputY):x(inputX),y(inputY)
    {
    }
    Vector2():x(0),y(0)
    {
    }
    Vector2(const Vector2<T>& vec):x(vec.x),y(vec.y)
    {
    }
    Vector2<T>& operator=(const Vector2<T> &vec);
    bool operator==(const Vector2<T> &vec);
    bool operator!=(const Vector2<T> &vec);
    Vector2<T> operator+(const Vector2<T> &vec)const;
    Vector2<T> operator-(const Vector2<T> &vec)const;
    //注意这里仅仅实现了标量的右乘
    Vector2<T> operator*(float s)const;
    Vector2<float> operator/(float s)const;
    Vector2<T>& operator+=(const Vector2<T> &vec);
    Vector2<T>& operator-=(const Vector2<T> &vec);
    Vector2<T>& operator*=(float s);
    Vector2<T>& operator/=(float s);
    Vector2<T> operator-()const;
    void zero();
    void normalize();
};
template<typename T>
inline Vector2<T> operator*(float s, Vector2<T>& vec)
{
    return vec*s;
}
template<typename T>
inline Vector2<T> operator*(const Vector2<T>& vec0,const Vector2<T>& vec1)
{
    return Vector2<T>(vec0.x * vec1.x, vec0.y * vec1.y);
}
//template<typename T>
//inline Vector2<T> Inverse(const Vector2<T>& vec)
//{
//    return Vector2<T>(1.0f/vec.x, 1.0f/vec.y);
//}

template<typename T>
inline T Dot(const Vector2<T>& vec0,const Vector2<T>& vec1)
{
    return vec0.x * vec1.x + vec0.y * vec1.y;
}

//求模长
template<typename T>
inline float Magnitude(const Vector2<T>& vec)
{
    return std::sqrt(vec.x*vec.x +vec.y+vec.y);
}

template<typename T>
inline Vector2<float> normalize(Vector2<T>& vec)
{
    float temp = vec.x*vec.x+vec.y*vec.y;
    float inverseTemp = 1.0f/std::sqrt(temp);
    return vec/inverseTemp;
}

template<typename T>
inline float Distance(Vector2<T>& vec0,Vector2<T>& vec1)
{
    float dx = vec0.x -vec1.x;
    float dy = vec0.y -vec1.y;
    return std::sqrt(dx*dx+dy*dy);
}
template<typename T>
inline void Vector2<T>::zero()
{
    x = 0;
    y = 0;
}


template<typename T>
Vector2<T> Vector2<T>::operator*(float s)const
{
    return Vector2<T>(x*s,y*s);
}



template<typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T> &vec)
{
    x = vec.x;
    y = vec.y;
    return *this;
}
template<typename T>
bool Vector2<T>::operator==(const Vector2<T> &vec)
{
    return x == vec.x&& y == vec.y;
}

template<typename T>
bool Vector2<T>::operator!=(const Vector2<T> &vec)
{
    return x != vec.x|| y != vec.y;
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &vec)const
{
    return Vector2<T>(x+vec.x, y+vec.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &vec)const
{
    return Vector2<T>(x-vec.x, y-vec.y);
}

//这么做是有问题，可以将分母的倒数求出来，避免做三次除法
//同时不应该在这里做分母的非0检测 这是不符合逻辑的
//Vector3f Vector3f::operator/(float s)const
//{
//    return Vector3f(x/s,y/s,z/s);
//}

template<typename T>
Vector2<float> Vector2<T>::operator/(float s)const
{
    float temp = 1.0f/s;
    return this->operator*(temp);
}

template<typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(float s)
{
    x *= s;
    y *= s;
    return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(float s)
{
    float temp = 1.0f/s;
    x *= temp;
    y *= temp;
    return *this;
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-()const
{
    return Vector2<T>(-x,-y);
}



template<typename T>
inline void Vector2<T>::normalize()
{
    float temp = x * x + y * y;
    float inverseTemp = 1.0f / std::sqrt(temp);
    x /=inverseTemp;
    y /=inverseTemp;
}


typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

//class Vector2f
//{
//public:
//    float x,y;
//    Vector2f(float inputX,float inputY):x(inputX),y(inputY)
//    {
//    }
//    Vector2f():x(0.0f),y(0.0f)
//    {
//    }
//    Vector2f(const Vector2f&vec):x(vec.x),y(vec.y)
//    {
//    }
//    Vector2f& operator=(const Vector2f &vec);
//    bool operator==(const Vector2f &vec);
//    bool operator!=(const Vector2f &vec);
//    Vector2f operator+(const Vector2f &vec)const;
//    Vector2f operator-(const Vector2f &vec)const;
//    //注意这里仅仅实现了标量的右乘
//    Vector2f operator*(float s)const;
//    Vector2f operator/(float s)const;
//    Vector2f& operator+=(const Vector2f &vec);
//    Vector2f& operator-=(const Vector2f &vec);
//    Vector2f& operator*=(float s);
//    Vector2f& operator/=(float s);
//    Vector2f operator-()const;
//    void zero();
//    void normalize();
//};
//inline Vector2f operator*(float s, Vector2f& vec)
//{
//    return vec*s;
//}
//
//inline Vector2f operator*(const Vector2f& vec0,const Vector2f& vec1)
//{
//    return Vector2f(vec0.x * vec1.x, vec0.y * vec1.y);
//}
//
//inline Vector2f Inverse(const Vector2f& vec)
//{
//    return Vector2f(1.0f/vec.x, 1.0f/vec.y);
//}
//
//inline float Dot(const Vector2f& vec0,const Vector2f& vec1)
//{
//    return vec0.x * vec1.x + vec0.y * vec1.y;
//}
//
////求模长
//inline float Magnitude(const Vector2f& vec)
//{
//    return std::sqrt(vec.x*vec.x +vec.y+vec.y);
//}
//inline Vector2f normalize(Vector2f& vec)
//{
//    float temp = vec.x*vec.x+vec.y*vec.y;
//    float inverseTemp = 1.0f/std::sqrt(temp);
//    return vec/inverseTemp;
//}
//inline float Distance(Vector2f& vec0,Vector2f& vec1)
//{
//    float dx = vec0.x -vec1.x;
//    float dy = vec0.y -vec1.y;
//    return std::sqrt(dx*dx+dy*dy);
//}
//

#endif /* VECTOR2_H */
