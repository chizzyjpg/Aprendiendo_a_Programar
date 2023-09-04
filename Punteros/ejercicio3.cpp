#include <iostream>

using namespace std;

void pedirDatos(int arr[]);
void esPar(int *num);

int main()
{
    int arr[10];
    pedirDatos(arr);
    int *dirArr = arr;
    esPar(dirArr);

    return 0;
}

void pedirDatos(int arr[])
{
    for(int i=0; i<10 ; i++)
    {
        cout << "Ingrece un dato para la pocicion ["<<i<<"]: "; cin>>arr[i];
        cout << '\n';
    }
}

void esPar(int *num)
{
    for (int i=0; i<10; i++)
    {
        if (*num%2 == 0)
        {
            cout << "El numero " << *num << " es par, y su posición es: " << num << endl;
        }
        *num++;
    }
}