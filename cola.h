#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

const int TAM = 100;

class Alumno {
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    Alumno();
    Alumno(const std::string& nombre, const std::string& carrera, int materiasAprobadas, float promedioGeneral);
    friend std::ostream& operator<<(std::ostream& os, const Alumno& alumno);
    std::string getNombre() const;
};

class Cola {
private:
    Alumno datos[TAM];
    int frente;
    int fin;

public:
    Cola();
    bool vacia() const;
    bool llena() const;
    void enqueue(const Alumno& alumno);
    Alumno dequeue();
};

#endif // COLA_H
