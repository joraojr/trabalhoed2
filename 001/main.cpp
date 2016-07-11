#include <iostream>
#include <fstream>
#include <string>
#include "SplayTree.h"
#include "Trie_RW.h"

using namespace std;

int main()
{



    Trie_RW Trie;

    string line;
    ifstream myfile ("/home/jorao/Documentos/trabalhoed2/001/Dicionarios/novos/dic2"); // ifstream = padrão ios:in
    if (myfile.is_open())
    {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line); // como foi aberto em modo texto(padrão)
            //e não binário(ios::bin) pega cada linha
            //string x ="abcèé";

            unsigned int x =line[0];
            //cout << line <<" "<<x<<" "<< line.size()<<endl;
            //string z =line;
            if(line.size() > 0)
            {
                //int x =line[1];
                //cout <<x;
                Trie.inserePalavra(line);

            }

            //cout << Arvore.busca(line)<<endl;
        }



        myfile.close();
    }
    cout<<"TAqui"<<Trie.buscaPalavra("abcde");

    /********************************************************************
    cout << Arvore.raiz->getDir()->getDir()->getPai()->getPalavra();
    Arvore.imprimeArvore();

    return 0;
    /*

    Trie_RW Trie;
    char c[] ={'a','b'};
    char x[] ={'ç','x','a'};
    unsigned char a[] = {'Ç','à','ç'};
    unsigned char h = a[0];
    string m = "aaaàrè";

    int z= a[0];
    int y=a[1];
    int b=a[2];
    //if(h == 'è')
    cout<<z<<endl;
    cout<<y<<endl;
    cout<<b<<endl;
    cout<<m.size()<<endl;
    //    cout<<
    Trie.inserePalavra(x);
    cout<<Trie.buscaPalavra(x);


    */










}
