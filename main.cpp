#include <iostream>
#include <fstream>


#include "Task3.h"
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
    std::ofstream out("3rdoutputfruit.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    Task3 t1;
    Image *itask1 = &t1;
    std::cin >> *itask1;

    Task3 t3(t1);
    Task3 t4(t1);
    t4.reverseImageX();
    t3.setMaxLocations();

    t3.setImageBlack();

    //std::cout << t3;
    t3.setMaxImage();

    //std::cout << t3;
    t3.applyGaussianFilter();
    //std::cout << t3;

    composite_image c(t4, t3, 0.6);

    std::cout << c;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
 return 0;
}
