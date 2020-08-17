//
//  Color.hpp
//  SoftRender
//
//  Created by bytedance on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color(float r, float g, float b,float a=1.0f);
    Color(unsigned char r, unsigned char g,unsigned char b, unsigned char a=255);
    
    bool operator==(const Color& rhs);
    bool operator!=(const Color& rhs);
    
    union
    {
        struct{float r,g,b,a;};
        struct{float x,y,z,w;};
    };

    
    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};
#endif /* Color_h */
