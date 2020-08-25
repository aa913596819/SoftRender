//
//  Mesh.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include "Mesh.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

//读取obj文件
Mesh::Mesh(const char* fileName)
{
    std::ifstream in;
    in.open (fileName, std::ifstream::in);
    if (in.fail()) return;
    std::string line;
    while (!in.eof()) {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vector3f v;
            for (int i=0;i<3;i++) iss >> v[i];
            vertsVector.push_back(v);
        } else if (!line.compare(0, 3, "vn ")) {
            iss >> trash >> trash;
            Vector3f n;
            for (int i=0;i<3;i++) iss >> n[i];
            normalsVector.push_back(n);
        } else if (!line.compare(0, 3, "vt ")) {
            iss >> trash >> trash;
            Vector2f uv;
            for (int i=0;i<2;i++) iss >> uv[i];
            uvsVector.push_back(uv);
        }  else if (!line.compare(0, 2, "f ")) {
            std::vector<Vector3i> f;
            Vector3i tmp;
            iss >> trash;
            while (iss >> tmp[0] >> trash >> tmp[1] >> trash >> tmp[2]) {
                for (int i=0; i<3; i++) tmp[i]--; // in wavefront obj all indices start at 1, not zero
                f.push_back(tmp);
            }
            facesVector.push_back(f);
        }
    }
}
int Mesh::facesNum()
{
    return static_cast<int>(facesVector.size());
}
int Mesh::vertsNum()
{
    return static_cast<int>(vertsVector.size());
}

int Mesh::uvsNum()
{
    return static_cast<int>(uvsVector.size());
}

int Mesh::normalsNum()
{
    return static_cast<int>(normalsVector.size());
}

Vector2f Mesh::getUV(int faceIndex,int vertexIndex)
{
    int index = facesVector[faceIndex][vertexIndex][1];
    return uvsVector[index];
}
Vector3f Mesh::getVertex(int index)
{
    return vertsVector[index];
}
Vector3f Mesh::getNormal(int index)
{
    return normalsVector[index];
}

std::vector<int> Mesh::getFace(int index)
{
    std::vector<int> faceVec;
    for(int i =0;i<(int)facesVector[index].size();i++)
    {
        faceVec.push_back(facesVector[index][i][0]);
    }
    return faceVec;
}
