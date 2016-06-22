#include "SplayTree.h"
#include "No_Splay.h"

SplayTree::SplayTree()
{
    //ctor
}

SplayTree::~SplayTree()
{
    //dtor
}

void SplayTree:: insertNo(string palavra)
{
    No_Splay *novo = new No_Splay;
    novo = busca(this->raiz,palavra);
    if(novo == NULL)
        novo->setPalavra(palavra);
    //return novo;

}

No_Splay* SplayTree:: busca(No_Splay* raiz,string palavra)
{
    splay(raiz,palavra);
}

No_Splay* SplayTree:: splay(No_Splay* raiz, string palavra)
{
    if(!raiz)
        return NULL;
    No_Splay aux ;
    aux.setDir(NULL);
    aux.setEsq(NULL);
    No_Splay* ArvDir = &aux;
    No_Splay* ArvEsq = &aux;

    while(1)
    {
        if(palavra < raiz->getPalavra())
        {
            if(!raiz->getEsq())
                break;
            if(palavra < raiz->getEsq()->getPalavra())
            {
                raiz = zigDIR(raiz);
                if(!raiz->getEsq())
                    break;
            }
            ArvDir->setEsq(raiz);
            ArvDir = ArvDir->getEsq();
            raiz = raiz->getEsq();
            ArvDir->setEsq(NULL);
        }

        else if(palavra > raiz->getPalavra())
        {
            if(!raiz->getDir())
                break;
            if(palavra > raiz->getDir()->getPalavra())
            {
                raiz = zigESQ(raiz);
                if(!raiz->getDir())
                    break;
            }
            ArvEsq->setDir(raiz);
            ArvEsq = ArvEsq->getDir();
            raiz = raiz->getDir();
            ArvEsq->setDir(NULL);
        }
        else
            break;

    }
    ArvEsq->setDir(raiz->getEsq());
    ArvEsq->setEsq(raiz->getDir());
    raiz->setEsq(aux.getDir());
    raiz->setDir(aux.getEsq());

    return raiz;


}

No_Splay* SplayTree:: zigDIR(No_Splay * x)
{
    No_Splay * aux = x->getEsq();
    x->setEsq(aux->getEsq());
    aux->setDir(x);
    return aux;
}
No_Splay*  SplayTree:: zigESQ(No_Splay * x)
{

    No_Splay * aux = x->getDir();
    x->setDir(aux->getDir());
    aux->setEsq(x);
    return aux;
}

