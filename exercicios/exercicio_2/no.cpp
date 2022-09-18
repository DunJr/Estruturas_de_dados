#include "no.hpp"

using namespace std;

no::no(){
    data = 0;
    prox = NULL;
}


no* no::getProx(){
    return prox;
}

int no::getData(){
    return data;
}

void no::setProx(no *p){
    prox = p;
}

void no::setData(int data){
    this->data = data;
}