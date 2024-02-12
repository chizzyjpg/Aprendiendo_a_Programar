#include <iostream>

using namespace std;

struct nodo_lista
{
    int info;
    nodo_lista *sig;
};
typedef nodo_lista *Lista;

struct nodo_abb
{
    int info;
    nodo_abb *izq;
    nodo_abb *der;
};
typedef nodo_abb *ABB;

int main()
{

    return 0;
}
