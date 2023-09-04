#include <iostream>
#include <math.h>

using namespace std;

void pedirNumeros ();
int alCuadrado(int num);
int num;

int main(){

    pedirNumeros();
    cout <<"\n"<< alCuadrado(num);

    return 0;

}

void pedirNumeros (){

    cout<< "Ingrece un número: \n"; cin>>num;

}

int alCuadrado(int num){
    int res;
    res = pow(num, 2);
    return res;
}