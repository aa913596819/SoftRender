//
//  Mesh.hpp
//  SoftRender
//
//  Created by bytedance on 2020/8/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef MESH_H
#define MESH_H
#include"Vector3.h"
#include"Vector2.h"
#include<vector>
class Mesh
{
public:
    std::vector<Vector3f> vertsVector;
    std::vector<Vector2f> uvsVector;
    std::vector<Vector3f> normalsVector;
    std::vector<std::vector<int>> facesVector;
    Mesh(const char* fileName);
    ~Mesh()
    {
        
    }
    int facesNum();
    int vertsNum();

};

#endif /* Mesh_h */
