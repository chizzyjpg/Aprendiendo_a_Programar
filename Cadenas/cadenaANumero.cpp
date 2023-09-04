#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

    char num1 [10], num2[10];
    float numero;
    int numero2;

    cout << "Ingrece un numero con decimales: ";
    cin.getline(num1, 100);
    cout << "Ingrece un numero entero: ";
    cin.getline(num2, 100);

    numero = atof(num1);
    numero2 = atoi(num2);

    cout << "El resultado de la suma entre " << numero << " y " << numero2 << " es: " << numero + numero2; 

    return 0;

}