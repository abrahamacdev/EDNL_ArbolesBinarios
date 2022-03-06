//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO3_2_HPP
#define PRACTICA1EDNL_EJERCICIO3_2_HPP

#include "ExpresionAritmetica.hpp"
#include "../../ArbolBinario.h"

double evaluar(ArbolBinario<ExpresionAritmetica>& A, typename ArbolBinario<ExpresionAritmetica>::nodo n){

    ExpresionAritmetica& tempExpr = A.elemento(n);

    // Es un nodo hoja, devolvemos el valor del operando
    if (tempExpr.exprArit == OPERANDO) return tempExpr.valor;

    // Es un operador, tenemos que evaluar los hijos
    else {

        switch ((int) tempExpr.valor) {

            // Es una suma
            case 1:
                return evaluar(A, A.hijoIzdo(n)) + evaluar(A, A.hijoDer(n));

            // Es una resta
            case 2:
                return evaluar(A, A.hijoIzdo(n)) - evaluar(A, A.hijoDer(n));

            // Es una multiplicación
            case 3:
                return evaluar(A, A.hijoIzdo(n)) * evaluar(A, A.hijoDer(n));

            // Es una división
            case 4:
                return evaluar(A, A.hijoIzdo(n)) / evaluar(A, A.hijoDer(n));
        }
    }
}

double evaluar(ArbolBinario<ExpresionAritmetica>& A){

    // El árbol no puede estar vacío
    assert(!A.arbolVacio());
    return evaluar(A, A.raiz());
}

#endif //PRACTICA1EDNL_EJERCICIO3_2_HPP
