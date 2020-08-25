//
//  Draw2d.hpp
//  SoftRender
//
//  Created by bytedance on 2020/8/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef DRAW2D_H
#define DRAW2D_H
#include"Vector2.h"
#include"Mesh.h"
#include"tgaimage.h"
#include"FrameBuffer.h"
#include"Color.h"
void drawPoint(int x0,int y0,FrameBuffer& targetFrame,const Color& col);
void drawPoint(Vector2i p,FrameBuffer& targetFrame,const Color& col);
//Bresenham
void drawLine(Vector2i p0,Vector2i p1,FrameBuffer &targetFrame,const Color& col);
void drawLine(int x0,int y0,int x1,int y1,FrameBuffer &targetFrame,const Color& col);
void drawMesh(Mesh* mesh,FrameBuffer& targetFrame);
//
void drawTriangle(Vector3f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuseTex);
#endif /* Draw2d_h */
