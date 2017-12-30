#ifndef TASK7_H_
#define TASK7_H_


#include "Base/image.h"

class ScaledImage : public Image {
    public:
        ScaledImage() = default;
        virtual ~ScaledImage();
        ScaledImage(const Image& img) : Image(img) {
           makeScaledImage(); };
        void makeScaledImage();
        void makeReflectionImage();
        void makeSquare();
    protected:
    private:
};

#endif
