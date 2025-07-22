#pragma once
#include <vector>
#include <string>

struct Transaccion {
    std::string fecha;
    double monto;
    std::string descripcion;
};

struct ResultadoConciliacion {
    std::vector<Transaccion> faltanEnBanco;
    std::vector<Transaccion> faltanEnInterno;
};

ResultadoConciliacion compararTransacciones(
    const std::vector<Transaccion>& interno,
    const std::vector<Transaccion>& banco);
