#include "Task1.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "Base/image.h"


int getDistance(int i1, int j1, int i, int j) {
    int xdiff = pow((i - i1), 2);
    int ydiff = pow((j - j1), 2);
    int res = floor(sqrt(xdiff + ydiff));
    return res;
}

bool isequal(Color a, Color b) {
    if((a.get_r() == b.get_r()) && (a.get_g() == b.get_g())) {
        if(a.get_b() == b.get_b()) {
            return true;
        }
        return false;
    }
    return false;
}


void Task1::makeCircle(float x1, float y1) {
    int x = floor(x1 * get_w());
    int y = floor(y1 * get_h());
    int radius = std::min(floor(get_w() * 0.125),
            floor(get_h() * 0.125));
    Color b(0, 0, 0);
    Color w(255, 255, 255);
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            int dis = getDistance(x, y, i, j);
            if(dis <= radius) {
                set_pixel(i, j, 0, 0, 0);
            }
            else {
                if(!isequal(color_at(i,j), b)) {
                    set_pixel(i, j, 255, 255, 255);
                }
            }
        }
    }
}


//Reversing image doesn't work on the same image.
//i.e, t1.reverseImage(t1) doesn't work.
void Task1::reverseImage(Image &i) {
    Pixel **dp1 = i.get_arr();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c =  dp1[i][get_w() - j - 1].get_color();
            set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}

//Reversing the image itself.
void Task1::reverseImage() {
    Task1 t1(*this);
    Pixel **dp1 = t1.get_arr();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c =  dp1[i][get_w() - j - 1].get_color();
            set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }


}

void Task1::imageClip(Image *i1, Image *i2) {
    Pixel **dp1 = i1->get_arr();
    Pixel **dp2 = i2->get_arr();
    Color b(0, 0, 0);
    Color w(255, 255, 255);
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(isequal(dp2[i][j].get_color(), w)) {
                set_pixel(i, j, 255, 255, 255);
            }
            else {
                Color c = dp1[i][j].get_color();
                set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());

            }
        }
    }
}


void Task1::imageStencil(Image *i1, Image *i2) {
    Pixel **dp1 = i1->get_arr();
    Pixel **dp2 = i2->get_arr();
    Color b(0, 0, 0);
    Color w(255, 255, 255);
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(isequal(dp2[i][j].get_color(), b)) {
                set_pixel(i, j, 255, 255, 255);
            }
            else {
                Color c = dp1[i][j].get_color();
                set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
            }
        }
    }
}


