#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};
typedef nodo *Lista;

void mostrar(Lista L);
Lista crearLista();
Lista subLista(Lista L, int p1, int p2);

int main()
{
    Lista L = crearLista();
    mostrar(L);

    return 0;
}

Lista crearLista()
{
    Lista L = new nodo;
    L->dato = 1;
    L->sig = new nodo;
    Lista aux = L->sig;
    for (int i = 2; i <= 5; i++)
    {
        aux->dato = i;
        aux->sig = new nodo;
        aux = aux->sig;
    }
    aux = NULL;
    return L;
}

void mostrar(Lista L)
{
    Lista aux = L;
    while (L != NULL)
    {
        cout << aux->dato << endl;
        aux = aux->sig;
    }
}