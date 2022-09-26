#ifndef PILHAES_
#define PILHAES_
#include <iostream>

using namespace std;

class pilhaES{
private:
    int data[10];
    int tamAt = 0;
    int tamMax = 10;
public:
    pilhaES(int tam);

    int getData(int i);
    int getTamAt();
    int getTamMax();

    void setData(int i, int data);
    void setTamAt(int tamAt);
    void setTamMax(int tamMax);

    void listarData();
    void printTopo();
    void add();
    void red();
    int tamAtual();
    int TamTotal();
    void pushData(int data);
    int popData();
    bool pVazia();
    bool pCheia();

};

#endif