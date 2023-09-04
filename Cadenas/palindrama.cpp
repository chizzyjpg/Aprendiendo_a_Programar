#include <iostream>
#include <string.h>

using namespace std;

int main() {

    int i = 0;
    char plr[100];
    string plr2;
    cout << "Ingrece palabra a comparar: ";
    cin.getline(plr, 100);

    plr2 = plr;

    strrev(plr);

    if (plr == plr2){
        cout << "\nLa palabra " << plr2 << " es palindrama";
    } else {
        cout << "\nLa palabra " << plr2 << " no es palindrama";
    }

    return 0;
}