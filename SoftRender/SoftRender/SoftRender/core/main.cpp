//
//  main.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/8/6.
//  Copyright © 2020 linweifeng. All rights reserved.
//
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "FrameBuffer.h"
#include "Draw2d.h"
#include "GIVector2.h"
#include "GIVector3.h"
const int width  = 800;
const int height = 800;
//argc和argv参数在用命令行编译程序时有用。main( int argc, char* argv[], char **env ) 中
//第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。
int main(int argc, char** argv) {
    Mesh* model = new Mesh("/Users/bytedance/Desktop/african_head.obj");
    TGAImage diffuseTex;
    diffuseTex.read_tga_file("/Users/bytedance/Desktop/african_head_diffuse.tga");
    diffuseTex.flip_vertically();
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
    Color a = Color(1.0f,1.0f,1.0f,1.0);
    while(!glfwWindowShouldClose(win)){
        frameBuffer.clear(Color::Red);
        drawMesh(model, frameBuffer);
        frameBuffer.draw();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

