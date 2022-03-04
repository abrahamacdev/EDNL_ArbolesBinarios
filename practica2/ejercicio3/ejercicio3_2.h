//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO3_2_H
#define PRACTICA1EDNL_EJERCICIO3_2_H

#include "../../ArbolBinario.h"

static const enum ExprArit {
    OPERADOR,       // 1.0 = Suma | 2.0 = Resta | 3.0 = Multiplicación | 4.0 = División
    OPERANDO
};

struct ExpresionAritmetica {
    ExprArit exprArit;
    double valor;
};

double evaluar(ArbolBinario<ExprArit>& A, typename ArbolBinario<T>::nodo n){}

double evaluar(ArbolBinario<ExprArit>& A){

    // El árbol no puede estar vacío
    assert(!A.arbolVacio());
    return evaluar(A, A.raiz());
}



#endif //PRACTICA1EDNL_EJERCICIO3_2_H
