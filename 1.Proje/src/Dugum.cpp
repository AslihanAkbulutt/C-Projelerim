#include "Dugum.hpp"
#include <math.h>
Dugum::Dugum(int X, int Y, int Z)
{
    //düğüm kurucu fonksiyonu
    
    sonraki = 0;
    this->x = X;
    this->y = Y;
    this->z = Z;
    this->orjin = sqrt((x*x)+(y*y)+(z*z));


}