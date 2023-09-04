#include <iostream>

using namespace std;

struct dirInfo {

    char direccion[50];
    char ciudad[25];
    char provincia_departamento[25];

};

struct empInfo {

    char nombre[40];
    struct dirInfo dirEmp;
    double salario;

} empleado[2];


int main(){

    empleado[0] = {"Leandro", "Carretera Boca del Cufré", "Ecilda Paullier", "San José", 10000};

    cout << "Nombre: ";
    cin.getline(empleado[1].nombre, 40, '\n');

    cout << "Direccion: ";
    cin.getline(empleado[1].dirEmp.direccion, 50, '\n');

    cout << "Ciudad: ";
    cin.getline(empleado[1].dirEmp.ciudad, 40, '\n');

    cout << "Provincia o Departamento: ";
    cin.getline(empleado[1].dirEmp.provincia_departamento, 40, '\n');

    cout << "Salario: ";
    cin >> empleado[1].salario;


    cout << "El empleado " << empleado[0].nombre << endl;
    cout << "Vive en " << empleado[0].dirEmp.direccion << " de la ciudad " << empleado[0].dirEmp.ciudad << " de " << empleado[0].dirEmp.provincia_departamento << endl;
    cout << "Tiene un salario de $" << empleado[0].salario << endl; 

    cout << "El empleado " << empleado[1].nombre << endl;
    cout << "Vive en " << empleado[1].dirEmp.direccion << " de la ciudad " << empleado[1].dirEmp.ciudad << " de " << empleado[1].dirEmp.provincia_departamento << endl;
    cout << "Tiene un salario de $" << empleado[1].salario << endl; 

    

    return 0;

}