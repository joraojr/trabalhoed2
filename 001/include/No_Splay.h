#include <string>
using std::string;
#ifndef NO_SPLAY_H
#define NO_SPLAY_H



class No_Splay
{
public:
    No_Splay()
    {
        this->esq = NULL;
        this->dir = NULL;
        this->pai = NULL;
    };
    ~No_Splay();
    No_Splay*  getDir()
    {
        return this->dir;
    }
    No_Splay* getEsq()
    {
        return this->esq;
    }
    No_Splay* getPai()
    {
        return this->pai;
    }
    string getPalavra()
    {
        return this->palavra;
    }
    void setDir(No_Splay* dir)
    {
        this->dir = dir;
    }
    void setEsq(No_Splay* esq)
    {
        this->esq = esq;
    }
    void setPai(No_Splay* pai)
    {
        this->pai = pai;
    }
    void setPalavra(string palavra)
    {
        this->palavra = palavra;
    }

private:
    string palavra;
    No_Splay * dir;
    No_Splay * esq;
    No_Splay * pai;
};

#endif // NO_SPLAY_Hzzzzz
