#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class cServicio {
private:
    string aIdServicio;
    string aNombreServicio;
    string aEspecialidad;
    double aCostoAtencion;
    string ToUpper(const string& texto) {
        string mayuscula = texto;
        for (char& c : mayuscula) {
            c = toupper(c);
        }
        return mayuscula;
    }
public:
    // Constructor por defecto
    cServicio() 
    {
        aIdServicio = ""; 
        aNombreServicio = "";
        aEspecialidad = "";
        aCostoAtencion = 0;
    }
    // Constructor con parámetros
    cServicio(string pIdServicio, string pNombreServicio, string pEspecialidad, double pCostoAtencion) {
        aIdServicio = pIdServicio;
        aNombreServicio = pNombreServicio;
        aEspecialidad = ToUpper(pEspecialidad);
        aCostoAtencion = pCostoAtencion;
    }

    // Getters
    string getIdServicio() const { return aIdServicio; }
    string getNombreAtencion() const { return aNombreServicio; }
    double getCostoAtencion() const { return aCostoAtencion; }
    string getEspecialidad() const { return aEspecialidad; }

    // Setters
    void setIdServicio(const string& pIdServicio) { aIdServicio = pIdServicio; }
    void setNombreServicio(const string& pNombreServicio) { aNombreServicio = pNombreServicio; }
    void setEspecialidad(const string& pEspecialidad) { aEspecialidad = ToUpper(pEspecialidad); }
    void setCostoAtencion(double pCostoAtencion) { aCostoAtencion = pCostoAtencion; }
    
    void LeerDatosServicio()
    {
        cout << "Código ID del Servicio: ";
        getline(cin, aIdServicio);
        cout << "Nombre del Servicio: ";
        getline(cin, aNombreServicio);
        cout << "Especialidad: ";
        getline(cin, aEspecialidad);
        cout << "Costo de la atención: ";
        cin >> aCostoAtencion;
        cin.ignore();
    }
    void MostrarDatosServicio() {
        cout << "=========================================" << endl;
        cout << "        DETALLES DEL SERVICIO            " << endl;
        cout << "=========================================" << endl;
        cout << left << setw(25) << "Código ID del Servicio:" << aIdServicio << endl;
        cout << left << setw(25) << "Nombre del Servicio:" << aNombreServicio << endl;
        cout << left << setw(25) << "Especialidad:" << aEspecialidad << endl;
        cout << left << setw(25) << "Costo de la atención:" << fixed << setprecision(2) << aCostoAtencion << " soles" << endl;
        cout << "-----------------------------------------" << endl;
    }
};
