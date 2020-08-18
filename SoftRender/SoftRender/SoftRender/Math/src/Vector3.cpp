
#include "Vector3.h"
Vector3f& Vector3f::operator=(const Vector3f &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}
bool Vector3f::operator==(const Vector3f &vec)
{
    return x == vec.x&& y == vec.y&& z ==vec.z;
}

bool Vector3f::operator!=(const Vector3f &vec)
{
    return x != vec.x|| y != vec.y || z !=vec.z;
}
Vector3f Vector3f::operator+(const Vector3f &vec)const
{
    return Vector3f(x+vec.x, y+vec.y, z+vec.z);
}
Vector3f Vector3f::operator-(const Vector3f &vec)const
{
    return Vector3f(x-vec.x, y-vec.y, z-vec.z);
}
Vector3f Vector3f::operator*(float s)const
{
    return Vector3f(x*s,y*s,z*s);
}
//这么做是有问题，可以将分母的倒数求出来，避免做三次除法
//同时不应该在这里做分母的非0检测 这是不符合逻辑的
//Vector3f Vector3f::operator/(float s)const
//{
//    return Vector3f(x/s,y/s,z/s);
//}
Vector3f Vector3f::operator/(float s)const
{
    float temp = 1.0f/s;
    return this->operator*(temp);
}
Vector3f& Vector3f::operator+=(const Vector3f& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}
Vector3f& Vector3f::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}
Vector3f& Vector3f::operator/=(float s)
{
    float temp = 1.0f/s;
    x *= temp;
    y *= temp;
    z *= temp;
    return *this;
}
inline Vector3f Vector3f::operator-()const
{
    return Vector3f(-x,-y,-z);
}
inline void Vector3f::zero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
void Vector3f::normalize()
{
    float temp = x * x + y * y + z * z;
    float inverseTemp = 1.0f / std::sqrt(temp);
    x *=inverseTemp;
    y *=inverseTemp;
    z *=inverseTemp;
}

