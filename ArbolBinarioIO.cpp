//
// Created by abrah on 18/02/2022.
//

#include "ArbolBinarioIO.h"

using namespace std;

template <typename T>
void imprimirPantalla(const ArbolBinario<T>& A, const typename ArbolBinario<T>::nodo& n){

    if (A.arbolVacio()) cout << "El árbol está vacío" << endl;
    else {

        if (n == A.raiz()){
            // Mostramos la raíz
            cout << "Raíz del árbol: " << A.elemento(A.raiz()) << endl;
        }

        if (A.hijoIzdo(n) != ArbolBinario<T>::NODO_NULO){
            cout << "Hijo izqdo de " << A.elemento(n) << ": " << A.elemento(A.hijoIzdo(n)) << endl;
            imprimirPantalla(A, A.hijoIzdo(n));
        }
        if (A.hijoDer(n) !=  ArbolBinario<T>::NODO_NULO){
                cout << "Hijo derecho de " << A.elemento(n) << ": " << A.elemento(A.hijoDer(n)) << endl;
                imprimirPantalla(A, A.hijoDer(n));
            }
    }
}

template <typename T>
void imprimirArbolBinario(const ArbolBinario<T>& A){

    // Mostramos los hijos de la raíz
    imprimirPantalla(A, A.raiz());
}

template <typename T>
void guardarNodo(ostream& os, const ArbolBinario<T>& A, const T& fin, const typename ArbolBinario<T>::nodo& n){

    if (n == ArbolBinario<T>::NODO_NULO){
        os << fin << " ";
    }
    else {
        os << A.elemento(n) << " ";

        guardarNodo(os, A, fin, A.hijoIzdo(n));
        guardarNodo(os, A, fin, A.hijoDer(n));
    }
}

template <typename T>
void imprimirArbolBinario (ostream& os, const ArbolBinario<T>& A, const T& fin){

    // El primer caracter es el que se usa como fin
    os << fin << endl;

    guardarNodo(os, A, fin, A.raiz());
}

template <typename T>
void leerNodo(istream& input, ArbolBinario<T>& A, typename ArbolBinario<T>::nodo& n, T& fin, bool esIzqdo){

    T e = (T) input.get();
    input.get();            // Leemos el espacio

    typename ArbolBinario<T>::nodo tempNodo;

    if (e != fin){

        // Insertamos hijo izquierdo del nodo n
        if (esIzqdo){
            A.insertarHijoIzdo(n, e);
            tempNodo = A.hijoIzdo(n);
        }
            // Insertamos hijo derecho del nodo n
        else {
            A.insertarHijoDer(n, e);
            tempNodo = A.hijoDer(n);
        }
        // Leemos los dos hijos del nuevo nodo
        leerNodo(input, A, tempNodo, fin, true);
        leerNodo(input, A, tempNodo, fin, false);
    }
}
template <typename T>
void rellenarArbolBinario(istream& input, ArbolBinario<T>& A){

    T fin = (T) input.get();
    input.get();    // Leemos el salto de línea

    // Insertamos la raíz
    A.insertarRaiz(input.get());
    input.get();    // Leemos el espacio

    typename ArbolBinario<T>::nodo n = A.raiz();

    // Continuamos leyendo el árbol
    leerNodo(input, A, n, fin, true);
    leerNodo(input, A, n, fin, false);
}

template <typename T>
void preguntarNodo(ArbolBinario<T>& A, const T& fin, const typename ArbolBinario<T>::nodo& n = ArbolBinario<T>::NODO_NULO, bool hijoIzdo = true){

    T input;

    // El árbol está vacío, preguntamos la raíz
    if (A.arbolVacio()) {

        // Leemos el dato
        cout << "Raíz (Fin = " << fin << "): ";
        cin >> input;
        cout << endl;

        if (input != fin) {

            // Insertamos la raíz
            A.insertarRaiz(input);

            // Preguntamos por el hijo izquierdo
            preguntarNodo(A, fin, A.raiz(), true);
            preguntarNodo(A, fin, A.raiz(), false);
        }
    }
    else {

        // Estamos solicitando el hijo izquierdo del nodo n
        if(hijoIzdo){
            cout << "Hijo izqdo. de " << A.elemento(n) << " (Fin = " << fin << "): ";
            cin >> input;
            cout << endl;
        }

        // Estamos solicitando el hijo derecho del nodo n
        else {
            cout << "Hijo drcho. de " << A.elemento(n) << " (Fin = " << fin << "): ";
            cin >> input;
            cout << endl;

        }

        // Introduciremos un nodo
        if (input != fin){

            typename ArbolBinario<T>::nodo tempN;

            // Guardamos el hijo izquierdo del nodo n
            if (hijoIzdo){
                A.insertarHijoIzdo(n, input);
                tempN = A.hijoIzdo(n);
            }
                // Guardamos el hijo izquierdo del nodo n
            else {
                A.insertarHijoDer(n, input);
                tempN = A.hijoDer(n);
            }

            preguntarNodo(A, fin, tempN, true);     // Preguntamos el hijo izquierdo del nuevo nodo introducido
            preguntarNodo(A, fin, tempN, false);     // Preguntamos el hijo derecho del nuevo nodo introducido
        }
    }
}

template <typename T>
void rellenarArbolBinario(ArbolBinario<T>& A, const T& fin){
    // El árbol tiene que estar vacío
    assert(A.arbolVacio());

    // Preguntamos por los nodos de A
    preguntarNodo(A, fin);
}