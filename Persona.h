#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
    string aDni;
    string aNombres;
    string aDireccion;

public:
    Persona() : aDni(""), aNombres(""), aDireccion("") {}
    Persona(string dni, string nombres, string direccion)
        : aDni(dni), aNombres(nombres), aDireccion(direccion) {
    }

    string getDni() const { return aDni; }
    string getNombres() const { return aNombres; }
    string getDireccion() const { return aDireccion; }

    void setDni(const string& dni) { aDni = dni; }
    void setNombres(const string& nombres) { aNombres = nombres; }
    void setDireccion(const string& direccion) { aDireccion = direccion; }

    virtual void Leer() {
        cout << "DNI: "; getline(cin, aDni);
        cout << "Nombres: "; getline(cin, aNombres);
        cout << "Direccion: "; getline(cin, aDireccion);
    }

    virtual void Escribir() const {

        cout << left << setw(20) << "DNI:" << aDni << endl;
        cout << left << setw(20) << "Nombres:" << aNombres << endl;
        cout << left << setw(20) << "Dirección:" << aDireccion << endl;


    }


    virtual ~Persona() {}
};
