#include "Task7.h"
#include "Base/image.h"
#include "Base/color.h"
#include "cmath"

ScaledImage::~ScaledImage() {
}

void ScaledImage::makeScaledImage() {
    Image img(*this);
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            set_pixel(i, j, 255, 255, 255);
        }
    }

    int count1 = 0;
    for(int i = 0; i < (get_h()); i = i + 2) {
        int count2 = 0;
        for(int j = 0; j < (get_w()); j = j + 2) {
            Color c = img.color_at(i, j);
            set_pixel(i - count1, j - count2, c.get_r(), c.get_g(), c.get_b());
            count2 += 1;
        }
        count1 += 1;
    }
}

void ScaledImage::makeReflectionImage() {

    //Reflecting Image w.r.t Y and merging.
    for(int i = 0; i < (get_h() / 2) + 1 ; i++) {
        for(int j = 0; j < (get_w() / 2); j++) {
            Color c = color_at(i, j);
            set_pixel(i, get_w() - j - 1, c.get_r(), c.get_g(), c.get_b());
        }
    }

    //Reflecting Image w.r.t X and merging.
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c = color_at(i, j);
            set_pixel(get_h() - i - 1, j, c.get_r(), c.get_g(), c.get_b());
        }
    }

}

float getDistance2(int i1, int j1, int i, int j) {
    float xdiff = pow((i - i1), 2);
    float ydiff = pow((j - j1), 2);
    float res = floor(sqrt(xdiff + ydiff));
    return res;
}

void ScaledImage::makeSquare() {

    int length = std::min(floor(get_h() * 0.5), 
            floor(get_w() * 0.5));

    int x = floor(get_w() * 0.5); 
    int y = floor(get_h() * 0.5); 

    int halflen = length / 2;

    int ylower = y + halflen;
    int yupper = y - halflen;
    int xstart = x - halflen;
    int xend = x + halflen;

    Image img(*this);

    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            set_pixel(i, j, 255, 255, 255);
        }
    }


    for(int i = yupper; i <= ylower; i++) {
        for(int j = xstart; j <= xend; j++) {
            Color c = img.color_at(i, j);
            set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}

