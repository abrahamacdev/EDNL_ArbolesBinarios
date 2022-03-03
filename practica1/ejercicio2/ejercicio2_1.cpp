//
// Created by abrah on 20/02/2022.
//

#include <algorithm>
#include "ejercicio2_1.h"

using namespace std;

template <typename T>
int calcularAltura_Rec(const ArbolBinario<T>& A, const typename ArbolBinario<T>::nodo& nodo){
    if (nodo == ArbolBinario<T>::NODO_NULO) return 0;
    else return 1 + max(calcularAltura_Rec(A, A.hijoIzdo(nodo)),
                        calcularAltura_Rec(A, A.hijoDer(nodo)));
}

template <typename T>
int calcularAltura(const ArbolBinario<T>& A){
    if (A.arbolVacio()) return 0;
    else return max(calcularAltura_Rec(A, A.hijoIzdo(A.raiz())),
                    calcularAltura_Rec(A, A.hijoDer(A.raiz())));
}