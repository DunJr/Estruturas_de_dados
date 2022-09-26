#include <iostream>
#include <memory>
#include "pilha.hpp"

void clear(){
    system("clear");
}

void statuspilha(pilha *l){
    string s;
    clear();

    int tamanho = l->getTam();
    if(tamanho == 0)
        cout << "Pilha vazia" << endl;
    else
        cout << "A pilha possui " << tamanho << " elementos." << endl;
    
    cout << "\nDigite algo para continuar: ";
    cin >> s;
}

void addIni(pilha *l)
{
    no *n = new no();
    int a;
    cout << "Digite o valor: ";
    cin >> a;
    n->setData(a);
    l->pushIni(n);
}

void addNo(pilha *l)
{
    int a;
   
    clear();
    l->listarData();
        
    addIni(l);
}

void remNO(pilha *l)
{
    clear();
    string s;
    if(l->getTam() == 0)
    return;
    else
    {
        cout << "Dado removido: " << l->popIni() << endl;
        cout << "Digite algo para sair: ";
        cin >> s;
    }
}

void listarNo(pilha *l)
{
    if(l->getTam() == 0)
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
            l->listarData();
            break;
        case 2:
            l->printTop();
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

void seletor(pilha *l)
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
            addNo(l);
            break;
        case 2:
            remNO(l);
            break;
        case 3:
            listarNo(l);
            break;
        case 4:
            statuspilha(l);
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
    pilha *l = new pilha();

    seletor(l);

    delete (l);

    // std::shared_ptr<pilha> pilha = std::make_shared<pilha>();

    return 0;
}