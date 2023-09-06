#include "pilha.hpp"
#include "no.hpp"

using namespace std;

pilha::pilha()
{
    tam = 0;
    c = NULL;
}

void pilha::pushIni(no *n)
{
    if (tam == 0)
    {
        c = n;
        tam++;
    }
    else
    {
        n->setProx(c);
        c = n;
        tam++;
    }
}

int pilha::popIni()
{
    int a;
    if (tam == 0)
    {
        return -1;
    }
    else
    {
        no *aux = c;
        c = aux->getProx();
        a = aux->getData();
        delete (aux);
        tam--;
        return a;
    }
}

void pilha::listarData()
{
    if (tam == 0)
    {
        return;
    }
    else
    {
        no *aux = c;

        for (int i = 0; i < tam; i++)
        {
            cout << aux->getData() << endl;
            aux = aux->getProx();
        }
    }
}

void pilha::printTop(){
    if (tam == 0)
    {
        return;
    }
    else
    {
        cout << c->getData() << endl;
    }
}

int pilha::getTam()
{
    return tam;
}

void pilha::setTam(int tam)
{
    this->tam = tam;
}