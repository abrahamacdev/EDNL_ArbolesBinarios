//
// Created by abrah on 20/02/2022.
//

#include <algorithm>
#include "ejercicio2.h"

using namespace std;

template <typename T>
int calcular_Altura(const ArbolBinario<T>& A, const typename ArbolBinario<T>::nodo& nodo){
    if (nodo == ArbolBinario<T>::NODO_NULO) return 0;
    else return 1 + max(calcular_Altura(A, A.hijoIzdo(nodo)),
                        calcular_Altura(A, A.hijoDer(nodo)));
}

template <typename T>
int calcularAltura(const ArbolBinario<T>& A){
    if (A.arbolVacio()) return 0;
    else return max(calcular_Altura(A, A.hijoIzdo(A.raiz())),
                    calcular_Altura(A, A.hijoDer(A.raiz())));
}