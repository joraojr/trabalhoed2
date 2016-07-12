#ifndef HashTable_h
#define HashTable_h
#define TAMA 499979
#include <string>
#include "Estrutura.h"

using namespace std;

class HashTable: public Estrutura
{
private:
    string dicionario[TAMA];// Vetor onde são armazenadas as palavras
    bool inserindo,colidiu; // verifica se tem uma colisão acontecendo e se esta inserindo
    int tamanho=TAMA; //tamanho do vetor
    int metodo; // verifica qual a função de hash que sera utilizada
    unsigned int hash( string palavraKey ); //realiza as funções de hash

public:
    int colisoes,NuPaCo; //contadores de colisoes e de palavras que colidiram
    HashTable(int metodos); // inicializa a tabela de hash
    bool insere(string novaPalavra ); //função que insere uma palavra na tabela
    bool procura( string PalavraKey ); //função de buscar palavra na tabela
    ~HashTable();
};

#endif
