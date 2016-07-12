#include "ListaEncd.h"

ListaEncd::ListaEncd()
{
    this->raiz = NULL;
}

ListaEncd::~ListaEncd()
{
    No_Livros * aux;
    while(this->raiz)
    {
        aux = this->raiz;
        this->raiz = this->raiz->prox;
        delete [] aux;
    }
}

No_Livros* ListaEncd::getRaiz()
{
    return this->raiz;
}

void ListaEncd::insereLista(string livro)
{
    //Insere no inicio da lista
    No_Livros* p = new No_Livros;

    p->livro = livro;
    p->prox = raiz;

    this->raiz = p;
}

bool ListaEncd::buscaLista(string  livro)
{
    No_Livros * aux = this->raiz;

    while(aux != NULL)
    {
        if(aux->livro == livro)
            return true;
        aux = aux->prox;
    }

    return false;
}

void ListaEncd::imprimeLista()
{
    while(raiz->prox != NULL)
    {
        cout << raiz->livro<<endl;
        raiz = raiz->prox;
    }

}
