//
//  Scene.h
//  SoftRender
//
//  Created by linweifeng on 2020/10/22.
//  Copyright © 2020 linweifeng. All rights reserved.
//

#ifndef SCENE_H
#define SCENE_H
#include "GIMacro.h"
#include "Camera.h"
#include "vector"
#include <memory>
#include "Model.h"
NAMESPACE_GIAM_ENGINE_BEGIN
class Scene
{
public:
    std::vector<ModelPtr> modelVector;
    void addModel(ModelPtr model);
    void removeModel(ModelPtr model);
    void draw();
};

NAMESPACE_GIAM_ENGINE_END


#endif /* Scene_h */
