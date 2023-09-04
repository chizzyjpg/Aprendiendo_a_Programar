#include <iostream>

using namespace std;

int main(){

    int numeros[] = {4,2,5,3,1}, i, pos, aux;

    for ( i = 0 ; i < 5 ; i++){
        cout << numeros[i] << " ";
    }


    for (i=0; i < 5; i++){
        pos = i;
        aux = numeros[i];
        while((pos>0) && (numeros[pos -1] > aux )){
            numeros[pos] = numeros[pos-1];
            pos--;
        }
        numeros[pos] = aux;
    }

    cout << endl;

    for ( i = 0 ; i < 5 ; i++){
        cout << numeros[i] << " ";
    }

    return 0;

}