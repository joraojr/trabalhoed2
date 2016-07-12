#ifndef ESTRUTURA_H
#define ESTRUTURA_H

class Estrutura
{
    //Classe 'mãe' das estruturas.
    //É utilizada apenas para que as classes hererdeiras possam ser identificadas como Arvore ou Hash.
public:
    Estrutura();
    virtual ~Estrutura();
    bool ehArvore; // Atributo para verificar se é Arvore ou não
private:
};

#endif // ESTRUTURA_H
