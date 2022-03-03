//
// Created by abrah on 21/02/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO7_1_H
#define PRACTICA1EDNL_EJERCICIO7_1_H
#include "../../ArbolBinario.h"

template <typename T>
bool pseudo(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo nodo){

    if (nodo == ArbolBinario<T>::NODO_NULO) return false;
    else return (A.hijoIzdo(nodo) == ArbolBinario<T>::NODO_NULO and A.hijoDer(nodo) == ArbolBinario<T>::NODO_NULO)
                or
                (A.hijoIzdo(nodo) != ArbolBinario<T>::NODO_NULO and A.hijoDer(nodo) != ArbolBinario<T>::NODO_NULO);
}

template <typename T>
void pseudoCompleto(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo nodo, int nivel, int penultNivel,
                    int* nNodosPenNivel, int* nNodosPseudoCompletos){

    if (nodo == ArbolBinario<T>::NODO_NULO) return;
    else{

        // No estamos en los nodos del penúltimo nivel
        if (nivel != penultNivel){
            pseudoCompleto(A, A.hijoIzdo(nodo), nivel+1, penultNivel, nNodosPenNivel, nNodosPseudoCompletos);
            pseudoCompleto(A, A.hijoDer(nodo), nivel+1, penultNivel, nNodosPenNivel, nNodosPseudoCompletos);
        }

            // El nodo pertenece al penúltimo nivel
        else {
            *nNodosPenNivel = *nNodosPenNivel + 1;      // Incrementamos el número de nodos del penúltimo nivel en 1

            // Comprobamos si el nodo es pseudocompleto
            if (pseudo(A, nodo)){
                *nNodosPseudoCompletos = *nNodosPseudoCompletos + 1;        // Incrementamos el número de nodos pseudo completos en 1
            }
        }
    }
}

template <typename T>
bool pseudoCompleto(ArbolBinario<T>& A){

    int nodosPenultimoNivel = 0;
    int nodosPseudoCompletos = 0;

    // Calculamos el número de nodos en el último nivel y cuantos son pseudo completos
    pseudoCompleto(A, A.raiz(), 0, A.altura(A.raiz()) - 1, &nodosPenultimoNivel, &nodosPseudoCompletos);

    // Comprobamos que el número de nodos del penúltimo nivel y el número de nodos pseudo completos (del penúltimo nivel) coinciden
    return nodosPenultimoNivel == nodosPseudoCompletos;
}

#endif //PRACTICA1EDNL_EJERCICIO7_1_H
