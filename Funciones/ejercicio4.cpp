#include <iostream>

using namespace std;

void pedirNumeros();
float fraccionaria(float n);
void imprimir (float n);
float num;

int main(){

    pedirNumeros();
    imprimir(fraccionaria(num));

    return 0;

}

void pedirNumeros(){
    cout << "Ingrece un número a fraccionar: "; cin>>num;
}

float fraccionaria(float n){
    int i = n;
    float res = n -i;
    return res;
}

void imprimir(float n){
    cout << n;
}
