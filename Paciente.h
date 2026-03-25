#pragma once
#include "Persona.h"

class Paciente : public Persona {
private:
    string aGenero;
    double aTalla;
    double aPeso;

public:
    Paciente() : Persona(), aGenero(""), aTalla(0.0), aPeso(0.0) {}
    Paciente(const string& dni, const string& nombres, const string& direccion,
        const string& genero, double talla, double peso)
        : Persona(), aGenero(genero), aTalla(talla), aPeso(peso)
    {
        // Atributos heredados de Persona
        aDni = dni;
        aNombres = nombres;
        aDireccion = direccion;

        // Los atributos propios ya se inicializan en la lista de inicialización
    }

    string getGenero() const { return aGenero; }
    double getTalla() const { return aTalla; }
    double getPeso() const { return aPeso; }

    void setGenero(const string& genero) { aGenero = genero; }
    void setTalla(double talla) { aTalla = talla; }
    void setPeso(double peso) { aPeso = peso; }

    void Leer() override {
        Persona::Leer();
        cout << "G?nero: "; getline(cin, aGenero);
        cout << "Talla (m): "; cin >> aTalla;
        cout << "Peso (kg): "; cin >> aPeso;
        cin.ignore();
    }

    void Escribir() const override {
        Persona::Escribir();

        cout << left << setw(20) << "Género:" << aGenero << endl;
        cout << left << setw(20) << "Talla:" << fixed << setprecision(2) << aTalla << " m" << endl;
        cout << left << setw(20) << "Peso:" << fixed << setprecision(1) << aPeso << " kg" << endl;
        cout << "=========================================" << endl;
    }

};

