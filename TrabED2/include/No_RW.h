#ifndef NO_RW_H
#define NO_RW_H
#include <string>
#include "No_Lista.h"

class No_Lista;
class No_RW
{
public:
    No_RW();
    ~No_RW();
    void setCaracter(char c);
    void setEhChave();
    No_RW * getCaracter(char c);
    void insereLista(char c);
    No_Lista* buscaLista(char c);
    No_Lista* getCaracteresEspeciais();
    bool getEhChave();
private:
    No_RW ** caractere; // Vetor de caracteres
    No_Lista* caracteresEspeciais; // Lista encadeada com caracteres especiais
    int tamAlfabeto = 27; // Tamanho do vetor
    bool ehChave; // Final da palavra




};

#endif // NO_RW_H
