#include "grafo.hpp"

using namespace std;

grafo::grafo(int tam){
    this->tam = tam;
    this->matrix = new int* [tam];
    this->pai = new int [tam];
    this->cor = new int [tam];
    this->distancia = new int [tam];

    for (size_t i = 0; i < tam; i++){
        this->matrix[i] = new int[tam];
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
           this->matrix[i][j] = 0; 
        }
    }

    for (size_t i = 0; i < tam; i++){
        vector<int> v;
        v.push_back(i);
        listaAdj.push_back(v);
    }

    
}

void grafo::printM(){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << '\n';
    }
}

void grafo::printL(){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < listaAdj[i].size(); j++){
            if(j == 0)
                cout << "(" << listaAdj[i][j] + 1 << ")" << " \t";
            else
                cout << listaAdj[i][j] + 1 << "\t";
        }
        cout << "\n";
    }
}

void grafo::preencheL(){
    for (size_t i = 0; i < tam; i++){
       for (size_t j = 0; j < tam; j++){
        if (this->matrix[i][j] != 0) {
            this->listaAdj[i].push_back(j);
        }
       }
    }
}

void grafo::bfs(int id){
    id--;
    int u, v, t;
    for(int i = 0; i < tam; i++){
        u = listaAdj[i][0];
        cor[u] = branco;
        distancia[u] = -1;
        pai[u] = -2;
    }
    int s = listaAdj[id][0];
    cor[s] = cinza;
    distancia[s] = 0;
    pai[s] = -2;

    vector<int> q;
    q.insert(q.begin(), s);
    while(q.size() > 0){
        u = q.back();
        q.pop_back();
        for(int i = 0; i < listaAdj[u].size(); i++){
            if(cor[listaAdj[u][i]] == branco){
                v = listaAdj[u][i];
                cor[v] = cinza;
                distancia[v] = distancia[u] + 1;
                pai[v] = u;
                q.insert(q.begin(), v);
            }
            cor[u] = preto;
        }
    }
}

void grafo::dfsV(int u){
    cor[u] = cinza;
    for (int i = 0; i < listaAdj[u].size(); i++){
        if(cor[listaAdj[u][i]] == branco){
            pai[listaAdj[u][i]] = u;
            dfsV(listaAdj[u][i]);
        }
    }
    cor[u] = preto;   
}

void grafo::dfs(){
    int u, v, t;
    for(int i = 0; i < tam; i++){
        cor[listaAdj[i][0]] = branco;
        pai[listaAdj[i][0]] = -2;
    }

    for(int i = 0; i < tam; i++){
        if(cor[listaAdj[i][0]] == branco){
            u = listaAdj[i][0];
            dfsV(u);
        }
    }
}


void grafo::dfsI(){
    int v, j;
    int aux;
    stack<int> pilha;

    

    for (int i = 0; i < tam; i++){
        v = listaAdj[i][0];
        if(cor[v] == branco){
            cor[v] = cinza;
            pai[v] = -2;
            pilha.push(v);
        }

        j = 0;
        while(!pilha.empty()){
            if(cor[listaAdj[v][j]] == branco){

                cor[listaAdj[v][j]] = cinza;
                pai[listaAdj[v][j]] = v;
                pilha.push(v);
                pilha.push(listaAdj[v][j]);
                v = listaAdj[v][j];
                j = 0;
            }else if((listaAdj[v][j] == listaAdj[v].back())){

                v = pilha.top();
                pilha.pop();
                j = 1;
                continue;
            }
            j++;
        }

    }
}



int grafo::caminhoB(int a, int b){
    a--;b--;
    bool existe = false;
    //int dis;
    vector<int> caminho;
    vector<int> camAux;
    if((distancia[listaAdj[a][0]] < 0) || (distancia[listaAdj[b][0]] < 0))
        return -1;
    if(a == b)
        return -2;


    int mai, men;
    if(distancia[a] > (distancia[b])){
        mai = a;
        men = b;
    }else{
        mai = b;
        men = a;
    }
    //dis = distancia[mai];

    while (pai[mai] > -2){
        caminho.insert(caminho.begin(), mai);
        if(men == pai[mai]){
            caminho.insert(caminho.begin(), men);
            existe = true;
            break;
        }
        mai = pai[mai];
    }

    if(!existe){
        while (pai[men] > -2){
            camAux.insert(camAux.begin(), men);
            men = pai[men];
        }
        caminho.insert(caminho.begin(), mai);
    }

    if(existe || (mai == men)){
        int size = caminho.size();
        if(distancia[a] > distancia[b]){
            for(int i = size; i > 0; i--){
                cout << caminho[i - 1] + 1 << "\t";
            }
            if(!existe){
                for (int i = 0; i < camAux.size(); i++){
                    cout << camAux[i] + 1 << "\t";
                }
            }
            
        }else{
            if(!existe){
                for(int i = camAux.size(); i > 0; i--){
                    cout << camAux[i - 1] + 1 << "\t";
                }
            }
            for(int i = 0; i < size; i++){
                cout << caminho[i] + 1 << "\t";
            }
        }
        
        cout << endl;
        return 0;
    }

    return -3;

}

int grafo::getM(int i, int j){
    return matrix[i][j];
}

int grafo::getTam(){
    return tam;
}

int grafo::getPai(int i){
    return pai[i];
}

int grafo::getDistancia(int i){
    return distancia[i];
}

int grafo::getLij(int i, int j){
    return listaAdj[i][j];
}

vector<int> grafo::getLi(int i){
    return listaAdj[i];
}

void grafo::setM(int val, int i, int j){
    matrix[i][j] = val;
}