#include <iostream>
#include <stdlib.h>

using namespace std;

void pedirNotas();
void imprimirNotas();

int numCalif, *calif;

int main()
{
    pedirNotas();
    imprimirNotas();

    delete[] calif;

    return 0;
}

void pedirNotas()
{
    cout << "Ingrece numero de calificaciones: "; cin>>numCalif;

    calif = new int[numCalif];
    
    for(int i=0; i<numCalif; i++)
    {
        cout << "\nIngrece un dato para la pocicion ["<<i<<"]: "; cin>>calif[i];
    }
}

void imprimirNotas()
{
    for(int i=0; i<numCalif; i++)
    {
        cout << "\nNota en la posicion ["<<i<<"]: " << calif[i];
    }
}