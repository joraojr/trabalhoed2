#include <iostream>
#include <fstream>
#include <string>
#include "SplayTree.h"
#include "No_Splay.h"

using namespace std;

int main()
{
    SplayTree Arvore;

    /** COLOCAR EM UMA FUNCAO **/
  string line;
  ifstream myfile ("/home/jorao/Documentos/trabalhoed2/001/Dicionarios/x.txt"); // ifstream = padrão ios:in
  if (myfile.is_open())
  {
    while (! myfile.eof() ) //enquanto end of file for false continua
    {
      getline (myfile,line); // como foi aberto em modo texto(padrão)
                             //e não binário(ios::bin) pega cada linha

      cout << line << endl;
     Arvore.insertNo("a");
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  /********************************************************************/
    return 0;
}
