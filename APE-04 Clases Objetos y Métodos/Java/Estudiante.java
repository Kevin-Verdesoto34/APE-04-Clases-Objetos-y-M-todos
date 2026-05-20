import java.util.Scanner;

// Clase publica Estudiante para gestionar datos de estudiantes
public class Estudiante {
    private String cedula;
    private String nombre;
    private String apellido;
    private double nota1;
    private double nota2;
    private double nota3;
    private double promedio;

    // Constructor con parametros
    public Estudiante(String cedula, String nombre, String apellido,
                      double nota1, double nota2, double nota3) {
        this.cedula = cedula;
        this.nombre = nombre;
        this.apellido = apellido;
        this.nota1 = nota1;
        this.nota2 = nota2;
        this.nota3 = nota3;
        calcularPromedio();
    }

    // Metodos get
    public String getCedula() { return cedula; }
    public String getNombre() { return nombre; }
    public String getApellido() { return apellido; }
    public double getNota1() { return nota1; }
    public double getNota2() { return nota2; }
    public double getNota3() { return nota3; }
    public double getPromedio() { return promedio; }

    // Metodos set
    public void setCedula(String cedula) { this.cedula = cedula; }
    public void setNombre(String nombre) { this.nombre = nombre; }
    public void setApellido(String apellido) { this.apellido = apellido; }

    public boolean setNota1(double nota1) {
        if (nota1 < 0.0 || nota1 > 10.0) {
            return false;
        }
        this.nota1 = nota1;
        return true;
    }

    public boolean setNota2(double nota2) {
        if (nota2 < 0.0 || nota2 > 10.0) {
            return false;
        }
        this.nota2 = nota2;
        return true;
    }

    public boolean setNota3(double nota3) {
        if (nota3 < 0.0 || nota3 > 10.0) {
            return false;
        }
        this.nota3 = nota3;
        return true;
    }

    // Calcula el promedio de las tres notas
    public void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0;
    }

    // Devuelve el estado del estudiante segun el promedio
    public String determinarEstado() {
        return promedio >= 7.0 ? "Aprobado" : "Reprobado";
    }

    // Muestra la informacion del estudiante por consola
    public void mostrarInformacion() {
        System.out.println("Cedula: " + cedula);
        System.out.println("Nombre: " + nombre + " " + apellido);
        System.out.printf("Notas: %.2f, %.2f, %.2f%n", nota1, nota2, nota3);
        System.out.printf("Promedio: %.2f%n", promedio);
        System.out.println("Estado: " + determinarEstado());
        System.out.println("----------------------------------------");
    }

    private static double leerNotaValida(Scanner scanner, String mensaje) {
        double nota;
        while (true) {
            System.out.print(mensaje);
            if (!scanner.hasNextDouble()) {
                System.out.println("Entrada invalida. Ingrese un numero entre 0 y 10.");
                scanner.next();
                continue;
            }
            nota = scanner.nextDouble();
            scanner.nextLine();
            if (nota < 0.0 || nota > 10.0) {
                System.out.println("La nota debe estar entre 0 y 10. Intente nuevamente.");
                continue;
            }
            return nota;
        }
    }

    private static String leerTexto(Scanner scanner, String mensaje) {
        System.out.print(mensaje);
        return scanner.nextLine();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int cantidadEstudiantes = 5;
        Estudiante[] estudiantes = new Estudiante[cantidadEstudiantes];

        System.out.println("=== Sistema de control de estudiantes ===");
        for (int i = 0; i < cantidadEstudiantes; i++) {
            System.out.println("\nRegistro del estudiante " + (i + 1) + ":");
            String cedula = leerTexto(scanner, "Ingrese la cedula: ");
            String nombre = leerTexto(scanner, "Ingrese el nombre: ");
            String apellido = leerTexto(scanner, "Ingrese el apellido: ");
            double nota1 = leerNotaValida(scanner, "Ingrese la nota 1 (0-10): ");
            double nota2 = leerNotaValida(scanner, "Ingrese la nota 2 (0-10): ");
            double nota3 = leerNotaValida(scanner, "Ingrese la nota 3 (0-10): ");

            estudiantes[i] = new Estudiante(cedula, nombre, apellido, nota1, nota2, nota3);
        }

        int aprobados = 0;
        int reprobados = 0;

        System.out.println("\n=== Listado completo de estudiantes ===");
        for (Estudiante estudiante : estudiantes) {
            estudiante.mostrarInformacion();
            if (estudiante.determinarEstado().equals("Aprobado")) {
                aprobados++;
            } else {
                reprobados++;
            }
        }

        System.out.println("Total de estudiantes aprobados: " + aprobados);
        System.out.println("Total de estudiantes reprobados: " + reprobados);
        scanner.close();
    }
}
