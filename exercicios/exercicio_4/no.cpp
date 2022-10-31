#include "no.hpp"


no::no(){
    esq = NULL;
    dir = NULL;
    cont = 0;
}

no::no(int dado){
    esq = NULL;
    dir = NULL;
    this->cont = dado;
}




no* no::getEsq(){
    return esq;
}

no* no::getDir(){
    return dir;
}

int no::getCont(){
    return cont;
}

void no::setEsq(no *novoNo){
    esq = novoNo;
}

void no::setDir(no *novoNo){
    dir = novoNo;
}

void no::setCont(int dado){
    this->cont = dado;
}