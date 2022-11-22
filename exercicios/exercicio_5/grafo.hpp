#ifndef GRAFO
#define GRAFO
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <list>
#include<stack>

enum cor {branco = 0, cinza, preto};

//#define BRANCO 0

using namespace std;

class grafo{
private:
    int** matrix;
    int* distancia;
    int* pai;
    int* cor;
    vector<vector<int>> listaAdj;
    // std::list<int>  *listaAdj;
    int tam;
public:
    grafo();
    grafo(int tam);

    int getTam();
    int getM(int i, int j);
    int getLij(int i, int j);
    int getPai(int i);
    int getDistancia(int i);
    vector<int> getLi(int i);
    void setM(int val ,int i, int j);
    void setL(int val, int i);
    void setTam(int tam);

    void preencheL();
    void printM();
    void printL();

    int caminhoB(int a, int b);
    void bfs(int id);
    void dfs();
    void dfsV(int u);
    void dfsI();
};

#endif