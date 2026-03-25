#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Servicio.h"
#include "Atencion.h"
#include "Paciente.h"
#include "Medico.h"
#include "Enfermera.h"
using namespace std;

class cCentroSalud {
private:
    cServicio** aServicios;
    int aNroServicios;

    cAtencion** aAtenciones;
    int aNroAtenciones;

    Persona** aPersonas; // Pacientes, M dicos, Enfermeras
    int aNroPersonas;

public:
    cCentroSalud() {
        aServicios = new cServicio * [100];
        aNroServicios = 0;

        aAtenciones = new cAtencion * [500];
        aNroAtenciones = 0;

        aPersonas = new Persona * [200];
        aNroPersonas = 0;
        CargarDatosIniciales();
    }

    // ---------- Registro ----------
    void RegistrarServicio() {
        cServicio* s = new cServicio();
        s->LeerDatosServicio();
        aServicios[aNroServicios++] = s;
    }

    void RegistrarPaciente() {
        Paciente* p = new Paciente();
        p->Leer();
        aPersonas[aNroPersonas++] = p;
    }

    void RegistrarPersonalSalud() {
        int opcion;
        cout << "1. Registrar Medico\n2. Registrar Enfermera\nSeleccione: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            Medico* m = new Medico();
            m->Leer();
            aPersonas[aNroPersonas++] = m;
        }
        else if (opcion == 2) {
            Enfermera* e = new Enfermera();
            e->Leer();
            aPersonas[aNroPersonas++] = e;
        }
        else {
            cout << "Opcion invalida.\n";
        }
    }

    void RegistrarAtencion() {
        cAtencion* a = new cAtencion();
        a->LeerDatosAtencion();
        // Validar que el servicio exista
        bool servicioEncontrado = false;
        double costoServicio = 0.0;
        for (int i = 0; i < aNroServicios; i++) {
            if (aServicios[i]->getIdServicio() == a->getIdServicio()) {
                costoServicio = aServicios[i]->getCostoAtencion();
                servicioEncontrado = true;
                break;
            }
        }
        if (!servicioEncontrado) {
            cout << "Error: ID de servicio no registrado.\n";
            delete a;
            return;
        }
        // Validar que el DNI corresponda a un paciente registrado
        bool pacienteEncontrado = false;
        for (int i = 0; i < aNroPersonas; i++) {
            Paciente* p = dynamic_cast<Paciente*>(aPersonas[i]);
            if (p && p->getDni() == a->getDni()) {
                pacienteEncontrado = true;
                break;
            }
        }
        if (!pacienteEncontrado) {
            cout << "Error: DNI no corresponde a un paciente registrado.\n";
            delete a;
            return;
        }
        // Asignamos el costo y registramos
        a->setCosto(costoServicio);
        aAtenciones[aNroAtenciones++] = a;
        cout << "Atencion registrada correctamente.\n";
    }

    // ---------- Listado ----------
    void ListarServicios() {
        cout << "\n=========================================" << endl;
        cout << "           LISTA DE SERVICIOS            " << endl;
        cout << "=========================================" << endl;
        for (int i = 0; i < aNroServicios; i++) {
            cout << ">> Servicio #" << (i + 1) << endl;
            aServicios[i]->MostrarDatosServicio();
            cout << endl;
        }
    }

    void ListarPersonas() {
        cout << "\n=========================================" << endl;
        cout << "           LISTA DE PERSONAS             " << endl;
        cout << "=========================================" << endl;
        for (int i = 0; i < aNroPersonas; i++) {
            cout << ">> Persona #" << (i + 1) << endl;
            aPersonas[i]->Escribir();
            cout << endl;
        }
    }

    void ListarAtenciones() {
        cout << "\n=========================================" << endl;
        cout << "          LISTA DE ATENCIONES            " << endl;
        cout << "=========================================" << endl;
        for (int i = 0; i < aNroAtenciones; i++) {
            cout << ">> Atencion #" << (i + 1) << endl;
            aAtenciones[i]->MostrarDatosAtencion();
            cout << endl;
        }
    }

    void ListarAtencionesPorRangoFechas() {
        cout << "\n--- LISTAR ATENCIONES POR RANGO DE FECHAS ---\n";
        string fechaInicio, fechaFin;
        cout << "Ingrese la fecha de inicio (dd/mm/aaaa): ";
        getline(cin, fechaInicio);
        cout << "Ingrese la fecha de fin (dd/mm/aaaa): ";
        getline(cin, fechaFin);

        // Validar formato y convertir a yyyymmdd
        auto convertirFecha = [](const string& fecha) {
            if (fecha.length() != 10) return string();  // Formato inválido
            string dia = fecha.substr(0, 2);
            string mes = fecha.substr(3, 2);
            string anio = fecha.substr(6, 4);
            return anio + mes + dia;  // formato: yyyymmdd
            };

        string f1 = convertirFecha(fechaInicio);
        string f2 = convertirFecha(fechaFin);

        if (f1.empty() || f2.empty()) {
            cout << "Formato de fecha inválido. Use dd/mm/aaaa.\n";
            return;
        }

        bool encontrada = false;
        for (int i = 0; i < aNroAtenciones; i++) {
            string fAt = convertirFecha(aAtenciones[i]->getFecha());
            if (fAt >= f1 && fAt <= f2) {
                aAtenciones[i]->MostrarDatosAtencion();
                encontrada = true;
            }
        }

        if (!encontrada) {
            cout << "No se encontraron atenciones en el rango de fechas especificado.\n";
        }
    }


    // ---------- Reportes ----------
    void ReporteIngresosPorServicio() {
        cout << "\n--- REPORTE DE INGRESOS POR SERVICIO ---\n";
        for (int i = 0; i < aNroServicios; i++) {
            string idServ = aServicios[i]->getIdServicio();
            double costoEstandar = aServicios[i]->getCostoAtencion();
            int cantidadAtenciones = 0;
            for (int j = 0; j < aNroAtenciones; j++) {
                if (aAtenciones[j]->getIdServicio() == idServ) {
                    cantidadAtenciones++;
                }
            }
            double total = cantidadAtenciones * costoEstandar;
            cout << "Servicio: " << aServicios[i]->getNombreAtencion();
            cout << ", Especialidad: " << aServicios[i]->getEspecialidad();
            cout << ", Atenciones: " << cantidadAtenciones;
            cout << ", Ingresos Totales: S/ " << total << endl;

        }
    }

    void ReporteAtencionesPorEspecialidad() {
        cout << "\n--- REPORTE DE ATENCIONES POR ESPECIALIDAD MEDICA ---\n";
        string especialidadBuscada;
        cout << "Ingrese especialidad: ";
        getline(cin, especialidadBuscada);
        bool encontrada = false;
        for (char& c : especialidadBuscada) {
            c = toupper(c);
        }
        for (int i = 0; i < aNroServicios; i++) {
            if (aServicios[i]->getEspecialidad() == especialidadBuscada) {
                string idServicio = aServicios[i]->getIdServicio();
                for (int j = 0; j < aNroAtenciones; j++) {
                    if (aAtenciones[j]->getIdServicio() == idServicio) {
                        aAtenciones[j]->MostrarDatosAtencion();
                        encontrada = true;
                    }
                }
            }
        }
        if (!encontrada) {
            cout << "No se encontraron atenciones para la especialidad: " << especialidadBuscada << endl;
        }

    }

    void ReporteAtencionesPorPaciente() {
        cout << "\n--- REPORTE DE ATENCIONES POR PACIENTE ---\n";
        string dni;
        cout << "Ingrese DNI del paciente: ";
        getline(cin, dni);
        bool encontrado = false;
        for (int i = 0; i < aNroAtenciones; i++) {
            if (aAtenciones[i]->getDni() == dni) {
                aAtenciones[i]->MostrarDatosAtencion();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron atenciones para el DNI ingresado.\n";
        }
    }

    void ReporteIngresosPorPaciente() {
        cout << "\n--- REPORTE DE INGRESOS POR PACIENTE ---\n";
        for (int i = 0; i < aNroPersonas; i++) {
            Paciente* p = dynamic_cast<Paciente*>(aPersonas[i]);
            if (p) {
                string dni = p->getDni();
                double total = 0;

                for (int j = 0; j < aNroAtenciones; j++) {
                    if (aAtenciones[j]->getDni() == dni) {
                        total += aAtenciones[j]->getCosto();
                    }
                }

                cout << "Paciente: " << p->getNombres() << " | DNI: " << dni << " | Total pagado: S/ " << total << endl;
            }
        }
    }

    void ReportePacientesPorServicio() {
        cout << "\n--- REPORTE DE PACIENTES POR SERVICIO ---\n";
        for (int i = 0; i < aNroServicios; i++) {
            string idServicio = aServicios[i]->getIdServicio();
            cout << "Servicio: " << aServicios[i]->getNombreAtencion() << " (" << idServicio << ")\n";

            bool alguno = false;
            for (int j = 0; j < aNroAtenciones; j++) {
                if (aAtenciones[j]->getIdServicio() == idServicio) {
                    string dniPaciente = aAtenciones[j]->getDni();
                    for (int k = 0; k < aNroPersonas; k++) {
                        Paciente* p = dynamic_cast<Paciente*>(aPersonas[k]);
                        if (p && p->getDni() == dniPaciente) {
                            cout << "- " << p->getNombres() << " (DNI: " << dniPaciente << ")\n";
                            alguno = true;
                            break;
                        }
                    }
                }
            }

            if (!alguno) {
                cout << "  No se registraron pacientes para este servicio.\n";
            }

            cout << endl;
        }
    }
    void CargarDatosIniciales() {
        // 1. Servicios
        aServicios[aNroServicios++] = new cServicio("S001", "Consulta General", "Medicina General", 60);
        aServicios[aNroServicios++] = new cServicio("S002", "Consulta Pediátrica", "Pediatría", 70);
        aServicios[aNroServicios++] = new cServicio("S003", "Consulta Ginecológica", "Ginecología", 80);

        // 2. Pacientes
        aPersonas[aNroPersonas++] = new Paciente("P001", "Ana Pérez", "Av. Lima 123", "Femenino", 1.65, 58.4);
        aPersonas[aNroPersonas++] = new Paciente("P002", "Luis Gómez", "Jr. Cusco 456", "Masculino", 1.75, 70.3);
        aPersonas[aNroPersonas++] = new Paciente("P003", "Carla Torres", "Av. Arequipa 789", "Femenino", 1.60, 55);
        aPersonas[aNroPersonas++] = new Paciente("P004", "Pedro Ruiz", "Calle Olivos 321", "Masculino", 1.80, 80);
        aPersonas[aNroPersonas++] = new Paciente("P005", "Lucía Morales", "Av. Grau 987", "Femenino", 1.68, 60);

        // 3. Médicos
        aPersonas[aNroPersonas++] = new Medico("M001", "Dr. Juan Sánchez", "Calle Médica 111", "MED01", "juan@correo.com", "999111111", "Medicina General", "CMP12345");
        aPersonas[aNroPersonas++] = new Medico("M002", "Dra. Rosa Flores", "Calle Salud 222", "MED02", "rosa@correo.com", "999222222", "Pediatría", "CMP54321");
        aPersonas[aNroPersonas++] = new Medico("M003", "Dr. Miguel Ríos", "Calle Central 333", "MED03", "miguel@correo.com", "999333333", "Ginecología", "CMP67890");

        // 4. Enfermeras
        aPersonas[aNroPersonas++] = new Enfermera("E001", "Enf. María López", "Av. Norte 444", "ENF01", "maria@correo.com", "988111111", "Emergencias", "CEP1111");
        aPersonas[aNroPersonas++] = new Enfermera("E002", "Enf. Julio Quispe", "Av. Sur 555", "ENF02", "julio@correo.com", "988222222", "Traumatología", "CEP2222");
        aPersonas[aNroPersonas++] = new Enfermera("E003", "Enf. Elena Chávez", "Av. Este 666", "ENF03", "elena@correo.com", "988333333", "Pediatría", "CEP3333");

        // 5. Atenciones
        aAtenciones[aNroAtenciones++] = new cAtencion("T001", "01/07/2025", "S001", "Dolor de cabeza", 60, "P001");
        aAtenciones[aNroAtenciones++] = new cAtencion("T002", "02/07/2025", "S002", "Fiebre alta", 70, "P002");
        aAtenciones[aNroAtenciones++] = new cAtencion("T003", "03/07/2025", "S003", "Control ginecológico", 80, "P003");
        aAtenciones[aNroAtenciones++] = new cAtencion("T004", "04/07/2025", "S001", "Dolor muscular", 60, "P004");
        aAtenciones[aNroAtenciones++] = new cAtencion("T005", "05/07/2025", "S002", "Consulta por tos", 70, "P005");
    }

};

