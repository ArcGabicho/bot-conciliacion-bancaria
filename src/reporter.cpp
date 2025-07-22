#include "../include/reporter.h"
#include <fstream>
#include <iostream>

void exportarReporte(const ResultadoConciliacion& resultado, const std::string& rutaArchivo) {
    std::ofstream out(rutaArchivo);
    if (!out.is_open()) {
        std::cerr << "❌ No se pudo guardar el archivo de reporte.\n";
        return;
    }

    out << "========== REPORTE DE CONCILIACIÓN ==========\n\n";

    out << "[FALTAN EN BANCO]:\n";
    for (const auto& t : resultado.faltanEnBanco) {
        out << t.fecha << " | " << t.monto << " | " << t.descripcion << "\n";
    }

    out << "\n[FALTAN EN INTERNO]:\n";
    for (const auto& t : resultado.faltanEnInterno) {
        out << t.fecha << " | " << t.monto << " | " << t.descripcion << "\n";
    }

    out << "\n=============================================\n";
    out.close();
}