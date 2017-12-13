#include <cstdlib>

#include "Task2.h"
#include "Base/image.h"

//This is the Gaussian-filter for sigma = 0.1
//while, using it needs to be divided by 273.
int GaussVal[5][5] = 
{
    {1, 4, 7, 4, 1},
    {4, 16, 26, 16, 4},
    {7, 26, 41, 26, 7},
    {4, 16, 26, 16, 4},
    {1, 4, 7, 4, 1}
};


Task2::~Task2() {
}


//Goes through each pixel and checks its
//8-neighbourhood, to see if this pixel 
//is local-minima.
void Task2::setMinLocations() {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            if(checkLocalMin(i, j)) {
                _arr[i][j].set_min_blue(true);
            }
            else {
                _arr[i][j].set_min_blue(false);
            }
        }
    }
}

//Checks whether a pixel is local-min by 
//comparing its blue-component with other
//blue-components of surrounding pixels in
//8-neighbourhood. If yes, then it's localmin
bool Task2::checkLocalMin(int i1, int j1) {
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

            if(color_at(i1, j1).get_b() >
                    color_at(i, j).get_b()) {
                return false;
            }
        }
    }
    return true;
}

//setMinImage() function, checks the pixel which
//has local-min and sets its 24-neighbourhood to
//white color.
void Task2::setMinImage() {
    for(int i1 = 0; i1 < get_h(); i1++) {
        for(int j1 = 0; j1 < get_w(); j1++) {

            if(_arr[i1][j1].get_min_blue()) {

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
void Task2::setImageBlack() {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            set_pixel(i, j, 0, 0, 0);
        }
    }
}

//If overlapped, we need to take average.
//If not, just multiply and divide by 273.
void Task2::applyGaussianFilter() {
    for(int i1 = 0; i1 < get_h(); i1++) {
        for(int j1 = 0; j1 < get_w(); j1++) {

            if(_arr[i1][j1].get_min_blue()) {

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
                        if(_arr[i][j].get_color().get_r() == 255)  {
                            int pval = 255 * GaussVal[abs(i - i1)][abs(j - j1)];
                            pval = pval / 273;
                            set_pixel(i, j, pval, pval, pval);
                        }
                        else { //Case where pixel falls in overlapped region.
                            int pbefore = _arr[i][j].get_color().get_r();
                            int pval = 255 * GaussVal[abs(i - i1)][abs(j - j1)];
                            pval = pval / 273;
                            //Taking avg of previous and present filter.
                            pval = (pbefore + pval) / 2;
                            set_pixel(i, j, pval, pval, pval);
                        }
                    }
                }
            }
        }
    }
}











