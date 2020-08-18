//
//  main.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/6.
//  Copyright © 2020 bytedance. All rights reserved.
//
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "FrameBuffer.h"
#include "Draw2d.h"
#include "Vector2.h"
#include "Vector3.h"
const int width  = 800;
const int height = 800;

Vector3f barycentric2(Vector2i p0,Vector2i p1,Vector2i p2,Vector2i p)
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

void triangle(Vector2i p0,Vector2i p1,Vector2i p2,Vector2i uv0,Vector2i uv1,Vector2i uv2, FrameBuffer &frambuffer, TGAImage &diffuseTex)
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
            Vector3f bary =barycentric2(p0,p1,p2,Vector2i(x,y));
            if(bary.x>=0&&bary.y>=0&&bary.z>=0)
            {
              Vector2i uv = Vector2i(uv0.x*bary.x+uv1.x*bary.y+uv2.x*bary.z,  uv0.y*bary.x+uv1.y*bary.y+uv2.y*bary.z);
              Vector2i pos = Vector2i(p0.x*bary.x+p1.x*bary.y+p2.x*bary.z,  p0.y*bary.x+p1.y*bary.y+p2.y*bary.z);

                frambuffer.drawPixel(pos.x, pos.y, diffuseTex.getColor(uv.x, uv.y)); // attention, due to int casts t0.y+i != A.y
            }
        }
    }
}


void triangle(Vector2i p0,Vector2i p1,Vector2i p2,FrameBuffer &frambuffer, Color& col)
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
            Vector3f bary =barycentric2(p0,p1,p2,Vector2i(x,y));
            if(bary.x>=0&&bary.y>=0&&bary.z>=0)
            {
//              Vector2i uv = Vector2i(uv0.x*bary.x+uv1.x*bary.y+uv2.x*bary.z,  uv0.y*bary.x+uv1.y*bary.y+uv2.y*bary.z);
              Vector2i pos = Vector2i(p0.x*bary.x+p1.x*bary.y+p2.x*bary.z,  p0.y*bary.x+p1.y*bary.y+p2.y*bary.z);
              frambuffer.drawPixel(pos.x, pos.y, col); // attention, due to int casts t0.y+i != A.y
            }
        }
    }
}



//argc和argv参数在用命令行编译程序时有用。main( int argc, char* argv[], char **env ) 中
//第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。
int main(int argc, char** argv) {
    Mesh* model = new Mesh("/Users/bytedance/Desktop/african_head.obj");
    TGAImage diffuseTex;
    diffuseTex.read_tga_file("/Users/bytedance/Desktop/african_head_diffuse.tga");
    diffuseTex.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    FrameBuffer frameBuffer(width,height,3);
    GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    win = glfwCreateWindow(width, height, "SoftRender", NULL, NULL);
    if(!win)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(win);
    while(!glfwWindowShouldClose(win)){
        frameBuffer.clear(Color::Black);
        drawMesh(model, frameBuffer);
        frameBuffer.draw();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;

}

