#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    /** COLOCAR EM UMA FUNCAO **/
  string line;
  ifstream myfile ("/home/get01/Documentos/palavras.ispell.txt"); // ifstream = padrão ios:in
  if (myfile.is_open())
  {
    while (! myfile.eof() ) //enquanto end of file for false continua
    {
      getline (myfile,line); // como foi aberto em modo texto(padrão)
                             //e não binário(ios::bin) pega cada linha
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  /********************************************************************/
    return 0;
}
