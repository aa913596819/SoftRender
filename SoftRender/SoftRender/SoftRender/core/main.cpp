//
//  main.cpp
//  SoftRender
//
//  Created by bytedance on 2020/8/6.
//  Copyright © 2020 bytedance. All rights reserved.
//

#include <iostream>
#include "tgaimage.h"
#include"Vector2.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void drawLine(const Vector2f &point0,const Vector2f &point1,TGAImage &targetImage,TGAColor col)
{
    if(point0.x>point1.y)
    {
        
    }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
   // line(13, 20, 80, 40, image, white);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
