

#include "Liste.hpp"
#include "Dugum.hpp"
#include <iomanip>

Liste::Liste()
{
    ilk = 0;
}
Liste::~Liste()
{
    Dugum* gec = ilk;
    while (gec!=0)
    {
        Dugum* sil = gec;
        gec = gec->sonraki;

        delete sil;
    }
    
}

void Liste::ekle(std::string isim, int sira)
{
    if (ilk==0&&sira==0)
    {
        //listede eleman yoksa ve eleman 0. indise eklenecekse
        ilk = new Dugum(isim);
        return;
    }
    else if(ilk==0&&sira!=0)
    {
        //listede eleman yoksa ve eleman 0'dan farklı indise eklenecekse
        ilk = new Dugum(isim);
        return;
    }

    Dugum* dug= dugumGetir(sira);
    if (dug==0)
    {
        //istenilen indiste düğüm yoksa
        Dugum* yeni = new Dugum(isim);
    
        Dugum* gecici = ilk;
        while (gecici->sonraki!=0)
        {
            gecici=gecici->sonraki;
        }        
        gecici->sonraki = yeni;
        yeni->onceki = gecici;     
        
    }
    else
    {
        if (sira==0)
        {
            //düğüm varsa ve 0. indise eklenecekse
            Dugum* yeniDugum = new Dugum("");
            Dugum* gecici = ilk;

            while (gecici->sonraki!=0)
            {
                gecici=gecici->sonraki;
            }        
            gecici->sonraki = yeniDugum;
            yeniDugum->onceki = gecici; 
            while(gecici!=ilk)
            {
                yeniDugum->veri = gecici->veri;
                yeniDugum = yeniDugum->onceki;
                gecici= gecici->onceki;

            }
            yeniDugum->veri = gecici->veri;
            gecici->veri = isim;
        }
        else
        {
            //istenilen indiste düğüm varsa ve 0'dan farklı indise eklenecekse
            Dugum* yeniDugum = new Dugum("");
            Dugum* gecici = ilk;

            while (gecici->sonraki!=0)
            {
                gecici=gecici->sonraki;
            }        
            gecici->sonraki = yeniDugum;
            yeniDugum->onceki = gecici; 

            do
            {
                yeniDugum->veri = gecici->veri;
                yeniDugum = yeniDugum->onceki;
                gecici= gecici->onceki;

            }while(gecici->sonraki!=dug);
            yeniDugum->veri = isim;

        }

    }
    
}

void Liste::cikar(int sira)
{
    Dugum* sil = dugumGetir(sira);
    if (ilk==0&&sira==0)
    {
        //listede eleman yoksa ve eleman silinmek isteniyorsa
        return;
    }
    if(sil==0)
    {
        //dugum yoksa sondan silinir
        Dugum* gecici = ilk;
        while (gecici->sonraki!=0)
        {
            gecici=gecici->sonraki;
        }
        gecici->onceki->sonraki=0;
        delete gecici;
        
    }
    else
    {
        if(sira==0)
        {
            //ilk düğüm silinmek isteniyorsa
            Dugum* gecici = ilk;
            while (gecici->sonraki!=0)
            {
                gecici->veri=gecici->sonraki->veri;
                gecici=gecici->sonraki;
            }
            gecici->onceki->sonraki=0;
            delete gecici;
            
            

        }
        else
        {
            //0'dan farklı bir indisten silinecekse
            Dugum* gecici = sil;
            while (gecici->sonraki!=0)
            {
                gecici->veri=gecici->sonraki->veri;
                gecici=gecici->sonraki;
            }
            gecici->onceki->sonraki=0;
            delete gecici;

        }

    }
}
Dugum* Liste::dugumGetir(int sira)
{
    //istenilen indisteki düğümü getirir
    int sayac = 0;
    Dugum* gecici = ilk;
    while (gecici!=0)
    {
        if(sayac==sira) return gecici;
        gecici= gecici->sonraki;

        sayac++;
            
    }
    return 0;

}
std::ostream& operator<<(std::ostream& os,Liste& liste)
{
    
    //listeyi yazdırmak için
    using namespace std;
    Dugum* gecici = liste.ilk;

    while (gecici->sonraki!=0)
    {
        cout<<gecici->veri<<"<-->";
        gecici=gecici->sonraki;
    }
    cout<<gecici->veri;
    
}
