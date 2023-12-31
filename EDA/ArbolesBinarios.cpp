#include <iostream>

using namespace std;

struct nodoAB
{
    int dato;
    nodoAB *izq;
    nodoAB *der;
};
typedef nodoAB *ab;

ab consArbol(int, ab, ab);
int contarElems(ab);
int contarHojas(ab);
int altura(ab);
ab copiar(ab);
void liberarArbol(ab &);

int main()
{
    ab izq = consArbol(5, NULL, NULL);
    ab der = consArbol(3, NULL, NULL);
    ab xd = consArbol(17, NULL, NULL);
    ab xD = consArbol(1378, xd, izq);
    ab raiz = consArbol(8, xD, der);
    int elementos = contarElems(raiz);
    int hojas = contarHojas(raiz);
    int alto = altura(raiz);

    cout << "Elementos: " << elementos << "\nHojas: " << hojas << "\nAltura: " << alto;

    return 0;
}

ab consArbol(int x, ab izq, ab der)
{
    ab res = new nodoAB;
    res->dato = x;
    res->izq = izq;
    res->der = der;
    return res;
}

int contarElems(ab a)
{
    int cont = 1;
    if (a->izq != NULL)
    {
        cont += contarElems(a->izq);
    }
    if (a->der != NULL)
    {
        cont += contarElems(a->der);
    }
    return cont;
}

int contarHojas(ab a)
{
    if (a == NULL)
    {
        return 0;
    }
    if (a->der == NULL && a->izq == NULL)
    {
        return 1;
    }
    return contarHojas(a->der) + contarHojas(a->izq);
}

int altura(ab a)
{
    if (a == NULL)
        return 0;
    return 1 + max(altura(a->izq), altura(a->der));
}

ab copiar(ab a)
{
    if (a == 0)
    {
        return 0;
    }
    else
    {
        ab newArbol = new nodoAB;
        newArbol->dato = a->dato;
        newArbol->der = copiar(a->der);
        newArbol->izq = copiar(a->izq);
        return newArbol;
    }
}

void liberarArbol(ab &a)
{
    if (a != NULL)
    {
        liberarArbol(a->izq);
        liberarArbol(a->der);
        delete a;
        a = NULL;
    }
}