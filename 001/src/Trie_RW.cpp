#include "Trie_RW.h"
#include <iostream>>
Trie_RW::Trie_RW()
{
    this->raiz = new No_RW;
}

Trie_RW::~Trie_RW()
{
    //dtor
}

bool Trie_RW::buscaPalavra(char *c)
{
    int pos = 0;
    int tam =  1;//mudar

    return buscaPalavraAux(c,this->raiz,tam,pos);
}
bool Trie_RW::buscaPalavraAux(char *c, No_RW * raiz, int tam, int pos)
{
    if(raiz->getCaracter(c[pos]) == NULL)
        return false;
    if(pos == tam)
        return raiz->getCaracter(c[pos])->getEhChave();
    else
    {
        return buscaPalavraAux(c,raiz->getCaracter(c[pos]),tam,pos +1 );
    }
}

void Trie_RW::inserePalavra(char *c)
{
    if(this->buscaPalavra(c))
    {
        std::cout<< "Estou aqui"<<std::endl;
        return ;
    }
    else
    {
        int tam = 1;
        int pos =0;
        inserePalavraAux(c,this->raiz, tam, pos);
    }
}

void Trie_RW::inserePalavraAux(char *c ,No_RW* raiz,int tam, int pos)
{

    if(raiz->getCaracter(c[pos]) == NULL)
    {

        raiz->setCaracter(c[pos]);
        std::cout<<"Inserindo "<<c[pos]<<std::endl;

    }
    if(pos == tam)
    {
        raiz->getCaracter(c[pos])->setEhChave();
    }
    else
    {
        this->inserePalavraAux(c,raiz->getCaracter(c[pos]),tam, pos +1);
    }

    return ;
}
