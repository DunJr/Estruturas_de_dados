#include "grafo.hpp"
using namespace std;

void clear(){
    system("clear");
}

grafo* criaGrafo(string fileName){
    int tam, val = 0, i = 0, j = 0;
    ifstream myfile (fileName); // Ler Arquivo
    if(myfile.is_open()){
            myfile >> tam;
            grafo *g = new grafo(tam);

            for (int i = 0; i < tam; i++){
                for (int j = 0; j < tam; j++){
                    myfile >> val;
                    g->setM(val, i, j);
                }
            }
        myfile.close();
        g->preencheL();
    return g;
    }else{
        cout << "Arquivo nao encontrado" << endl;
        return NULL;
    }
}
// grafo* criaGrafo(){
//     int tam, val;
//     int cont = 0;
//     vector<int> aux;
//     // ifstream myfile;
//     // myfile.open("pcv10.txt");
//     ifstream myfile ("pcv50.txt");
//     if(myfile.is_open()){
//         myfile >> tam;
//         grafo *g = new grafo(tam);
//         tam = tam*tam;
//         for(int i = 0; i < tam; i++){
//             aux.push_back(0);
//         }
//         for (int i = 0; i < tam; i++){
//             myfile >> aux[i];
//         }
//         myfile.close();
//         tam = sqrt(tam);
//         for(int i = 0; i < tam; i++){
//             for(int j = 0; j < tam; j++){
//                 g->m[i][j] = aux[cont];
//                 cont++;
//             }
//         }
//     return g;
//     }else{
//         cout << "Arquivo nao encontrado" << endl;
//         return NULL;
//     }
// }



void menu(){
    bool bfs = false;
    int sel = 0, raiz = 0;
    string fileName;
    clear();
    grafo *g;
    

    while(sel == 0){
        cout << "[1] pcv10" << "\n" << "[2] pcv50" << "\n" << "[3] pcv177" << "\n" << "Escolha o arquivo: ";
        cin >> sel;
        if(sel == 1){
            fileName = "pcv10.txt";
        }else if(sel == 2){
            fileName = "pcv50.txt";
        }else if(sel == 3){
            fileName = "pcv177.txt";
        }else{
            cout << "Opcao invalida." << endl;
            sel = 0;
        }
    }
    g = criaGrafo(fileName);

    int sel2 = 0;
    while(sel2 == 0){
        cout << "[1] BFS" << "\n" << "[2] DFS (Recursivo)" << "\n" << "[3] DFS (Iterativo)" << "\n" << "Escolha o mapeamento: ";
        cin >> sel2;
        if(sel2 == 1){
            while((raiz < 1) || (raiz > g->getTam())){
                cout << "Escolha uma raiz (1 a "<< g->getTam() << "): ";
                cin >> raiz;
                if((raiz > 0) && (raiz < g->getTam() + 1))
                    g->bfs(raiz);
            }
            bfs = true;
        }else if(sel2 == 2){
            g->dfs();
        }else if(sel2 == 3){
            g->dfsI();
        }else{
            cout << "Opcao invalida." << endl;
            sel2 = 0;
        }
    }
    
    g->printM();
    cout << endl;
    g->printL();
    cout << endl;

    for(int i = 0; i < g->getTam(); i++){
        cout << i + 1 << "\t";
        if(sel2 == 1)
            cout << g->getDistancia(i)  << "\t";
        cout << g->getPai(i) +1;
        cout << endl;
    }
    cout << endl;

    if(bfs){
        cout << "Escolha o inicio do caminho (1-"<< g->getTam() << "): ";
        cin >> sel;
        cout << "Escolha o fim do caminho (1-"<< g->getTam() << "): ";
        cin >> sel2;
        

        if(g->caminhoB(sel, sel2) != 0)
            cout << "Caminho nao encontrado" << endl;
    }
}

int main(void){
    clear();
    vector<grafo> *cr, *mp;



    menu();

    // grafo *g;
    // g = criaGrafo("pcv10.txt");



    // g->printM();
    // cout << endl;
    // g->printL();
    // cout << endl;

    // g->dfs();

    // for(int i = 0; i < g->getTam(); i++){
    //     cout << i + 1 << "\t";
    //     cout << g->getDistancia(i)  << "\t";
    //     cout << g->getPai(i) +1;
    //     cout << endl;
    // }
    // cout << endl;

    
    // if(g->caminhoB(177, 1) != 0)
    //     cout << "FALHA NO CAMINHO" << endl;
}