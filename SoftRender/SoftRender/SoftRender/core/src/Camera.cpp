//
//  Camera.cpp
//  SoftRender
//
//  Created by linweifeng on 2020/10/10.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#include "Camera.h"
#include "GIFloatConversion.h"
#include <cmath>
void Camera::update()
{
    GiamEngine::Vector3f f;
    f.x = cos(GiamEngine::Deg2Rad(yaw))* cos(GiamEngine::Deg2Rad(pitch));
    f.y = sin(GiamEngine::Deg2Rad(pitch));
    f.z = sin(GiamEngine::Deg2Rad(yaw))* cos(GiamEngine::Deg2Rad(pitch));
    
    front = GiamEngine::Normalize(f);
    right = GiamEngine::Normalize(GiamEngine::Cross(front, worldUp));
    up = GiamEngine::Normalize(GiamEngine::Cross(front, right));
    //??????????
    //up = GiamEngine::Normalize(GiamEngine::Cross(right, front));

}



GiamEngine::Matrix4x4f Camera::GetViewMatrix()
{
    GiamEngine::Matrix4x4f rotate0 = GiamEngine::Matrix4x4f::Rotate(-yaw, GiamEngine::Vector3f(0.0,1.0,0.0));
    GiamEngine::Matrix4x4f rotate1 = GiamEngine::Matrix4x4f::Rotate(-pitch, GiamEngine::Vector3f(1.0,0.0,0.0));
    GiamEngine::Matrix4x4f translate = GiamEngine::Matrix4x4f::Translate(-pos);
    GiamEngine::Matrix4x4f negate = GiamEngine::Matrix4x4f(1.0);
    negate.Get(2, 2) = -1.0f;
    GiamEngine::Matrix4x4f viewMatrix = rotate0*rotate1*translate*negate;
    return viewMatrix;
}

void Camera::ProcessKeyboard(Camera_Movement m, float deltaTime)
{
    float velocity = moveSpeed * deltaTime;
    if (m == FORWARD)
        pos += front * velocity;
    if (m == BACKWARD)
        pos -= front * velocity;
    if (m == LEFT)
        pos -= front * velocity;
    if (m == RIGHT)
        pos += right * velocity;
}

void Camera::ProcessMouse(float xOffset,float yOffset)
{
    yaw += xOffset;
    pitch += yOffset;
    if(yaw >=90.0f)
    {
        yaw = 90.0f;
    }
    if(pitch >=90.0f)
    {
        pitch = 90.0f;
    }
    update();
}
