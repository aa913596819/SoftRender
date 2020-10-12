//
//  GIType.h
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

typedef  unsigned int  GIEnum;
#endif /* GITYPE_H */
