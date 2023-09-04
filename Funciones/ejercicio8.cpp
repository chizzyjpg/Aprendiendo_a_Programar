#include <iostream>

using namespace std;

void calcular(int, int, int&, int&);
void imprimir(int, int);

int main(){

    int num1, num2, suma=0, producto=0;

    cout << "Ingrece 2 Números: " ; cin>>num1>>num2;
    calcular(num1, num2, suma, producto);
    imprimir(suma, producto);

    return 0;

}

void calcular(int n1, int n2, int& suma, int& producto){

    suma = n1+n2;
    producto = n1*n2;

}

void imprimir(int s, int p){

    cout << "El resultado de la suma es: " << s << endl;
    cout << "El resultado del producto es: " << p << endl;

}