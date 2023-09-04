#include <iostream>

using namespace std;

void tiempo(long, int&, int&, int&);

int main()
{
    long segs;
    int hs = 0, min = 0, seg = 0;

    cout << "Ingrece un tiempo en segundos: "; cin>>segs;

    tiempo(segs, hs, min, seg);

    cout << "\n\nEl tiempo "<< segs << " son " << hs << " horas " << min << " minutos y " << seg << " segundos";

    return 0;
}

void tiempo(long segT, int& hs, int& min, int& seg)
{
    if (segT >= 60){
        min = segT/60;
        seg = segT%60;
    }

    if (min >= 60){
        hs = min/60;
        min = min%60;
    }
}