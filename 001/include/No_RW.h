#ifndef NO_RW_H
#define NO_RW_H
#include <No_Lista.h>

/** Criar  NORMALIZAÇÃO ( TO UPPER OR TO LOWER) */
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
    bool buscaLista(char c);
    //ListaEncd* getCaracteresEspeciais();
    bool getEhChave();
private:
    No_RW ** caractere;
    No_Lista* caracteresEspeciais;
    //ListaEncd* caracteresEspeciais;
    int tamAlfabeto = 27;
    bool ehChave;




};

#endif // NO_RW_H
