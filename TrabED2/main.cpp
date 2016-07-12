#include <iostream>
#include <string>
#include "Leitor.h"
using namespace std;


int main()
{
    Leitor leitor; // Declara um Leitor que posui as funções principais do trabalho.
    //Inicialização do Menu.
    cout<<"Qual método? "<<endl<<"1-Hash"<<endl<<"2-Árvore"<<endl;
    int metodo;
    cin>> metodo;
    while(metodo != 1 && metodo != 2 )
    {
        cout << "Metodo invalido"<<endl<<"Qual método? "<<endl<<"1-Hash"<<endl<<"2-Árvore"<<endl;
        cin >> metodo;
    }
    leitor.insereEstrura(metodo);
}
