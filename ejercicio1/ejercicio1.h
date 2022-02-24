//
// Created by abrah on 20/02/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO1_H
#define PRACTICA1EDNL_EJERCICIO1_H

#include "../ArbolBinario.h"

// TODO 1º Las funciones recursivas ponerle de nombre "X_Rec"
// TODO 2º Poner como primer parámetro el que se va a ir modificando

template <typename T>
int calcularNodos_Rec(const typename ArbolBinario<T>::nodo& nodo, const ArbolBinario<T>& A){
    if (nodo == ArbolBinario<T>::NODO_NULO) return 0;
    else return 1 + calcularNodos_Rec(A.hijoIzdo(nodo), A) + calcularNodos_Rec(A.hijoDer(nodo), A);
}

template <typename T>
int calcularNodos(const ArbolBinario<T>& A){
    return calcularNodos_Rec(A.raiz(), A);
}

#endif //PRACTICA1EDNL_EJERCICIO1_H
