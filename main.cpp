#include <iostream>
#include <string>
#include "./include/bot_conciliacion.h"
#include "./include/reporter.h"
#include "./include/loader.h"


int main() {
    std::cout << R"(
 ____              _      _____                           _ _ _       _   _
|  _ \            | |    |  __ \                         (_) (_)     | | (_)
| |_) | __ _ _ __ | | __ | |__) |___  ___ ___  _ __   ___ _| |_  __ _| |_ _  ___  _ __
|  _ < / _` | '_ \| |/ / |  _  // _ \/ __/ _ \| '_ \ / __| | | |/ _` | __| |/ _ \| '_ \
| |_) | (_| | | | |   <  | | \ \  __/ (_| (_) | | | | (__| | | | (_| | |_| | (_) | | | |
|____/ \__,_|_| |_|_|\_\ |_|  \_\___|\___\___/|_| |_|\___|_|_|_|\__,_|\__|_|\___/|_| |_|
    )" << std::endl;

    std::cout << "Iniciando Bot de Conciliacion Bancaria Automatica...\n" << std::endl;

    int opcion = 0;
    std::cout << "Seleccione una opcion:\n";
    std::cout << "1) Ejecutar conciliacion con datos reales\n";
    std::cout << "2) Ejecutar conciliacion con datos de prueba\n";
    std::cout << "3) Salir\n> ";
    std::cin >> opcion;

    if (opcion == 3) {
        std::cout << "Saliendo del programa...\n";
        return 0;
    }

    std::string rutaInterno, rutaBanco;

    if (opcion == 1) {
        rutaInterno = "../data/interno.csv";
        rutaBanco = "../data/banco.csv";
    } else if (opcion == 2) {
        rutaInterno = "../test_data/interno_simulado.csv";
        rutaBanco = "../test_data/banco_simulado.csv";
    } else {
        std::cerr << "Opcion invalida. Abortando...\n";
        return 1;
    }

    char exportar;
    std::cout << "\n¿Desea exportar el resultado a archivo? [y/n]\n> ";
    std::cin >> exportar;

    std::cout << "\nCargando archivos...\n";
    std::vector<Transaccion> transInterno = leerCSV(rutaInterno);
    std::vector<Transaccion> transBanco = leerCSV(rutaBanco);

    std::cout << "Comparando transacciones...\n";
    ResultadoConciliacion resultado = compararTransacciones(transInterno, transBanco);

    std::cout << "\nConciliacion finalizada.\n";

    if (exportar == 'y' || exportar == 'Y') {
        std::string rutaReporte = "output/reporte_conciliacion.txt";
        exportarReporte(resultado, rutaReporte);
        std::cout << "Reporte guardado en: " << rutaReporte << "\n";
    }

    return 0;
}