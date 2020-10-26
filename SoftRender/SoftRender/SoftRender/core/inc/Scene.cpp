//
//  Scene.cpp
//  SoftRender
//
//  Created by bytedance on 2020/10/22.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include "Scene.h"
NAMESPACE_GIAM_ENGINE_USING

void Scene::addModel(ModelPtr model)
{
    modelVector.push_back(model);
}

void Scene::removeModel(ModelPtr model)
{
    for(int i =0 ;i<modelVector.size();i++)
    {
        if(modelVector[i] == model)
        {
            modelVector.erase(modelVector.begin()+i);
        }
    }
}
