#include <iostream>
#include <cstring>

using namespace std;


int main(){

    char palabra[100], palabra2[100];

    cout << "Ingrece una palabra: \n";
    cin.getline(palabra, 100);
    cout << "Ingrece otra palabra: \n";
    cin.getline(palabra2, 100);

    strupr(palabra);
    strupr(palabra2);

    if ( strcmp(palabra, palabra2) == 0){
        cout << "Las palabras son iguales";
    } else {
        cout << "Las palabras no son iguales";
    }
    return 0;
}