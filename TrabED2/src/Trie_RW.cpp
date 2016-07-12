#include "Trie_RW.h"
#include <iostream>>
Trie_RW::Trie_RW()
{
    this->raiz = new No_RW;
    this->ehArvore = true;
}

Trie_RW::~Trie_RW()
{
    //dtor
}

bool Trie_RW::verificaAlfabeto(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool Trie_RW::buscaPalavra(string c)
{

    int pos = 0;
    int tam =  c.size() -1;//mudar
    return buscaPalavraAux(c,this->raiz,tam,pos);
}



bool Trie_RW::buscaPalavraAux(string c, No_RW * raiz, int tam, int pos)
{
    if(verificaAlfabeto(c[pos]))//Está no vetor, Caracter normal
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
    else //Caracter Especial , verificamos a ListaEncadeada
    {

        No_Lista* aux = raiz->buscaLista(c[pos]);
        if(aux == NULL)
            return false;
        if(tam == pos)
            return aux->getFilho()->getEhChave();
        else
            return(c,aux->getFilho(),tam,pos +1);

    }

}

void Trie_RW::inserePalavra(string c)
{
    if(this->buscaPalavra(c))
    {
        return ;
    }
    else
    {
        int tam = c.size() -1;
        int pos =0;
        inserePalavraAux(c,this->raiz, tam, pos);
    }
}

void Trie_RW::inserePalavraAux(string c ,No_RW* raiz,int tam, int pos)
{
    if(verificaAlfabeto(c[pos]))
    {

        if(raiz->getCaracter(c[pos]) == NULL)
        {

            raiz->setCaracter(c[pos]);


        }
        if(pos == tam)
        {
            // std::cout<<"Inserindo chave "<<c[pos]<<std::endl;
            raiz->getCaracter(c[pos])->setEhChave();
        }
        else
        {
            this->inserePalavraAux(c,raiz->getCaracter(c[pos]),tam, pos +1);
        }
    }
    else
    {

        //std::cout <<"Inserindo Lista  "<<c[pos] << pos <<std::endl;
        raiz->insereLista(c[pos]);
        if(pos == tam)
        {
            //   std::cout << "Inserindo chave   "<<c[pos]<<std::endl;
            raiz->getCaracteresEspeciais()->getFilho()->setEhChave();
        }
        else
        {
            this->inserePalavraAux(c,raiz->getCaracteresEspeciais()->getFilho(),tam,pos +1);
        }


    }


    return ;
}
