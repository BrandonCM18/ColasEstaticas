#include "cola.h"
#include <stdio.h>
#include "cola.h"

Alumno::Alumno() : nombre(""), carrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}

Alumno::Alumno(const std::string& nombre, const std::string& carrera, int materiasAprobadas, float promedioGeneral)
    : nombre(nombre), carrera(carrera), materiasAprobadas(materiasAprobadas), promedioGeneral(promedioGeneral) {}

std::ostream& operator<<(std::ostream& os, const Alumno& alumno) {
    os << "Nombre: " << alumno.nombre << std::endl;
    os << "Carrera: " << alumno.carrera << std::endl;
    os << "Materias Aprobadas: " << alumno.materiasAprobadas << std::endl;
    os << "Promedio General: " << alumno.promedioGeneral << std::endl;
    return os;
}

std::string Alumno::getNombre() const {
    return nombre;
}

Cola::Cola() : frente(0), fin(0) {}

bool Cola::vacia() const {
    return frente == fin;
}

bool Cola::llena() const {
    return (fin + 1) % TAM == frente;
}

void Cola::enqueue(const Alumno& alumno) {
    if (!llena()) {
        datos[fin] = alumno;
        fin = (fin + 1) % TAM;
    } else {
        std::cout << "La cola esta llena. No se puede agregar la solicitud." << std::endl;
    }
}

Alumno Cola::dequeue() {
    if (!vacia()) {
        Alumno alumno = datos[frente];
        frente = (frente + 1) % TAM;
        return alumno;
    } else {
        std::cout << "La cola esta vacia. No hay solicitudes para atender." << std::endl;
        return Alumno();
    }
}
