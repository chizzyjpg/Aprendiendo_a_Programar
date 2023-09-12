#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned int uint;

struct nodoAB
{
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

struct nodoABB
{
    uint elem;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

struct nodoLista
{
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;

struct nodoAG
{
    int elem;
    nodoAG *pH;
    nodoAG *sH;
};
typedef nodoAG *AG;

struct EstInfo
{
    uint nota; // dato
    int ci;    // clave
};

struct nodoABBEstudiantes
{
    EstInfo info;
    nodoABBEstudiantes *izq, *der;
};
typedef nodoABBEstudiantes *ABBEstudiantes;

// **************************************************************************

void imprimirAB_enOrden(AB);
void imprimirNivelK(AB, uint);
void imprimirElegante(AB);
uint altura(AB);
AB copiar(AB);

// **************************************************************************

void imprimirAB_enOrden(AB a)
{
    if (a != NULL)
    {
        cout << a->elem << "    ";
        imprimirAB_enOrden(a->izq);
        imprimirAB_enOrden(a->der);
    }
}

void imprimirNivelK(AB raiz, uint k)
{
    if (raiz != NULL && k > 0)
    {
        if (k == 1)
            cout << raiz->elem << "  ";
        else
        {
            imprimirNivelK(raiz->izq, k - 1);
            imprimirNivelK(raiz->der, k - 1);
        }
    }
}

// Función para imprimir el árbol binario de manera elegante con espaciado centrado
void imprimirElegante(AB a)
{
    if (a == NULL)
        cout << "###";
    else
    {
        uint h = altura(a);
        for (uint i = 1; i <= h; i++)
        {
            int espacios = pow(2, (h - i + 1)); // Cálculo de espacios
            for (int j = 0; j < espacios / 2; j++)
            {
                cout << " ";
            }
            imprimirNivelK(a, i);
            cout << endl;
        }
    }
}

// EJERCICIO 1

AB consArbol(uint x, AB subArbol_izq, AB subArbol_der)
{
    AB res = new nodoAB;
    res->elem = x;
    res->izq = subArbol_izq;
    res->der = subArbol_der;
    return res;
}

uint contarElems(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + contarElems(a->izq) + contarElems(a->der);
}

uint contarHojas(AB a)
{
    if (a == NULL)
        return 0;
    if (a->izq == NULL && a->der == NULL)
        return 1;
    return contarHojas(a->izq) + contarHojas(a->der);
}

uint altura(AB a)
{
    if (a == NULL)
        return 0;
    return 1 + max(altura(a->izq), altura(a->der));
}

AB copiar(AB a)
{
    if (a == NULL)
        return NULL;
    AB res = new nodoAB;
    res->elem = a->elem;
    res->izq = copiar(a->izq);
    res->der = copiar(a->der);
    return res;
}

void liberarArbol(AB &a)
{
    if (a != NULL)
    {
        liberarArbol(a->izq);
        liberarArbol(a->der);
        delete a;
        a = NULL;
    }
}

// EJERCICIO 2
void imprimir(Lista L)
{
    while (L != NULL)
    {
        cout << "|" << L->elem << "| - ";
        L = L->sig;
    }
    cout << "#";
}

Lista insComienzo(uint elem, Lista L)
{
    Lista nuevo = new nodoLista;
    nuevo->elem = elem;
    nuevo->sig = L;
    return nuevo;
}

Lista merge(Lista L1, Lista L2)
{
    if (L1 == NULL)
        return L2;
    Lista aux = L1;
    while (aux->sig != NULL)
        aux = aux->sig;
    aux->sig = L2;
    return L1;
}
// a) i)

Lista enOrden(AB a)
{
    if (a == NULL)
        return NULL;
    Lista der = enOrden(a->der);
    Lista izq = enOrden(a->izq);
    der = insComienzo(a->elem, der);

    return merge(izq, der);
}

// a) iv)
bool esCamino(Lista L, AB a)
{
    if (a == NULL || L == NULL)
        return false;
    if (a->elem != L->elem)
        return false;
    if (a->izq == NULL && a->der == NULL)
        return L->sig == NULL;
    return esCamino(L->sig, a->izq) || esCamino(L->sig, a->der);
}

bool mayor(Lista L1, Lista L2)
{
    if (L2 == NULL)
        return true;
    if (L1 == NULL)
        return false;
    return mayor(L1->sig, L2->sig);
}

Lista camino_mas_largo(AB a)
{
    if (a == NULL)
        return NULL;
    Lista izq = camino_mas_largo(a->izq);
    Lista der = camino_mas_largo(a->der);
    if (mayor(izq, der))
        return insComienzo(a->elem, izq);
    else
        return insComienzo(a->elem, der);
}

// b)
bool esPerfecto(AB a, uint h)
{
    if (a == NULL)
        return h == 0;
    if (a->izq == NULL && a->der == NULL)
        return h == 1;
    if (a->izq == NULL || a->der == NULL)
        return false;
    return (h > 1 && esPerfecto(a->izq, h - 1) && esPerfecto(a->der, h - 1));
}

// EJERCICIO 3 -- ARBOLES BINARIOS DE BÚSQUEDA

void insertarABB(ABB &a, uint x)
{
    if (a == NULL)
    {
        a = new nodoABB;
        a->elem = x;
        a->der = a->izq = NULL;
        return;
    }
    if (x < a->elem)
        insertarABB(a->izq, x);
    if (x > a->elem)
        insertarABB(a->der, x);
}

bool pertenece(ABB a, uint x)
{
    if (a == NULL)
        return false;
    if (a->elem == x)
        return true;
    if (x < a->elem)
        return pertenece(a->izq, x);
    else
        return pertenece(a->der, x);
}

bool pertenece_iterativo(ABB a, uint x)
{
    while (a != NULL)
    {
        if (a->elem == x)
            return true;
        if (x < a->elem)
            a = a->izq;
        else
            a = a->der;
    }
    return false;
}

// pre-condición: a no es vacío
uint maxABB(ABB a)
{
    while (a->der != NULL)
        a = a->der;
    return a->elem;
}

// pre-condición: a no es vacío
void removerMaxABB(ABB &a)
{
    if (a->der == NULL)
    {
        ABB borrar = a;
        a = a->izq;
        delete borrar;
    }
    else
        removerMaxABB(a->der);
}

// EJERCICIO 4

// SOLUCIÓN FÁCIL

void insertarABBEstudiantes(ABBEstudiantes &a, EstInfo x)
{
    if (a == NULL)
    {
        a = new nodoABBEstudiantes;
        a->info = x;
        a->der = a->izq = NULL;
        return;
    }
    if (x.ci < a->info.ci)
        insertarABBEstudiantes(a->izq, x);
    if (x.ci > a->info.ci)
        insertarABBEstudiantes(a->der, x);
}

void incluir(ABBEstudiantes a, uint cota, ABBEstudiantes &res)
{
    if (a != NULL)
    {
        if (a->info.nota > cota)
        {
            insertarABBEstudiantes(res, a->info);
        }
        incluir(a->izq, cota, res);
        incluir(a->der, cota, res);
    }
}

ABBEstudiantes filtrado_facil(ABBEstudiantes a, uint cota)
{
    ABBEstudiantes res = NULL;
    incluir(a, cota, res);
    return res;
}

// SOLUCIÓN TAL COMO LO PIDEN EN LA LETRA

// pre-condición: a no es vacío
EstInfo maxABBEstudiantes(ABBEstudiantes a)
{
    while (a->der != NULL)
        a = a->der;
    return a->info;
}

// pre-condición: a no es vacío
void removerMaxABBEstudiantes(ABBEstudiantes &a)
{
    if (a->der == NULL)
    {
        ABBEstudiantes borrar = a;
        a = a->izq;
        delete borrar;
    }
    else
        removerMaxABBEstudiantes(a->der);
}

ABBEstudiantes filtrado(ABBEstudiantes a, uint cota)
{
    if (a == NULL)
        return NULL;
    ABBEstudiantes res_izq = filtrado(a->izq, cota);
    ABBEstudiantes res_der = filtrado(a->der, cota);
    if (a->info.nota > cota)
    {
        ABBEstudiantes res = new nodoABBEstudiantes;
        res->info = a->info;
        res->izq = res_izq;
        res->der = res_der;
        return res;
    }
    if (res_izq == NULL)
        return res_der;
    EstInfo mayor = maxABBEstudiantes(res_izq);
    removerMaxABBEstudiantes(res_izq);
    ABBEstudiantes res = new nodoABBEstudiantes;
    res->info = mayor;
    res->izq = res_izq;
    res->der = res_der;
    return res;
}

// EJERCICIO 5 -- ÁRBOLES GENERALES

AG arbolHoja(int x)
{
    AG a = new nodoAG;
    a->elem = x;
    a->sH = a->pH = NULL;
    return a;
}

// pre-condición: a no es vacío
bool esArbolHoja(AG a)
{
    return a->pH == NULL;
}

// pertenece: Dados un árbol y un entero x, retorna true si y solo si x pertenece al árbol.
bool pertenece(AG a, int x)
{
    if (a == NULL)
        return false;
    if (a->elem == x)
        return true;
    return pertenece(a->sH, x) || pertenece(a->pH, x);
}

// pre-condición: a no es vacío
void insertar(int p, int h, AG a)
{
    if (a->elem != h)
    {
        if (a->elem == p)
        {
            AG nuevo = new nodoAG;
            nuevo->elem = h;
            nuevo->pH = NULL;
            nuevo->sH = a->pH;
            a->pH = nuevo;
        }
        else
        {
            if (a->pH != NULL)
                insertar(p, h, a->pH);
            if (a->sH != NULL)
                insertar(p, h, a->sH);
        }
    }
}

void borrarHoja(AG arbolitodenavidadquelegustaalchepy, uint elnumeritoflipantealquetengoqueborrar)
{
    if (arbolitodenavidadquelegustaalchepy != NULL)
    {
        if (arbolitodenavidadquelegustaalchepy->elem == elnumeritoflipantealquetengoqueborrar && arbolitodenavidadquelegustaalchepy->pH == NULL && arbolitodenavidadquelegustaalchepy->sH == NULL)
        {
            delete arbolitodenavidadquelegustaalchepy;
        }
        else
        {
            borrarHoja(arbolitodenavidadquelegustaalchepy->pH, elnumeritoflipantealquetengoqueborrar);
            borrarHoja(arbolitodenavidadquelegustaalchepy->sH, elnumeritoflipantealquetengoqueborrar);
        }
    }
}

int main()
{
    return 0;
}