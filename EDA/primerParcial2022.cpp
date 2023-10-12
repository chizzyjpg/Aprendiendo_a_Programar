#include <iostream>

using namespace std;

struct nodoLista {
 int info;
 nodoLista * sig;
};
typedef nodoLista * Lista;

Lista crearlista(int info, Lista sig);
void juntarRepetidos (Lista L);

int main()
{
    Lista lista = crearlista(1, crearlista(1, crearlista(2, crearlista(3, crearlista(2, crearlista(4, crearlista(1, NULL)))))));
    return 0;
}

Lista crearlista(int info, Lista sig)
{
    Lista nueva = new nodoLista;
    nueva->info = info;
    nueva->sig = sig;

    return nueva;
}

void juntarRepetidos (Lista L)
{
    int aux;
    while (L->sig != NULL)
    {
        Lista ayu = L
        if()
    }
    
}