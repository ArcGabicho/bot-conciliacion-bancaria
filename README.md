# 🤖 Bot de Conciliación Bancaria Automática

![Portada](https://i.pinimg.com/736x/7a/b1/73/7ab173a65cc849e2f0205a04ad4ed974.jpg)

Este proyecto es un bot desarrollado en C++ que simula el proceso de **conciliación bancaria automática**, comparando transacciones internas de una empresa con extractos bancarios. Su propósito es detectar diferencias, omisiones y posibles errores contables.

---

## 🚀 Características

- Lectura de archivos CSV (`interno.csv`, `banco.csv`)
- Comparación de fechas, montos y descripciones
- Detección de transacciones faltantes o no coincidentes
- Informe resumen de diferencias
- Interfaz CLI simple e interactiva

---

## 📂 Estructura del proyecto

```
├── CMakeLists.txt
├── README.md
├── LICENSE
├── /data
│ ├── interno.csv
│ └── banco.csv
├── /src
│ ├── main.cpp
│ └── bot_conciliacion.cpp
├── /include
│ └── bot_conciliacion.h
```

---

# 💡 Futuras mejoras

- Soporte para lectura de JSON y bases de datos

- Tolerancia a errores en montos por centavos

- Generación automática de reportes en PDF o HTML

- Interfaz web conectada al CLI

## 📄 Licencia

Este proyecto está licenciado bajo los términos de la [MIT License](LICENSE).