//
//  GI.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/28.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GITYPE_H
#define GITYPE_H

/* PixelFormat */
#define GI_RED              0x0000
#define GI_GREEN            0x0001
#define GI_BLUE             0x0002
#define GI_ALPHA            0x0003
#define GI_RGB              0x0004
#define GI_RGBA             0x0005

/* Rasterization Format */
#define GI_SCAN             0x1000
#define GI_BARYCENTER       0x1001

/* RenderState */
#define GI_DEPTH_TEST       0x2000
#define GI_BLEND            0x2001
#define GI_BLEND_DST        0x2002
#define GI_BLEND_SRC        0x2003
#define GI_FRONT            0x2004
#define GI_BACK             0x2005
#define GI_FRONT_AND_BACK   0x2006


typedef  unsigned int  GIenum;



enum cullFaceMode
{
    CFM_FRONT = 0,
    CFM_BACK = 1,
    CFM_FRONT_BACK =2
};

enum frontFace
{
    //逆时针
    FF_CCW = 0,
    FF_CW = 1
};

void GI_CULLFACE(GIenum);

void GI_ENABLE

#endif /* GI_H */
