#include <iostream>
using namespace std;

class Pokemon {
    //inicialisas dentro de public las variables
    public:
        string nombre;
        float peso;
    public:
    //estructura nobmre(tipoDeDatos)
        Pokemon(string, float);
        void mostrarPokemon();
};
//nombre de la clase, ::invocar nombre de la estructura(tipoDeDato variable temporal pasada por estructura)
Pokemon::Pokemon(string _nombre, float _peso){
    //se iguala lo que se pasa por parametros con las variables declaradas en la clase
    nombre = _nombre;
    peso = _peso;
}

//estructura para mostrar por pantalla
void Pokemon::mostrarPokemon(){
    cout << "El Pokemon " << nombre << " pesa: " << peso << " kilogramos \n";
};

//clase hija : invoca public nombreClaseHeredar
class PokemonAgua : public Pokemon{
    public:
        int vida;
        char genero;
    public:
        //en los parametros colocar tipo de datos que te van a pasar para padre e hijo, respetando orden
        PokemonAgua(string, float, int, char);
        void mostrarPokemonAgua();
};

// se colocan todos los parametros tanto de padre como de hijo : invoca estructura NombreEstructuraPadre (variable de parametros)
PokemonAgua::PokemonAgua(string _nombre, float _peso, int _vida, char _genero) : Pokemon(_nombre, _peso){
    //solo igualar variables de la clase hijo ya que al heredar tambien toma esos parametros
    vida = _vida;
    genero = _genero;
};

void PokemonAgua::mostrarPokemonAgua(){
    //invocas el mostrar por pantalla de la clase padre, nombreClasePadre :: estructuraMostrarPorPantalla
    Pokemon::mostrarPokemon();
    cout << "Tiene " << vida << " puntos de vida y su genero es " << genero << endl;
}

int main () {

    PokemonAgua pokemon1("Squirtel", 1.15, 30, 'm');
    pokemon1.mostrarPokemonAgua();

    return 0;

}