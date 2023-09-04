#include <iostream>

using namespace std;

int suma(int);

int main()
{
    cout << suma(1) << ' ' << suma(2) << ' ' << suma(3) << ' ' << suma(4);

    return 0;
}

int suma(int n)
{
    if (n == 1)
    {
        n = 1;
    }
    else
    {
        n = n + suma(n-1);
    }
    return n;
}