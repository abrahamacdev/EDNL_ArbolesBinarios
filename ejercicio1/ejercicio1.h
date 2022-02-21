//
// Created by abrah on 20/02/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO1_H
#define PRACTICA1EDNL_EJERCICIO1_H

#include "../ArbolBinario.h"

template <typename T>
int calcularNodos(const ArbolBinario<T>& A, const typename ArbolBinario<T>::nodo& nodo){
    if (nodo == ArbolBinario<T>::NODO_NULO) return 0;
    else return 1 + calcularNodos(A, A.hijoIzdo(nodo)) + calcularNodos(A, A.hijoDer(nodo));
}

#endif //PRACTICA1EDNL_EJERCICIO1_H
