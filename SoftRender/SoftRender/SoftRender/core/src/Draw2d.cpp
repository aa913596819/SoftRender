//
//  Draw2d.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include"Draw2d.h"
#include<cmath>
#include"GIVector3.h"
#include<iostream>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void drawPoint(int x0,int y0,FrameBuffer& targetFrame,const Color& col)
{
    targetFrame.drawPixel(x0, y0, col);
}
void drawPoint(Vector2i p,FrameBuffer& targetFrame,const Color& col)
{
    targetFrame.drawPixel(p.x, p.y, col);
}
void drawLine(int x0,int y0,int x1,int y1,FrameBuffer& targetFrame,const Color& col)
{
    //首先检测x、y方向哪个方向更陡峭。向更陡峭的方向步进，一个极端的例子 x方向只移动一格，
    //而y方向移动10格
    bool isSteep = false;
    if(std::abs(x0-x1)>std::abs(y0-y1))
    {
        isSteep = false;
    }
    else
    {
        isSteep = true;
        swap(x0,y0);
        swap(x1,y1);
    }
    if(x0>x1)
    {
        swap(x0,x1);
        swap(y0,y1);
    }
    int dx = x1-x0;
    int dy = std::abs(y1-y0);
//    //注意使用C++风格的转换而非C风格的
//    //所有涉及到的元素 同乘2dx 即可避免除法。
//    float k = dy/static_cast<float>(dx);
    int k = 2*dy;
    int error = 0;
    int y = y0;
    for(int x = x0;x<=x1;x++)
    {
        if(!isSteep)
        {
           targetFrame.drawPixel(x, y, col);
        }
        else
        {
            targetFrame.drawPixel(y, x, col);
        }
        error +=k;
        if(error>dx)
        {
            error -=2*dx;
            y += y1>y0?1:-1;
        }
    }
}

void drawLine(Vector2i p0,Vector2i p1,FrameBuffer &targetFrame,const Color& col)
{
    drawLine(p0.x, p0.y, p1.x, p1.y,targetFrame,col);
}
void drawMesh(Mesh* mesh,FrameBuffer& targetFrame)
{
    Vector3f light_dir(0,0,-1);
    TGAImage diffuseTex;
    diffuseTex.read_tga_file("/Users/bytedance/Desktop/african_head_diffuse.tga");
    diffuseTex.flip_vertically();
    
    for (int i=0; i<mesh->facesNum(); i++)
    {
        std::vector<int> face = mesh->getFace(i);
        Vector2f texture_coords[3];
        Vector3f world_coords[3];
        Vector3f normals[3];
        for (int j=0; j<3; j++) {
            world_coords[j]  = mesh->getVertex(face[j]);
            normals[j] =mesh->getNormal(face[j]);
        }
        Vector3f vec0 =world_coords[2]-world_coords[0];
        Vector3f vec1 =world_coords[1]-world_coords[0];
        Vector3f n = Cross(vec0, vec1);
        
        for(int k=0; k<3; k++)
        {
            texture_coords[k]=mesh->getUV(i,k);
        }
        n.normalize();
        float intensity = Dot(n,light_dir);
        Color col(intensity,intensity,intensity);
        drawTriangle(&world_coords[0], &normals[0], &texture_coords[0], targetFrame, diffuseTex);
    }
}

//重心坐标法 扫描线算法
//三角形所在平面的所有点 都可以用重心坐标表示，且坐标和为1.
//三角形内部的点 坐标都为[0,1],该算法通过遍历三角形的BBOX内所有的点来实现填充
//
template<typename T0,typename T1>
Vector3f barycentric(Vector2<T0>p0,Vector2<T0>p1,Vector2<T0>p2,Vector3<T1>p)
{
    Vector3f a(p2.x-p0.x,p1.x-p0.x,p0.x-p.x);
    Vector3f b(p2.y-p0.y,p1.y-p0.y,p0.y-p.y);
    Vector3f bary = Cross(a, b);
    if(std::abs(bary.z)<1.0f)
    {
        return Vector3f(-1.0f,1.0f,1.0f);
    }
    //因为我们的三角形顶点没有做排序，可能所有点都是负数。所以/z 使得同号为正。
    return Vector3f(1.0f-(bary.x+bary.y)/bary.z, bary.y/bary.z, bary.x/bary.z);
}

