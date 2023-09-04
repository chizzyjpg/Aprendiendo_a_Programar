#include <iostream>

using namespace std;

void intercambio(float *, float *);

int main()
{
    float num1 = 20.8, num2 = 6.78;

    cout << "El primer numero es: " << num1 << endl;
    cout << "El segundo numero es: " << num2 << endl;

    intercambio(&num1, &num2);

    cout << "\n\n";
    cout << "El primer numero es: " << num1 << endl;
    cout << "El segundo numero es: " << num2 << endl;

    return 0;
}

void intercambio(float *dirNum1, float *dirNum2)
{
    float aux;

    aux = *dirNum1;
    *dirNum1 = *dirNum2;
    *dirNum2 = aux;
}