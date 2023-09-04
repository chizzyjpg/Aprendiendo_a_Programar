#include <iostream>

using namespace std;

void pedirDatos();
void esSimetrica(int m[][100], int, int);
void mostrarMatriz(int m[][100], int, int);

int m[100][100], nf, nc;
bool simetrica = true;

int main()
{
    pedirDatos();
    esSimetrica(m, nf, nc);

    return 0;
}

void pedirDatos()
{
    cout << "Ingrece numero de filas: ";
    cin >> nf;
    cout << "Ingrece numero de columnas: ";
    cin >> nc;

    for (int i = 0; i < nf; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            cout << "\nIngrece un número: ";
            cin >> m[i][j];
        }
    }
}

void esSimetrica(int m[][100], int x, int y)
{
    if (x == y)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (m[i][j] != m[j][i])
                {
                    simetrica = false;
                    break;
                }
            }
        }
        
        mostrarMatriz(m, nf, nc);
        cout << "\nLa Matriz es simetrica";
    }
    else
    {
        simetrica = false;
        mostrarMatriz(m, nf, nc);
        cout << "\nLa Matriz no es Cuadrada por lo tanto no es simetrica\n";
    }
}

void mostrarMatriz(int m[][100], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        cout << '\n';
        for (int j = 0; j < y; j++)
        {
            cout << ' ' << m[i][j];
        }
    }
}