void drawTriangle(Vector3f* verts,Vector3f* normals,Vector2f* uvs,FrameBuffer& targetFrame,TGAImage& diffuse)
{
    Vector2i bboxMin(0,0);
    Vector2i bboxMax(0,0);
    
    Vector2i screen_coords[3];
    screen_coords[0] = Vector2i((verts[0].x+1.)*(targetFrame.getWidth()-1)/2., (verts[0].y+1.)*(targetFrame.getHeight()-1)/2.);
    screen_coords[1] = Vector2i((verts[1].x+1.)*(targetFrame.getWidth()-1)/2., (verts[1].y+1.)*(targetFrame.getHeight()-1)/2.);
    screen_coords[2] = Vector2i((verts[2].x+1.)*(targetFrame.getWidth()-1)/2., (verts[2].y+1.)*(targetFrame.getHeight()-1)/2.);
    
    bboxMin.x = std::min(screen_coords[0].x,std::min(screen_coords[1].x,screen_coords[2].x));
    bboxMin.y = std::min(screen_coords[0].y,std::min(screen_coords[1].y,screen_coords[2].y));
    bboxMax.x = std::max(screen_coords[0].x,std::max(screen_coords[1].x,screen_coords[2].x));
    bboxMax.y = std::max(screen_coords[0].y,std::max(screen_coords[1].y,screen_coords[2].y));

    Vector3f p;
    for(p.x= bboxMin.x;p.x<=bboxMax.x;p.x++)
    {
        for(p.y= bboxMin.y;p.y<=bboxMax.y;p.y++)
        {
            Vector3f bary =barycentric(screen_coords[0],screen_coords[1],screen_coords[2],p);
            if(bary.x>=0&&bary.y>=0&&bary.z>=0)
            {
                float z = verts[0].z *bary.x + verts[1].z *bary.y + verts[2].z *bary.z;
                int zIndex =p.x+p.y*targetFrame.getWidth();
                if(targetFrame.Zbuffer[zIndex]<z)
                {
                    Vector2i uv = Vector2i(
                                           (uvs[0].x *bary.x + uvs[1].x *bary.y + uvs[2].x *bary.z)*(diffuse.get_width()),
                                           (uvs[0].y *bary.x + uvs[1].y *bary.y + uvs[2].y *bary.z)*(diffuse.get_height())
                                           );
                    targetFrame.Zbuffer[zIndex]=z;
                    targetFrame.drawPixel(p.x,p.y,diffuse.getColor(uv.x, uv.y));
                }
            }
        }
    }
}

















#if 0
//old shcool
void drawTriangle(Vector2i p0,Vector2i p1,Vector2i p2,FrameBuffer& targetFrame,const Color& col)
{
    if(p0.y==p1.y&&p1.y==p2.y)
    {
        return;
    }
    if(p0.y>p1.y)
    {
        std::swap(p0,p1);
    }
    if(p0.y>p2.y)
    {
        std::swap(p0,p2);
    }
    if(p1.y>p2.y)
    {
        std::swap(p1,p2);
    }
    int totalHeight = p2.y-p0.y;
    int segmentHeight0 =p1.y-p0.y+1;
    int segmentHeight1 =p2.y-p1.y+1;
    //原理很简单，即一次向y方向步进一个点，同时通过差值的方式计算x的坐标
    for(int y = p0.y;y<=p2.y;y++)
    {
        bool isUpper = y>p1.y || p1.y==p0.y;
        float a = static_cast<float>(y - p0.y)/totalHeight;
        float b = isUpper?static_cast<float>(y - p1.y)/segmentHeight1:static_cast<float>(y - p0.y)/segmentHeight0;
        int x0 = p0.x +(p2.x-p0.x)*a;
        int x1 = isUpper?p1.x +(p2.x-p1.x)*b:p0.x +(p1.x-p0.x)*b;
        
        if(x0>x1)
        {
            std::swap(x0,x1);
        }
        for(int x =x0;x<=x1;x++)
        {
            targetFrame.drawPixel(x, y, col);
        }
    }
}
#endif

    
