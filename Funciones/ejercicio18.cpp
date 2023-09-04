#include <iostream>

using namespace std;

struct Fecha
{
    int año, mes, dia;
} f1, f2;

void pedirFechas();
Fecha mayor(Fecha, Fecha);
void mostrarFechaMayor(Fecha);

int main()
{
    pedirFechas();
    Fecha f = mayor(f1, f2);
    mostrarFechaMayor(f);

    return 0;
}

void pedirFechas()
{
    cout << "Ingrece la primer fecha: " << endl;
    cout << "Año: ";
    cin >> f1.año;
    cout << "Mes: ";
    cin >> f1.mes;
    cout << "Dia: ";
    cin >> f1.dia;

    cout << "\nIngrece la segunda fecha: " << endl;
    cout << "Año: ";
    cin >> f2.año;
    cout << "Mes: ";
    cin >> f2.mes;
    cout << "Dia: ";
    cin >> f2.dia;
}

Fecha mayor(Fecha f1, Fecha f2)
{
    if ((f1.mes >= 1) && (1 <= f2.mes) && (f1.mes <= 12) && (12 >= f2.mes))
    {
        if ((f1.dia >= 1) && (1 <= f2.dia) && (f1.dia <= 30) && (30 >= f2.dia))
        {
            if (f1.año > f2.año)
            {
                return f1;
            }
            else if (f2.año > f1.año)
            {
                return f2;
            }
            else // Si los años son iguales
            {
                if (f1.mes > f2.mes)
                {
                    return f1;
                }
                else if (f2.mes > f1.mes)
                {
                    return f2;
                }
                else // Si los años y meses son iguales
                {
                    if (f1.dia >= f2.dia)
                    {
                        return f1;
                    }
                    else
                    {
                        return f2;
                    }
                }
            }
        }
    }
}

void mostrarFechaMayor(Fecha f)
{
    cout << "La fecha mayor es: " << f.dia << '/' << f.mes << '/' << f.año;
}