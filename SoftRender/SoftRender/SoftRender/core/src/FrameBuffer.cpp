//
//  FrameBuffer.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/13.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "FrameBuffer.h"
#include <GLFW/glfw3.h>
#include<iostream>
using namespace GiamEngine;

FrameBuffer:: FrameBuffer(const  int& w,const  int& h,const  int& c):width(w),height(h),channels(c)
{
    ColorBuffer = new unsigned char[width*height*channels];
    Zbuffer = new float[width*height];
    for(int i =0 ;i<width*height;i++)
    {
        Zbuffer[i]= INT_MAX;
        
    }
}

FrameBuffer::~FrameBuffer()
{
    delete [] ColorBuffer;
    delete [] Zbuffer;
}

 int FrameBuffer::getWidth()
{
    return width;
}

 int FrameBuffer::getHeight()
{
    return height;
}

 int FrameBuffer::getChannels()
{
    return channels;
}

void FrameBuffer::drawPixel(int x,int y,const Color& col)
{
    int index =(y*width+x)*channels;
    if(channels == 4)
    {
        ColorBuffer[index] = col.r;
        ColorBuffer[index+1] = col.g;
        ColorBuffer[index+2] = col.b;
        ColorBuffer[index+3] = col.a;
    }
    else
    {
        ColorBuffer[index] = col.r;
        ColorBuffer[index+1] = col.g;
        ColorBuffer[index+2] = col.b;
    }
}

void FrameBuffer::draw()
{
    
    glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, ColorBuffer);
}
//
void FrameBuffer::clear(const Color &col)
{
    
    glClearColor(col.r, col.g, col.b, col.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i = 0;i<width;i++)
    {
        for(int j =0;j<height;j++)
        {
            int index =(j*width+i)*channels;
            ColorBuffer[index] = col.r;
            ColorBuffer[index+1] = col.g;
            ColorBuffer[index+2] = col.b;
        }
    }
    for(int i = 0;i<width;i++)
    {
        for(int j =0;j<height;j++)
        {
            int index =(j*width+i);
            Zbuffer[index] =INT_MAX;
        }
    }
}
