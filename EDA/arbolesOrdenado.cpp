#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned int uint;

struct nodoAB;
typedef nodoAB *AB;

struct nodoAB
{
    uint elem;
    AB izq, der;
};

struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

void imprimirAB_enOrden(AB);
void imprimirNivelK(AB, uint);
void imprimirElegante(AB);
uint altura(AB);
AB copiar(AB);

// *************************************

void imprimirAB_enOrden(AB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimirAB_enOrden(a->izq);
        imprimirAB_enOrden(a->der);
    }
}

void imprimirNivelK(AB raiz, uint k)
{
    if (raiz != NULL && k > 0)
    {
        if (k == 1)
            cout << raiz->elem << "  ";
        else
        {
            imprimirNivelK(raiz->izq, k - 1);
            imprimirNivelK(raiz->der, k - 1);
        }
    }
}

// Función para imprimir el árbol binario de manera elegante con espaciado centrado
void imprimirElegante(AB a)
{
    if (a == NULL)
        cout << "###";
    else
    {
        uint h = altura(a);
        for (uint i = 1; i <= h; i++)
        {
            int espacios = pow(2, (h - i + 1)); // Cálculo de espacios
            for (int j = 0; j < espacios / 2; j++)
            {
                cout << " ";
            }
            imprimirNivelK(a, i);
            cout << endl;
        }
    }
}

// EJERCICIO 1

AB consArbol(uint x, AB subArbol_izq, AB subArbol_der)
{
    AB res = new nodoAB;
    res->elem = x;
    res->izq = subArbol_izq;
    res->der = subArbol_der;
    return res;
}

uint contarElems(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + contarElems(a->izq) + contarElems(a->der);
}

uint contarHojas(AB a)
{
    if (a == NULL)
        return 0;
    if (a->izq == NULL && a->der == NULL)
        return 1;
    return contarHojas(a->izq) + contarHojas(a->der);
}

uint altura(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + max(altura(a->izq), altura(a->der));
}

AB copiar(AB a)
{
    if (a == NULL)
        return NULL;
    AB res = new nodoAB;
    res->elem = a->elem;
    res->izq = copiar(a->izq);
    res->der = copiar(a->der);
    return res;
}

void liberarArbol(AB &a)
{
    if (a != NULL)
    {
        liberarArbol(a->izq);
        liberarArbol(a->der);
        delete a;
        a = NULL;
    }
}

// EJERCICIO 2
void imprimir(Lista L)
{
    while (L != NULL)
    {
        cout << "|" << L->elem << "| - ";
        L = L->sig;
    }
    cout << "#";
}

Lista insComienzo(uint elem, Lista L)
{
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = L;
    return nuevo;
}

Lista merge(Lista L1, Lista L2)
{
    if (L1 == NULL)
        return L2;
    Lista aux = L1;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = L2;
    return L1;
}
// a) i)

Lista enOrden(AB a)
{
    if (a == NULL)
        return NULL;
    Lista der = enOrden(a->der);
    Lista L = insComienzo(a->elem, der);
    return merge(enOrden(a->izq), L);
}

// a) iv)
bool esCamino(Lista L, AB a)
{
    if (a == NULL || L == NULL)
        return false;
    if (a->elem != L->elem)
        return false;
    if (a->izq == NULL && a->der == NULL)
        return L->sig == NULL;
    return esCamino(L->sig, a->izq) || esCamino(L->sig, a->der);
}

bool mayor(Lista L1, Lista L2)
{
    if (L2 == NULL)
        return true;
    if (L1 == NULL)
        return false;
    return mayor(L1->sig, L2->sig);
}

Lista camino_mas_largo(AB a)
{
    if (a == NULL)
        return NULL;
    Lista izq = camino_mas_largo(a->izq);
    Lista der = camino_mas_largo(a->der);
    if (mayor(izq, der))
        return insComienzo(a->elem, izq);
    else
        return insComienzo(a->elem, der);
}

int main()
{
    AB izq = consArbol(2, consArbol(1, consArbol(0, NULL, NULL), NULL), consArbol(3, NULL, NULL));
    AB der = consArbol(8, consArbol(7, NULL, NULL), NULL);
    AB raiz = consArbol(6, izq, der);

    imprimirElegante(raiz);
    cout << endl;
    Lista L = NULL;

    L = insComienzo(7, L);
    L = insComienzo(8, L);
    L = insComienzo(6, L);
    imprimir(L);
    cout << endl;
    if (esCamino(L, raiz))
        cout << "es camino";
    else
        cout << "no es camino";

    L = camino_mas_largo(raiz);
    imprimir(L);

    return 0;
}