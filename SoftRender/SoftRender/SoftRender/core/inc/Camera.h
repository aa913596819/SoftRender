//
//  Camera.h
//  SoftRender
//
//  Created by linweifeng on 2020/10/10.
//  Copyright © 2020 linweifeng. All rights reserved.
//


#ifndef CAMERA_H
#define CAMERA_H
#include"GIVector3.h"
#include"GIMatrix4x4f.h"
const float DEF_YAW          = -90.0f;
const float DEF_FOV          = 45.0f;
const float DEF_SPEED        = 2.0f;
const float DEF_SENSITIVITY  = 0.1f;
const float DEF_PITCH        = 0.0f;
const float DEF_NEARCLIP     = 0.1f;
const float DEF_FARCLIP      = 1.0f;
const float DEF_ASPECT       = 1.3333f;
enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};
class Camera
{
private:
    void update();
    GiamEngine::Vector3f worldUp;
public:
    GiamEngine::Vector3f pos;
    GiamEngine::Vector3f front;
    GiamEngine::Vector3f up;
    GiamEngine::Vector3f right;

    float aspect;
    float yaw;
    float pitch;
    float moveSpeed;
    float mouseSensitivity;
    float fov;
    float nearClip;
    float farClip;
    
    Camera(GiamEngine::Vector3f Pos = GiamEngine::Vector3f(0.0f, 0.0f, 0.0f), GiamEngine::Vector3f Up = GiamEngine::Vector3f(0.0f, 1.0f, 0.0f), float Pitch = DEF_PITCH,float Yaw = DEF_YAW) : pos(Pos),front(GiamEngine::Vector3f(0.0f, 0.0f, -1.0f)),worldUp(Up),yaw(Yaw),pitch(Pitch) ,moveSpeed(DEF_SPEED), mouseSensitivity(DEF_SENSITIVITY), fov(DEF_FOV),nearClip(DEF_NEARCLIP),farClip(DEF_FARCLIP),aspect(DEF_ASPECT)
    {
        update();
    }
    GiamEngine::Matrix4x4f GetViewMatrix();
    GiamEngine::Matrix4x4f GetProjMatrix();
    void ProcessKeyboard(Camera_Movement,float deltaTime);
    void ProcessMouse(float xOffset,float yOffset);
};

#endif /* CAMERA_H */
