#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
}p1;

void pedirDatos();
void mostrarDatos(Persona);


int main()
{
    pedirDatos();
    mostrarDatos(p1);

    return 0;
}

void pedirDatos()
{
    cout << "Ingrece el nombre de la persona: "; getline(cin, p1.nombre);
    cout << "Ingrece la edad de la persona: "; cin>>p1.edad;
}

void mostrarDatos(Persona p)
{
    cout << "\nNombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
}