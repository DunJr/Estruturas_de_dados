#include <iostream>
#include <memory>
#include "lista.hpp"

void clear(){
    system("clear");
}

void statusLista(lista *l){
    string s;
    clear();

    int tamanho = l->getTam();
    if(tamanho == 0)
        cout << "Lista Vazia" << endl;
    else
        cout << "A lista possui " << tamanho << " elementos." << endl;
    
    cout << "\nDigite algo para continuar: ";
    cin >> s;
}

void addIni(lista *l)
{
    no *n = new no();
    int a;
    cout << "Digite o valor: ";
    cin >> a;
    n->setData(a);
    l->pushIni(n);
}

void addFim(lista *l)
{
    no *n = new no();
    int a;
    cout << "Digite o valor: ";
    cin >> a;
    n->setData(a);
    l->pushFim(n);
}

void addMid(lista *l)
{
    no *n = new no();
    int a, b;

    cout << "Digite a posicao: ";
    cin >> b;
    cout << "Digite o valor: ";
    cin >> a;
    n->setData(a);
    l->pushGen(b, n);
}

void remMid(lista *l){
    int pos;
    cout << "Digite a posicao: ";
    cin >> pos;
    l->popGen(pos);
}

void PesPos(lista *l){
    int pos, res;
    
    do
    {
        cout << "Digite a posicao(0 para sair): ";
        cin >> pos;
        if(pos < 1 || pos > l->getTam())
        return;

        res = l->pesquisaPos(pos);
        
        cout << "O valor guardado na posicao "<< pos << " foi " << res << endl;

    } while (pos != 0);
}

void PesData(lista *l){
    int data;
    
    cout << "Digite o valor para pesquisa: ";
    cin >> data;
    l->pesquisaData(data);

}

void modNo(lista *l){
    int pos, data;
    if(l->getTam() == 0)
    return;

    do{
        clear();
        l->listarData();
        cout << "Digite a posicao(0 para sair): ";
        cin >> pos;

        if(pos == 0)
        break;

        cout << "Digite o novo valor: ";
        cin >> data;

        l->modData(pos, data);
    }while(l->getTam() != 0);
}

void addNo(lista *l)
{
    int a;
    while (a != 0)
    {
        clear();
        l->listarData();
        cout << "1: Inicio, 2: Meio, 3: Fim, 0: Sair: ";
        cin >> a;

        switch (a)
        {
        case 1:
            addIni(l);
            break;
        case 2:
            addMid(l);
            break;
        case 3:
            addFim(l);
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

void remNO(lista *l)
{
    if(l->getTam() == 0)
    return;

    int a;
    while (a != 0)
    {
        clear();
        l->listarData();
        cout << "1: Inicio, 2: Meio, 3: Fim, 0: Sair: ";
        cin >> a;

        switch (a)
        {
        case 1:
            l->popIni();
            break;
        case 2:
            remMid(l);
            break;
        case 3:
            l->popFim();
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

void listarNo(lista *l)
{
    if(l->getTam() == 0)
    return;

    int a;
    while (a != 0)
    {
        cout << "1: Todos, 2: Por posicao, 3: Por conteudo, 0: Sair: ";
        cin >> a;
        clear();
        switch (a)
        {
        case 1:
            l->listarData();
            break;
        case 2:
            PesPos(l);
            break;
        case 3:
            PesData(l);
            break;
        case 0:
            return;
            break;

        default:
            break;
        }
    }
}

void seletor(lista *l)
{
    int a;
    while (a != 0)
    {
        clear();
        cout << "1: Adicionar, 2: Remover, 3: Modificar, 4: Listar, 5: Status, 0: Sair: ";
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
            modNo(l);
            break;
        case 4:
            listarNo(l);
            break;
        case 5:
            statusLista(l);
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
    lista *l = new lista();

    seletor(l);

    delete (l);

    // std::shared_ptr<lista> lista = std::make_shared<lista>();

    return 0;
}