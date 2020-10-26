//
//  GIFloatConversion.h
//  SoftRender
//
//  Created by linweifeng on 2020/9/15.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GIFLOATCONVERSION_H
#define GIFLOATCONVERSION_H

#define PI 3.14159265358979323846264338327950288419716939937510f

#include"GIMacro.h"
NAMESPACE_GIAM_ENGINE_BEGIN
inline float Deg2Rad(float deg)
{
    return deg*2.0f* PI /360.0f;
}

inline float Rad2Deg(float rad)
{
    return rad/2.0f/PI *360.0f;
}

inline float lerp(float a, float b, float factor)
{
    return a * factor + b * (1.0f-factor);
}
NAMESPACE_GIAM_ENGINE_END
#endif /* GIFLOATCONVERSION_H */
