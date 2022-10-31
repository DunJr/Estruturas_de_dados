#include "arv.hpp"

arv::arv(){
    raiz = NULL;
    nElementos = 0;
}

no* arv::busca(int dado){
    no *r = raiz;

    while(r){
        if(r->getCont() == dado){
            return r;
        }else{
            if(dado < r->getCont()){
                r = r->getEsq();
            }else{
                r = r->getDir();
            }
        }
    }
    return r;
}

void arv::listarNos(no *r){
    if(r){
        listarNos(r->getEsq());
        std::cout << r->getCont() << std::endl;
        listarNos(r->getDir());
    }
}

int arv::listar(){
    if(nElementos == 0)
        return -1;

    no *r = raiz;
    listarNos(r);
    return 0;
}

void arv::push(int novoDado){
    no *novoNo = new no(novoDado);
    no *aux = raiz;
    if(raiz == NULL){
        raiz = novoNo;
        nElementos++;
        return;
    }else{
        while(1){
            if((novoDado < aux->getCont()) || (novoDado == aux->getCont())){
                if(aux->getEsq() == NULL){
                    aux->setEsq(novoNo);
                    nElementos++;
                    return;
                }else{
                    aux = aux->getEsq();
                }
            }else{
                if(aux->getDir() == NULL){
                    aux->setDir(novoNo);
                    nElementos++;
                    return;
                }else{
                    aux = aux->getDir();
                }
            }
        }
    }
}

no* arv::getRaiz(){
    return raiz;
}

int arv::getNElementos(){
    return nElementos;
}

void arv::setRaiz(no *novoNo){
    this->raiz = novoNo;
}

void arv::setNElementos(int nElementos){
    this->nElementos = nElementos;
}