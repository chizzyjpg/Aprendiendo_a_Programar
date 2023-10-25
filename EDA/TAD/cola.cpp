#include <iostream>

typedef int T;

struct Nodo
{
    T valor;
    Nodo *sig;
};

struct RepresentacionCola
{
    Nodo *primero, *ultimo;
};
typedef RepresentacionCola *Cola;

Cola crearCola()
{
    Cola c = new RepresentacionCola;
    c->primero = c->ultimo = NULL;
    return c;
}

void encolar(T t, Cola &c)
{
    if (c->primero == NULL)
    {
        c->primero->valor = t;
        c->ultimo->valor = t;
    }
    if (c->ultimo != NULL)
    {
        c->ultimo->sig = new Nodo;
        c->ultimo->sig->valor = t;
        c->ultimo = c->ultimo->sig;
    }
};
/* Agrega el elemento t al final de c. */

bool esVaciaCola(Cola c)
{
    bool siONo;
    if (c->primer == NULL && c->ultimo == NULL)
    {
        siONo = true;
    }
    else
    {
        siONo = false;
    }
}
/* Devuelve 'true' si c es vacia, 'false' en otro caso. */

T frente(Cola c);
/* Devuelve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */

void desencolar(Cola &c);
/* Remueve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */

void destruirCola(Cola &c);
/* Libera toda la
(Cola &c);
memoria ocupada por c. */
