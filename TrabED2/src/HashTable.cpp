#include <iostream>
#include <string>
using namespace std;
#include "HashTable.h"

HashTable::HashTable(int metodos)
{
    this->metodo=metodos;
    this->inserindo=false;
    this->colidiu=false;
    this->colisoes=0;
    this->NuPaCo=0;
    this->ehArvore=false;
    for (int i=0; i<TAMA; i++) //inicializa a hashtable com "_NADA_" para poder vericar se a posição esta vazia
        dicionario[i]="_NADA_";
}

// retorna o local baseado na chave
unsigned int HashTable::hash( string chave )
{
    unsigned int value=0;
    unsigned int tam=chave.length(); //verifica o tamanho da palavra que sera inserida
    unsigned int index;
    while(1)
    {
        if (metodo==1)              //verica se sera utilizada a primeira função de hash
        {
            for ( int i = 0; i < tam; i++ )
                value += chave[i];  //calcula a posição
            index=(value *tam) % TAMA;
        }
        else if(metodo==2)          //verica se sera utilizada a segunda função de hash
        {
            for (int i = 0; i < tam; i++)
            {
                value =(value*33)^(unsigned int)chave[i]; //calcula a posição
            }
            index= value % TAMA;
        }
        else                      //utiliza a terceira função de hash como padrão
        {
            for (int i = 0; i < tam; i++)
            {
                value = value*101+chave[i];   //calcula a posição
            }
            index= value % TAMA;
        }
        if((dicionario[index]=="_NADA_")||(dicionario[index]==chave))  //verifica se a posição esta livre pra incerção ou com a palavra desejada na busca
        {
            return index;
        }
        else   // retorna ao incio para poder fazer o rehash
        {
            if(inserindo)
            {
                colisoes++;
                colidiu=true;
            }
        }
    }
}

// insere na tabela de Hash
bool HashTable::insere( string novaPalavra )
{
    if(procura(novaPalavra))  // Busca a palavra antes, para não inserir termos repetidamente
    {
        return false;
    }
    inserindo=true;
    unsigned int index = hash(novaPalavra); // faz o hash e armazena a posição da palavra
    dicionario[index] = novaPalavra; // insere a palavra em sua devida posição
    inserindo=false;
    if(colidiu)
        NuPaCo++;
    colidiu=false;
    return true;
}
bool HashTable::procura( string Palavrachave )
{
    unsigned int index = hash(Palavrachave); // faz o hash da palavra para achar sua suposta posição
    if (dicionario[index]==Palavrachave) // se na suposta posição da palavra ela estiver presente retorna verdadeiro
        return true;
    else
        return false;
}

HashTable::~HashTable()
{
}
