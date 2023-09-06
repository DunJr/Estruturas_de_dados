#include "lista.hpp"
#include "no.hpp"

using namespace std;

lista::lista()
{
    tam = 0;
    c = NULL;
}

void lista::modData(int pos, int data)
{
    if (pos < 1 || pos > tam)
        return;

    no *aux = c;
    for (int i = 1; i < pos; i++)
    {
        aux = aux->getProx();
    }
    aux->setData(data);
}

void lista::pushFim(no *n)
{
    no *aux = c;
    if (tam == 0)
    {
        c = n;
        tam++;
    }
    else
    {
        while (aux->getProx() != NULL)
        {
            aux = aux->getProx();
        }
        aux->setProx(n);
        tam++;
    }
}

void lista::pushIni(no *n)
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

void lista::pushGen(int pos, no *n)
{
    no *aux = c;
    int var = tam + 1;

    if (pos < 1 || pos > var)
    {
        return;
    }
    else if (tam == 0)
    {
        c = n;
        tam++;
    }
    else if (pos == 1)
    {
        n->setProx(c);
        c = n;
        tam++;
    }
    else if (pos == var)
    {
        while (aux->getProx() != NULL)
        {
            aux = aux->getProx();
        }
        aux->setProx(n);
        tam++;
    }
    else
    {
        var = pos - 1;
        for (int i = 1; i < var; i++)
        {
            aux = aux->getProx();
        }
        n->setProx(aux->getProx());
        aux->setProx(n);
        tam++;
    }
}

void lista::popFim()
{
    if (tam == 0)
    {
        return;
    }

    int var;
    no *aux = c;
    no *aux2 = new no();
    var = tam - 1;
    aux = c;
    for (int i = 1; i < var; i++)
    {
        aux = aux->getProx();
    }
    aux2 = aux->getProx();
    aux->setProx(NULL);
    delete (aux2);
    tam--;
}

void lista::popIni()
{
    if (tam == 0)
    {
        return;
    }

    no *aux = c;
    c = aux->getProx();
    delete (aux);
    tam--;
}

void lista::popGen(int pos)
{
    if (pos < 1 || pos > tam)
    {
        return;
    }
    else if (pos == 1)
    {
        no *aux = new no();
        aux = c;
        c = aux->getProx();
        delete (aux);
        tam--;
    }
    else if (pos == tam)
    {
        int var;
        no *aux = c;
        no *aux2 = new no();
        var = tam - 1;
        for (int i = 1; i < var; i++)
        {
            aux = aux->getProx();
        }
        aux2 = aux->getProx();
        aux->setProx(NULL);
        delete (aux2);
        tam--;
    }
    else
    {
        int var = pos - 1;
        no *aux = c;
        no *aux2 = new no();
        for (int i = 1; i < var; i++)
        {
            aux = aux->getProx();
        }
        aux2 = aux->getProx();
        aux->setProx(aux2->getProx());
        delete (aux2);
        tam--;
    }
}

void lista::listarData()
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

int lista::pesquisaPos(int pos)
{
    // if (pos < 1 || pos > tam)
    //     return 0;
    no *aux = c;

    for (int i = 1; i < pos; i++)
    {
        aux = aux->getProx();
    }
    return aux->getData();
}

void lista::pesquisaData(int data)
{
    if (tam == 0)
        return;

    int pos = 1;
    no *aux = c;

    for (int i = 0; i < tam; i++)
    {
        if (aux->getData() == data)
            cout << "O valor foi encontrado na posicao: " << pos << endl;
        pos++;
        aux = aux->getProx();
    }
}

int lista::getTam()
{
    return tam;
}

void lista::setTam(int tam)
{
    this->tam = tam;
}