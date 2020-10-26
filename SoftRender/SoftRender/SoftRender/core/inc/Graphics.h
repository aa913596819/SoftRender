//
//  Graphics.h
//  SoftRender
//
//  Created by linweifeng on 2020/8/11.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H
#include"GIVector2.h"
#include"GIVector4.h"
#include"Mesh.h"
#include"tgaimage.h"
#include"FrameBuffer.h"
#include"GIColor.h"
#include"GI.h"
#include"GIMacro.h"

NAMESPACE_GIAM_ENGINE_BEGIN
class Camera;
void drawPoint(int x0,int y0,FrameBuffer& targetFrame,const Color& col);
void drawPoint(Vector2i p,FrameBuffer& targetFrame,const Color& col);
//Bresenham
void drawLine(Vector2i p0,Vector2i p1,FrameBuffer &targetFrame,const Color& col);
void drawLine(int x0,int y0,int x1,int y1,FrameBuffer &targetFrame,const Color& col);
//基于重心坐标的光栅化
//需要做透视插值矫正，所以需要Vector4f的数组
//verts 为NDC
void drawTriangle(Vector4f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuseTex);
void drawTriangle(const Vector4f& v0,const Vector4f& v1,const Vector4f& v2,const Vector3f& normal0,const Vector3f& normal1,const Vector3f& normal2,const Vector2f& uv0,const Vector2f& uv1,const Vector2f& uv2,FrameBuffer& targetFrame,TGAImage& diffuseTex);

//基于扫描线的光栅化
void drawTriangle_scan(Vector4f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuseTex);

void drawMesh(Camera& cam,Mesh* mesh,FrameBuffer& targetFrame,GIenum type);
NAMESPACE_GIAM_ENGINE_END

#endif /* GRAPHICS_H */
