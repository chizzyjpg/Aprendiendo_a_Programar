#include <iostream>

using namespace std;

int elevado(int , int);

int main()
{
    int base, exponente;
    cout << "Dijite la base: "; cin>>base;
    cout << "Dijite el expnente: "; cin>>exponente;

    cout << "\nEl resultado es: " << elevado(base, exponente);

    return 0;
}

int elevado(int x , int y)
{
    int pot;
    if( y == 0 )
    {
        return 1;
    }
    else if (y == 1)
    {
        return x;
    }
    else
    {
        for(int i=0; i<y; i++)
        {
            pot = x * elevado(x, y-1);
        }
        return pot;
    }
}