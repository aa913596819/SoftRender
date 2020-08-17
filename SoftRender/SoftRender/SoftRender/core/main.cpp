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

int main(int argc, const char * argv[]) {
    FrameBuffer frameBuffer(300,300,3);
    Mesh* dogMesh = new Mesh("/Users/bytedance/Desktop/african_head.obj");
    GLFWwindow* win;
    if(!glfwInit()){
        return -1;
    }
    win = glfwCreateWindow(300, 300, "SoftRender", NULL, NULL);
    if(!win)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(win);
    while(!glfwWindowShouldClose(win)){
        frameBuffer.clear(Color::Black);
        drawMesh(dogMesh, frameBuffer, Color::White);
        frameBuffer.draw();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

////#include<random>
//const TGAColor white = TGAColor(255, 255, 255, 255);
//const TGAColor red   = TGAColor(255, 0,   0,   255);
//const int width = 800;
//const int height = 800;
//int main(int argc, char** argv) {
//    Mesh* dogMesh = new Mesh("/Users/bytedance/Desktop/african_head.obj");
//    TGAImage image(width, height, TGAImage::RGB);
//    drawMesh(dogMesh, image, red);
//    delete dogMesh;
//    return 0;
//}




//const float Aspect = 1280.0f/720.0f;
//int main(int argc, char** argv) {
//std::uniform_real_distribution<float> randomFloats(0.0f, 1.0f);
//std::default_random_engine generator;
//for(int i =0;i<1200;i+=3)
//{
//   std::cout<<randomFloats(generator)<<std::endl;
//
//}
//    //center 0.3 halfWidth 0.1
//    float halfWidth = 0.1f;
//    float halfLength = halfWidth*Aspect;
//    float vertexArray[] = {0.3f-halfLength,0.3f-halfWidth,0.3f,0.3f,
//        0.3f+halfLength,0.3f-halfWidth,0.3f,0.3f,
//        0.3f+halfLength,0.3f+halfWidth,0.3f,0.3f,
//        0.3f-halfLength,0.3f+halfWidth,0.3f,0.3f
//    };
//    float uv[] = {0.0f,0.0f,0.0f,-1.0f,
//        1.0f,0.0f,0.0f,-1.0f,
//        1.0f,1.0f,0.0f,-1.0f,
//        0.0f,1.0f,0.0f,-1.0f
//    };
//    unsigned short index[] =
//    {
//      0,1,2,2,3,0
//    };
//    std::ofstream vertexFile("vertexs.bin",std::ios::out|std::ios::binary);
//    if(!vertexFile)
//    {
//        std::cout<<"vertex.bin error"<<std::endl;
//        return -1;
//    }
//    vertexFile.write((char*)vertexArray,sizeof(vertexArray));
//    vertexFile.close();
//
//    std::ofstream uvFile("uvs.bin",std::ios::out|std::ios::binary);
//    if(!uvFile)
//    {
//        std::cout<<"uvs.bin error"<<std::endl;
//        return -1;
//    }
//    uvFile.write((char*)uv,sizeof(uv));
//    uvFile.close();
//
//    std::ofstream indexFile("indexs.bin",std::ios::out|std::ios::binary);
//    if(!indexFile)
//    {
//        std::cout<<"indexs.bin error"<<std::endl;
//        return -1;
//    }
//    indexFile.write((char*)index,sizeof(index));
//    indexFile.close();
//
//    return 0;
//}
//
//
////1. 随机生成一个中心点和半宽长 由于长宽比一致 可以直接计算的到 半长的数值
////2.随机生成一个运动方向。由这个运动方向 计算得到旋转矩阵
//
