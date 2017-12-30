#include <iostream>
#include <fstream>


#include "Task6.h"
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
    std::ofstream out("6thoutput.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    Image img;
    std::cin >> img;
    Task6 temp(img);
    temp.setBrightnessHistogram();
    temp.setMinThresholds();
    Image C(img), D(img);
    int flag = temp.setBinaryImage();
    if(flag == -1) {
        std::cout << img;
    }
    else {
        temp.setConnected();
        temp.colorComponents();
        std::cout << temp;

    }
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
    return 0;
}
