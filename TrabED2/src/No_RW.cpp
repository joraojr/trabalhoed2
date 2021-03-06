#include "No_RW.h"
#include <iostream>

No_RW::No_RW()
{
    this->caractere = new No_RW * [this->tamAlfabeto];
    this->ehChave = false;
    for(int i = 0; i< this->tamAlfabeto; i++)
    {
        this->caractere[i] = NULL;
    }
    this->caracteresEspeciais = new No_Lista;

}

No_RW::~No_RW()
{
    //dtor
}


bool No_RW::getEhChave()
{
    return this->ehChave; // Retorna se é uma palavra
}

void No_RW::setEhChave()
{
    this->ehChave = true; // Set o final de uma palavra
}

No_RW * No_RW::getCaracter(char c)
{
    return this->caractere[c - 97];
}

void No_RW::setCaracter(char c)
{
    int pos = (c - 97);// pos no vetor referente a tabela ascii
    if(this->caractere[pos] == NULL)
    {
        this->caractere[pos] = new No_RW [this->tamAlfabeto];
    }
}


void No_RW::insereLista(char c)// Insere na Lista encadeada (caracteres especiais)
{
    No_Lista* p = new No_Lista;
    No_RW* f = new No_RW;

    p->setCaractereEspecial(c);
    p->setFilho(f);
    p->setProx(this->caracteresEspeciais);

    this->caracteresEspeciais = p;
}

No_Lista* No_RW::buscaLista(char c) // Busca na Lista encadeada (caracteres especiais)
{
    No_Lista * aux = this->caracteresEspeciais;

    while(aux != NULL)
    {
        if(aux->getCaractereEspecial() == c)
            break;
        aux = aux->getProx();
    }

    return aux;
}

No_Lista* No_RW::getCaracteresEspeciais()
{
    return this->caracteresEspeciais;
}









