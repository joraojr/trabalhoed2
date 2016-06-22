#include "No_Splay.h"


class SplayTree
{
public:
    SplayTree();
    ~SplayTree();
    void insertNo(string palavra);
    No_Splay* busca(No_Splay* raiz,string palavra);
    No_Splay* getRaiz(){return this->raiz;}
private:
    No_Splay* raiz;
    No_Splay* zigDIR(No_Splay * x);
    No_Splay* zigESQ(No_Splay * x);
    No_Splay* splay(No_Splay* raiz,string palavra);


};


