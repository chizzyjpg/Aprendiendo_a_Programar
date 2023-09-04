#include <iostream>

using namespace std;

struct Promedio {

    float nota1, nota2, nota3;

};

struct Alumno {

    char nombre[25], sexo[15];
    int edad;
    struct Promedio prom;


}alumn;


int main(){

    float pro;

    cout << "Nombre: ";
    cin.getline(alumn.nombre, 20, '\n');
    
    cout << "Sexo: ";
    cin.getline(alumn.sexo, 15, '\n');
    
    cout << "Edad: ";
    cin >> alumn.edad;

    cout << "Nota 1: ";
    cin >> alumn.prom.nota1;

    fflush(stdin);

    cout << "Nota 2: ";
    cin >> alumn.prom.nota2;

    cout << "Nota 3: ";
    cin >> alumn.prom.nota3;

    pro = (alumn.prom.nota1 + alumn.prom.nota2 + alumn.prom.nota3)/3;

    cout << "\n-----------------------------\n\n";

    cout << "Imprimiendo Datos del Alumno" << endl;

    cout << "Nombre: " << alumn.nombre << endl;

    cout << "Edad: " << alumn.edad << endl;

    cout << "Promedio: " << pro;



    return 0;

}