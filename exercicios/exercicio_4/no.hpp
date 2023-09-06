#ifndef NO
#define NO
#include <iostream>

class no{
    private:
        no *esq;
        no *dir;
        int cont;
    public:
        no();
        no(int dado);
        
        no* getEsq();
        no* getDir();
        int getCont();

        void setEsq(no *novoNo);
        void setDir(no *novoNo);
        void setCont(int dado);

};


#endif