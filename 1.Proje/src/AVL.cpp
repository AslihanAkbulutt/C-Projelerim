#include <algorithm>
#include <iostream>
#include "AVL.hpp"

AVL::AVL()
{
    kok = 0;
}
AVL::~AVL()
{
    temizle();
}
void AVL::Ekle(int toplamuzaklik, DogruKuyrugu* kuyruk)
{
    kok = ekle(toplamuzaklik,kuyruk,kok);
}
void AVL::postOrder()
{
    postOrder(kok);
}
bool AVL::bosmu()
{
    return kok == 0;
}
int AVL::yukseklik()
{
    return yukseklik(kok);
}
void AVL::temizle()
{
    while(!bosmu()) silDugum(kok);
}
int AVL::yukseklik(DogruKuyrugu* aktif)
{
    if (aktif)
    {
        return 1+std::max(yukseklik(aktif->sol),yukseklik(aktif->sag));
    }
    return -1;
}

void AVL::postOrder(DogruKuyrugu* aktif)
{
    if (aktif)
    {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        std::cout<<*aktif;
    }
    
}
bool AVL::silDugum(DogruKuyrugu* &aktif)
{
    DogruKuyrugu* sil = aktif;
    if(aktif->sag == 0) aktif = aktif->sol;
    else if(aktif->sol == 0) aktif = aktif->sag;
    else
    {
        sil = aktif->sol;
        DogruKuyrugu* root = aktif;
        while (sil->sag != 0)
        {
            root = sil;
            sil = sil->sag;
        }
        aktif->toplamuzunluk = sil->toplamuzunluk;
        if (root == aktif) aktif->sol =sil->sol;
        else root->sag = sil->sol;        
    }
    delete sil;
    return true;
}
DogruKuyrugu* AVL::ekle(int toplamuzak,DogruKuyrugu* kuyruk, DogruKuyrugu* aktif)
{
    if (aktif == 0) 
    {
        aktif = kuyruk;
    }
    else if ((toplamuzak <= aktif->toplamuzunluk))
    {
        aktif->sol = ekle(toplamuzak, kuyruk, aktif->sol);
        if (yukseklik(aktif->sol)-yukseklik(aktif->sag)==2)
        {
            //sol sol durumu
            if (toplamuzak <= aktif->sol->toplamuzunluk)
            {
                aktif = solCocukile(aktif);
            }
            else
            {
                //sol sag durumu
                aktif->sol = sagCocukile(aktif->sol);
                aktif = solCocukile(aktif);
            }
        }
        
    }
    
    else if (toplamuzak > aktif->toplamuzunluk)
    {
        aktif->sag = ekle(toplamuzak,kuyruk, aktif->sag); 
        if (yukseklik(aktif->sag)-yukseklik(aktif->sol)==2)
        {
            if (toplamuzak > aktif->sag->toplamuzunluk)
            {
                aktif = sagCocukile(aktif);
            }
            else
            {
                aktif->sag = solCocukile(aktif->sag);
                aktif = sagCocukile(aktif);
            }
        }
       
    }

    return aktif; 
}
DogruKuyrugu* AVL::solCocukile(DogruKuyrugu* kuyruk)
{
    DogruKuyrugu* temp = kuyruk->sol;
    kuyruk->sol = temp->sag;
    temp->sag = kuyruk;
   
    return temp;
}
DogruKuyrugu* AVL::sagCocukile(DogruKuyrugu* kuyruk)
{
    DogruKuyrugu* temp = kuyruk->sag;
    kuyruk->sag = temp->sol;
    temp->sol = kuyruk;
    
    return temp;
}