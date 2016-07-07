#include "ListaEncd.h"

ListaEncd::ListaEncd()
{
    this->raiz = new No_Lista;
}

ListaEncd::~ListaEncd()
{
    //dtor
}

No_Lista* ListaEncd::getRaiz()
{
    return this->raiz;
}

void ListaEncd::insereLista(char c)
{
    No_Lista* p = new No_Lista;
    //No_RW* f = new No_RW;

    p->setCaractereEspecial(c);
    //p->setFilho(f);
    p->setProx(this->raiz);

    this->raiz = p;
}

bool ListaEncd::buscaLista(char c)
{
    No_Lista * aux = this->raiz;

    while(aux != NULL)
    {
        if(aux->getCaractereEspecial() == c)
            return true;
        aux = aux->getProx();
    }

    return false;
}

