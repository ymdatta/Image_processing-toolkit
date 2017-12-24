#include "Task5.h"
#include <iostream>


//int thres_arr[257];




//We will assume that necessary steps like checking whether image has
//two thresholds is done before calling this function.
//
//We also assume that height, width, memory space would be allocated
//for i before calling this function.
void Task5::setFirstBinary(Image& img) {
    int thres_val = 256;
    std::vector<int> thre_list = getMinThresholds();

    thres_val = getMinThresholds()[1]; //first threshold value.
    int thres_bright = 256;

    std::vector<int> thre_arr = get_histvec();
    for(int i = 0; i < 256; i++) {
        if(thre_arr[i] == thres_val) {
            thres_bright = i;
            break;
        }
    }



    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(_arr[i][j].get_brightness() <= thres_bright) {

                //std::cout << "lol " << std::endl;
                img.set_pixel(i, j, 0, 0, 255);
                continue;
            }
            else {
                //std::cout << "Here " << std::endl;
                img.set_pixel(i, j, 255, 255, 255);
            }
        }
    }
}


//We will assume that necessary steps like checking whether image has
//two thresholds is done before calling this function.
//
//We also assume that height, width, memory space would be allocated
//for i before calling this function.


void Task5::setSecondBinary(Image& img) {
    int thres_val = 256;
    std::vector<int> thre_list = getMinThresholds();

    thres_val = getMinThresholds()[2]; //first threshold value.

    int thres_bright = 256;

    std::vector<int> thre_arr = get_histvec();
    for(int i = 0; i < 256; i++) {
        if(thre_arr[i] == thres_val) {
            thres_bright = i;
            break;
        }
    }

    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {

            if(_arr[i][j].get_brightness() <= thres_bright) {
           //std::cout << "gere" << std::endl;
                img.set_pixel(i, j, 255, 255, 0);
                continue;
            }
            else {


           //std::cout << "where" << std::endl;
                img.set_pixel(i, j, 255, 255, 255);
                continue;
            }
        }
    }
}

void Task5::reflectImageY(Image& img) {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c = color_at(i, get_w() - j - 1);
            img.set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}

void Task5::reflectImageX(Image& img){
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c = color_at(get_h() - i - 1, j);
            img.set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}

Task5::~Task5() {
}
