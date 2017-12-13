#include <iostream>
#include <fstream>


#include "Task1.h"
#include "Task2.h"
#include "composite_image.h"

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
    Task1 t1;
    Image *itask1 = &t1;
    std::cin >> *itask1;
    t1.reverseImage();
    //std::cout << t1;

    Task2 t2(t1);
    t2.setMinLocations();


    t2.setImageBlack();
    t2.setMinImage();
    t2.applyGaussianFilter();
    std::cout << t2;

    composite_image c(t2, t1, 0.75);

    std::cout << c;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
 return 0;
}
