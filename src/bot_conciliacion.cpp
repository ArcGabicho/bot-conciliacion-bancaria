#include "../include/bot_conciliacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

bool Transaccion::operator==(const Transaccion& otra) const {
    return fecha == otra.fecha &&
           std::abs(monto - otra.monto) < 0.01 && // tolerancia
           descripcion == otra.descripcion;
}

std::vector<Transaccion> leerCSV(const std::string& rutaArchivo) {
    std::vector<Transaccion> transacciones;
    std::ifstream archivo(rutaArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir: " << rutaArchivo << std::endl;
        return transacciones;
    }

    std::getline(archivo, linea); // saltar encabezado
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string fecha, montoStr, descripcion;
        std::getline(ss, fecha, ',');
        std::getline(ss, montoStr, ',');
        std::getline(ss, descripcion, ',');

        Transaccion t;
        t.fecha = fecha;
        t.monto = std::stod(montoStr);
        t.descripcion = descripcion;

        transacciones.push_back(t);
    }

    return transacciones;
}

void compararTransacciones(const std::vector<Transaccion>& internas, const std::vector<Transaccion>& banco) {
    std::cout << "Comparando transacciones...\n";

    for (const auto& t1 : internas) {
        bool encontrada = false;
        for (const auto& t2 : banco) {
            if (t1 == t2) {
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            std::cout << "FALTA EN BANCO: " << t1.fecha << " | " << t1.monto << " | " << t1.descripcion << "\n";
        }
    }

    for (const auto& t2 : banco) {
        bool encontrada = false;
        for (const auto& t1 : internas) {
            if (t2 == t1) {
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            std::cout << "FALTA EN INTERNO: " << t2.fecha << " | " << t2.monto << " | " << t2.descripcion << "\n";
        }
    }

    std::cout << "Conciliación finalizada.\n";
}