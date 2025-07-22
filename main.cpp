#include <iostream>
#include "./include/bot_conciliacion.h"

int main() {
    std::cout << R"(
 ____              _      _____                           _ _ _       _   _
|  _ \            | |    |  __ \                         (_) (_)     | | (_)
| |_) | __ _ _ __ | | __ | |__) |___  ___ ___  _ __   ___ _| |_  __ _| |_ _  ___  _ __
|  _ < / _` | '_ \| |/ / |  _  // _ \/ __/ _ \| '_ \ / __| | | |/ _` | __| |/ _ \| '_ \
| |_) | (_| | | | |   <  | | \ \  __/ (_| (_) | | | | (__| | | | (_| | |_| | (_) | | | |
|____/ \__,_|_| |_|_|\_\ |_|  \_\___|\___\___/|_| |_|\___|_|_|_|\__,_|\__|_|\___/|_| |_|
    )";

    std::cout << "Iniciando Bot de Conciliacion Bancaria Automatica...\n";

    std::string rutaInterno = "../data/interno.csv";
    std::string rutaBanco = "../data/banco.csv";

    std::vector<Transaccion> transInterno = leerCSV(rutaInterno);
    std::vector<Transaccion> transBanco = leerCSV(rutaBanco);

    compararTransacciones(transInterno, transBanco);

    return 0;
}