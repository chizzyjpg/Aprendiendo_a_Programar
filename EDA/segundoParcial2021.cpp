#include <iostream>

using namespace std;

struct nodoAB
{
    int info;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

AB crearArbol(int, AB, AB);
void imprimir(AB);
AB cortarArbol(AB &, int);
int maxAlturaPerfecto(AB);

int main()
{
    AB Arbol = new nodoAB;
    Arbol = crearArbol(11, crearArbol(5, NULL, NULL), crearArbol(3, crearArbol(13, NULL, NULL), crearArbol(1, NULL, NULL)));
    imprimir(Arbol);
    cout << '\n';
    imprimir(cortarArbol(Arbol, 3));
    return 0;
}

AB crearArbol(int x, AB izq, AB der)
{
    AB nuevo = new nodoAB;

    nuevo->info = x;
    nuevo->izq = izq;
    nuevo->der = der;

    return nuevo;
}

void imprimir(AB a)
{
    if (a->izq != NULL)
        imprimir(a->izq);
    cout << "|" << a->info << "| ";
    if (a->der != NULL)
        imprimir(a->der);
}

AB cortarArbol(AB &a, int x)
{
    if (a == NULL)
    {
        return NULL;
    }
    AB temp;
    if (a->info == x)
    {
        temp = a;
        a = NULL
    }
    else
    {
        temp = cortarArbol(a->izq, x);
        if ()
    }
    if (a->izq != NULL && a->izq->info == x)
    {
        temp = a->izq;
        return temp;
    }
    if (a->der != NULL && a->der->info == x)
    {
        temp = a->der;
        return temp;
    }
    if (a->izq != NULL)
        return cortarArbol(a->izq, x);
    if (a->der != NULL)
        return cortarArbol(a->der, x);
    if (a->izq == NULL && a->der == NULL)
        return NULL;
}

int maxAlturaPerfecto(AB a)
{
}