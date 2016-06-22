#include <string>
using std::string;
#ifndef NO_SPLAY_H
#define NO_SPLAY_H



class No_Splay
{
public:
    No_Splay(){this->DIR = NULL; this->ESQ = NULL;};
    ~No_Splay();
    No_Splay*  getDir(){return this->DIR;}
    No_Splay* getEsq(){return this->ESQ;}
    string getPalavra(){return this->palavra;}
    void setDir(No_Splay* DIR){ this->DIR = DIR;}
    void setEsq(No_Splay* ESQ){this->ESQ = ESQ;}
    void setPalavra(string palavra){this->palavra = palavra;}

private:
    string palavra;
    No_Splay * DIR;
    No_Splay * ESQ;
};

#endif // NO_SPLAY_Hzzzzz
