cmake_minimum_required(VERSION 3.19)
project(Practica1EDNL)

set(CMAKE_CXX_STANDARD 11)

include_directories(practica2/ejercicio3)
add_executable(Practica1EDNL main.cpp ArbolBinario.h ArbolBinarioIO.h ArbolBinarioIO.cpp practica1/ejercicio1/ejercicio1_1.h
        practica1/ejercicio2/ejercicio2_1.h practica1/ejercicio2/ejercicio2_1.cpp practica1/ejercicio3/ejercicio3_1.h
        practica1/ejercicio6/ejercicio6_1.h practica1/ejercicio7/ejercicio7_1.h practica2/ejercicio1/ejercicio1_2.h
        practica2/ejercicio2/ejercicio2_2.h practica2/ejercicio3/ejercicio3_2.hpp
        practica2/ejercicio3/ArbolBinarioAritmeticoIO.hpp practica2/ejercicio3/ArbolBinarioAritmeticoIO.cpp
        practica2/ejercicio3/ExpresionAritmetica.hpp preExamen/poda.cpp preExamen/poda.h examen/examen.cpp examen/examen.h)