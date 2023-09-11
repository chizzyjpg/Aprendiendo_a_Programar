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
void mostrarArbol(ab);
bool busqueda(ab, int);

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
        cout << "3. Busqueda de 1 dato." << endl;
        cout << "4. Salir." << endl;
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
            mostrarArbol(arbol);
            break;
        case 3:
            cout << endl
                 << "Digite el numero: ";
            cin >> dato;

            break;
        case 4:
            cout << "saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no Valida, Seleccione una valida" << endl;
            break;
        }
        system("pause");
        system("cls");
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

void mostrarArbol(ab arbol)
{
    if (arbol != NULL)
    {
        cout << "|" << arbol->dato << "| ";
        mostrarArbol(arbol->izq);
        mostrarArbol(arbol->der);
    }
}

bool busqueda(ab arbol, int numero)
{
    if (arbol != NULL)
    {
    }
}