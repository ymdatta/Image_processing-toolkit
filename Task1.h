#ifndef TASK1_H_
#define TASK1_H_

#include "Base/image.h"
#include <iostream>


class Task1 : public Image {
    public:
        Task1() = default;
        ~Task1() {};
        Task1(const Image& i) : Image(i) {};
        Task1(int width, int hei) :
        Image(width, hei) { };
        void makeCircle(float x, float y);
        void reverseImage(Image &x);
        void imageClip(Image *i1, Image *i2);
        void imageStencil(Image *i1, Image *i2);
    protected:
    private:
};

#endif

