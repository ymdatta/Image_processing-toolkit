#include <iostream>
#include <fstream>


#include "Task1.h"
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
    std::ofstream out("outputnormal.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    Task1 t1;
    Image *itask1 = &t1;
    std::cin >> *itask1;
    Task1 t2(t1);
    Image *itask2 = &t2;
    t2.makeCircle(0.5, 0.5);
    t2.makeCircle(0.125, 0.125);
    t2.makeCircle(0.125, 0.875);
    t2.makeCircle(0.875, 0.125);
    t2.makeCircle(0.875, 0.875);
    Task1 t3(t1);
    t3.imageClip(itask1, itask2); //CLIP.
    Task1 t4(t1);
    t4.reverseImage(*itask1);   //REVERSE IMAGING.
    t4.imageStencil(&t4, itask2); //STENCILING.
    std::cout << t4;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
    std::ofstream outfinal("outfinal.ppm");
    coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(outfinal.rdbuf());
    composite_image c(t3, t4, 0.5);
    std::cout << c;
  return 0;
}
