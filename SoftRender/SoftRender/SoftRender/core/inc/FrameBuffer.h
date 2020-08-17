//
//  FrameBuffer.hpp
//  SoftRender
//
//  Created by bytedance on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "Vector2.h"
#include "Vector3.h"
#include "Color.h"
//这里暂定用数组存储Buffer
class FrameBuffer
{
private:
    int width,height,channels;
    unsigned char* ColorBuffer;
public:
    FrameBuffer(const int& w,const  int& h,const  int& c);
    void clear(const Color &col);
    ~FrameBuffer();
    int getWidth();
    int getHeight();
    int getChannels();
    void drawPixel(int x,int y,const Color& col);
    void draw();
};



#endif /* FrameBuffer_h */
