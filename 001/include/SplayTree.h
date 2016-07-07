#include <iostream>>
#include "No_Splay.h"


class SplayTree
{
public:
    SplayTree();
    ~SplayTree();
    void insertNo(string palavra);
    bool busca(string palavra);
    void imprimeArvore();
    string getRaiz()
    {
        return this->raiz->getPalavra();
    }
    No_Splay* raiz;
private:

    No_Splay* insertNoAux(string palavra, No_Splay* raiz);
    bool buscaAux(string palavra, No_Splay* aux);
    void imprimeArvoreAux(No_Splay * raiz);
    void zigDIR(No_Splay * x);
    void zigESQ(No_Splay * x);
    void splay(No_Splay* x);


};


