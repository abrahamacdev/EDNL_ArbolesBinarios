//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO2_2_H
#define PRACTICA1EDNL_EJERCICIO2_2_H

#include "../../ArbolBinario.h"

template <typename T>
void reflejar(ArbolBinario<T>& A1, typename ArbolBinario<T>::nodo n1, ArbolBinario<T>& A2, typename ArbolBinario<T>::nodo n2){

    if (n1 != ArbolBinario<T>::NODO_NULO){

        // Hijo izdo. de n2 = Hijo der. de n1;
        if (A1.hijoIzdo(n1) != ArbolBinario<T>::NODO_NULO){
            A2.insertarHijoDer(n2, A1.elemento(A1.hijoIzdo(n1)));
            reflejar(A1, A1.hijoIzdo(n1), A2, A2.hijoDer(n2));
        }

        // Hijo der. de n2 = Hijo izdo. de n1;
        if (A1.hijoDer(n1) != ArbolBinario<T>::NODO_NULO){
            A2.insertarHijoIzdo(n2, A1.elemento(A1.hijoDer(n1)));
            reflejar(A1, A1.hijoDer(n1), A2, A2.hijoIzdo(n2));
        }
    }
}

template <typename T>
ArbolBinario<T> reflejar(ArbolBinario<T>& A){

    // Hacemos una copia del árbol pasado por parámetro
    ArbolBinario<T> copia = ArbolBinario<T>();

    // Si el árbol está vacío no tenemos que reflejar nada
    if (A.arbolVacio()) return copia;

    // Reflejamos a partir del nodo raíz
    else {
        copia.insertarRaiz(A.elemento(A.raiz()));
        reflejar(A, A.raiz(), copia, copia.raiz());
    }
}

#endif //PRACTICA1EDNL_EJERCICIO2_2_H
