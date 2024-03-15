#include <iostream>

using namespace std;

struct dummy
{
    deque *ini;
    deque *fin;
};
typedef dummy *Dummy;

struct deque
{
    int dato;
    deque *sig;
    deque *ant;
};
typedef deque *Deque;

Dummy crearLista();
void agregarInicio(Dummy &, int);
void agregarFinal(Dummy &, int);
void eliminarInicio(Dummy &);
void eliminarUltimo(Dummy &);
int inicio(Dummy &);
int final(Dummy &);
bool esVacia(Dummy &);

int main()
{
    Dummy l = new dummy;
    l = crearLista();

    return 0;
}

Dummy crearLista()
{
    Dummy l = new dummy;
    l->ini = NULL;
    l->fin = NULL;
    return l;
}

void agregarInicio(Dummy &l, int i)
{
    Deque aux = new deque;
    aux->dato = i;
    l->ini->ant = aux;
    aux->sig = l->ini;
    l->ini = aux;
}

void agregarFinal(Dummy &l, int i)
{
    Deque aux = new deque;
    aux->dato = i;
    aux->ant = l->fin;
    l->fin->sig = aux;
    l->fin = aux;
}

void eliminarInicio(Dummy &l)
{
    Deque aux = new deque;
    aux = l->ini;
    l->ini = l->ini->sig;
    l->ini->ant = NULL;
    delete aux;
}

void eliminarUltimo(Dummy &l)
{
    Deque aux = new deque;
    aux = l->fin;
    l->fin = l->fin->ant;
    l->fin->sig = NULL;
    delete aux;
}

int inicio(Dummy &l)
{
    return l->ini->dato;
}

int final(Dummy &l)
{
    return l->fin->dato;
}

bool esVacia(Dummy &l)
{
    bool vacia = false;
    if (l->ini == NULL && l->fin == NULL)
        vacia = true;
    return vacia;    
}
