#ifndef TASK2_H_
#define TASK2_H_

#include "Base/image.h"
#include <iostream>
#include <vector>
#include <utility>

class Task2 : public Image {
    public:
        Task2() = default;
        virtual ~Task2();
        Task2(const Image& i) : Image(i) {};
        void setMinLocations();
        void setMinImage();
        bool checkLocalMin(int i, int j);
        void setImageBlack();
        void applyGaussianFilter();
    private:
};
        
#endif
