#ifndef NO_LISTA_H
#define NO_LISTA_H
#include <iostream>

class No_RW;
class No_Lista
{
public:
    No_Lista()
    {
        this->prox = NULL;
        this->filho = NULL;
    };
    ~No_Lista();

    void setCaractereEspecial(char c)
    {
        this->caractereEspecial = c;
    };
    char getCaractereEspecial()
    {
        return this->caractereEspecial;
    };
    void setProx(No_Lista* prox)
    {
        this->prox = prox;
    }
    No_Lista* getProx()
    {
        return this->prox;
    };
    No_RW* getFilho()
    {
        return this->filho;
    };
    void setFilho(No_RW* filho){
        this->filho = filho;
    };
private:
    No_Lista* prox;
    char caractereEspecial;
    No_RW* filho;
};

#endif // NO_LISTA_H
