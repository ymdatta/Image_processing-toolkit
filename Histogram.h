#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include "Base/image.h"
#include <vector>

class Histogram: public Image {
    public:
        Histogram() = default;
        virtual ~Histogram();
        Histogram(const Image& i) : Image(i) {};
        void setBrightnessHistogram();
        std::vector<int> getMinThresholds(); //Returns indexes of thresholds.
        void setMinThresholds();
        std::vector<int> get_histvec(); //getter function for _hist_vec.

    private:
        std::vector<int> _hist_vec = std::vector<int>(256, 0);
        std::vector<int> _min_thresholds;
};

#endif
