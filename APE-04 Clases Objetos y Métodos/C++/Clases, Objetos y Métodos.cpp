#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

// Clase que representa a un estudiante de Algoritmos y Logica de Programacion
class Estudiante {
private:
    std::string cedula;
    std::string nombre;
    std::string apellido;
    double nota1;
    double nota2;
    double nota3;
    double promedio;

public:
    // Constructor por defecto
    Estudiante()
        : cedula(""), nombre(""), apellido(""), nota1(0.0), nota2(0.0), nota3(0.0), promedio(0.0) {}

    // Constructor con parametros
    Estudiante(const std::string& cedula, const std::string& nombre, const std::string& apellido,
              double nota1, double nota2, double nota3)
        : cedula(cedula), nombre(nombre), apellido(apellido), nota1(nota1), nota2(nota2), nota3(nota3), promedio(0.0) {
        calcularPromedio();
    }

    // Metodos get
    std::string getCedula() const { return cedula; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    double getPromedio() const { return promedio; }

    // Metodos set
    void setCedula(const std::string& value) { cedula = value; }
    void setNombre(const std::string& value) { nombre = value; }
    void setApellido(const std::string& value) { apellido = value; }

    bool setNota1(double value) {
        if (value < 0.0 || value > 10.0) {
            return false;
        }
        nota1 = value;
        return true;
    }

    bool setNota2(double value) {
        if (value < 0.0 || value > 10.0) {
            return false;
        }
        nota2 = value;
        return true;
    }

    bool setNota3(double value) {
        if (value < 0.0 || value > 10.0) {
            return false;
        }
        nota3 = value;
        return true;
    }

    // Calcula el promedio en base a las tres notas
    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0;
    }

    // Determina si el estudiante aprueba o reprueba
    std::string determinarEstado() const {
        return (promedio >= 7.0) ? "Aprobado" : "Reprobado";
    }

    // Muestra la informacion completa del estudiante
    void mostrarInformacion() const {
        std::cout << "Cedula: " << cedula << "\n";
        std::cout << "Nombre: " << nombre << " " << apellido << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Notas: " << nota1 << ", " << nota2 << ", " << nota3 << "\n";
        std::cout << "Promedio: " << promedio << "\n";
        std::cout << "Estado: " << determinarEstado() << "\n";
        std::cout << "----------------------------------------\n";
    }
};

// Lee una nota valida entre 0 y 10
double leerNotaValida(const std::string& mensaje) {
    double nota;
    while (true) {
        std::cout << mensaje;
        std::cin >> nota;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Ingrese un numero entre 0 y 10.\n";
            continue;
        }

        if (nota < 0.0 || nota > 10.0) {
            std::cout << "La nota debe estar entre 0 y 10. Intente de nuevo.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return nota;
    }
}

// Lee una linea de texto desde la entrada estandar
std::string leerLinea(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

int main() {
    std::vector<Estudiante> estudiantes;
    const int cantidadEstudiantes = 5;

    std::cout << "=== Sistema de control de estudiantes ===\n";
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        std::cout << "\nRegistro del estudiante " << (i + 1) << ":\n";
        std::string cedula = leerLinea("Ingrese la cedula: ");
        std::string nombre = leerLinea("Ingrese el nombre: ");
        std::string apellido = leerLinea("Ingrese el apellido: ");

        double nota1 = leerNotaValida("Ingrese la nota 1 (0-10): ");
        double nota2 = leerNotaValida("Ingrese la nota 2 (0-10): ");
        double nota3 = leerNotaValida("Ingrese la nota 3 (0-10): ");

        Estudiante estudiante(cedula, nombre, apellido, nota1, nota2, nota3);
        estudiantes.push_back(estudiante);
    }

    int aprobados = 0;
    int reprobados = 0;

    std::cout << "\n=== Listado completo de estudiantes ===\n";
    for (const Estudiante& estudiante : estudiantes) {
        estudiante.mostrarInformacion();
        if (estudiante.determinarEstado() == "Aprobado") {
            ++aprobados;
        } else {
            ++reprobados;
        }
    }

    std::cout << "Total de estudiantes aprobados: " << aprobados << "\n";
    std::cout << "Total de estudiantes reprobados: " << reprobados << "\n";

    return 0;
}
