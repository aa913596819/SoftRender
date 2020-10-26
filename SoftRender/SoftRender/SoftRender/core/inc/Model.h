//
//  Model.h
//  SoftRender
//
//  Created by linweifeng on 2020/10/21.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef MODEL_H
#define MODEL_H
#include"GIVector3.h"
#include"GIMacro.h"
#include"list"
#include"Mesh.h"
#include<memory>
namespace GiamEngine {
class GIMatrix4x4f;
}

NAMESPACE_GIAM_ENGINE_BEGIN
class Model;

using ModelPtr = std::shared_ptr<Model>;


class Model
{
private:
    std::list<Mesh>meshList;
public:
    Vector3f position;
    Vector3f rotation;
    Vector3f scale;
    
    GIMatrix4x4f getModelMatrix();
    void translate(Vector3f translation);
    void rotate(Vector3f rotation);
    void draw();
};


NAMESPACE_GIAM_ENGINE_END
#endif /* Model_h */
