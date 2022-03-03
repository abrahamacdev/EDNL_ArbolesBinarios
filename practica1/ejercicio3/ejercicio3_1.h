//
// Created by abrah on 20/02/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO3_1_H
#define PRACTICA1EDNL_EJERCICIO3_1_H

#include "../../ArbolBinario.h"

template <typename T>
int calcularProfundidad(const ArbolBinario<T>& A, const typename ArbolBinario<T>::nodo& nodo){
    if (nodo == ArbolBinario<T>::NODO_NULO) return -1;
    else if (nodo == A.raiz()) return 0;
    else return 1 + calcularProfundidad(A, A.padre(nodo));
}

#endif //PRACTICA1EDNL_EJERCICIO3_1_H