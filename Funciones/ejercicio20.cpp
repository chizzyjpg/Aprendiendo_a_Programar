#include <iostream>

using namespace std;

int fibonacci(int);

int main()
{
    int nElementos;
    do
    {
        cout << "Digite el numero de elementos: "; cin>>nElementos;
    }while (nElementos <= 0);

    cout << "\nSerie fibonacci\n";
    cout << "---------------";
    for(int i=0; i<=nElementos; i++)
    {
        cout << fibonacci(i) << " , ";
    }
    

    return 0;
}

int fibonacci(int n)
{
    if (n<2)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
