#include <iostream>
#include <sstream>

using namespace std;

void hola(string arr[100], string, char);

int main()
{
    string arr[100];
    string consola = "touch hola.txt";

    hola(arr, consola, ' ');

    cout << arr[0] << endl
         << arr[1] << endl;

    string consolaAux = arr[1];

    hola(arr, consolaAux, '.');

    cout << arr[0] << endl
         << arr[1];
}

void hola(string arr[100], string consola, char c)
{
    string comando;
    stringstream comandoConsola(consola);
    int i = 0;

    while (getline(comandoConsola, comando, c))
    {
        arr[i] = comando;
        i++;
    }
}