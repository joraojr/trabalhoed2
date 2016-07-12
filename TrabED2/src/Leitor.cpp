#include "Leitor.h"

Leitor::Leitor()
{
    //ctor
}

Leitor::~Leitor()
{
    //dtor
}

ListaEncd * Leitor::abrirDiretorio(string diretorio)
{
    ListaEncd *livros = new ListaEncd;//Criação da lista encadeada.

    DIR *dir;
    dirent *lsdir;

    dir = opendir(diretorio.c_str());
    while((lsdir = readdir(dir)) != NULL)
    {
        //Leitura do diretório
        string palavra(lsdir->d_name);
        if(palavra != "." && palavra != "..")
        {
            livros->insereLista(palavra);
        }
    }
    closedir(dir);
    return livros;
}

void Leitor::insereEstrura(int metodo)
{
    if(metodo == 1)//Escolha do método de Hash
    {
        insereHash();// Inserção na tabelda de Hash
        lerLivro(this->hashing); // Leitura dos livros e utilização da tabela de Hash
    }
    if(metodo == 2)//Escolha da Trie_RW
    {
        insereArvore();// Inserção na Trie_RW
        lerLivro(this->trie_rw); // Leitura dos livros e utilização da Trie_RW
    }

}


void Leitor:: insereArvore()
{
    Trie_RW *trie_rw  = new Trie_RW; // Instanciar a Trie_RW
    string diretorio;

    cout<<"Qual o diretorio dos dicionarios ?"<<endl;
    cin >> diretorio;

    ListaEncd* dicionarios = abrirDiretorio(diretorio); // Lê os arquivos dentro do diretorio
    No_Livros* aux = dicionarios->getRaiz();// Cria um ponteiro para o primeiro nó da Lista

    string line;
    while(aux)//Enquanto aux for diferente de NULL, faça
    {
        ifstream myfile ((diretorio + (aux->livro)).c_str());// Abre o dicionário
        if (myfile.is_open())
        {
            while (! myfile.eof() ) //enquanto end of file for false continua
            {
                getline (myfile,line);
                transform(line.begin(), line.end(), line.begin(), ::tolower);//Normalização das strings
                char str[sizeof(line)+10];
                strncpy(str,line.c_str(),sizeof(str));
                str[sizeof(str)-1]=0;
                char * pch;
                pch = strtok(str, "/");//Tratamento dos caracteres indesejados
                {
                    while (pch != NULL)
                    {
                        std::string line(pch);

                        if(line.size() > 0)//Verifica se não é uma string vazia
                        {
                            trie_rw->inserePalavra(line); // Insere na Trie_RW
                        }
                        pch = NULL;
                    }
                }
            }
            myfile.close();
        }
        aux = aux->prox; // pega o próximo arquivo dentro do diretório
    }
    this->trie_rw=trie_rw; // set a Trie_RW

}


void Leitor:: insereHash()
{
    int funcao;
    string diretorio;

    cout << "Qual função de hash?"<<endl<<"1-"<<endl<<"2-"<<endl<<"3-";
    cin >> funcao;
    while(funcao != 1 && funcao != 2 && funcao != 3)
    {
        cout << "Função  invalido"<< "Qual função de hash?"<<endl<<"1-"<<endl<<"2-"<<endl<<"3-";
        cin >> funcao;
    }

    HashTable * hashing = new HashTable(funcao); // Insntacia a tabela de Hash

    cout<<"Qual o diretorio dos dicionarios ?"<<endl;
    cin >> diretorio;

    ListaEncd* dicionarios = abrirDiretorio(diretorio); // Lê os arquivos dentro do diretorio
    No_Livros* aux = dicionarios->getRaiz();// Cria um ponteiro para o primeiro nó da Lista

    string line;
    while(aux)//Enquanto aux for diferente de NULL, faça
    {
        ifstream myfile (((diretorio + aux->livro)).c_str());
        if (myfile.is_open())
        {
            while (! myfile.eof() ) //enquanto end of file for false continua
            {
                getline (myfile,line);
                transform(line.begin(), line.end(), line.begin(), ::tolower);//Normalização das strings
                char str[sizeof(line)+10];
                strncpy(str,line.c_str(),sizeof(str));
                str[sizeof(str)-1]=0;
                char * pch;
                pch = strtok(str, "/");//Tratamento dos caracteres indesejados
                {
                    while (pch != NULL)
                    {
                        std::string line(pch);

                        if(line.size() > 0)
                        {
                            hashing->insere(line);// Insere na tabela de Hash
                        }
                        pch = NULL;
                    }
                }
            }
            myfile.close();

        }

        aux = aux->prox; // pega o proximo arquivo dentro do diretorio
    }
    this->hashing=hashing; // set o Hash

}

void Leitor::lerLivro(Estrutura * estrutura)
{
    string diretorio;
    string saida = "../001/Resultados/"; // Caminho de saida aonde ficarão os txt's contendo as palavras 'erradas'

    cout<<"Qual o diretorio dos Livros ?"<<endl;
    cin >> diretorio;

    ListaEncd* dicionarios = abrirDiretorio(diretorio);
    No_Livros* aux = dicionarios->getRaiz();
    while(aux)
    {
        ifstream file;
        file.open ((( diretorio + aux->livro)).c_str());// Abertura do livro
        ofstream results;
        results.open((saida +(aux->livro)).c_str());// Abertura do txt referente ao livro
        string word;

        while (file >> word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            char str[sizeof(word)+10];
            strncpy(str,word.c_str(),sizeof(str));
            str[sizeof(str)-1]=0;
            char * pch;
            pch = strtok(str, "  \",/.;':()*?«»!<>_-");// Tratamento de caracteres indesejados
            {
                while (pch != NULL)
                {
                    std::string word(pch);
                    if(estrutura->ehArvore)// Verifica se a estrutura é uma Trie_RW
                    {
                        if(!this->trie_rw->buscaPalavra(word))
                            results << word << '\n'; // Escreve no txt de resultado

                    }
                    else if(!estrutura->ehArvore) // Verifica se a estrutura é uma tabela de Hash
                    {
                        if(!this->hashing->procura(word))
                            results << word << '\n'; // Escreve no txt de resultado
                    }
                    pch = strtok (NULL, " \",/.;':()*?«»!<>_-");
                }
            }
        }
        file.close();
        results.close();
        aux =aux->prox;// proximo livro
    }

    cout <<"Feito.";
}



