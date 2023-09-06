#ifndef LISTA
#define LISTA
#include <iostream>
#include "no.hpp"

using namespace std;

class lista{
private:
    no *c;
    int tam;
public:
    lista();
    int getTam();

    void setTam(int tam);

    void listarData();
    int pesquisaPos(int pos);
    void pesquisaData(int data);
    void modData(int pos, int data);
    void pushGen(int pos, no *n);
    void pushFim(no *n);
    void pushIni(no *n);
    void popIni();
    void popFim();
    void popGen(int pos);
    bool lVazia();
};

#endif