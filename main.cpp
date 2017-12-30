#include <iostream>
#include <fstream>


#include "Task7.h"
#include "composite_image.h"

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
    std::ofstream out("7thoutputlena.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    Image img;
    std::cin >> img;

    ScaledImage s(img);
    s.makeReflectionImage();
    s.makeSquare();
    std::cout << s;

   //composite_image c(D, C, 0.2);

    ////std::cout << c;
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    in.close();
    out.close();
    return 0;
}
