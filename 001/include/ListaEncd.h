#ifndef LISTAENCD_H
#define LISTAENCD_H
#include <No_Lista.h>

class ListaEncd
{
public:
    ListaEncd();
    ~ListaEncd();
    No_Lista * getRaiz();
    void insereLista(char c);
    bool buscaLista(char c);
private:
    No_Lista* raiz;
};

#endif // LISTAENCD_H
