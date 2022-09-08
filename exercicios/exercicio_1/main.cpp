#include <stdio.h>
#include "lista_seq.hpp"
using namespace std;

void popData(lista_seq *lista)
{
    int pos;
    do
    {
        if(lista->getTamAt() == 0){
        cout << "A lista esta vazia \n" << endl;
        break;
        }

        cout << endl;
        lista->listarData();
        cout << "Selecioni posição a ser removido(0 para sair): " << endl;
        cin >> pos;
        if (lista->popData(pos))
            continue;
        else
            break;
    } while (pos = !0);
}

void pushData(lista_seq *lista)
{
    int pos, data;

    do
    {
        
        cout << endl;
        lista->listarData();
        
        if(lista->getTamAt() == lista->getTamMax()){
            cout << "A lista esta cheia \n" << endl;
            break;
        }

        cout << "Selecione o local para insercao(0 para sair): " << endl;
        cin >> pos;

        if(pos != 0){
        cout << "Digite o valor do novo elemento: " << endl;
        cin >> data;
        lista->pushData(pos, data);
        }
        else
        break;
    } while (pos != 0);
    
}

void modData(lista_seq *lista)
{
    int pos, data;

    do
    {
        lista->listarData();
        cout << "Escolha o elemento a ser modificado(0 para sair): ";
        cin >> pos;
        if (pos == 0)
        {
            break;
        }
        else
        {
            cout << "Digite o novo valor: ";
            cin >> data;
            lista->modData(pos, data);
        }
    } while (pos != 0);
}

void statusLista(lista_seq *lista)
{
    if (lista->lCheia())
        cout << "A lista esta cheia" << endl;
    else if (lista->lVazia())
        cout << "A lista esta vazia" << endl;
    else
        cout << "A lista nao esta vazia nem cheia" << endl;
}

void Test1()
{
    int i;

    lista_seq *lista = new lista_seq(10);

    lista->pushData(1, 23);
    lista->pushData(2, 25);
    lista->pushData(2, 24);
    lista->pushData(1, 8);

    lista->listarData();

    do
    {
        cout << "Digite 1 para adicionar elementos, 2 para remover elementos, 3 para consultar status da lista ou 0 para sair: ";
        cin >> i;
        switch (i)
        {
        case 1:
            pushData(lista);
            break;

        case 2:
            popData(lista);
            break;
        case 3:
            statusLista(lista);
            cout << endl;
            break;

        case 0:
            return;

        default:
            break;
        }

    } while (i = !0);

    cout << endl;
    lista->listarData();
    delete lista;
}

void test2()
{
    lista_seq *lista = new lista_seq(10);


    cout << "A lista suporta: " << lista->TamTotal() << " Elemento(s)" << endl;
    cout << endl;
    cout << "A lista possui: " << lista->tamAtual() << " Elemento(s)" << endl;
    statusLista(lista);
    cout << endl;

    lista->pushData(1, 23);
    lista->pushData(2, 25);
    lista->pushData(2, 24);
    lista->pushData(1, 8);

    cout << "A lista possui: " << lista->tamAtual() << " Elemento(s)" << endl;
    statusLista(lista);
    lista->listarData();
    cout << endl;

    lista->pushData(1, 11);
    lista->pushData(2, 13);
    lista->pushData(2, 12);
    lista->pushData(1, 10);
    lista->pushData(5, 14);
    lista->pushData(10, 50);

    cout << "A lista possui: " << lista->tamAtual() << " Elemento(s)" << endl;
    statusLista(lista);
    lista->listarData();
    cout << endl;
    delete lista;
}

void test3()
{
    lista_seq *lista = new lista_seq(10);

    lista->pushData(1, 23);
    lista->pushData(2, 25);
    lista->pushData(2, 24);
    lista->pushData(1, 8);
    lista->pushData(1, 11);
    lista->pushData(2, 13);
    lista->pushData(2, 12);
    lista->pushData(1, 10);
    lista->pushData(5, 14);
    lista->pushData(10, 50);

    modData(lista);

    delete lista;
}

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        if (std::string(argv[1]) == "test1")
        {
            Test1();
            system("clear");
            
        }
        else if (std::string(argv[1]) == "test2")
        {
            test2();
        }
        else if (std::string(argv[1]) == "test3")
        {
            test3();
            system("clear");
        }
    }
    else
    {
    }
    return 0;
}