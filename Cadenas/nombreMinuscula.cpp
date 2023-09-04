#include <iostream>
#include <string.h>

using namespace std;


int main(){

    char nombre[100];

    cout << "Ingrece su nombre en mayusculas: ";
    cin.getline(nombre, 100);

    if ( nombre[0] == 'A' ){
        strlwr(nombre);
    }
    cout << nombre;

    return 0;

}