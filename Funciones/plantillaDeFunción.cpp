#include <iostream>

using namespace std;

template <class TDDATO>
void mostrarAbsoluto (TDDATO num);

int main(){

    int entero = 15;
    float flotante = -12.36;
    double doble = -356.157;

    mostrarAbsoluto(entero);
    mostrarAbsoluto(flotante);
    mostrarAbsoluto(doble);

    return 0;

}

template <class TDDATO>
void mostrarAbsoluto (TDDATO num) {

    if (num < 0){
        cout << num*-1 << endl;
    } else {
        cout << num << endl;
    }

};