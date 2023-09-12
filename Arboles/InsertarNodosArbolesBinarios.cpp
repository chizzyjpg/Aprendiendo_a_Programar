#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct NodoAB
{
    int dato;
    NodoAB *izq;
    NodoAB *der;
    NodoAB *padre;
};
typedef NodoAB *ab;

void menu(ab);
ab crearArbol(int, ab);
void insertar(ab &, int, ab);
void preOrden(ab);
void mostrarArbolATS(ab, int);
bool busqueda(ab, int);
void enOrden(ab);
void postOrden(ab);
void eliminar(ab, int);
void eliminarElNodo(ab);
ab minimo(ab);
void reemplasar(ab, ab);
void destruirNodo(ab);

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
        cout << "7. Borrar un nodo del arbol." << endl;
        cout << "8. Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << endl
                 << "Digite un elemento: ";
            cin >> dato;
            insertar(arbol, dato, NULL);
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
            cout << "Digite el numero a eliminar: ";
            cin >> dato;
            eliminar(arbol, dato);
            cout << endl;
            system("pause");
            break;
        case 8:
            cout << "saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no Valida, Seleccione una valida" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 8);
}

ab crearArbol(int numero, ab padre)
{
    ab newNodo = new NodoAB;

    newNodo->dato = numero;
    newNodo->der = NULL;
    newNodo->izq = NULL;
    newNodo->padre = padre;

    return newNodo;
}

void insertar(ab &arbol, int num, ab padre)
{
    if (arbol == NULL)
    {
        arbol = crearArbol(num, padre);
    }
    else
    {
        if (arbol->dato > num)
        {
            insertar(arbol->izq, num, arbol);
        }
        else
        {
            insertar(arbol->der, num, arbol);
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
    else
    {
        return;
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
    else
    {
        return;
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
    else
    {
        return;
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
    else
    {
        return;
    }
}

void eliminar(ab arbol, int numero)
{
    if (arbol->dato == NULL)
    {
        return;
    }
    else if (arbol->dato > numero)
    {
        eliminar(arbol->izq, numero);
    }
    else if (arbol->dato < numero)
    {
        eliminar(arbol->der, numero);
    }
    else
    {
        eliminarElNodo(arbol);
    }
}

void eliminarElNodo(ab eliminarNodo)
{
    if (eliminarNodo->izq && eliminarNodo->der)
    {
        ab menor = minimo(eliminarNodo->der);
        eliminarNodo->dato = menor->dato;
        eliminarElNodo(menor);
    }
    else if (eliminarNodo->izq)
    {
        reemplasar(eliminarNodo, eliminarNodo->izq);
        destruirNodo(eliminarNodo);
    }
    else if (eliminarNodo->der)
    {
        reemplasar(eliminarNodo, eliminarNodo->der);
        destruirNodo(eliminarNodo);
    }
    else
    {
        reemplasar(eliminarNodo, NULL);
        destruirNodo(eliminarNodo);
    }
}

ab minimo(ab arbol)
{
    if (arbol == NULL)
    {
        return NULL;
    }
    if (arbol->izq)
    {
        return minimo(arbol->izq);
    }
    else
    {
        return arbol;
    }
}

void reemplasar(ab nodo, ab nodoAReemplasar)
{
    if (nodo->padre)
    {
        if (nodo->dato == nodo->padre->izq->dato)
        {
            nodo->padre->izq = nodoAReemplasar;
        }
        else if (nodo->dato == nodo->padre->der->dato)
        {
            nodo->padre->der = nodoAReemplasar;
        }
    }
    if (nodoAReemplasar)
    {
        nodoAReemplasar->padre = nodo->padre;
    }
}

void destruirNodo(ab nodo)
{
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}