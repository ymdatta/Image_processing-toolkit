#ifndef TASK6_H_
#define TASK6_H_

#include "Histogram.h"
#include "Base/image.h"
#include <vector>

class Task6 : public Histogram {
    public:
        Task6() = default;
        virtual ~Task6();
        Task6(const Image& img) : Histogram(img) {
            _matrix = new int*[img.get_h()];
            for(int i = 0; i < img.get_h(); i++) {
                _matrix[i] = new int[img.get_w()];
            }

            for(int i = 0; i < img.get_h(); i++) {
                for(int j = 0; j < img.get_w(); j++) {
                    _matrix[i][j] = -1;
                }
            }
            _visited_matrix= new bool*[img.get_h()];
            for(int i = 0; i < img.get_h(); i++) {
                _visited_matrix[i] = new bool[img.get_w()];
            }

            for(int i = 0; i < img.get_h(); i++) {
                for(int j = 0; j < img.get_w(); j++) {
                    _visited_matrix[i][j] = false;
                }
            }
        }


        int setBinaryImage(); //Make Image Binary, by taking median
                               //of the thresholds. 
                               //If there are no thresholds, return -1.
        
        void setConnected();
        void generateNoise(Image& img);
        int setComponents(int i, int j, int val);
        bool isValidCoordinate(int i, int j);

        void colorComponents();

            
                               
    protected:
    private:
        //std::vector< std::vector<int> >matrix;
        int **_matrix;
        bool **_visited_matrix;


};

#endif
