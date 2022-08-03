/**
* @file        main.cpp
* @description programın genel işlemlerinin yapıldığı dosya
* @course      Bilgisayar Mühendisliği 2.sınıf veri yapıları dersi 2B 
* @assignment  1.Ödev
* @date        5.11.2021
* @author      Aslıhan Akbulut aslihan.akbulut1@ogr.sakarya.edu.tr
*/
using namespace std;
#include <sstream> 
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Liste.hpp"
#include "Dugum.hpp"


int main()
{
    setlocale(LC_ALL,"Turkish");
    //yeni bağlı liste oluşturulur
    Liste* liste = new Liste();
    
    //dosya okumaya açılır
    ifstream dosyaOku;
    dosyaOku.open("./doc/veri.txt", ios::app);
 
    string gecici;
    int sayac = 0;
    //dosyadaki satır sayısı bulunur
    while (getline(dosyaOku, gecici))
    {
        sayac++;
    }
    dosyaOku.close();
   
    dosyaOku.open("./doc/veri.txt", ios::app);
    int uzunluk = sayac;
    string* veriler = new string[uzunluk];
    gecici = "";
    sayac = 0;
    //her satır tek tek veriler dizisine atanır
    while (getline(dosyaOku, gecici))
    {
        
        veriler[sayac] = gecici;
        sayac++;

    }
    dosyaOku.close();

    //dizinin elemanları tek tek okunur
    for (int i = 0; i < uzunluk; i++)
    {
        string secim;
        secim = veriler[i];
        char sec = secim[0];


        if (sec == 'E')
        {
            //ekleme yapılacaksa
            string veri = veriler[i];
            int hashtag = 0;
            int uzunluk = 0;
            string indis;
            string isim;
            int indis2 = 0;

            hashtag = veri.find("#");
            uzunluk = veri.length();


            for (int j = 2; j < hashtag; j++)
            {
                indis += veri[j];
            }
            for (int k = hashtag+1; k < (uzunluk - 1); k++)
            {
                isim += veri[k];
            }
            indis2 = stoi(indis);

            liste->ekle(isim,indis2);

            
        }
        else if (sec == 'S')
        {
            //silme yapılacaksa
            string veri = veriler[i];
            int indis2 = 0;
            int uzunluk = 0;
            string indis;

            uzunluk = veri.length();
            for (int l = 2; l < (uzunluk - 1); l++)
            {
                indis += veri[l];
            }
            indis2 = stoi(indis);

            liste->cikar(indis2);

        }

    }
    //liste yazdırılır
    cout<<*liste;

    delete[] veriler;
    delete liste;

}