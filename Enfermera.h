#pragma once
#include "PersonalSalud.h"

class Enfermera : public PersonalSalud {
private:
    string aServicio;
    string aCEP;

public:
    Enfermera() : PersonalSalud(), aServicio(""), aCEP("") {}

    Enfermera(const string& dni, const string& nombres, const string& direccion,
        const string& idPersonal, const string& email, const string& nroCelular,
        const string& servicio, const string& cep)
        : PersonalSalud() // Llamamos al constructor por defecto
    {
        // Atributos heredados de Persona
        aDni = dni;
        aNombres = nombres;
        aDireccion = direccion;

        // Atributos de PersonalSalud
        aIdPersonal = idPersonal;
        aEmail = email;
        aNroCelular = nroCelular;

        // Atributos propios de Enfermera
        aServicio = servicio;
        aCEP = cep;
    }



    string getServicio() const { return aServicio; }
    string getCEP() const { return aCEP; }

    void setServicio(const string& s) { aServicio = s; }
    void setCEP(const string& c) { aCEP = c; }

    void Leer() override {
        PersonalSalud::Leer();
        cout << "Servicio: "; getline(cin, aServicio);
        cout << "CEP: "; getline(cin, aCEP);
    }

    void Escribir() const override {
        PersonalSalud::Escribir();  // Llama a la funci n base

        cout << left << setw(20) << "Servicio:" << aServicio << endl;
        cout << left << setw(20) << "CEP:" << aCEP << endl;
        cout << "=========================================" << endl;
    }

};
