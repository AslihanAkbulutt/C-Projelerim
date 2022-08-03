#include "DogruKuyrugu.hpp"
#include "Dugum.hpp"

DogruKuyrugu::DogruKuyrugu()
{
    ilk = son = 0;
    toplamuzunluk = 0;
    sag = sol = 0;
    noktasayisi = 0;
   
}
DogruKuyrugu::~DogruKuyrugu()
{
    while (ilk != 0)
    {
        Dugum* gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
    
}

void DogruKuyrugu::ekle(int X, int Y, int Z)
{
    if(ilk==0)
    {
        ilk = new Dugum(X,Y,Z);
        son = ilk;
        
    }
    else
    {
        Dugum* yeni = new Dugum(X,Y,Z);
        son->sonraki = yeni;
        son = yeni;
    }
    noktasayisi++;
}
Dugum* DogruKuyrugu::enYuksekOnceki()
{
    if(ilk==0) return 0;
    Dugum* gec = ilk;
    Dugum* onceki = 0;
    int enKucuk = gec->orjin;

    while (gec->sonraki != 0)
    {
        if (gec->sonraki->orjin < enKucuk)
        {
            enKucuk = gec->sonraki->orjin;
            onceki = gec;
        }
        gec = gec->sonraki;
        
    }
    return onceki;
}
void DogruKuyrugu::enYuksekCikar()
{
    Dugum* onceki = enYuksekOnceki();
    if (onceki)
    {
        if (onceki->sonraki == son)
        {
            son = onceki;
        }
        Dugum* sil = onceki->sonraki;
        onceki->sonraki = sil->sonraki;
        delete sil;
    }
    else
    {
        if (ilk == 0) return;
        Dugum* sil = ilk;
        ilk = ilk->sonraki;
        delete sil;
    }
    
}
int DogruKuyrugu::enKucukGetir()
{
    Dugum* onceki = enYuksekOnceki();
    if(onceki)
        return onceki->sonraki->orjin;
    
    if (ilk != 0 )
    {
        return ilk->orjin;
    }
    throw std::out_of_range("Kuyruk Bos");
}

std::ostream& operator<<(std::ostream& os, DogruKuyrugu& kuyruk)
{
    using namespace std;
    cout<<"Toplam Uzunluk: "<<kuyruk.toplamuzunluk<<endl;
    for (int i = 0; i < kuyruk.noktasayisi; i++)
    {
        cout<<i+1<<". Nokta Orjin Uzakligi: "<<kuyruk.enKucukGetir()<<endl;
        kuyruk.enYuksekCikar();
    }
    cout<<"--------------------------------"<<endl;
    

}
