#include <iostream>

using namespace std;

void pedirDatos();

int vec[100], tam;

int calcularSuma(int vec[], int tam);

int main()
{
    pedirDatos();

    cout << "La suma del vector da: "<< calcularSuma(vec, tam);

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

int calcularSuma(int vec[], int tam)
{
    int suma = 0;

    for(int i = 0; i<tam; i++)
    {
        suma += vec[i];
    }

    return suma;
}
