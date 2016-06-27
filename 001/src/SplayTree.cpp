#include "SplayTree.h"


SplayTree::SplayTree()
{
    this->raiz = NULL;
}

SplayTree::~SplayTree()
{
    //dtor
}



void SplayTree::insertNo(string palavra)
{
    No_Splay* aux = this->raiz;
    No_Splay* ant = NULL;
    while(aux != NULL)
    {
        ant = aux;
        if(palavra > aux->getPalavra())
            aux = aux->getDir();
        else if (palavra < aux->getPalavra())
            aux = aux->getEsq();
    }

    No_Splay * novo = new No_Splay;
    novo->setPalavra(palavra);

    novo->setPai(ant);

    if(ant == NULL)
    {
        this->raiz = novo;
    }
    else if(palavra >ant->getPalavra())
    {
        ant->setDir(novo);
    }
    else if(palavra < ant->getPalavra())
    {
        ant->setEsq(novo);
    }


}


bool SplayTree::busca(string palavra)
{
    return buscaAux(palavra, this->raiz);
}

bool SplayTree::buscaAux(string palavra, No_Splay * raiz)
{
    if(raiz == NULL)
    {
        //splay(raiz);
        return false;
    }
    else if(raiz->getPalavra() == palavra)
    {
        splay(raiz);
        return true;
    }
    else if(palavra > raiz->getPalavra())
    {

        return buscaAux(palavra,raiz->getDir());
    }
    else if(palavra < raiz->getPalavra())
    {
        return buscaAux(palavra, raiz->getDir());
    }
}


void SplayTree::imprimeArvore()
{
    imprimeArvoreAux(this->raiz);

}
void SplayTree::imprimeArvoreAux(No_Splay * raiz)
{
    // EM ORDEM ... CARACTERES ESPECIAIS VAO PARA O FINAL DA ARVORE
    if(raiz != NULL)
    {
        imprimeArvoreAux(raiz->getEsq());
        std::cout << raiz->getPalavra()<<std::endl;
        imprimeArvoreAux(raiz->getDir());
    }

}



void SplayTree::splay(No_Splay * x)
{
    while(x->getPai() != NULL)
    {
        if(x->getPai()->getPai() == NULL)
        {
            if(x->getPai()->getEsq() == x)
            {
                zigDIR(x);
            }
            else
                zigESQ(x);
        }

        else if (x->getPai()->getEsq() == x && x->getPai()->getPai()->getEsq() == x->getPai())
        {
            zigDIR(x->getPai()->getPai());
            zigDIR(x->getPai());
        }
        else if (x->getPai()->getDir() == x && x->getPai()->getPai()->getDir() == x->getPai())
        {
            zigESQ(x->getPai()->getPai())   ;
            zigESQ(x->getPai());
        }
        else if(x->getPai()->getEsq() == x && x->getPai()->getPai()->getDir() == x->getPai())
        {
            zigDIR(x->getPai());
            zigESQ(x->getPai());
        }
        else
        {
            zigESQ(x->getPai());
            zigDIR(x->getPai());
        }



    }
}

void SplayTree:: zigDIR(No_Splay * x)
{

    No_Splay * aux = x->getPai();
    aux->setEsq(x->getDir());
    if(aux->getPai() != NULL)
        aux->getPai()->setEsq(x);
    else
        this->raiz = x;
    x->setPai(aux->getPai());
    aux->setPai(x);
    x->setDir(aux);
}
void  SplayTree:: zigESQ(No_Splay * x)
{

    No_Splay * aux = x->getPai();
    aux->setDir(x->getEsq());
    if(aux->getPai() != NULL)
        aux->getPai()->setDir(x);
    else
        this->raiz = x;
    x->setPai(aux->getPai());
    aux->setPai(x);
    x->setEsq(aux);
}

