//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO3_2_HPP
#define PRACTICA1EDNL_EJERCICIO3_2_HPP

#include "ExpresionAritmetica.h"
#include "../../ArbolBinario.h"

double evaluar(ArbolBinario<ExpresionAritmetica>& A, typename ArbolBinario<ExpresionAritmetica>::nodo n){}

double evaluar(ArbolBinario<ExpresionAritmetica>& A){

    // El árbol no puede estar vacío
    assert(!A.arbolVacio());
    return evaluar(A, A.raiz());
}

#endif //PRACTICA1EDNL_EJERCICIO3_2_HPP
