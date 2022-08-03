using namespace std;
#include <sstream> 
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "Dugum.hpp"
#include "AVL.hpp"

int indissayisi(string satir, char aranan)
{
    int sayac=0;
    int indis = satir.find(aranan);
    while (indis != -1)
    {
        indis = satir.find(aranan, indis+1);
        sayac++;
    }

    return sayac;
}

 int main()
 {
     
    ifstream dosyaOku;
    dosyaOku.open("./doc/Noktalar.txt", ios::app);
    string gecici;
    int sayac=0;

    while (getline(dosyaOku, gecici))
    {
        sayac++;
    }
    dosyaOku.close();
    int uzunluk = sayac;
//----------------------------------------------------

    dosyaOku.open("./doc/Noktalar.txt", ios::app);
    
    string* satirlar = new string[uzunluk];
    gecici = "";
    sayac =0;

    while (getline(dosyaOku, gecici))
    {
        
        satirlar[sayac] = gecici;
        sayac++;

    }
    dosyaOku.close();
//-------------------------------------------------------
    int* indisler = new int[uzunluk];
    for (int i = 0; i < uzunluk; i++)
    {
        indisler[i] = indissayisi(satirlar[i], ' ')+1;
    }

//--------------------------------------------------------
    int toplamsayi = 0;
    for (int i = 0; i < uzunluk; i++)
    {
        toplamsayi += indisler[i];
    }
    int* sayilar = new int[toplamsayi];
//----------------------------------------------------------
    dosyaOku.open("./doc/Noktalar.txt", ios::app);
    int sayac1 =0;
    while (!dosyaOku.eof())
    {
        if(sayac1==toplamsayi+1)
            break;
        
        dosyaOku>>sayilar[sayac1];
        sayac1++;
    }    
    dosyaOku.close();
    
//---------------------------------------------------------
    int* toplamuzunlukk = new int[uzunluk];
    int mesafe = 0;
    int sayac4 = 0;
    int sayac5 = 0;
    for (int i = 0; i < toplamsayi; i+=3)
    {
        if(indisler[sayac4]==3)
        {
            toplamuzunlukk[sayac4]=0;
            sayac4++;
            mesafe =0;
            sayac5 = 0;
            continue;
        }
        mesafe += (sqrt(pow((sayilar[i]-sayilar[i+3]),2)+
        pow((sayilar[i+1]-sayilar[i+4]),2)+
        pow((sayilar[i+2]-sayilar[i+5]),2)));
        sayac5++;
        if(sayac5==(indisler[sayac4]/3)-1)
        {
            toplamuzunlukk[sayac4] = mesafe;
            mesafe = 0;
            sayac5 =0;
            sayac4++;
            i+=3;                    
        }
    }
//---------------------------------------------------------
    DogruKuyrugu* dogruKuyrugu = new DogruKuyrugu[uzunluk]; 
    int sayac2 = 0;
    int sayac3 = 0;

    for (int i = 0; i < (toplamsayi); i+=3)
    {
        dogruKuyrugu[sayac2].ekle(sayilar[i],sayilar[i+1],sayilar[i+2]);
        sayac3++;

        if (sayac3==indisler[sayac2]/3)
        {
            dogruKuyrugu[sayac2].toplamuzunluk = toplamuzunlukk[sayac2];
            sayac3=0;
            sayac2++;
        }
    }
    

    AVL* avl = new AVL();
    for (int i = 0; i < uzunluk; i++)
    {
        avl->Ekle(toplamuzunlukk[i],&dogruKuyrugu[i]);
    }
    avl->postOrder();
    
    delete avl;
    delete[] satirlar;
    delete[] indisler;
    delete[] sayilar;
    delete[] toplamuzunlukk;
    delete[] dogruKuyrugu;
    
 }