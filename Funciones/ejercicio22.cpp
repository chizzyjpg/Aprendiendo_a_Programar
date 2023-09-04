#include <iostream>

using namespace std;

void escribeNumeros(int, int);
void escribeNumerosDecendente(int, int);


int main()
{
    int ini = 0, fin = 0;
    do
    {
        cout << "Dijite el numero de inicio: "; cin>> ini;
        cout << "Dijite el numero final: "; cin>> fin;
    } while (ini > fin);

    cout << "\nDe forma decendente" << endl ;
    escribeNumerosDecendente(ini, fin);
    cout << "\nDe forma acendente" << endl ;
    escribeNumeros(ini, fin);
    

    return 0;
}

void escribeNumeros(int ini, int fin)
{
    while (ini <= fin)
    {
        cout << ini <<endl;
        ini++;
    }
    
}

void escribeNumerosDecendente(int ini, int fin)
{
    while (ini <= fin)
    {
        cout << fin <<endl;
        fin--;
    }
    
}