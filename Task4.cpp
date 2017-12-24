#include "Task4.h"
#include "Base/color.h"
#include <algorithm>
#include <iostream>

int thres_arr[257];

void setArray(std::vector<int> thre_val) {
    for(int i = 0; i < 257; i++) {
        thres_arr[i] = 0;
    }

    for(int i = 0; i < 256; i++) {
        thres_arr[i] = thre_val[i];
    }
}

int get_val(int val) {
    for(int i = 0; i < 256; i++) {
        if(thres_arr[i] == val) {
            return i;
        }
    }
    return -1;
}

void Task4::setColorOrder() {
    Color r(255, 0, 0);
    Color g(0, 128, 0);
    Color y(255, 255, 0);
    Color m(255, 0, 255);
    Color c(0, 255, 255);
    _color_order.push_back(r); 
    _color_order.push_back(g); 
    _color_order.push_back(y); 
    _color_order.push_back(m); 
    _color_order.push_back(c); 
}

Task4::~Task4() {
}

int Task4::setSegments() {
    int noSegs = getMinThresholds().size();

    setArray(get_histvec());
    if(noSegs == 0) {
        return -1;
    }

    int thres_vals[5];
    for(int i = 0; i < 5; i++) {
        thres_vals[i] = 256;
    }
    std::vector<int> MinThresholds = getMinThresholds(); 

    for(int i = 0; i < noSegs; i++) {
        thres_vals[i] = get_val(MinThresholds[i]);
    }
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(_arr[i][j].get_brightness() <= thres_vals[0]) {
                set_pixel(i, j, 255, 0, 0);
                //std::cout << " red" << std::endl;
                continue;
            }
            else if((_arr[i][j].get_brightness() > thres_vals[0]) && 
                    (_arr[i][j].get_brightness() <= thres_vals[1])) {
                set_pixel(i, j, 0, 128, 0);
                //std::cout << " green" << std::endl;
                continue;
            }
            else if((_arr[i][j].get_brightness() > thres_vals[1]) && 
                    (_arr[i][j].get_brightness() <= thres_vals[2])) {
                set_pixel(i, j, 255, 255, 0);
                //std::cout << " yello" << std::endl;
                continue;
            }

            else if((_arr[i][j].get_brightness() > thres_vals[2]) && 
                    (_arr[i][j].get_brightness() <= thres_vals[3])) {
                set_pixel(i, j, 255, 0, 255);
                //std::cout << " magneta" << std::endl;
                continue;
            }

            else if((_arr[i][j].get_brightness() > thres_vals[3]) && 
                    (_arr[i][j].get_brightness() <= thres_vals[4])) {
                set_pixel(i, j, 255, 0, 0);
                //std::cout << " cyan" << std::endl;
                continue;
            }
            else {
                set_pixel(i, j, 0, 0, 0);
                //std::cout << " black" << std::endl;
                continue;
            }
        }
    }
    MinThresholds.clear();
    return 0;
}

void Task4::reflectImageY() {
    Task4 t4(*this);
    Pixel **dp1 = t4.get_arr();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c =  dp1[i][get_w() - j - 1].get_color();
            set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}
