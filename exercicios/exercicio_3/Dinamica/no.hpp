#ifndef NO
#define NO
#include <iostream>

using namespace std;

class no{
private:
    int data;
    no *prox;
public:
    no();

    no * getProx();
    int getData();
    void setData(int data);
    void setProx(no *p);

};

#endif