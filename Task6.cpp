#include "Task6.h"
#include <algorithm>
#include <iostream>

#include "Base/color.h"
#include <vector>

std::vector < Color > col_vec;

void setColorArray() {
    Color red(255, 0, 0);
    Color green(0, 128, 0);
    Color blue(0, 0, 255);
    Color cyan(0, 255, 255);
    Color magneta(255, 0, 255);
    Color yellow(255, 255, 0);
    col_vec.push_back(red);
    col_vec.push_back(green);
    col_vec.push_back(blue);
    col_vec.push_back(cyan);
    col_vec.push_back(magneta);
    col_vec.push_back(yellow);
}


int thres_arr1[257];
int glob_hei = 0; int glob_wid = 0;



void setArray1(std::vector<int> thre_val) {
    for(int i = 0; i < 257; i++) {
        thres_arr1[i] = 0;
    }

    for(int i = 0; i < 256; i++) {
        thres_arr1[i] = thre_val[i];
    }
}

void Task6::generateNoise(Image& img) {
    for(int i = 0; i < img.get_h(); i++) {
        for(int j = 0; j < img.get_w(); j++) {
            int randval = (rand() % 256);
            img.set_pixel(i, j, randval, randval, randval);
        }
    }
}

int get_val1(int val) {
    for(int i = 0; i < 256; i++) {
        if(thres_arr1[i] == val) {
            return i;
        }
    }
    return -1;
}


Task6::~Task6() {
}


int Task6::setBinaryImage() {
    int noSegs = getMinThresholds().size();

    if(noSegs == 0) {
        return -1;
    }

    setArray1(get_histvec());

    std::vector<int> thres_vec;
    for(int i = 0; i < noSegs; i++) {
        thres_vec.push_back(get_val1(getMinThresholds()[i]));
    }

    std::sort(thres_vec.begin(), thres_vec.end());
    int median = 256;
    if((noSegs % 2) == 0) {
        median = thres_vec[((noSegs - 1)/ 2)];
        median += thres_vec[((noSegs + 1)/ 2)];
        median /= 2;
    }
    else {
        median = thres_vec[((noSegs - 1)/ 2)];
    }

    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(_arr[i][j].get_brightness() <= median) {
                set_pixel(i, j, 0, 0, 0);
                continue;
            }
            else {
                set_pixel(i, j, 255, 255, 255);
                continue;
            }
        }
    }
    thres_vec.clear();
    return 0;
}


void Task6::setConnected() {
    int count = 0;
    glob_hei = get_h();
    glob_wid = get_w();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if((_arr[i][j].get_brightness() == 255) && 
                    (!_visited_matrix[i][j]) ) { 
                //If the pixel is white, and if it is not visited before.
                //
                //Only white, since we are finding connected-components
                //of white only.
                setComponents(i, j, count);
                count += 1;
            }
        }
    }
    //std::cout << "count at the end was " << count << std::endl;
}

int Task6::setComponents(int i, int j, int val) {

    if(!isValidCoordinate(i, j)) {
        return -1;
    }

    if(_visited_matrix[i][j]) {  //Already visited case.
        return -1;
    }

    if(_arr[i][j].get_brightness() == 0) { //If not white, return -1.
        return -1;
    }

    //This means, the this (i, j) is white and is not given value.

    _matrix[i][j] = val;
    _visited_matrix[i][j] = true;  //marking as visited.

    setComponents(i - 1, j - 1, val);
    setComponents(i - 1, j + 1, val);
    setComponents(i - 1, j, val);

    setComponents(i, j - 1, val);
    setComponents(i, j + 1, val);

    setComponents(i + 1, j - 1, val);
    setComponents(i + 1, j + 1, val);
    setComponents(i + 1, j, val);

    return 0;
}

bool Task6::isValidCoordinate(int i, int j) {

    //Boundary Cases.
    if((i < 0) || (i >= glob_hei)) {
        return false;
    }

    if((j < 0) || (j >= glob_wid)) {
        return false;
    }
    return true;
}

void Task6::colorComponents() {
    setColorArray();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_h(); j++) {
            if((_matrix[i][j] >=0) && (_matrix[i][j] <=5)) {
                Color c = col_vec[_matrix[i][j]];
                set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
            }
            else {
                set_pixel(i, j, 0, 0, 0);
            }
        }
    }
}
