# Sistema de Gestión de Centro de Salud

Sistema de gestión de consultas externas para un centro de salud, desarrollado en C++ aplicando principios de Programación Orientada a Objetos (POO).

## Descripción

El sistema permite administrar los servicios médicos, pacientes, personal de salud (médicos y enfermeras) y las atenciones brindadas en un centro de salud. Incluye módulos de registro, listado y generación de reportes, integrados a través de un menú interactivo por consola.

## Estructura de Clases

```
Persona (clase base)
├── Paciente
└── PersonalSalud
    ├── Medico
    └── Enfermera

Servicio (independiente)
Atencion (independiente)
CentroSalud (clase gestora principal)
```

## Funcionalidades

### Registro
- Servicios médicos (ID, nombre, especialidad, costo)
- Pacientes (DNI, nombres, dirección, género, talla, peso)
- Personal de salud: médicos (especialidad, CMP) y enfermeras (servicio, CEP)
- Atenciones con validación de servicio y paciente existentes

### Listado
- Servicios registrados
- Personas (pacientes, médicos, enfermeras)
- Atenciones realizadas
- Atenciones filtradas por rango de fechas

### Reportes
- Ingresos totales por servicio
- Atenciones por especialidad médica
- Atenciones por paciente (búsqueda por DNI)
- Ingresos acumulados por paciente
- Pacientes atendidos por servicio

## Conceptos de POO Aplicados

- **Herencia:** jerarquía `Persona → Paciente`, `Persona → PersonalSalud → Medico/Enfermera`
- **Polimorfismo:** métodos virtuales `Leer()` y `Escribir()` sobrescritos en cada clase derivada, uso de `dynamic_cast` para identificar tipos en tiempo de ejecución
- **Encapsulamiento:** atributos privados/protegidos con acceso mediante getters y setters
- **Composición:** la clase `cCentroSalud` gestiona arreglos dinámicos de punteros a `Servicio`, `Persona` y `Atencion`
- **Memoria dinámica:** uso de `new` para creación de objetos en el heap y arreglos de punteros

## Archivos del Proyecto

| Archivo | Descripción |
|---|---|
| `Centro_de_Salud.cpp` | Programa principal con menú interactivo |
| `cCentroSalud.h` | Clase gestora con lógica de negocio |
| `Persona.h` | Clase base abstracta |
| `Paciente.h` | Hereda de Persona |
| `PersonalSalud.h` | Hereda de Persona |
| `Medico.h` | Hereda de PersonalSalud |
| `Enfermera.h` | Hereda de PersonalSalud |
| `Servicio.h` | Clase independiente para servicios médicos |
| `Atencion.h` | Clase independiente para atenciones |

## Compilación

El proyecto fue desarrollado en **Visual Studio** (Windows). Para compilar:

1. Abrir Visual Studio y crear un proyecto de consola C++ vacío
2. Agregar todos los archivos `.h` y `Centro_de_Salud.cpp` al proyecto
3. Compilar y ejecutar (Ctrl + F5)

## Tecnologías

- C++
- Visual Studio (IDE)
- Programación Orientada a Objetos
