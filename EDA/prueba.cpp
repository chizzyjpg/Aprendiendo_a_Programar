#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
    nodo *ant;
};
typedef nodo *listaVacia;

listaVacia crearLista(int);
void incertarLuego(listaVacia, int);
void incertarAntes(listaVacia, int);

int main()
{
    listaVacia li = crearLista(4);
    incertarLuego(li, 5);
    incertarAntes(li, 3);

    return 0;
}

listaVacia crearLista(int dato)
{
    listaVacia li = new nodo;
    li->dato = dato;
    return li;
}

void incertarLuego(listaVacia li, int dato)
{
    if (li->sig != NULL)
    {
        li = li->sig;
        incertarLuego(li, dato);
    }
    else
    {
        li->sig = new nodo;
        li->sig->ant = li->sig;
        li = li->sig;
        li->dato = dato;
    }
}

void incertarAntes(listaVacia li, int dato)
{
    if (li->ant != NULL)
    {
        li = li->ant;
        incertarAntes(li, dato);
    }
    else
    {
        li->ant = new nodo;
        li->ant->sig = li->ant;
        li = li->ant;
        li->dato = dato;
    }
}