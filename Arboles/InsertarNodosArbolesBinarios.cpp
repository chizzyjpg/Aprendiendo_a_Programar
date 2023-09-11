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
void preOrden(ab);
void mostrarArbolATS(ab, int);
bool busqueda(ab, int);
void enOrden(ab);
void postOrden(ab);

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
        cout << "2. Mostrar Arbol." << endl;
        cout << "3. Mostrar Arbol ATS." << endl;
        cout << "4. Busqueda de un elemento." << endl;
        cout << "5. Mostrar en orden." << endl;
        cout << "6. Mostrar en post orden." << endl;
        cout << "7. Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << endl
                 << "Digite un elemento: ";
            cin >> dato;
            insertar(arbol, dato);
            cout << endl;
            system("pause");
            break;
        case 2:
            preOrden(arbol);
            cout << endl;
            system("pause");
            break;
        case 3:
            mostrarArbolATS(arbol, 0);
            system("pause");
            break;
        case 4:
        {
            cout << endl
                 << "Digite el elemento: ";
            cin >> dato;
            if (busqueda(arbol, dato) == true)
            {
                cout << "El elemento " << dato << " se encuentra en el Arbol." << endl;
            }
            else
            {
                cout << "El elemento " << dato << " no se encuentra en el Arbol" << endl;
            }
            system("pause");
            break;
        }
        case 5:
            enOrden(arbol);
            system("pause");
            cout << endl;
            break;
        case 6:
            postOrden(arbol);
            system("pause");
            cout << endl;
            break;
        case 7:
            cout << "saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no Valida, Seleccione una valida" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 7);
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

void preOrden(ab arbol)
{
    if (arbol != NULL)
    {
        cout << "|" << arbol->dato << "| ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void mostrarArbolATS(ab arbol, int cont)
{
    if (arbol != NULL)
    {
        mostrarArbolATS(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbolATS(arbol->izq, cont + 1);
    }
}

bool busqueda(ab arbol, int numero)
{
    if (arbol != NULL)
    {
        if (arbol->dato == numero)
        {
            return true;
        }
        else if (arbol->dato > numero)
        {
            return busqueda(arbol->izq, numero);
        }
        else
        {
            return busqueda(arbol->der, numero);
        }
    }
    else
    {
        return false;
    }
}

void enOrden(ab arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izq);
        cout << "|" << arbol->dato << "| ";
        enOrden(arbol->der);
    }
}

void postOrden(ab arbol)
{
    if (arbol != NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << "|" << arbol->dato << "| ";
        }
}