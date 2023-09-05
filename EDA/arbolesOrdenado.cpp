#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};
typedef nodo *lista;

struct nodoAB
{
    int dato;
    nodoAB *izq;
    nodoAB *der;
};
typedef nodoAB *ab;

lista enOrden(ab);

int main()
{
    ab izq = consArbol(5, NULL, NULL);
    ab der = consArbol(3, NULL, NULL);
    ab xd = consArbol(17, NULL, NULL);
    ab xD = consArbol(1378, xd, izq);
    ab raiz = consArbol(8, xD, der);

    return 0;
}

lista enOrden(ab b)
{
}