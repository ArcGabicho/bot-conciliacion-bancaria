cmake_minimum_required(VERSION 3.31)
project(bot_conciliacion_bancaria)

set(CMAKE_CXX_STANDARD 20)

add_executable(bot_conciliacion_bancaria main.cpp
        src/bot_conciliacion.cpp)
