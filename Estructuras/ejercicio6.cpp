#include <iostream>

using namespace std;

struct Promedio
{

    float nota1, nota2, nota3;
};

struct Alumno
{

    char nombre[25], sexo[15];
    int edad;
    struct Promedio prom;

} alumn[100];

int main()
{

    float pro, proTemp;
    int a, posMP;

    cout << "Ingrece el Numero de Alumnos: ";
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        
        fflush(stdin);

        cout << "Nombre: ";
        cin.getline(alumn[i].nombre, 20, '\n');

        cout << "Sexo: ";
        cin.getline(alumn[i].sexo, 15, '\n');

        cout << "Edad: ";
        cin >> alumn[i].edad;

        cout << "Nota 1: ";
        cin >> alumn[i].prom.nota1;

        fflush(stdin);

        cout << "Nota 2: ";
        cin >> alumn[i].prom.nota2;

        cout << "Nota 3: ";
        cin >> alumn[i].prom.nota3;

        proTemp = (alumn[i].prom.nota1 + alumn[i].prom.nota2 + alumn[i].prom.nota3)/3;

        if (proTemp > pro)
        {

            pro = proTemp;
            posMP = i;
        }
    }

    cout << "\n-----------------------------\n\n";

    cout << "Imprimiendo Datos del Alumno" << endl;

    cout << "Nombre: " << alumn[posMP].nombre << endl;

    cout << "Edad: " << alumn[posMP].edad << endl;

    cout << "Promedio: " << pro;

    return 0;
}