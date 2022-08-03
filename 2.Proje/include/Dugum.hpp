
#ifndef Dugum_hpp
#define Dugum_hpp
#include <string>

class Dugum
{
public:
    
    Dugum(std::string veri);
    std::string veri;
    Dugum* sonraki;
    Dugum* onceki;

};

#endif
