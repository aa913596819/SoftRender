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
private:
    std::vector<Vector3f> vertsVector;
    std::vector<Vector2f> uvsVector;
    std::vector<Vector3f> normalsVector;
    std::vector<std::vector<Vector3i>> facesVector;
public:
    Mesh(const char* fileName);
    ~Mesh()
    {
    }
    int facesNum();
    int vertsNum();
    int normalsNum();
    int uvsNum();
    //返回的是构成该三角形的 三个顶点位置的索引
    std::vector<int>getFace(int index);
    Vector3f getVertex(int index);
    Vector3f getNormal(int index);
    Vector2f getUV(int faceIndex,int vertexIndex);
};

#endif /* Mesh_h */
