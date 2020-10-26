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
#include"GIMacro.h"

NAMESPACE_GIAM_ENGINE_BEGIN
const float DEF_YAW          = -90.0f;
const float DEF_FOV          = 60.0;
const float DEF_SPEED        = 2.0f;
const float DEF_SENSITIVITY  = 0.1f;
const float DEF_PITCH        = 0.0f;
const float DEF_NEARCLIP     = 0.1f;
const float DEF_FARCLIP      = 40.0f;
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
    Vector3f worldUp;
public:
    Vector3f pos;
    Vector3f front;
    Vector3f up;
    Vector3f right;

    float aspect;
    float yaw;
    float pitch;
    float moveSpeed;
    float mouseSensitivity;
    float fov;
    float nearClip;
    float farClip;
    
    Camera(Vector3f Pos = Vector3f(0.0f, 0.0f, 0.0f), Vector3f Up = Vector3f(0.0f, 1.0f, 0.0f), float Pitch = DEF_PITCH,float Yaw = DEF_YAW) : pos(Pos),front(Vector3f(0.0f, 0.0f, -1.0f)),worldUp(Up),yaw(Yaw),pitch(Pitch) ,moveSpeed(DEF_SPEED), mouseSensitivity(DEF_SENSITIVITY), fov(DEF_FOV),nearClip(DEF_NEARCLIP),farClip(DEF_FARCLIP),aspect(DEF_ASPECT)
    {
        update();
    }
    Matrix4x4f GetViewMatrix();
    Matrix4x4f GetProjMatrix();
    void ProcessKeyboard(Camera_Movement,float deltaTime);
    void ProcessMouse(float xOffset,float yOffset);
};
NAMESPACE_GIAM_ENGINE_END
#endif /* CAMERA_H */
