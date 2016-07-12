#ifndef LISTAENCD_H
#define LISTAENCD_H
#include <No_Lista.h>
using namespace std;

typedef struct No_Livros
{
    string livro;
    No_Livros * prox;
} No_Livros;//Cria um struct para Lista de livros

class ListaEncd // É utilizada para adicionar os livros e os dicionarios em um diretorio
{
public:
    ListaEncd();
    ~ListaEncd();
    No_Livros * getRaiz();
    void insereLista(string livro);
    bool buscaLista(string livro);
    void imprimeLista();
private:
    No_Livros * raiz; // Pontero para o primeiro nó da lista
};

#endif // LISTAENCD_H
