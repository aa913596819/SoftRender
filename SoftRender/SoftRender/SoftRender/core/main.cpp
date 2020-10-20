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
#include "GIType.h"
#include "Camera.h"
#include <chrono>

double fps()
{
    static double fps = 0.0;
    static int frameCount = 0;
    static auto lastTime = std::chrono::system_clock::now();
    static auto curTime = std::chrono::system_clock::now();
    
    curTime = std::chrono::system_clock::now();
    
    auto duration = duration_cast<std::chrono::microseconds>(curTime - lastTime);
    double duration_s = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;

    if (duration_s > 2)//2秒之后开始统计FPS
    {
        fps = frameCount / duration_s;
        frameCount = 0;
        lastTime = curTime;
    }

    ++frameCount;

    return fps;
}

const int width  = 800;
const int height = 800;

void processInput(GLFWwindow* window,Camera& cam);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = 0.0f;
float lastY = 0.0f;
float firstMouse =true;
Camera cam(Vector3f(0.0,10.0,-10.0f),Vector3f(0.0,1.0,0.0),30.0,0.0);
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
    glfwSetCursorPosCallback(win, mouse_callback);
    while(!glfwWindowShouldClose(win)){
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(win,cam);
        frameBuffer.clear(Color::Black);
//        drawMesh(model, frameBuffer,GI_BARYCENTER);
        drawMesh(cam,model, frameBuffer,GI_SCAN);
        frameBuffer.draw();
        glfwSwapBuffers(win);
        glfwPollEvents();
        std::cout<<"fps:"<<fps()<<std::endl;
    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window,Camera& cam)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cam.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cam.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cam.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cam.ProcessKeyboard(RIGHT, deltaTime);
}

void mouse_callback(GLFWwindow* window,double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = (xpos - lastX)*0.5;
    float yoffset =(lastY - ypos)*0.5; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    cam.ProcessMouse(xoffset, yoffset);
}
