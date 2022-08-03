/**
* @file        Liste.hpp
* @description Liste sınıfının değişken ve fonksiyonlarını tanımladım.
* @course      Bilgisayar Mühendisliği 2.sınıf veri yapıları dersi 2B 
* @assignment  1.Ödev
* @date        5.11.2021
* @author      Aslıhan Akbulut aslihan.akbulut1@ogr.sakarya.edu.tr
*/
#ifndef LISTE
#define LISTE
#include<string>
#include<iomanip>
#include<exception>
#include<iostream>
#include "Dugum.hpp"

class Liste
{
public:
    Liste();

    ~Liste();
  
    void ekle(std::string isim,int sira);

    void cikar(int sira);

    Dugum* dugumGetir(int sira);
    
    friend std::ostream& operator<<(std::ostream& os,Liste& liste);
private:
    Dugum* ilk;

    

};
#endif