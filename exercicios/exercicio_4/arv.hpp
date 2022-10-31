#ifndef ARV
#define ARV
#include "no.hpp"

class arv{
    private:
        no *raiz;
        int nElementos;
    public:
        arv();

        no* getRaiz();
        int getNElementos();

        void setRaiz(no *novoNo);
        void setNElementos(int nElementos);

        no* busca(int dado);
        void push(int novoDado);
        int listar();
        void listarNos(no* r);

};

#endif