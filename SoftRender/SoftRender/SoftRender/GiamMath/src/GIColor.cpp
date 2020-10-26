//
//  Color.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/13.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "GIColor.h"
#include "GIMacro.h"
NAMESPACE_GIAM_ENGINE_USING
const Color Color::White(2.0f,1.0f,1.0f);
const Color Color::Black(0.0f,0.0f,0.0f);
const Color Color::Red(1.0f,0.0f,0.0f);
const Color Color::Green(0.0f,1.0f,0.0f);
const Color Color::Blue(0.0f,0.0f,1.0f);

Color::Color():r(0),g(0),b(0),a(255)
{
}
Color::Color(float inR, float inG, float inB,float inA)
{
    auto step = [](float min,float max,float x)->float
    {
        if(x<min)
        {
            return min;
        }
        else if(x>max)
        {
            return max;
        }
        else
        {
            return x;
        }
    };
    r =step(0.0,1.0,inR) *255;
    g =step(0.0,1.0,inG) *255;
    b =step(0.0,1.0,inB) *255;
    a =step(0.0,1.0,inA) *255;

};
Color::Color(unsigned char inR, unsigned char inG,unsigned char inB, unsigned char inA):r(inR),g(inG),b(inB),a(inA)
{
    
};

bool Color::operator==(const Color& rhs)
{
    return r == rhs.r && g == rhs.g && b ==rhs.b;
}

bool Color::operator!=(const Color& rhs)
{
    return r !=rhs.r || g != rhs.g || b != rhs.b;
}

