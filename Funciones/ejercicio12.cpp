#include <iostream>

using namespace std;

void pedirDatos();

int vec[100], tam;

bool ordCreciente(int vec[], int tam);

int main()
{
    pedirDatos();

    if (ordCreciente(vec, tam) == 1)
    {
        cout << "\nEl vector está ordenado";
    }
    else
    {
        cout << "\nEl vector no está ordenado";
    }

    return 0;
}

void pedirDatos()
{
    cout << "Dijite el número de elementos del vector: "; cin>>tam;
    cout << '\n';
    for(int i = 0; i < tam; i++)
    {
        cout << "Dijite un número: " << endl; cin>>vec[i];
    }
}

bool ordCreciente(int vec[], int tam)
{
    bool ordenado = true;

    for(int i = 1; i < tam; i++){
        if(vec[i] >= vec[i-1])
        {
            continue;
        }
        if (vec[i] < vec[i-1])
        {
            ordenado = false;
            break;
        }
    }

    return ordenado;
}