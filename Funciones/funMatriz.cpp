#include <iostream>

using namespace std;

void mCuadrado(int m[][3], int, int);
void imprimir(int m[][3], int, int);

int main()
{
    const int nc  = 3, nf = 2;
    int m[nf][nc] = {{1,2,3},{4,5,6}};

    imprimir(m, nf, nc);
    cout << '\n';
    mCuadrado(m, nf, nc);
    imprimir(m, nf, nc);



    return 0;
}

void mCuadrado(int m[][3], int nf, int nc)
{
    for (int i = 0; i<nf; i++){
        for (int x=0; x< nc; x++){
            m[i][x] *= m[i][x];
        }
    }
}

void imprimir(int m[][3], int nf, int nc)
{
    for (int i = 0; i<nf; i++){
        cout << '\n';
        for (int x=0; x< nc; x++){
            cout << ' ' << m[i][x];
        }
    }
}
