#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct NodoAB
{
    int dato;
    NodoAB *izq;
    NodoAB *der;
};
typedef NodoAB *ab;

void menu(ab);
ab crearArbol(int);
void insertar(ab &, int);
void mostrarArbol(ab, int);

int main()
{
    ab arbol = new NodoAB;
    arbol = NULL;
    menu(arbol);

    return 0;
}

void menu(ab arbol)
{
    int dato, opcion;

    do
    {
        cout << "\t.:Menu:." << endl;
        cout << "1. Insertar elemento." << endl;
        cout << "2. Mosrar Arbol." << endl;
        cout << "3. Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << endl
                 << "Digite un numero: ";
            cin >> dato;
            insertar(arbol, dato);
            cout << endl;
            break;
        case 2:
            mostrarArbol(arbol, 0);
            break;
        case 3:
            cout << "saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no Valida, Seleccione una valida" << endl;
            break;
        }
        system("pause");
        system("clear");
    } while (opcion != 3);
}

ab crearArbol(int numero)
{
    ab newNodo = new NodoAB;

    newNodo->dato = numero;
    newNodo->der = NULL;
    newNodo->izq = NULL;

    return newNodo;
}

void insertar(ab &arbol, int num)
{
    if (arbol == NULL)
    {
        arbol = crearArbol(num);
    }
    else
    {
        if (arbol->dato > num)
        {
            insertar(arbol->izq, num);
        }
        else
        {
            insertar(arbol->der, num);
        }
    }
}

void mostrarArbol(ab arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}