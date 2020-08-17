//
//  Draw2d.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include"Draw2d.h"
#include<cmath>
#include"Vector3.h"
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
void drawMesh(Mesh* mesh,FrameBuffer& targetFrame,const Color& col)
{
#ifdef POLYGON_MODE_LINE
    for (int i=0; i<mesh->facesNum(); i++)
    {
           std::vector<int> face = mesh->facesVector[i];
           for (int j=0; j<3; j++)
           {
               Vector3f v0 = mesh->vertsVector[face[j]];
               Vector3f v1 = mesh->vertsVector[face[(j+1)%3]];
               int x0 = (v0.x+1.)/2.0f *(targetFrame.getWidth()-1);//[-1,1]->[0,1]
               int y0 = (v0.y+1.)/2.0f * (targetFrame.getHeight()-1);
               int x1 = (v1.x+1.)/2.0f * (targetFrame.getWidth()-1);
               int y1 = (v1.y+1.)/2.0f * (targetFrame.getHeight()-1);
               drawLine(x0, y0, x1, y1, targetFrame, col);
           }
       }
#else
    for(int i = 0;i<mesh->facesNum();i++)
    {
        std::vector<int> face = mesh->facesVector[i];
        Vector3f v0 = mesh->vertsVector[face[0]];
        Vector3f v1 = mesh->vertsVector[face[1]];
        Vector3f v2 = mesh->vertsVector[face[2]];
        int x0 = (v0.x+1.)/2.0f *(targetFrame.getWidth()-1);//[-1,1]->[0,1]
        int y0 = (v0.y+1.)/2.0f * (targetFrame.getHeight()-1);
        int x1 = (v1.x+1.)/2.0f * (targetFrame.getWidth()-1);
        int y1 = (v1.y+1.)/2.0f * (targetFrame.getHeight()-1);
        int x2 = (v2.x+1.)/2.0f * (targetFrame.getWidth()-1);
        int y2 = (v2.y+1.)/2.0f * (targetFrame.getHeight()-1);
        drawTriangle(Vector2i(x0,y0), Vector2i(x1,y1), Vector2i(x2,y2), targetFrame, col);
    }
#endif
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

//重心坐标法 扫描线算法
//三角形所在平面的所有点 都可以用重心坐标表示，且坐标和为1.
//三角形内部的点 坐标都为[0,1],该算法通过遍历三角形的BBOX内所有的点来实现填充
//
Vector3f barycentric(Vector2i p0,Vector2i p1,Vector2i p2,Vector2i p)
{
    Vector3f a(p2.x-p0.x,p1.x-p0.x,p0.x-p.x);
    Vector3f b(p2.y-p0.y,p1.y-p0.y,p0.y-p.y);
    Vector3f bary = Cross(a, b);
    if(bary.z<1.0f)
    {
        return Vector3f(-1.0f,1.0f,1.0f);
    }
    //因为我们的三角形顶点没有做排序，可能所有点都是负数。所以/z 使得同号为正。
    return Vector3f(1.0f-(bary.x+bary.y)/bary.z, bary.y/bary.z, bary.x/bary.z);
}
void drawTriangle(Vector2i p0,Vector2i p1,Vector2i p2,FrameBuffer& targetFrame,const Color& col)
{
    Vector2i bboxMin(0,0);
    Vector2i bboxMax(0,0);
    
    bboxMin.x = std::min(p0.x,std::min(p1.x,p2.x));
    bboxMin.y = std::min(p0.y,std::min(p1.y,p2.y));
    bboxMax.x = std::max(p0.x,std::max(p1.x,p2.x));
    bboxMax.y = std::max(p0.y,std::max(p1.y,p2.y));
    
    for(int x= bboxMin.x;x<=bboxMax.x;x++)
    {
        for(int y= bboxMin.y;y<=bboxMax.y;y++)
        {
            Vector3f bary =barycentric(p0,p1,p2,Vector2i(x,y));
            if(bary.x>=0&&bary.y>=0&&bary.z>=0)
            {
                targetFrame.drawPixel(x,y,col);
            }
        }
    }
}
