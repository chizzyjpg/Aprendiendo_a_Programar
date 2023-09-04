#include <iostream>

using namespace std;

void valNuevo(int&, int&);

int main(){

    int num1, num2;
    cout << "Ingrece 2 Números: "; cin>>num1>>num2;

    valNuevo(num1, num2);

    cout << "\nEl nuevo valor del primer dato es: " << num1<< endl;
    cout << "El nuevo valor del segundo dato es: " << num2<< endl;



    return 0;

}

void valNuevo(int& n1, int& n2){

    cout << "El valor del primer dato es: " << n1<< endl;
    cout << "El valor del segundo dato es: " << n2<< endl;

    n1 = 75;
    n2 = 128;

}