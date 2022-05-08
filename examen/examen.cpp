//
// Created by abrah on 25/03/2022.
//

#include "examen.h"

template <typename T>
void insertarInOrder(typename ArbolBinario<T>::nodo n, ArbolBinario<T>& A, queue<T>& c){
    if (n != ArbolBinario<T>::NODO_NULO){
        insertarInOrder(A.hijoIzdo(n), A, c);
        c.push(A.elemento(n));
        insertarInOrder(A.hijoDer(n), A, c);
    }
}

template <typename T>
void insertarInOrderInverso(typename ArbolBinario<T>::nodo n, ArbolBinario<T>& A, queue<T>& c){
    if (n != ArbolBinario<T>::NODO_NULO){
        insertarInOrderInverso(A.hijoDer(n), A, c);
        c.push(A.elemento(n));
        insertarInOrderInverso(A.hijoIzdo(n), A, c);
    }
}

template <typename T>
bool reflejado(typename ArbolBinario<T>::nodo a, typename ArbolBinario<T>::nodo b, ArbolBinario<T>& A){

    // La raíz de los subárboles tiene que coincidir
    if (A.elemento(a) == A.elemento(b)){

        queue<T> ca;
        queue<T> cb;

        insertarInOrder(a, A, ca);
        insertarInOrderInverso(b, A, cb);

        int numElemsA = 0;
        int numElemsB = 0;

        while (!ca.empty() && !cb.empty()){

            T& elemA = ca.front();
            T& elemB = cb.front();

            numElemsA++;
            numElemsB++;

            // Los elementos no coinciden
            if (elemA != elemB) return false;

            ca.pop();
            cb.pop();
        }

        // Comprobamos si todos los elementos han coincidido o algun subárbol tenía menos elementos
        return numElemsA == numElemsB;
    }
    return false;
}

template <typename T>
int cuentaReflejados_Rec(typename ArbolBinario<T>::nodo hijoIzq, typename ArbolBinario<T>::nodo hijoDer, ArbolBinario<T>& A){

    // Comparamos si son hijos reflejados
    if (hijoIzq != ArbolBinario<T>::NODO_NULO && hijoDer != ArbolBinario<T>::NODO_NULO){

        // El subárbol está reflejado, contamos un nodo
        if (reflejado(hijoIzq, hijoDer, A)){
            return 1 + cuentaReflejados_Rec(A.hijoIzdo(hijoIzq), A.hijoDer(hijoIzq), A)
                     + cuentaReflejados_Rec(A.hijoIzdo(hijoDer), A.hijoDer(hijoDer), A);
        }

        // El subárbol no está reflejado, seguimos con sus hijos
        else {
            return cuentaReflejados_Rec(A.hijoIzdo(hijoIzq), A.hijoDer(hijoIzq), A)
                    + cuentaReflejados_Rec(A.hijoIzdo(hijoDer), A.hijoDer(hijoDer), A);
        }
    }

    // Estos nodos no valen, seguimos con los de los hijos
    else{

        // Estos nodos no valen, seguimos con los del hijo izquierdo
        if (hijoIzq != ArbolBinario<T>::NODO_NULO){
            return cuentaReflejados_Rec(A.hijoIzdo(hijoIzq), A.hijoDer(hijoIzq), A);
        }

        // Estos nodos no valen, seguimos con los del hijo derecho
        if (hijoDer != ArbolBinario<T>::NODO_NULO){
            return cuentaReflejados_Rec(A.hijoIzdo(hijoDer), A.hijoDer(hijoDer), A);
        }
    }

    return 0;
}

template <typename T>
int cuentaReflejados(ArbolBinario<T>& A){
    if (A.raiz() == ArbolBinario<T>::NODO_NULO) return 0;
    else return cuentaReflejados_Rec(A.hijoIzdo(A.raiz()), A.hijoDer(A.raiz()), A) * 2;
}