#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

class cAtencion {
private:
    string aNroTicket;
    string aFecha;
    string aIdServicio;
    string aDescripcion;
    double aCostoAtencion;
    string aDni;

    // Funcion auxiliar para generar numero de ticket
    string GenerarNroTicket() {
        static int contador = 1;
        stringstream ss;
        ss << "TK" << setw(5) << setfill('0') << contador++;
        return ss.str();
    }

    // Funcion auxiliar para obtener la fecha actual
    string ObtenerFechaActual() {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);  // version segura en Visual Studio

        stringstream ss;
        ss << setw(2) << setfill('0') << ltm.tm_mday << "/"
            << setw(2) << setfill('0') << (ltm.tm_mon + 1) << "/"
            << (ltm.tm_year + 1900);
        return ss.str();
    }

public:
    // Constructor por defecto
    cAtencion()
    {
        aNroTicket = GenerarNroTicket();
        aFecha = ObtenerFechaActual();
        aIdServicio = "";
        aDescripcion = "";
        aCostoAtencion = 0.0;
        aDni = "";
    }

    // Constructor con parametros
    cAtencion(string pNroTicket, string pFecha, string pIdServicio, string pDescripcion, double pCostoAtencion, string pDni)
    {
        aNroTicket = pNroTicket;
        aFecha = pFecha;
        aIdServicio = pIdServicio;
        aDescripcion = pDescripcion;
        aCostoAtencion = pCostoAtencion;
        aDni = pDni;
    }

    // Getters
    string getNroTicket() const { return aNroTicket; }
    string getFecha() const { return aFecha; }
    string getIdServicio() const { return aIdServicio; }
    string getDescripcion() const { return aDescripcion; }
    double getCosto() const { return aCostoAtencion; }
    string getDni() const { return aDni; }

    // Setters
    void setNroTicket(const string& pNroTicket) { aNroTicket = pNroTicket; }
    void setFecha(const string& pFecha) { aFecha = pFecha; }
    void setIdServicio(const string& pIdServicio) { aIdServicio = pIdServicio; }
    void setDescripcion(const string& pDescripcion) { aDescripcion = pDescripcion; }
    void setCosto(double pCostoAtencion) { aCostoAtencion = pCostoAtencion; }
    void setDni(const string& pDni) { aDni = pDni; }

    // Metodos
    void LeerDatosAtencion()
    {
        // aNroTicket y aFecha ya se generan automaticamente en el constructor
        cout << "ID del Servicio: ";
        getline(cin, aIdServicio);
        cout << "Descripcion de la atencion: ";
        getline(cin, aDescripcion);
        cout << "Costo de la atencion: ";
        cin >> aCostoAtencion;
        cin.ignore();
        cout << "DNI del paciente: ";
        getline(cin, aDni);
    }

    void MostrarDatosAtencion() const {
        cout << "=========================================" << endl;
        cout << "          DETALLES DE LA ATENCION        " << endl;
        cout << "=========================================" << endl;
        cout << left << setw(30) << "Numero de Ticket:" << aNroTicket << endl;
        cout << left << setw(30) << "Fecha (dd/mm/aaaa):" << aFecha << endl;
        cout << left << setw(30) << "ID del Servicio:" << aIdServicio << endl;
        cout << left << setw(30) << "Descripcion de la atencion:" << aDescripcion << endl;
        cout << left << setw(30) << "Costo de la atencion:" << fixed << setprecision(2) << aCostoAtencion << " soles" << endl;
        cout << left << setw(30) << "DNI del paciente:" << aDni << endl;
        cout << "-----------------------------------------" << endl;
    }
};
