#include <iostream>
#include <fstream>


#include "Task4.h"
#include "composite_image.h"
#include "Histogram.h"

#include <cmath>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Usage: ./a.out image.ppm" << std::endl;
        return -1;
    }
    std::ifstream in(argv[1]);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    std::ofstream out("lenaoutput.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    Task4 t1;
    Image *itask1 = &t1;
    std::cin >> *itask1;

    Task4 t2(t1);
    t2.setBrightnessHistogram();
    t2.setMinThresholds();
    t2.setColorOrder();

    int flag = t2.setSegments();
    if(flag == -1) {
        t2.reflectImageY();
    }
    //std::cout << t2;

    composite_image c(t1, t2, 0.4);

    std::cout << c;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
 return 0;
}
