#include "../include/loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Transaccion> leerCSV(const std::string& ruta) {
    std::vector<Transaccion> transacciones;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir: " << ruta << std::endl;
        return transacciones;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string fecha, montoStr, descripcion;

        if (!std::getline(ss, fecha, ',')) continue;
        if (!std::getline(ss, montoStr, ',')) continue;
        if (!std::getline(ss, descripcion, ',')) continue;

        try {
            double monto = std::stod(montoStr);
            transacciones.push_back({fecha, monto, descripcion});
        } catch (...) {
            std::cerr << "Error al convertir monto: " << montoStr << std::endl;
        }
    }

    return transacciones;
}