#include <iostream>
#include "cCentroSalud.h"
using namespace std;

void MenuPrincipal() {
    cout << "\nGESTIÓN DE CONSULTAS EXTERNAS - CENTRO DE SALUD" << endl;
    cout << "===============================================" << endl;
    cout << "1. Registrar" << endl;
    cout << "2. Listar" << endl;
    cout << "3. Reportes" << endl;
    cout << "0. Salir" << endl;
}

void MenuRegistrar() {
    cout << "\n--- REGISTRAR ---" << endl;
    cout << "1. Registrar Servicio" << endl;
    cout << "2. Registrar Paciente" << endl;
    cout << "3. Registrar Personal de Salud" << endl;
    cout << "4. Registrar Atención" << endl;
    cout << "0. Volver" << endl;
}

void MenuListar() {
    cout << "\n--- LISTAR ---" << endl;
    cout << "1. Listar Servicios" << endl;
    cout << "2. Listar Personas" << endl;
    cout << "3. Listar Atenciones" << endl;
    cout << "4. Listar Atenciones por rango de fechas" << endl;
    cout << "0. Volver" << endl;
}

void MenuReportes() {
    cout << "\n--- REPORTES ---" << endl;
    cout << "1. Ingresos por Servicio" << endl;
    cout << "2. Atenciones por Especialidad Médica" << endl;
    cout << "3. Atenciones por Paciente" << endl;
    cout << "4. Ingresos por Paciente" << endl;
    cout << "5. Pacientes por Servicio" << endl;
    cout << "0. Volver" << endl;
}

int main() {
    cCentroSalud* sistema = new cCentroSalud();
    int opcionPrincipal;

    do {
        MenuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcionPrincipal;
        cin.ignore();

        if (opcionPrincipal == 1) {
            int op;
            do {
                MenuRegistrar();
                cout << "Seleccione una opción: ";
                cin >> op;
                cin.ignore();
                if (op == 1) sistema->RegistrarServicio();
                else if (op == 2) sistema->RegistrarPaciente();
                else if (op == 3) sistema->RegistrarPersonalSalud();
                else if (op == 4) sistema->RegistrarAtencion();
            } while (op != 0);
        }

        else if (opcionPrincipal == 2) {
            int op;
            do {
                MenuListar();
                cout << "Seleccione una opción: ";
                cin >> op;
                cin.ignore();
                if (op == 1) sistema->ListarServicios();
                else if (op == 2) sistema->ListarPersonas();
                else if (op == 3) sistema->ListarAtenciones();
                else if (op == 4) sistema->ListarAtencionesPorRangoFechas();
            } while (op != 0);
        }

        else if (opcionPrincipal == 3) {
            int op;
            do {
                MenuReportes();
                cout << "Seleccione una opción: ";
                cin >> op;
                cin.ignore();
                if (op == 1) sistema->ReporteIngresosPorServicio();
                else if (op == 2) sistema->ReporteAtencionesPorEspecialidad();
                else if (op == 3) sistema->ReporteAtencionesPorPaciente();
                else if (op == 4) sistema->ReporteIngresosPorPaciente();
                else if (op == 5) sistema->ReportePacientesPorServicio();
            } while (op != 0);
        }
    } while (opcionPrincipal != 0);
    
    system("pause");
    return 0;
}
