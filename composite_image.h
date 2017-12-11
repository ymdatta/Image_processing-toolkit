#ifndef COMPOSITE_IMAGE
#define COMPOSITE_IMAGE

#include "Base/image.h"

class composite_image : public Image {
public:
    composite_image(const Image& i1, const Image& i2, float a);
    composite_image(const composite_image &other) : Image(other) {};
};

#endif
