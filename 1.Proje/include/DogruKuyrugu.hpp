#ifndef DogruKuyrugu_HPP
#define DogruKuyrugu_Hpp
#include<string>
#include<iomanip>
#include<exception>
#include<iostream>
#include "Dugum.hpp"

class DogruKuyrugu
{
public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    void ekle(int X, int Y, int Z);
    void enYuksekCikar();
    int enKucukGetir();
    friend std::ostream& operator<<(std::ostream& os, DogruKuyrugu& kuyruk);
    int toplamuzunluk;
    int noktasayisi;
    DogruKuyrugu* sag;
    DogruKuyrugu* sol;
    
private:
    Dugum* enYuksekOnceki();
    Dugum* ilk;
    Dugum* son;
    
    

};
#endif