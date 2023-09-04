#include <iostream>

using namespace std; 

void pedirNumeros ();
float mult(float x, float y);

float f1, f2;

int main(){

    pedirNumeros();
    cout <<"\n"<< mult(f1, f2);

    return 0;

}

void pedirNumeros (){

    cout<< "Ingrece 2 números: \n"; cin>>f1>>f2;

}

float mult(float x, float y){

    return x*y;

}