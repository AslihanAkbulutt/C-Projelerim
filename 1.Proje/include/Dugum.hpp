#ifndef Dugum_hpp
#define Dugum_hpp
#include <string>
  
class Dugum
{
public:
    
    Dugum(int X, int Y, int Z);
    
    int x;
    int y;
    int z;
    int orjin;
    Dugum* sonraki;

};

#endif