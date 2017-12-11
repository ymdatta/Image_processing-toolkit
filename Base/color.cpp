#include <iostream>
#include "color.h"

Color::Color(){_r = _g = _b = 0;}
Color::Color(int r, int g, int b): _r(r), _g(g), _b(b) {}
Color::~Color(){};
Color::Color(const Color& p) {
    _r = p._r;
    _g = p._g;
    _b = p._b;
}

void Color::set_color(int r, int g, int b) {
    _r = r;
    _g = g;
    _b = b;
}
int Color::get_r() const{return _r;}
int Color::get_g() const{return _g;}
int Color::get_b() const{return _b;}

Color Color::scalar_product(float a) {
    Color res;
    res._r = a*_r;
    res._g = a*_g;
    res._b = a*_b;

    return res;
}

bool Color::operator==(const Color& c) {
    return (_r == c._r) && (_g == c._g) && (_b == c._b);
}

Color& Color::operator=(const Color &other) {
    _r = other._r;
    _g = other._g;
    _b = other._b;

    return *this;
}

Color& Color::operator+(const Color &other) {
    _r += other._r;
    _g += other._g;
    _b += other._b;

    return *this;
}

// Color& Color::operator*(const float& a) {
//     _r *= a;
//     _g *= a;
//     _b *= a;

//     return *this;
// }

// Color operator*(const float& a, const Color& c) {
//     Color res(c);
//     res._r *= a;
//     res._g *= a;
//     res._b *= a;

//     return res;
// }

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << c._r << " " << c._g << " " << c._b;
    return os;
}

std::istream& operator>>(std::istream& is, Color& c) {
    is >> c._r >> c._g >> c._b;
    return is;
}
