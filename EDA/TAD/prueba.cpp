#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
    nodo *ant;
};
typedef nodo *lista;

lista crearLista(int);
void incertarLuego(lista, int);
void incertarAntes(lista, int);

int main()
{
    lista li = crearLista(4);
    incertarLuego(li, 5);
    incertarAntes(li, 3);

    return 0;
}

lista crearLista(int dato)
{
    lista li = new nodo;
    li->dato = dato;
    return li;
}

void incertarLuego(lista li, int dato)
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

void incertarAntes(lista li, int dato)
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