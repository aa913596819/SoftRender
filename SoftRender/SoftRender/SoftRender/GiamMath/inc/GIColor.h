//
//  GIColor.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/13.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GICOLOR_H
#define GICOLOR_H
#include"GIMacro.h"
NAMESPACE_GIAM_ENGINE_BEGIN
class Color
{
public:
    Color(float r, float g, float b,float a=1.0f);
    Color();
    Color(unsigned char r, unsigned char g,unsigned char b, unsigned char a=255);
    
    bool operator==(const Color& rhs);
    bool operator!=(const Color& rhs);
    
    union
    {
        struct{unsigned char r,g,b,a;};
        struct{unsigned char x,y,z,w;};
    };

    
    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};
NAMESPACE_GIAM_ENGINE_END
#endif /* GICOLOR_H */
