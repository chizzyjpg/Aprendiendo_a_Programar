#include <iostream>

using namespace std;

int main(){

     int numeros[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                       21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                       31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                       41, 42, 43, 44, 45, 46, 47, 48, 49, 50}, inf, mit, sup, dato = 10;

    char band = 'F';

    inf = 0;
    sup = 50 ;

    while (inf <= sup)
    {
        mit = (inf+sup)/2;

        if (numeros[mit] == dato){
            band = 'V';
            break;
        }

        if (numeros[mit] > dato){
            sup = mit;

        }

        if (numeros[mit] < dato){
            inf = mit;
        }
    }

    if (band == 'V'){
        cout << "El numero " << dato << " se encuentra en la posicion " << mit;
    }else{
        cout << "El numero " << dato << " no se encuentra en la lista";
    }

    return 0;

}