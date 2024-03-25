#ifndef DIRECCION_H
#define DIRECCION_H
#include <iostream>

using namespace std;

class Direccion {
    private:
        string pais;
        string ciudad;
        string numbero;
        string calle;
    public:
        Direccion();
        Direccion(string, string, string, string);
        string getPais();
        string getCiudad();
        string getNumbero();
        string getCalle();
};

#endif