#ifndef BOT_CONCILIACION_H
#define BOT_CONCILIACION_H

#include <string>
#include <vector>

struct Transaccion {
    std::string fecha;
    double monto;
    std::string descripcion;

    bool operator==(const Transaccion& otra) const;
};

std::vector<Transaccion> leerCSV(const std::string& rutaArchivo);
void compararTransacciones(const std::vector<Transaccion>& internas, const std::vector<Transaccion>& banco);

#endif