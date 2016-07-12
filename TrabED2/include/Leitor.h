#ifndef LEITOR_H
#define LEITOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <dirent.h>
#include <algorithm>
#include <ctime>
#include "ListaEncd.h";
#include "Trie_RW.h"
#include "HashTable.h";
#include "Estrutura.h";
using namespace std;

class Leitor
{
public:
    Leitor();
    ~Leitor();
    void insereEstrura(int metodo);//Verifica qual a estrutura será utilizada.
    void lerLivro(Estrutura * estrutura);// Realiza a leituras dos Livros.
private:
    HashTable * hashing;
    Trie_RW * trie_rw;
    ListaEncd* abrirDiretorio(string diretorio); // Abre um diretorio e cria uma lista encadeda contendo todos os arquivos dentro dele.
    void insereArvore(); // Inserção do dicionário na Trie_RW
    void insereHash(); // Inserção do dicionário na Tabela de Hash

};

#endif // LEITOR_H
