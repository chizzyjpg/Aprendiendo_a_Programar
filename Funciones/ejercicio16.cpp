#include <iostream>

using namespace std;

void pedirDatos();
void cualEsMayor(int m[][100], int nf, int nc, int arr[]);
void mostrarMatriz(int m[][100], int x, int y, int arr[]);

int m[100][100], arr[100], nf, nc;

int main()
{
    pedirDatos();
    cualEsMayor(m, nf, nc, arr);
    mostrarMatriz(m, nf, nc, arr);

    return 0;
}

void pedirDatos()
{
    cout << "Ingrece numero de filas: ";
    cin >> nf;
    cout << "Ingrece numero de columnas: ";
    cin >> nc;

    for (int i = 0; i < nf; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << "\nIngrece un número: ";
            cin >> m[i][j];
        }
    }
}

void cualEsMayor(int m[][100], int nf, int nc, int arr[])
{

    for(int i=0; i<nf; i++)
    {
        arr[i] = m[i][0];
        for(int j=0; j<nc; j++)
        {
            if (m[i][j] > arr[i])
            {
                arr[i] = m[i][j];
            }
        }
    }
}

void mostrarMatriz(int m[][100], int x, int y, int arr[])
{
    for (int i = 0; i < x; i++)
    {
        cout << '\n';
        for (int j = 0; j < y; j++)
        {
            cout << ' ' << m[i][j];
        }
    }
    cout << "\nY los numeros mayores de cada fila son: " <<endl;
    for (int j=0; j<x; j++)
    {
        cout << ' ' << arr[j] << endl;
    }
}