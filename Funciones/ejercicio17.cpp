#include <iostream>

using namespace std;

struct Complejo
{
    float real, imaginaria;
}z1, z2;

void pedirDatos();
Complejo suma(Complejo, Complejo);
void muestra(Complejo);

int main()
{
    pedirDatos();
    Complejo x = suma(z1, z2);
    muestra(x);

    return 0;
}

void pedirDatos()
{
    cout << "Ingrece los datos para el primer numero comlpejo: " << endl;
    cout << "Numero real: "; cin>>z1.real;
    cout << "Numero imaginaria: "; cin>>z1.imaginaria;

    cin.ignore();

    cout << "\nIngrece los datos para el segundo numero comlpejo: " << endl;
    cout << "Numero real: "; cin>>z2.real;
    cout << "Numero imaginaria: "; cin>>z2.imaginaria;
}

Complejo suma(Complejo z1, Complejo z2)
{
    z1.real += z2.real;
    z1.imaginaria += z2.imaginaria;

    return z1;
}

void muestra(Complejo i)
{
    cout << "\nEl resultado es: " << i.real << " , " << i.imaginaria;
}

