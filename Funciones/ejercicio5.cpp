#include <iostream>
#include <string.h>

using namespace std;

template <class TDDATO>
void despliege(TDDATO dato);

int main(){

    int i = 10;
    float f = 3.14;
    double d = 316.398;
    char c = 'a';
    string s = "hola";
    long l = 361827328;
    bool b = true;

    despliege(i);
    despliege(f);
    despliege(d);
    despliege(c);
    despliege(s);
    despliege(l);
    despliege(b);

    return 0;

}

template <class TDDATO>
void despliege(TDDATO dato){

    cout << "Dato: " << dato << endl;

}