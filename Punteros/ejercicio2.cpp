#include <iostream>

using namespace std;

void pedirDato(int&);
void esPrimo(int);
void imprimir(bool);

int *num, n;
bool primo = 1;

int main()
{
    pedirDato(n);
    num = &n;
    esPrimo(*num);
    imprimir(primo);

    return 0;
}

void pedirDato(int& n)
{
    cout << "Ingrece un nuemro: "; cin>>n;
}

void esPrimo(int n)
{
    if (n <= 1) {
        primo = false;
        return;
    }
    
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            primo = false;
            break;
        }
    }
}

void imprimir(bool p)
{
    if (p == 1)
    {
        cout << "\nEl numero " << *num << " es primo" << endl;
        cout << "Posicion: " << num;
    }
    else
    {
        cout << "\nEl numero " << *num << " no es primo" << endl;
        cout << "Posicion: " << num;
    }
}