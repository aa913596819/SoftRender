//
//  Vector3.hå
//  SoftRender
//
//  Created by bytedance on 2020/8/10.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>
class Vector3f
{
public:
    float x,y,z;
    Vector3f()
    {
    }
    Vector3f(float inX, float inY, float inZ):x(inX),y(inY),z(inZ)
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
    Vector3f(const Vector3f& vec):x(vec.x),y(vec.y),z(vec.z)
    {
    }
    Vector3f& operator=(const Vector3f &vec);
    bool operator==(const Vector3f &vec);
    bool operator!=(const Vector3f &vec);
    Vector3f operator+(const Vector3f &vec)const;
    Vector3f operator-(const Vector3f &vec)const;
    //注意这里仅仅实现了标量的右乘
    Vector3f operator*(float s)const;
    Vector3f operator/(float s)const;
    Vector3f& operator+=(const Vector3f &vec);
    Vector3f& operator-=(const Vector3f &vec);
    Vector3f& operator*=(float s);
    Vector3f& operator/=(float s);
    Vector3f operator-()const;
    void zero();
    void normalize();
};

inline Vector3f operator*(float s, Vector3f& vec)
{
    return vec*s;
}

inline Vector3f operator*(const Vector3f& vec0,const Vector3f& vec1)
{
    return Vector3f(vec0.x * vec1.x, vec0.y * vec1.y, vec0.z *vec1.z);
}

inline Vector3f Inverse(const Vector3f& vec)
{
    return Vector3f(1.0f/vec.x, 1.0f/vec.y, 1.0f/vec.z);
}

inline float Dot(const Vector3f& vec0,const Vector3f& vec1)
{
    return vec0.x * vec1.x + vec0.y * vec1.y + vec0.z * vec1.z;
}

//求模长
inline float Magnitude(const Vector3f& vec)
{
    return std::sqrt(vec.x*vec.x +vec.y+vec.y+ vec.z*vec.z);
}
inline Vector3f normalize(Vector3f& vec)
{
    float temp = vec.x*vec.x+vec.y*vec.y+vec.z*vec.z;
    float inverseTemp = 1.0f/std::sqrt(temp);
    return vec/inverseTemp;
}
//叉乘
inline Vector3f Cross(Vector3f& vec0,Vector3f& vec1)
{
    return Vector3f(vec0.y*vec1.z - vec0.z*vec1.y,
                    vec0.z*vec1.x - vec0.x*vec1.z,
                    vec0.x*vec1.y - vec0.y*vec1.x);
}

inline float Distance(Vector3f& vec0,Vector3f& vec1)
{
    float dx = vec0.x -vec1.x;
    float dy = vec0.y -vec1.y;
    float dz = vec0.z -vec1.z;
    return std::sqrt(dx*dx+dy*dy+dz*dz);
}

#endif /* VECTOR3_H */
    
