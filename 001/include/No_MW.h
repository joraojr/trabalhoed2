#ifndef NO_MW_H
#define NO_MW_H

//crias lista encadeada para os caracteres especias
//procurar t-string ou t-char para usa encode


class No_MW
{
public:
    No_MW();
    ~No_MW();
    void setCaracter(char caracter);
    void setEhChave(bool ehChave);
    No_MW* getCaracter();
    bool getEhChave();

private:
    bool ehChave;
    No_MW ** caracter;
    int tamAlfabeto = 27;


};

#endif // NO_MW_H
