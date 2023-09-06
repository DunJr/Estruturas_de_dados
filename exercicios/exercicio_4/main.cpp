#include <iostream>
#include "arv.hpp"
#include <string>

void clear(){
    system("clear");
}

void addNo(arv *a){
    int aux;
    clear();

    std::cout << "Digite o valor a ser adicionado: ";
    std::cin >> aux;
    a->push(aux);
}

void listar(arv *a){
    std::string s;
    clear();
    if(a->listar()){
       std::cout << "Arvore Vazia." << std::endl; 
    }
    std::cout << "Digite Algo para continuar." << std::endl;
    std::cin >> s;
}

void busca(arv *a){
    std::string s;
    int aux;
    no *n;
    std::cout << "Digite o valor: ";
    std::cin >> aux;
    n = a->busca(aux);
    if(n){
        std::cout << "Valor = " << n->getCont() << " endereco = " << n << std::endl;
    }else{
        std::cout << "Valor nao encontrado." << std::endl;
    }
    std::cout << "Digite Algo para continuar." << std::endl;
    std::cin >> s;
}

void seletor(arv *a)
{
    int aux;
    while (a != 0)
    {
        clear();
        std::cout << "1: Adicionar, 2: buscar, 3: Listar, 0: Sair: ";
        std::cin >> aux;

        switch (aux)
        {
        case 1:
            addNo(a);
            break;
        case 2:
            busca(a);
            break;
        case 3:
            listar(a);
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

int main(){

    arv *a = new arv();
    seletor(a);

    return 0;
}