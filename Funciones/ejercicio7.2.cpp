#include <iostream>

using namespace std;

void intercambiar(int&, int&);

int main(){

    int n1, n2;
    cout << "Ingrece 2 numeros: "<< endl; cin>>n1>>n2;

    intercambiar(n1, n2);

    cout << "El primer número es: " << n1 << endl;
    cout << "El segundo número es: " << n2 << endl;


    return 0;

}

void intercambiar(int& n1, int& n2){

    int aux;
    aux = n1;
    n1 = n2;
    n2 = aux;

}