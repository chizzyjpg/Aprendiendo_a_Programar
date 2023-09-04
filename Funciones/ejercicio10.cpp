#include <iostream>

using namespace std;

void calcAños(int, int, int, int&);

int main()
{
    int año, mes, dia, diasT=0;

    cout << "Ingrece el Año: "; cin>>año;
    cout << "Ingrece el Mes: "; cin>>mes;
    cout << "Ingrece el Dia: "; cin>>dia;

    calcAños(año, mes, dia, diasT);

    cout << "Van " << diasT << " dias desde el 1/1/2000";
    
    return 0;
}

void calcAños(int a, int m, int d, int& dT)
{
    a -= 2000;
    m -= 1;
    d -= 1;
    dT = (a*365) + (m*30) + (d*30);
}