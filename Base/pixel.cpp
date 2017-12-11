#include <iostream>
#include "color.h"
#include "pixel.h"

Pixel::Pixel() {}
Pixel::~Pixel(){}
Pixel::Pixel(const Pixel& p) {
    _x = p._x;
    _y = p._y;
    _c = p._c;
}


Color Pixel::get_color() const {return _c;}
int Pixel::get_brightness() const {return (_c.get_r() + _c.get_g() + _c.get_b())/3;}

bool Pixel::get_min_blue() const {
    return min_blue;
}
    
void Pixel::set_min_blue(bool m) {
    min_blue = m;
}

void Pixel::set_color(int r, int g, int b) {
    _c.set_color(r, g, b);
}
void Pixel::set_color(const Color& c) {
    _c = c;
}
void Pixel::set_loc(int x, int y) {
    _x = x;
    _y = y;
}
void Pixel::apply_filter(const Color& c, float a) {
    _c.set_color(static_cast<int>( (1-a)*_c.get_r() + a*c.get_r() ),
                static_cast<int>( (1-a)*_c.get_g() + a*c.get_g() ),
                static_cast<int>( (1-a)*_c.get_b() + a*c.get_b() ) );
}

std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    os << p._c; // Outputs the color
    return os;
}

std::istream& operator>>(std::istream& is, Pixel& p) {
    is >> p._c;
    return is;
}