#include <iostream>

using namespace std;

void cambio(int, int &);

int main()
{
    int precio, dinero;
    cout << "Ingrece el precio: "; cin>>precio;
    cout << "Ingrece el monto entregado: "; cin>>dinero;
    cambio(precio, dinero);

    return 0;
}

void cambio(int precio, int &dinero)
{

    int cien = 0, cincuenta = 0, veinte = 0, diez = 0, cinco = 0, dos = 0, uno = 0;
    
    dinero -= precio;

    while (dinero != 0)
    {
        if (dinero >= 100)
        {
            dinero -= 100;
            cien++;
            continue;
        }

        if (dinero >= 50)
        {
            dinero -= 50;
            cincuenta++;
            continue;
        }

        if (dinero >= 20)
        {
            dinero -= 20;
            veinte++;
            continue;
        }

        if (dinero >= 10)
        {
            dinero -= 10;
            diez++;
            continue;
        }

        if (dinero >= 5)
        {
            dinero -= 5;
            cinco++;
            continue;
        }

        if (dinero >= 1)
        {
            dinero -= 1;
            uno++;
            continue;
        }
    }

    cout << "Los billetes a entregar son: " << endl;
    cout << "\n-----------------------------\n"<<endl;
    cout << "Cien: "<<cien<<endl;
    cout << "Cincuenta: "<<cincuenta<<endl;
    cout << "Veinte: "<<veinte<<endl;
    cout << "Diez: "<<diez<<endl;
    cout << "Cinco: "<<cinco<<endl;
    cout << "Uno: "<<uno<<endl;
}
