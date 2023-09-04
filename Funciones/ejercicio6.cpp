#include <iostream>
#include <string.h>

using namespace std;

template <class TDDATO>
void maximo(TDDATO n1, TDDATO n2, TDDATO n3);

int main(){

    int i1 = 1, i2 = 2, i3 = 3; 

    maximo(i1, i2, i3);

    return 0;

}

template <class TDDATO>
void maximo(TDDATO n1, TDDATO n2, TDDATO n3){

    if (n1 > n2){
        if (n1 > n3){
            cout << "El dato mayor es: " << n1;
        } else {
            cout << "El dato mayor es: " << n3;
        }
    }else{
      if (n2 > n3){
            cout << "El dato mayor es: " << n2;
        } else {
            cout << "El dato mayor es: " << n3;
        }  
    } 

}