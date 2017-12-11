#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    int _r, _g, _b;
public:
    Color();
    Color(int, int, int);
    virtual ~Color();
    Color(const Color&);
    void set_color(int, int, int);
    int get_r() const;
    int get_g() const;
    int get_b() const;
    Color& operator=(const Color &other);
    Color& operator+(const Color& other);
    Color scalar_product(float a);
    // Color& operator*(const float& a);

    // friend Color operator*(const float& a, const Color& c);
    bool operator==(const Color& c);
    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    friend std::istream& operator>>(std::istream& is, Color& c);
};

#endif
