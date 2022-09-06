#ifndef LISTA_SEQ_
#define LISTA_SEQ_
#include <iostream>

using namespace std;

class lista_seq{
private:
    int data[10];
    int tamAt = 0;
    int tamMax = 10;
public:
    lista_seq();

    int getData(int i);
    int getTamAt();
    int getTamMax();

    void setData(int i, int data);
    void setTamAt(int tamAt);
    void setTamMax(int tamMax);

    void listarData();
    void add();
    void red();
    int modData(int pos, int data);
    int tamAtual();
    int TamTotal();
    int pushData(int i, int data);
    int popData(int i);
    bool lVazia();
    bool lCheia();

};

#endif