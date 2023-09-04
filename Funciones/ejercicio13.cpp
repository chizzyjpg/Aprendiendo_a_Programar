#include <iostream>

using namespace std;

void pedirDatos();

int arr[100], x;

void cambioSigno(int arr[], int x);

int main()
{
    pedirDatos();

    cambioSigno(arr, x);

    for (int i=0; i<x; i++)
    {
        cout << "\n" << arr[i];
    }

    return 0;
}

void pedirDatos()
{
    cout << "Dijite el número de elementos del vector: "; cin>>x;
    cout << '\n';
    for(int i = 0; i < x; i++)
    {
        cout << "Dijite un número: " << endl; cin>>arr[i];
    }
}

void cambioSigno(int arr[], int x)
{
    for (int i=0; i<x; i++)
    {
        arr[i] *= -1;
    }
}