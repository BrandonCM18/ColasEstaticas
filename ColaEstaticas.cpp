#include <iostream>
#include "cola.h"

int main() {
    Cola colaSolicitudes;

    while (true) {
        std::cout << "Menu para solicitudes de alumnos y constancias:" << std::endl;
        std::cout << "1. Dar de alta solicitud de alumno" << std::endl;
        std::cout << "2. Elaborar constancia" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion:" << std::endl;


        int opcion;
        std::cin >> opcion;

        if (opcion == 1) {
            std::string nombre, carrera;
            int materiasAprobadas;
            float promedioGeneral;

            std::cout << "Nombre del alumno: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);

            std::cout << "Carrera: ";
            std::getline(std::cin, carrera);

            std::cout << "Materias aprobadas: ";
            std::cin >> materiasAprobadas;

            std::cout << "Promedio general: ";
            std::cin >> promedioGeneral;

            Alumno nuevoAlumno(nombre, carrera, materiasAprobadas, promedioGeneral);
            colaSolicitudes.enqueue(nuevoAlumno);
            std::cout << "Solicitud de alumno agregada a la cola" << std::endl;
        } else if (opcion == 2) {
            if (!colaSolicitudes.vacia()) {
                Alumno alumnoAtendido = colaSolicitudes.dequeue();
                std::cout << "Constancia elaborada para el siguiente alumno:" << std::endl;
                std::cout << alumnoAtendido << std::endl;
            } else {
                std::cout << "No hay solicitudes pendientes para atender." << std::endl;
            }
        } else if (opcion == 3) {
            break;
        } else {
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}
