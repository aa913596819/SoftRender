//
//  Vector2.h
//  SoftRender
//
//  Created by bytedance on 2020/8/9.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef VECTOR2_H
#define VECTOR2_H
class Vector2f
{
public:
    float x,y;
    Vector2f(float x,float y)
    {
        this.x=x;
        this.y=y;
    }
    Vector2f():x(0.0f),y(0.0f)
    {
        
    }
}


#endif /* VECTOR2_H */
