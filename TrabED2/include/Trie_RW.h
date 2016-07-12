#ifndef TRIE_RW_H
#define TRIE_RW_H
#include "No_RW.h"
#include "Estrutura.h"
#include <iostream>
using std::string;



class Trie_RW : public Estrutura
{
public:
    Trie_RW();
    ~Trie_RW();
    bool buscaPalavra(string c);
    void inserePalavra(string c);
private:
    No_RW* raiz;
    bool buscaPalavraAux(string c,No_RW * raiz, int tam, int pos);
    void inserePalavraAux(string c, No_RW* raiz, int tam,int pos);
    bool verificaAlfabeto(char c);
    //string normalizaString(string palavra);
};

#endif // TRIE_RW_H
