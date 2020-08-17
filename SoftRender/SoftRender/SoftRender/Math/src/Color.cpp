//
//  Color.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include "Color.h"

const Color Color::White(1.0f,1.0f,1.0f);
const Color Color::Black(0.0f,0.0f,0.0f);
const Color Color::Red(1.0f,0.0f,0.0f);
const Color Color::Green(0.0f,1.0f,0.0f);
const Color Color::Blue(0.0f,0.0f,1.0f);
Color::Color(float inR, float inG, float inB,float inA):r(inR),g(inG),b(inB),a(inA)
{
    
};
Color::Color(unsigned char inR, unsigned char inG,unsigned char inB, unsigned char inA):r(inR/255.0f),g(inG/255.0f),b(inB/255.0f),a(inA/255.0f)
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

