#include <iostream>
#include <fstream>


#include "Task5.h"
#include "composite_image.h"
#include "Histogram.h"

#include "Base/image.h"

#include <cmath>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Usage: ./a.out image.ppm" << std::endl;
        return -1;
    }
    std::ifstream in(argv[1]);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    std::ofstream out("output.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    Image img;
    std::cin >> img;


    Task5 temp(img);
    temp.setBrightnessHistogram();
    temp.setMinThresholds();
    Image C(img), D(img);

    if(temp.getMinThresholds().size() < 2) {
        temp.reflectImageY(C);
        temp.reflectImageX(D);
    }
    else {
        temp.setFirstBinary(C);
        temp.setSecondBinary(D);
    }

    composite_image c(D, C, 0.2);

    std::cout << c;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
 return 0;
}
