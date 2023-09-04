#include <iostream>
#include <math.h>

using namespace std;

void pedirNumeros ();
int funpot(int num, int pot);
int num, pot;

int main(){

    pedirNumeros();
    cout <<"\n"<< funpot(num, pot);

    return 0;

}

void pedirNumeros (){

    cout<< "Ingrece un número: \n"; cin>>num;
    cout<< "Ingrece la potencia: \n"; cin>>pot;


}

int funpot(int x, int y){

    long res;
    res = pow(x, y);
    return res;

}