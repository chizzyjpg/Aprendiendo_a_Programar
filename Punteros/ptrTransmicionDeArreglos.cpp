#include <iostream>

using namespace std;

int hallarMax(int *, int);

int main()
{
    const int nArr = 15;
    int arr[nArr] = {1, 2, 3, 4, 5, 6, 99, 2, 412, 4, 32, 6, 4, 8, 3};
    int *dirVec = arr;

    cout << "El numero mayor del Arreglo es: " << hallarMax(dirVec, nArr);

    return 0;
}

int hallarMax(int *dirVec, int nArr)
{
    int max = 0;
    for (int i = 0; i < nArr; i++)
    {
        if (*dirVec > max)
        {
            max = *dirVec;
        }
        dirVec++;
    }
    return max;
}