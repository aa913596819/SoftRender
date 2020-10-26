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
    ColorBuffer.resize(width*height*channels);
    Zbuffer.resize(width*height);
    for(int i =0 ;i<width*height;i++)
    {
        Zbuffer[i]= INT_MAX;
    }
}

FrameBuffer::~FrameBuffer()
{
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
    unsigned char* p = ColorBuffer.data();
    if(channels == 4)
    {
        *(p+index) = col.r;
        *(p+index+1) = col.g;
        *(p+index+2) = col.b;
        *(p+index+3) = col.a;
    }
    else
    {
        *(p+index) = col.r;
        *(p+index+1) = col.g;
        *(p+index+2) = col.b;
    }
    
//    int index =(799*width+799)*channels;
//    if(channels == 4)
//    {
//        ColorBuffer[index] = 255;
//        ColorBuffer[index+1] = 255;
//        ColorBuffer[index+2] = 255;
//        ColorBuffer[index+3] = 255;
//    }
//    else
//    {
//        ColorBuffer[index] = 255;
//        ColorBuffer[index+1] = 255;
//        ColorBuffer[index+2] = 255;
//    }
}

void FrameBuffer::draw()
{
    glViewport(0, 0, 20, 20);
    glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, ColorBuffer.data());
}

void FrameBuffer::reSize(int width,int height)
{
    this->width =width;
    this->height =height;
    ColorBuffer.resize(width*height*channels);
    Zbuffer.resize(width*height);
}
//
void FrameBuffer::clear(const Color &col)
{
//    glClearColor(col.r, col.g, col.b, col.a);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i = 0;i<width;i++)
    {
        for(int j =0;j<height;j++)
        {
            unsigned char* p = ColorBuffer.data();
            int index =(j*width+i)*channels;
            *(p+index) = col.r;
            *(p+index+1) = col.g;
            *(p+index+2) = col.b;
        }
    }
    Zbuffer.assign(width*height, 1.0f);
}
