#include <iostream>
#include "./include/bot_conciliacion.h"

int main() {
    std::cout << "Iniciando Bot de Conciliación Bancaria Automática...\n";

    std::string rutaInterno = "../data/interno.csv";
    std::string rutaBanco = "../data/banco.csv";

    std::vector<Transaccion> transInterno = leerCSV(rutaInterno);
    std::vector<Transaccion> transBanco = leerCSV(rutaBanco);

    compararTransacciones(transInterno, transBanco);

    return 0;
}