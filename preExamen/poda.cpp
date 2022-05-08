//
// Created by abrah on 24/03/2022.
//

#include "poda.h"

template <typename T>
void eliminar_Rec(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo n){
    if (n != ArbolBinario<T>::NODO_NULO){
        if (A.hijoIzdo(n) != ArbolBinario<T>::NODO_NULO){
            eliminar_Rec(A, A.hijoIzdo(n));
            A.eliminarHijoIzdo(n);
        }
        if (A.hijoDer(n) != ArbolBinario<T>::NODO_NULO){
            eliminar_Rec(A, A.hijoDer(n));
            A.eliminarHijoDer(n);
        }
    }
}

template <typename T>
void poda_Rec(typename ArbolBinario<T>::nodo actual, ArbolBinario<T>& A, typename ArbolBinario<T>::nodo n){

    // El nodo actual tiene hijo izdo
    if (A.hijoIzdo(actual) != ArbolBinario<T>::NODO_NULO){

        // El nodo n es hijo izdo del nodo actual
        if (A.hijoIzdo(actual) == n){
            eliminar_Rec(A, A.hijoIzdo(actual));            // Eliminamos los hijos del nodo actual
            A.eliminarHijoIzdo(actual);            // Eliminamos el propio nodo actual
        }

        // Seguimos buscando por el hijo izquierdo
        else {
            poda_Rec(A.hijoIzdo(actual), A, n);
        }
    }

    // El nodo actual tiene hijo izdo
    if (A.hijoDer(actual) != ArbolBinario<T>::NODO_NULO){

        // El nodo n es hijo dercho del nodo actual
        if (A.hijoDer(actual) == n){

            eliminar_Rec(A, A.hijoDer(actual));             // Eliminamos los hijos del nodo actual
            A.eliminarHijoDer(actual);                      // Eliminamos el propio nodo actual
        }

        // Seguimos buscando por el hijo derecho
        else {
            poda_Rec(A.hijoDer(actual), A, n);
        }
    }
}

template <typename T>
void poda(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo n){

    assert(!A.arbolVacio());
    assert(n != ArbolBinario<T>::NODO_NULO);

    // El nodo buscado es la raíz
    if (A.raiz() == n){
        eliminar_Rec(A, n);
        A.eliminarRaiz();
    }

    // Buscamos el nodo a través del árbol
    else poda_Rec(A.raiz(), A, n);
}