//
//  Draw2d.hpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/11.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef DRAW2D_H
#define DRAW2D_H
#include"GIVector2.h"
#include"GIVector4.h"
#include"Mesh.h"
#include"tgaimage.h"
#include"FrameBuffer.h"
#include"GIColor.h"
#include"GIType.h"

class Camera;
void drawPoint(int x0,int y0,FrameBuffer& targetFrame,const Color& col);
void drawPoint(Vector2i p,FrameBuffer& targetFrame,const Color& col);
//Bresenham
void drawLine(Vector2i p0,Vector2i p1,FrameBuffer &targetFrame,const Color& col);
void drawLine(int x0,int y0,int x1,int y1,FrameBuffer &targetFrame,const Color& col);
//基于重心坐标的光栅化
//需要做透视插值矫正，所以需要Vector4f的数组
//verts 为NDC
void drawTriangle(Vector4f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuseTex,int k);
//基于扫描线的光栅化
void drawTriangle_scan(Vector4f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuseTex);

void drawMesh(Camera& cam,Mesh* mesh,FrameBuffer& targetFrame,GIEnum type);


#endif /* Draw2d_h */
