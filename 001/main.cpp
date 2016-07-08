#include <iostream>
#include <fstream>
#include <string>
#include "SplayTree.h"
#include "Trie_RW.h"
#include <cwchar>

using namespace std;

int main()
{
    /*
    SplayTree Arvore;

    string X ="Teste";
    string y = "teste2";
    Arvore.insertNo(X);
    Arvore.insertNo(y);
    Arvore.imprimeArvore();


    **COLOCAR EM UMA FUNCAO **
    string line;
    ifstream myfile ("/home/jorao/Documentos/trabalhoed2/001/Dicionarios/teste.txt"); // ifstream = padrão ios:in
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            //e não binário(ios::bin) pega cada linha

            //cout << line << endl;
            Arvore.insertNo(line);
            //cout << Arvore.busca(line)<<endl;
        }
        Arvore.imprimeArvore();

        myfile.close();
    }

    else cout << "Unable to open file";
    /********************************************************************
    cout << Arvore.raiz->getDir()->getDir()->getPai()->getPalavra();
    Arvore.imprimeArvore();

    return 0;
    */

    Trie_RW Trie;
    char c[] ={'a','b'};
    char x[] ={'ç','x','a'};
    string a = "èèè";
    unsigned wchar_t h = a[0];

    unsigned int z= h;
    unsigned int y=a[1];
    unsigned int b=a[2];
    if(h == 'è')
    cout<<z<<endl;
    cout<<y<<endl;
    cout<<b<<endl;
    Trie.inserePalavra(x);
    cout<<Trie.buscaPalavra(x);













}
