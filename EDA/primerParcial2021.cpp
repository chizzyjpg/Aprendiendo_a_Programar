#include <iostream>

using namespace std;

struct nodo_lista
{
    int info;
    nodo_lista *sig;
};
typedef nodo_lista *Lista;

struct nodo_ocurrencias
{
    int info;
    unsigned cant;
    nodo_ocurrencias *sig;
};
typedef nodo_ocurrencias *ListaOcurrencias;

Lista crearlista(int, Lista);
ListaOcurrencias crear_lista_ocurrencias(Lista);
void imprimir(ListaOcurrencias);
void eliminar_ocurrencias(ListaOcurrencias L, int elem, unsigned cant);
bool separados(Lista);

int main()
{
    Lista lista = crearlista(1, crearlista(3, crearlista(5, crearlista(10, crearlista(15, crearlista(700, NULL))))));
    ListaOcurrencias lo = crear_lista_ocurrencias(lista);
    imprimir(lo);
    eliminar_ocurrencias(lo, 1, 5000);
    cout << '\n';
    imprimir(lo);
    cout << '\n';
    cout << separados(lista) << '\n';
    lista = crearlista(1, crearlista(3, crearlista(5, crearlista(6, crearlista(15, crearlista(700, NULL))))));
    cout << separados(lista);

    return 0;
}

Lista crearlista(int info, Lista sig)
{
    Lista nueva = new nodo_lista;
    nueva->info = info;
    nueva->sig = sig;

    return nueva;
}

ListaOcurrencias crear_lista_ocurrencias(Lista L)
{
    ListaOcurrencias ocu = new nodo_ocurrencias;
    ocu->sig = new nodo_ocurrencias;
    ListaOcurrencias aux = ocu;
    if (L != NULL)
    {
        while (L != NULL)
        {
            if (L->info == aux->info)
                aux->cant += 1;
            if (L->info != aux->info)
            {
                aux->sig = new nodo_ocurrencias;
                aux = aux->sig;
                aux->info = L->info;
                aux->cant = 1;
                aux->sig = NULL;
            }
            L = L->sig;
        }
    }
    return ocu;
}

void imprimir(ListaOcurrencias L)
{
    L = L->sig;
    if (L != NULL)
    {
        cout << "El elemento " << L->info << " aparecio " << L->cant << endl;
        imprimir(L);
    }
    else
        return;
}

void eliminar_ocurrencias(ListaOcurrencias L, int elem, unsigned cant)
{
    if (L != NULL)
    {
        ListaOcurrencias aux = L;
        while (aux != NULL)
        {
            if (aux->info == elem)
            {
                if (aux->cant > cant)
                {
                    aux->cant -= cant;
                }
                else
                {
                    aux->cant = 0;
                }
            }
            aux = aux->sig;
        }
    }
}

bool separados(Lista L)
{
    if (L == NULL || L->sig == NULL)
        return true;
    if (L->sig->info < L->info + 2)
        return false;
    return separados(L->sig);
}