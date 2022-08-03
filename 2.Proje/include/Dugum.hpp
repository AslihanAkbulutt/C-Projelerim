/**
* @file        Dugum.hpp
* @description Dugum sınıfının değişken ve fonksiyonlarını tanımladım.
* @course      Bilgisayar Mühendisliği 2.sınıf veri yapıları dersi 2B 
* @assignment  1.Ödev
* @date        5.11.2021
* @author      Aslıhan Akbulut aslihan.akbulut1@ogr.sakarya.edu.tr
*/

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