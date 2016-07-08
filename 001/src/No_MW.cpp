#include "No_MW.h"

No_MW::No_MW()
{
    this->caracter = new No_MW*[this->tamAlfabeto];
    this->ehChave = false;
    for(int i = 0; i < this->tamAlfabeto ; i++){
       // this->caracter[i] = 1;
    }
}

No_MW::~No_MW()
{
    //dtor
}

void No_MW::setEhChave(bool ehChave){
    this->ehChave = ehChave;
}

