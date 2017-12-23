#ifndef TASK3_H_
#define TASK3_H_

#include "Base/image.h"
#include <utility>

class Task3 : public Image {
    public:
        Task3() = default;
        virtual ~Task3();
        Task3(const Image& i) : Image(i) {};
        void reverseImageX(); 
        void setMaxLocations();
        void setMaxImage();
        bool checkLocalMax(int i, int j);
        void setImageBlack();
        void applyGaussianFilter();
        float getSaturation(Color c); 
    private:
};

#endif



