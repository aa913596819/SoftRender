//
//  FrameBuffer.hpp
//  SoftRender
//
//  Created by bytedance on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
//这里暂定用数组存储Buffer
class FrameBuffer
{
private:
    unsigned int width,height,channels;
    unsigned char ColorBuffer[];
public:
    FrameBuffer(const unsigned int& width,const unsigned int& height,const unsigned int& channels);
    
}



#endif /* FrameBuffer_h */
