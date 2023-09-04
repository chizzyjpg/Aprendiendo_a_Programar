#include <iostream>

using namespace std;

void cuadrado(int vec[], int);

int main()
{
    const int TAM = 5;
    int vec[TAM] = {1,2,3,4,5};

    for (int i = 0; i<TAM; i++)
    {
        cout << vec[i] << endl;
    }

    cout << '\n';

    cuadrado(vec, TAM);

    for (int i = 0; i<TAM; i++)
    {
        cout << vec[i] << endl;
    }


    return 0;
}

void cuadrado(int vec[], int tam)
{
    for ( int i = 0; i<tam; i++)
    {
        vec[i] *= vec[i];
    }
}