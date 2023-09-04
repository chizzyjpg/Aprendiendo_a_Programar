#include <iostream>

using namespace std;

void pedirDatos(int arr[], int&);
int esMenor(int *num, int);

int main()
{
    int arr[100], i, menor;
    pedirDatos(arr, i);
    int *dirArr = arr;
    menor = esMenor(dirArr, i);

    cout << "El numero menor es: " << menor; 

    return 0;
}

void pedirDatos(int arr[], int& n )
{
    cout << "Ingrece cuantos valores son: "; cin>>n;
    for(int i=0; i<n ; i++)
    {
        cout << "\nIngrece un dato para la pocicion ["<<i<<"]: "; cin>>arr[i];
    }
}

int esMenor(int *num, int p)
{
    int n = *num;
    for(int i=0; i<p; i++)
    {
        if (*num < n )
        {
            n = *num;
        }
        num++;
    }
    return n;
}