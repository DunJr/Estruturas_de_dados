#ifndef PILHA
#define PILHA
#include <iostream>
#include "no.hpp"

using namespace std;

class pilha{
private:
    no *c;
    int tam;
public:
    pilha();
    int getTam();

    void setTam(int tam);

    void listarData();
    void printTop();
    void pushIni(no *n);
    int popIni();
    bool lVazia();
};

#endif