#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *dirArr = arr;

    for(int i=0; i<5; i++)
    {
        cout << "El elemento del vector ["<<i<<"]: " << *dirArr++ << endl;
    }

    return 0;
}