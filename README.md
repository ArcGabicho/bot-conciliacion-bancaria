# 🤖 Bot de Conciliación Bancaria Automática

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
## ⚙️ Instalación

### 🧱 Requisitos

- CMake >= 3.24
- Compilador C++17 o superior
- CLion o cualquier IDE/CMake toolchain
- Git (opcional para clonar)

### 🔧 Compilación

```bash
git clone https://github.com/ArcGabicho/bot-conciliacion-bancaria.git
```
```bash
cd bot-conciliacion-bancaria
```
```bash
mkdir build && cd build
```
```bash
cmake ..
```
```bash
make
```
```bash
./BotConciliacion
```
---

# 💡 Futuras mejoras

- Soporte para lectura de JSON y bases de datos

- Tolerancia a errores en montos por centavos

- Generación automática de reportes en PDF o HTML

- Interfaz web conectada al CLI

# 🧑‍💻 Autor

**Gabriel Polack**  
*Consultor TI & Software Architect — [Blog](https://gabicho.dev)*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/tu-usuario/)  
[![GitHub](https://img.shields.io/badge/GitHub-181717?logo=github&logoColor=white)](https://github.com/tu-usuario)
