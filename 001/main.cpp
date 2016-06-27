#include <iostream>
#include <fstream>
#include <string>
#include "SplayTree.h"


using namespace std;

int main()
{
    SplayTree Arvore;
    /*
    string X ="Teste";
    string y = "teste2";
    Arvore.insertNo(X);
    Arvore.insertNo(y);
    Arvore.imprimeArvore();
    */

    /**COLOCAR EM UMA FUNCAO **/
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
    /********************************************************************/
    cout << Arvore.raiz->getDir()->getDir()->getPai()->getPalavra();

    return 0;
}
