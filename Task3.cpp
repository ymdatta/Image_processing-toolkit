#include <cstdlib>

#include "Task3.h"
#include "Base/image.h"
#include <iostream>
#include <algorithm>


//This is the Gaussian-filter for sigma = 0.1.
//while using it, needs to be divided by 273.
int GaussVal1[5][5] = 
{
    {1, 4, 7, 4, 1},
    {4, 16, 26, 16, 4},
    {7, 26, 41, 26, 7},
    {4, 16, 26, 16, 4},
    {1, 4, 7, 4, 1}
};

int myArray[512][512];
void setmyArray() {
    for(int i = 0; i < 512; i++) {
        for(int j = 0; j < 512; j++) {
            myArray[i][j] = 0;
        }
    }
}

Task3::~Task3() {
}


//Goes through each pixel and checks its
//8-neighbourhood, to see if this pixel 
//is local-maxima.
void Task3::setMaxLocations() {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(!checkLocalMax(i, j)) {     //here, min_blue bool is set to false
                //to indicate it is max_blue.
                //std::cout <
                _arr[i][j].set_min_blue(false);
            }
            else {
                _arr[i][j].set_min_blue(true);
            }
        }
    }
}

//Checks whether a pixel is local-max by 
//comparing its Saturation with the 
//saturation of 8-pixels surrounding it. 
bool Task3::checkLocalMax(int i1, int j1) {
    for(int i = i1 - 1; i <= i1 + 1; i++) {
        if((i < 0) || (i >= get_h())) {
            continue;
        }
        for(int j = j1 - 1 ; j <= j1 + 1; j++) {
            if((j < 0) || (j >= get_w())) {
                continue;
            }

            if((i == i1) && (j == j1)) {
                continue;
            }

            if((getSaturation(color_at(i, j))) >=
                    (getSaturation(color_at(i1, j1)))) {
                return true;
            }

        }
    }
    return false;
}

//setMaxImage() function, checks the pixel which
//has local-max and sets its 24-neighbourhood to
//white color.
void Task3::setMaxImage() {
    for(int i1 = 0; i1 < get_h(); i1++) {
        for(int j1 = 0; j1 < get_w(); j1++) {

            if(!(_arr[i1][j1].get_min_blue())) {
                //False, implying that it's local-max.
                for(int i = i1 - 2; i <= i1 + 2; i++) {
                    if((i < 0) || (i >= get_h())) {
                        continue;
                    }

                    for(int j = j1 - 2 ; j <= j1 + 2; j++) {
                        if((j < 0) || (j >= get_w())) {
                            continue;
                        }
                        set_pixel(i, j, 255, 255, 255);
                    }
                }
            }
        }
    }
}

//Sets the entire pixels to Black.
void Task3::setImageBlack() {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            set_pixel(i, j, 0, 0, 0);
        }
    }
}

//If overlapped, we need to take average.
//If not, just multiply and divide by 273.
void Task3::applyGaussianFilter() {
    setmyArray();
    for(int i1 = 0; i1 < get_h(); i1++) {
        for(int j1 = 0; j1 < get_w(); j1++) {

            if(!(_arr[i1][j1].get_min_blue())) {
                //If it's false only, then it is local-max.

                for(int i = i1 - 2; i <= i1 + 2; i++) {
                    if((i < 0) || (i >= get_h())) {
                        continue;
                    }

                    for(int j = j1 - 2 ; j <= j1 + 2; j++) {
                        if((j < 0) || (j >= get_w())) {
                            continue;
                        }
                        //check if overlapped or not.
                        //If not overlapped region.
                        //if(_arr[i][j].get_color().get_r() == 255)  {
                        if(myArray[i][j] == 0) {
                            int pval = 255 * GaussVal1[abs(i - i1)][abs(j - j1)];
                            pval = pval / 273;
                            myArray[i][j] += 1;
                            set_pixel(i, j, pval, pval, pval);
                        }
                        else { //Case where pixel falls in overlapped region.
                            int pbefore = _arr[i][j].get_color().get_r();
                            pbefore *= myArray[i][j];
                            pbefore *= 273;
                            myArray[i][j] += 1;
                            int pval = 255 * GaussVal1[abs(i - i1)][abs(j - j1)];

                            //Taking avg of previous and present filter.
                            pval = (pbefore + pval) / myArray[i][j];
                            pval /= 273;
                            set_pixel(i, j, pval, pval, pval);
                        }

                    }
                }
            }
        }
    }
}

void Task3::reverseImageX() {
    Task3 t3(*this);
    Pixel **dp1 = t3.get_arr();
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            Color c =  dp1[get_h() - i - 1][j].get_color();
            set_pixel(i, j, c.get_r(), c.get_g(), c.get_b());
        }
    }
}




float Task3::getSaturation(Color c) {
    int r = c.get_r();int b = c.get_b();int g = c.get_r();

    //int max = -1, min = 256;
    int max, min;

    max = r > g ? r : g;
    max = max > b ? max : b;

    min = r < g ? r : g;
    min = min < b ? min : b;

    float V = max;
    if(V == 0) { 
        return 0;
    }
    else {
        float C = max - min;
        return C/V;
    }
}

