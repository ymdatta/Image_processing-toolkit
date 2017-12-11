#include <iostream>
#include <algorithm>
#include <fstream>

#include "Base/image.h"

#include "composite_image.h"

composite_image::composite_image(const Image& i1, const Image& i2, float a): Image(std::min(i1.get_w(), i2.get_w()), 
                                                                    std::min(i1.get_h(), i2.get_h())) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j].set_color(i1.color_at(i, j).scalar_product(1-a) + i2.color_at(i, j).scalar_product(a));
        }
    }
}

