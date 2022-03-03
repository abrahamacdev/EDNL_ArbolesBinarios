//
// Created by Judith Olalde Alonso on 3/3/22.
//

#ifndef PRACTICA1EDNL_EJERCICIO1_2_H
#define PRACTICA1EDNL_EJERCICIO1_2_H

#include "../../ArbolBinario.h"

template <typename T>
bool similares(ArbolBinario<T>& A1, typename ArbolBinario<T>::nodo n1,
               ArbolBinario<T>& A2, typename ArbolBinario<T>::nodo n2){

    int n1Nulo = n1 == ArbolBinario<T>::NODO_NULO;
    int n2Nulo = n2 == ArbolBinario<T>::NODO_NULO;

    int sum = n1Nulo + n2Nulo;

    // Uno de los nodos es nulo y el otro no
    if (sum == 1) return false;
    else if (sum == 2) return true;
    // Ambos nodos no son nulos
    else {

        // Comprobamos que tanto la pata izquierda como la derecha sean iguales
        return  similares(A1, A1.hijoIzdo(n1), A2, A2.hijoIzdo(n2))
                and
                similares(A1, A1.hijoDer(n1), A2, A2.hijoDer(n2));
    }
}

template <typename T>
bool similares(ArbolBinario<T>& A1, ArbolBinario<T>& A2){
    int a1Vacio = A1.arbolVacio();
    int a2Vacio = A2.arbolVacio();

    int sum = a1Vacio + a2Vacio;

    if (sum == 2) return true;                                              // Los árboles están vacíos
    else if (sum == 0) return similares(A1, A1.raiz(), A2, A2.raiz());      // Los árboles tienen nodos
    else return false;                                                      // Uno está vacío y otro no
}

#endif //PRACTICA1EDNL_EJERCICIO1_2_H
