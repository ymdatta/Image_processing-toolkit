#ifndef TASK4_H_
#define TASK4_H_

#include "Histogram.h"
#include "Base/color.h"

class Task4 : public Histogram {
    public:
        Task4() = default;
        virtual ~Task4();
        Task4(const Image& i) : Histogram(i) {};
        int setSegments();
        void reflectImageY();
        void setColorOrder();
    private:
        std::vector<Color> _color_order;

};

#endif





