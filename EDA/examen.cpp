#include <iostream>

using namespace std;

struct nodoABB
{
    int dato;
    unsigned cantNodos;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

unsigned abs(int n);
unsigned cant_nodos(ABB a);
bool insertar(ABB &a, int x);

int main()
{

    return 0;
}

bool insertar(ABB &a, int x)
{
    ABB buscador = a;
    bool encontrado = false;
    while (encontrado != true)
    {
        if (x < buscador->dato)
        {
            if (buscador->izq != NULL)
            {
                buscador = buscador->izq;
            }
            else
            {
                break;
            }
        }
        else if (x > buscador->dato)
        {
            if (buscador->der != NULL)
            {
                buscador = buscador->der;
            }
            else
            {
                break;
            }
        }
        else if (x = buscador->dato)
        {
            encontrado = true;
        }

        if (encontrado == false)
        {
            ABB aux = a;
            while (encontrado == false)
            {
                if (x < buscador->dato)
                {
                    if (buscador->izq != NULL)
                    {
                        buscador = buscador->izq;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (x > buscador->dato)
                {
                    if (buscador->der != NULL)
                    {
                        buscador = buscador->der;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
