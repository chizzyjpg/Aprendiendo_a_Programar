#include <iostream>

using namespace std;

int main(){

    int numeros[] = {5,3,4,1,2}, i, j, aux;

    for ( i = 0 ; i < 5 ; i++){
        cout << numeros[i] << " ";
    }

    for (i=0; i < 5; i++){
        for(j=0; j < 5; j++){
            if (numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }

    cout << endl;

    for ( i = 0 ; i < 5 ; i++){
        cout << numeros[i] << " ";
    }

    return 0;

}