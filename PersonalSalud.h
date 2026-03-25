#pragma once
#include "Persona.h"
#include <iomanip>
class PersonalSalud : public Persona {
protected:
    string aIdPersonal;
    string aEmail;
    string aNroCelular;

public:
    PersonalSalud() : Persona(), aIdPersonal(""), aEmail(""), aNroCelular("") {}

    string getIdPersonal() const { return aIdPersonal; }
    string getEmail() const { return aEmail; }
    string getNroCelular() const { return aNroCelular; }

    void setIdPersonal(const string& id) { aIdPersonal = id; }
    void setEmail(const string& email) { aEmail = email; }
    void setNroCelular(const string& celular) { aNroCelular = celular; }

    void Leer() override {
        Persona::Leer();
        cout << "ID Personal: "; getline(cin, aIdPersonal);
        cout << "Email: "; getline(cin, aEmail);
        cout << "Nro Celular: "; getline(cin, aNroCelular);
    }

    void Escribir() const {
        cout << "=========================================" << endl;
        cout << left << setw(20) << "DNI:" << aDni << endl;
        cout << left << setw(20) << "Nombres:" << aNombres << endl;
        cout << left << setw(20) << "Dirección:" << aDireccion << endl;

    }
};

