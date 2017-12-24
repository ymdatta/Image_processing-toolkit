#ifndef TASK5_H_
#define TASK5_H_

#include "Histogram.h"
#include "Base/image.h"

class Task5 : public Histogram {
    public:
        Task5() = default;
        virtual ~Task5();
        Task5(const Image& i) : Histogram(i) {};
        void setFirstBinary(Image& i); //Binary of input image,white & blue only.
        void setSecondBinary(Image& i); //Another binary of input image,
                                        //yellow and white only.

        void reflectImageY(Image& i);  
        void reflectImageX(Image& i);  
       
       //In both reflectImage cases, i actually contains the data same as Task5
       //before getting reflected.

    protected:
    private:

};

#endif
