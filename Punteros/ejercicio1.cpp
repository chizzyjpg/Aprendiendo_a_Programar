#include <iostream>

using namespace std;

int pedirDato();

int main()
{
    int *dirNum;

    *dirNum = pedirDato();

    if ((*dirNum%2) == 0)
    {
        cout << "el numero " << *dirNum << " es par, y su direccion de memoria es: " << dirNum;
    }
    else
    {
        cout << "el numero " << *dirNum << " es impar, y su direccion de memoria es: " << dirNum;
    }

    return 0;
}

int pedirDato()
{
    int n;
    cout << "Ingrece un número: "; cin>>n;
    return n;
}