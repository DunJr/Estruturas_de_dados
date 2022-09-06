#include "lista_seq.hpp"

lista_seq::lista_seq(int tam)
{
    data[tam] = {0};
    tamAt = 0;
    tamMax = 10;
}

bool lista_seq::lCheia(){
    if(tamAt == tamMax){
        return true;
    }else{
        return false;
    }
}

bool lista_seq::lVazia(){
    if(tamAt == 0){
        return true;
    }else{
        return false;
    }
}

void lista_seq::listarData()
{
    for (int i = 0; i < tamAt; i++)
    {
        cout << data[i] << endl;
    }
}

int lista_seq::pushData(int pos, int data)
{
    int aux;

    if (pos < 0 || pos > tamMax || tamAt == tamMax)
    {
        return 0;
    }
    else if ((pos - 1) == tamAt)
    {
        aux = tamAt;
        this->data[aux] = data;
        tamAt++;
        return 1;
    }
    else
    {
        aux = pos - 1; // aux = indice da lista que receberá o dado
        for (int i = tamAt; aux < i; i--)
        {
            this->data[i] = this->data[i - 1];
        }
        this->data[aux] = data;
        tamAt++;
        return 1;
    }
}

int lista_seq::popData(int pos)
{
    if (pos < 1 || pos > tamAt || tamAt == 0)
    {
        return 0;
    }
    else if (pos == tamAt)
    {
        tamAt--;
        return 1;
    }
    else
    {
        for (int i = tamAt; pos < i; pos++)
        {
            this->data[pos - 1] = this->data[pos];
        }
        tamAt--;
        return 1;
    }
}

int lista_seq::modData(int pos, int data){
    if(pos < 1 || tamAt < pos){
        return 0;
    }else{
        this->data[(pos - 1)] = data;
    }
    return 1;
}

void lista_seq::add()
{
    tamAt++;
}

void lista_seq::red()
{
    tamAt--;
}

int lista_seq::tamAtual(){
    return tamAt;
}
int lista_seq::TamTotal(){
    return tamMax;
}

int lista_seq::getData(int i)
{
    return data[i];
}

int lista_seq::getTamAt()
{
    return tamAt;
}

int lista_seq::getTamMax()
{
    return tamMax;
}

void lista_seq::setData(int i, int data)
{
    this->data[i] = data;
}

void lista_seq::setTamAt(int tamAt)
{
    this->tamAt = tamAt;
}

void lista_seq::setTamMax(int tamMax)
{
    this->tamMax = tamMax;
}