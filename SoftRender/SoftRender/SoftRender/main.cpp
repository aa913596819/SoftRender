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
#include "Graphics.h"
#include "GIVector2.h"
#include "GIVector3.h"
#include "GI.h"
#include "Camera.h"
#include <chrono>
#include<string>
NAMESPACE_GIAM_ENGINE_USING
int SRC_WIDTH  = 800;
int SRC_HEIGHT = 500;
bool enableMouse = false;
void processInput(GLFWwindow* window,GiamEngine::Camera& cam);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
double fps();
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float lastX = 0.0f;
float lastY = 0.0f;
float firstMouse =true;
GiamEngine::Camera cam(Vector3f(0.0,0.0,-3.0f),Vector3f(0.0,1.0,0.0),0.0,0.0);
FrameBuffer frameBuffer(SRC_WIDTH,SRC_HEIGHT,3);


//argc和argv参数在用命令行编译程序时有用。main( int argc, char* argv[], char **env ) 中
//第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。
int main(int argc, char** argv) {
    glfwInit();

    Mesh* model = new Mesh("/Users/bytedance/Desktop/african_head.obj");
    GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    
    win = glfwCreateWindow(SRC_WIDTH/2, SRC_HEIGHT/2, "",NULL, NULL);

    glfwMakeContextCurrent(win);
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
    glfwSetCursorPosCallback(win, mouse_callback);
    
    glfwGetFramebufferSize(win,&SRC_WIDTH,&SRC_HEIGHT);
    std::cout<<SRC_WIDTH<<std::endl<<SRC_HEIGHT<<std::endl;
    if(!win)
    {
        glfwTerminate();
        return -1;
    }
    while(!glfwWindowShouldClose(win)){
        std::string windowName = "SoftRender fps:" + std::to_string(fps());
        glfwSetWindowTitle(win, windowName.c_str());

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(win,cam);
        frameBuffer.clear(Color::Red);
        drawMesh(cam,model, frameBuffer,GI_SCAN);
        frameBuffer.draw();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}



//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

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
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        enableMouse =!enableMouse;
}

void mouse_callback(GLFWwindow* window,double xpos, double ypos)
{
    if(enableMouse)
    {
        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = (xpos - lastX)*0.1;
        float yoffset =(lastY - ypos)*0.1;

        lastX = xpos;
        lastY = ypos;

        cam.ProcessMouse(xoffset, yoffset);
    }
}


double fps()
{
    static double fps = 0.0;
    static int frameCount = 0;
    static auto lastTime = std::chrono::system_clock::now();
    static auto curTime = std::chrono::system_clock::now();
    
    curTime = std::chrono::system_clock::now();
    
    auto duration = duration_cast<std::chrono::microseconds>(curTime - lastTime);
    double duration_s = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
    fps = frameCount / duration_s;
    frameCount = 0;
    lastTime = curTime;
    ++frameCount;

    return fps;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

}
