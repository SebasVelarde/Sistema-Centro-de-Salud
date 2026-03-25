#include "PersonalSalud.h"

class Medico : public PersonalSalud {
private:
    string aEspecialidad;
    string aCMP;

public:
    Medico() : PersonalSalud(), aEspecialidad(""), aCMP("") {}
    Medico(const string& dni, const string& nombres, const string& direccion,
        const string& idPersonal, const string& email, const string& nroCelular,
        const string& especialidad, const string& cmp)
        : PersonalSalud() // Llama al constructor por defecto
    {
        // Atributos heredados de Persona
        aDni = dni;
        aNombres = nombres;
        aDireccion = direccion;

        // Atributos de PersonalSalud
        aIdPersonal = idPersonal;
        aEmail = email;
        aNroCelular = nroCelular;

        // Atributos propios de Medico
        aEspecialidad = especialidad;
        aCMP = cmp;
    }

    string getEspecialidad() const { return aEspecialidad; }
    string getCMP() const { return aCMP; }

    void setEspecialidad(const string& esp) { aEspecialidad = esp; }
    void setCMP(const string& cmp) { aCMP = cmp; }

    void Leer() override {
        PersonalSalud::Leer();
        cout << "Especialidad: "; getline(cin, aEspecialidad);
        cout << "CMP: "; getline(cin, aCMP);
    }

    void Escribir() const override {
        PersonalSalud::Escribir();

        cout << left << setw(20) << "Especialidad:" << aEspecialidad << endl;
        cout << left << setw(20) << "CMP:" << aCMP << endl;
        cout << "=========================================" << endl;
    }

};
