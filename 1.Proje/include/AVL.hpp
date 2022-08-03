#ifndef AVL_HPP
#define AVL_HPP
#include "DogruKuyrugu.hpp"
class AVL
{
public:
    AVL();
    ~AVL();
    void Ekle(int toplamuzaklik,DogruKuyrugu* kuyruk);
    void postOrder();
    bool bosmu();
    int yukseklik();
    void temizle();
private:
    
    int yukseklik(DogruKuyrugu* aktif);
    void postOrder(DogruKuyrugu* aktif);
    bool silDugum(DogruKuyrugu* &aktif);
    DogruKuyrugu* ekle(int toplamuzaklik,DogruKuyrugu* kuyruk, DogruKuyrugu* aktif);
    DogruKuyrugu* solCocukile(DogruKuyrugu* kuyruk);
    DogruKuyrugu* sagCocukile(DogruKuyrugu* kuyruk);
    DogruKuyrugu* kok;
};
#endif