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
    std::ifstream objFile;
    objFile.open(fileName);
    if(objFile.fail())
    {
        return;
    }
    std::string line;
    float vert[3];
    while (!objFile.eof()) {
        std::getline(objFile, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            iss >> trash;
            for (int i=0;i<3;i++)
            {
                iss >> vert[i];
            }
            vertsVector.push_back(Vector3f(vert[0],vert[1],vert[2]));
        }
        else if (!line.compare(0, 2, "f "))
        {
            std::vector<int> f;
            int itrash, idx;
            iss >> trash;
            while (iss >> idx >> trash >> itrash >> trash >> itrash)
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
            }
            facesVector.push_back(f);
        }
    }
    std::cout<<static_cast<int>(vertsVector.size());
}
int Mesh::facesNum()
{
    return static_cast<int>(facesVector.size());
}
int Mesh::vertsNum()
{
    return static_cast<int>(vertsVector.size());
}
