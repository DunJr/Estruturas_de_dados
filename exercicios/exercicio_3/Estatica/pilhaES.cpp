#include "pilhaES.hpp"

pilhaES::pilhaES(int tam)
{
    data[tam] = {0};
    tamAt = 0;
    tamMax = 10;
}

bool pilhaES::pCheia(){
    if(tamAt == tamMax){
        return true;
    }else{
        return false;
    }
}

bool pilhaES::pVazia(){
    if(tamAt == 0){
        return true;
    }else{
        return false;
    }
}

void pilhaES::listarData()
{
    for (int i = (tamAt - 1); i > -1; i--)
    {
        cout << data[i] << endl;
    }
}

void pilhaES::printTopo(){
    if(pVazia())
    return;
    else
    cout << "Topo: " << data[(tamAt -1)] << endl; 
}

void pilhaES::pushData(int data)
{
    if (tamAt == tamMax)
    {
        return;
    }
    else{
        this->data[tamAt] = data;
        tamAt++;
    }
}

int pilhaES::popData()
{
    int a;

    if (tamAt == 0)
    {
        return -1;
    }
    else
    {
        tamAt--;
        a = data[tamAt];
        return a;
    }
}

void pilhaES::add()
{
    tamAt++;
}

void pilhaES::red()
{
    tamAt--;
}

int pilhaES::tamAtual(){
    return tamAt;
}
int pilhaES::TamTotal(){
    return tamMax;
}

int pilhaES::getData(int i)
{
    return data[i];
}

int pilhaES::getTamAt()
{
    return tamAt;
}

int pilhaES::getTamMax()
{
    return tamMax;
}

void pilhaES::setData(int i, int data)
{
    this->data[i] = data;
}

void pilhaES::setTamAt(int tamAt)
{
    this->tamAt = tamAt;
}

void pilhaES::setTamMax(int tamMax)
{
    this->tamMax = tamMax;
}