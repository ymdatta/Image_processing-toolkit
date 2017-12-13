#include <iostream>
#include <algorithm>
#include "color.h"
#include "pixel.h"
#include "image.h"

Image::Image(int w, int h):_w(w), _h(h) {
    set_arr();
    max_pixel = 255;
    _encoding = "P3";
}
Image::Image(){
    _encoding = "P3";    
}
Image::Image(const Image& im) {
    _w = im._w; _h = im._h;
    max_pixel = 255;
    _encoding = "P3";    
    set_arr();
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j] = Pixel(im._arr[i][j]);
        }
    }
}
Image::~Image() {
    for(int i = 0; i < _h; i++) {
        delete [] _arr[i];
    }
    delete [] _arr;
}

void Image::set_arr() {
    _arr = new Pixel*[_h];
    for(int i = 0; i < _h; i++) {
        _arr[i] = new Pixel[_w];
        for(int j = 0; j < _w; j++) {
            _arr[i][j].set_loc(i, j);
        }
    }
}

void Image::set_arr2(Pixel** a) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j] = a[i][j];
        }
    }
}
void Image::set_pixel(int i, int j, int r, int g, int b) {
    _arr[i][j].set_color(r, g, b);
}
void Image::filter(const Color& c, float a) {
    for(int i = 0; i < _h; i++) {
        for(int j = 0; j < _w; j++) {
            _arr[i][j].apply_filter(c, a);
        }
    }
}

int Image::get_w() const {return _w;}
int Image::get_h() const {return _h;}
Pixel** Image::get_arr() const {return _arr;}

Color Image::color_at(int x, int y) const{
    return _arr[x][y].get_color();
}

std::istream& operator>>(std::istream& in, Image& im) {
    in >> im._encoding;
    if(im._encoding != "P3") {
        std::cout << "unsupported file encoding!" << std::endl;
        exit(1);
    }
    in >> im._w >> im._h >> im.max_pixel;

    im.set_arr();
    Pixel p;
    for(int i = 0; i < im._h; i++) {
        for(int j = 0; j < im._w; j++) {
            in >> p;
            p.set_loc(j, i);
            im._arr[i][j] = p;
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& os, const Image& im) {
    os << im._encoding << std::endl;
    os << im._w << " " << im._h << std::endl;

    os << im.max_pixel << std::endl;

    for(int i = 0; i < im._h; i++) {
        for(int j = 0; j < im._w; j++) {
            os << im._arr[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
