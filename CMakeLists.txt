cmake_minimum_required(VERSION 3.31)
project(bot_conciliacion_bancaria)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(bot_conciliacion_bancaria main.cpp ${SOURCES})
