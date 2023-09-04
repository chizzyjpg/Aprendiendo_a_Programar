#include <iostream>

using namespace std;

struct alumno {

    char nombre[25];
    int edad;
    float promedio;

}alumno[3];

int main(){

    for (int i = 0; i < 3 ; i++){
    
    // Limpia Buffer
    fflush(stdin);

    cout << "Nombre: ";
    cin.getline(alumno[i].nombre, 25, '\n');

    cout << "Edad: ";
    cin>>alumno[i].edad;

    cout << "Promedio: ";
    cin>>alumno[i].promedio;

    cout<<'\n';

    }

    float prom = alumno[0].promedio;
    int j;

    for ( int i = 1; i<3; i++){

        if (prom < alumno[i].promedio){
            prom = alumno[i].promedio;
            j = i;
        }

    }

    cout << "Nombre: "<<alumno[j].nombre<<endl;
    cout << "Edad: "<<alumno[j].edad<<endl;
    cout << "Promedio: "<<alumno[j].promedio<<endl;


}