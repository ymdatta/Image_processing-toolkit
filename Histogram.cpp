#include "Histogram.h"
#include <algorithm>
#include <iostream>

std::vector<int> Histogram::getMinThresholds() {
    //std::sort(_min_thresholds.begin(), _min_thresholds.end());
    //_min_thresholds.erase( unique( _min_thresholds.begin(),
                //_min_thresholds.end() ), _min_thresholds.end());
    return _min_thresholds;
}

void Histogram::setBrightnessHistogram() {
    for(int i = 0; i < get_h(); i++) {
        for(int j = 0; j < get_w(); j++) {
            _hist_vec[_arr[i][j].get_brightness()] += 1;
        }
    }
}

std::vector<int> Histogram::get_histvec() {
    return _hist_vec;
}

void Histogram::setMinThresholds() {
    for(int i = 10; i < 246; i++) {
        int cur = _hist_vec[i];

        bool flag1 = true, flag2 = true;
        for(int j = i - 10; j < i; j++) {
            if(cur >= _hist_vec[j]) {
                flag1 = false;
                break;
            }
        }
        for(int j = i + 10; j > i; j--) {
            if(cur >= _hist_vec[j]) {
                flag2 = false;
                break;
            }
        }
        if(flag1 && flag2) {
            _min_thresholds.push_back(cur);
        }
    }

}

Histogram::~Histogram() {
}
