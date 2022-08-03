
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
