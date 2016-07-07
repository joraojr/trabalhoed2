#ifndef TRIE_RW_H
#define TRIE_RW_H
#include <No_RW.h>
#include <iostream>


class Trie_RW
{
public:
    Trie_RW();
    ~Trie_RW();
    bool buscaPalavra(char* c);
    void inserePalavra(char* c);
private:
    No_RW* raiz;
    bool buscaPalavraAux(char *c,No_RW * raiz, int tam, int pos);
    void inserePalavraAux(char *c, No_RW* raiz, int tam,int pos);
};

#endif // TRIE_RW_H
