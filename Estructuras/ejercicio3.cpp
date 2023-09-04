#include <iostream>

using namespace std;

struct empleado{

    char nombre[25];
    float salario;

}emp[100];

void imprimir(string mm, string nom, float sal){

    cout << "El empleado con el " << mm << " salario es " << nom << " con un salario de $" << sal << endl;

}


int main() {

    int num, imin, imax;
    float min = 999999999 , max = 0;
    cout << "Ingrece cuantos empleados tiene: " ;
    cin >> num;

    for (int i=0; i<num; i++){

        fflush(stdin);

        cout << "\nNombre: ";
        cin.getline(emp[i].nombre, 25, '\n');

        cout << "Salario: ";
        cin >> emp[i].salario;
    
        if (emp[i].salario < min){

            min = emp[i].salario;
            imin = i;
        
        }
        
        if (emp[i].salario > max){
        
            max = emp[i].salario;
            imax = i;

        }

    }

    imprimir("mayor", emp[imax].nombre, max);
    imprimir("menor", emp[imin].nombre, min);
    

    return 0;

}