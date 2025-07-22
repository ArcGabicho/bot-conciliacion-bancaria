#include "../include/bot_conciliacion.h"

ResultadoConciliacion compararTransacciones(
    const std::vector<Transaccion>& interno,
    const std::vector<Transaccion>& banco) {

    ResultadoConciliacion resultado;

    for (const auto& tInt : interno) {
        bool encontrada = false;
        for (const auto& tBan : banco) {
            if (tInt.fecha == tBan.fecha &&
                tInt.monto == tBan.monto &&
                tInt.descripcion == tBan.descripcion) {
                encontrada = true;
                break;
                }
        }
        if (!encontrada)
            resultado.faltanEnBanco.push_back(tInt);
    }

    for (const auto& tBan : banco) {
        bool encontrada = false;
        for (const auto& tInt : interno) {
            if (tBan.fecha == tInt.fecha &&
                tBan.monto == tInt.monto &&
                tBan.descripcion == tInt.descripcion) {
                encontrada = true;
                break;
                }
        }
        if (!encontrada)
            resultado.faltanEnInterno.push_back(tBan);
    }

    return resultado;
}