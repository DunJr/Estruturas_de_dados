#include <iostream>
#include <memory>
#include "pilhaES.hpp"

void clear(){
    system("clear");
}

void statuspilha(pilhaES *p){
    string s;
    clear();

    int tamanho = p->getTamAt();
    if(tamanho == 0)
        cout << "Pilha vazia" << endl;
    else
        cout << "A pilha possui " << tamanho << " elementos." << endl;
    
    cout << "\nDigite algo para continuar: ";
    cin >> s;
}

void push(pilhaES *p)
{
    int a;
    cout << "Digite o valor: ";
    cin >> a;
    p->pushData(a);
   
    clear();
    p->listarData();
}

void pop(pilhaES *p)
{
    clear();
    string s;
    if(p->getTamAt() == 0)
    return;
    else
    {
        cout << "Dado removido: " << p->popData() << endl;
        cout << "Digite algo para sair: ";
        cin >> s;
    }
}

void print(pilhaES *p){
    if(p->pVazia())
    return;

    string s;
    p->printTopo();
    cout << "Digite algo para continuar: " ;
    cin >> s;
}

void listarNo(pilhaES *p)
{
    if(p->getTamAt() == 0)
    return;

    int a;
    while (a != 0)
    {
        cout << "1: Todos, 2: Topo, 0: Sair: ";
        cin >> a;
        clear();
        switch (a)
        {
        case 1:
            p->listarData();
            break;
        case 2:
            print(p);
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

void seletor(pilhaES *p)
{
    int a;
    while (a != 0)
    {
        clear();
        cout << "1: Adicionar, 2: Remover, 3: Listar, 4: Status, 0: Sair: ";
        cin >> a;

        switch (a)
        {
        case 1:
            push(p);
            break;
        case 2:
            pop(p);
            break;
        case 3:
            listarNo(p);
            break;
        case 4:
            statuspilha(p);
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

int main()
{
    pilhaES *p = new pilhaES(10);

    seletor(p);

    delete (p);

    // std::shared_ptr<pilha> pilha = std::make_shared<pilha>();

    return 0;
}