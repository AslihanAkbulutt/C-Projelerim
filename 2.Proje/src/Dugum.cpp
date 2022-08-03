/**
* @file        Dugum.cpp
* @description Dugum sınıfının kurucu fonksiyonunun gövdesini tanımladım.
* @course      Bilgisayar Mühendisliği 2.sınıf veri yapıları dersi 2B 
* @assignment  1.Ödev
* @date        5.11.2021
* @author      Aslıhan Akbulut aslihan.akbulut1@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
#include <string>


Dugum::Dugum(std::string veri)
{
    //düğüm kurucu fonksiyonu
    this->veri = veri;
    sonraki = onceki = 0;

}