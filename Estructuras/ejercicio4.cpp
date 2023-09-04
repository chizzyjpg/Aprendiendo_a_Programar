#include <iostream>

using namespace std;

struct atleta {

    char nombre[25];
    char pais[35];
    int numMedallas;

}atl[100];


int main(){

    int numAtletas, maxMedallas = 0, posMedalla;

    cout << "Ingrece numeros de atletas: ";
    cin>>numAtletas;

    for (int i = 0; i<numAtletas; i++){
    
        fflush(stdin);

        cout << i+1 << ". Nombre: ";
        cin.getline(atl[i].nombre, 25, '\n');

        cout << i+1 << ". Pais: ";
        cin.getline(atl[i].pais, 35, '\n');

        cout << i+1 << ". Numero de Medallas: ";
        cin>>atl[i].numMedallas;

        cout << '\n';

        if (atl[i].numMedallas > maxMedallas){
        
            maxMedallas = atl[i].numMedallas;
            posMedalla = i;

        }
    
    }

    cout << "El atleta con mas medallas es " << atl[posMedalla].nombre << " con " << maxMedallas << " medallas";   

    return 0;

}