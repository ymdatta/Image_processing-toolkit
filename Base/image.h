#ifndef IMAGE_H
#define IMAGE_H
#include <string>

#include "color.h"
#include "pixel.h"

class Image {
protected:
    int _w, _h, max_pixel;
    std::string _encoding;
    Pixel** _arr;
public:
    Image(int w, int h);
    Image();
    Image(const Image& i);
    virtual ~Image();
    int get_w() const;
    int get_h() const;
    Pixel** get_arr() const;
    
    void set_pixel(int i, int j, int r, int g, int b);
    Color color_at(int i, int j) const;
    void filter(const Color& c, float a);
    void set_arr();
    void set_arr2(Pixel**);
    friend std::ostream& operator<<(std::ostream& os, const Image& i);
    friend std::istream& operator>>(std::istream& in, Image& i);    
};

#endif
