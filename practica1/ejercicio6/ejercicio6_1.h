//
// Created by abrah on 21/02/2022.
//

#ifndef PRACTICA1EDNL_EJERCICIO6_1_H
#define PRACTICA1EDNL_EJERCICIO6_1_H

#include "../../ArbolBinario.h"
#include "algorithm"

using namespace std;

template <typename T>
int desequilibrioNodo(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo nodo){

    // Un nodo nulo no tiene subarboles -> desequilibrio = 0
    if (nodo == ArbolBinario<T>::NODO_NULO) return 0;
    else {

        typename ArbolBinario<T>::nodo hijoIzq = A.hijoIzdo(nodo);
        typename ArbolBinario<T>::nodo hijoDer = A.hijoDer(nodo);

        int alturaHijoIzq = A.altura(hijoIzq);
        int alturaHijoDer = A.altura(hijoDer);

        // Contamos la rama que va del nodo actual a su respectivo hijo (si tiene)
        if (hijoIzq != ArbolBinario<T>::NODO_NULO) alturaHijoIzq++;
        if (hijoDer != ArbolBinario<T>::NODO_NULO) alturaHijoDer++;

        // Calculamos la diferencia entre la altura de sus subárboles
        int tempDes = abs(alturaHijoDer - alturaHijoIzq);

        // Calculamos el desequilibrio de sus hijos y nos quedamos con el que tenga más desequilibrio
        int tempDesHijos = max(desequilibrioNodo(A, A.hijoIzdo(nodo)),
                               desequilibrioNodo(A, A.hijoDer(nodo)));

        // Retornamos que el mayor desequilibrio
        return max(tempDes, tempDesHijos);
    }
}

template <typename T>
int desequilibrio(ArbolBinario<T>& A){
    return max(desequilibrioNodo(A, A.hijoIzdo(A.raiz())),
               desequilibrioNodo(A, A.hijoDer(A.raiz())));
}

/*template <typename T>
int desequilibrio(ArbolBinario<T>& A){
    return max(desequilibrio(A, A.hijoIzdo(A.raiz())),
               desequilibrio(A, A.hijoDer(A.raiz())));
};*/

#endif //PRACTICA1EDNL_EJERCICIO6_1_H
