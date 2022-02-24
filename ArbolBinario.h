#ifndef ARBOLBINARIO_ARBOLBINARIO_H
#define ARBOLBINARIO_ARBOLBINARIO_H

#include <iostream>
#include "cassert"
#include "algorithm"
using namespace std;

/**
 * Un árbol binario es un árbol que, como máximo, puede ser de grado 2, es decir, tiene: 0, 1 ó dos hijos.
 * Un NODO_NULO no hace referencia a ningún nodo válido del árbol.
 *
 * Operaciones:
 *
 *      ArbolBinario() ->
 *          Postcondicion: Crea un árbol binario vacío.
 *
 *      insertarRaiz(const T& e) ->
 *          Precondición: El árbol debe de estar vacío.
 *          Postcondicion: Crea un nodo que será la raíz del árbol. Su contenido será e.
 *
 *      insertarHijoIzdo(nodo padre, const T& e) ->
 *          Precondición: El nodo padre sea un nodo válido que no tenga ningun hijo izquierdo.
 *          Postcondición: Añade un nodo al árbol que contiene el elemento. Este nuevo nodo será el hijo izquierdo del nodo padre.
 *
 *      insertarHijoDer(nodo padre, const T& e) ->
 *          Precondición: El nodo padre sea un nodo válido que no tenga ningun hijo derecho.
 *          Postcondición: Añade un nodo al árbol que contiene el elemento. Este nuevo nodo será el hijo derecho del nodo padre.
 *
 *      const T& elemento(nodo n) const ->
 *          Precondición: El nodo debe de ser válido.
 *          Postcondición: Devuelve el contenido del nodo n
 *
 *      T& elemento(nodo n) ->
 *          Precondición: El nodo debe de ser válido.
 *          Postcondición: Devuelve el contenido del nodo n
 *
 *      eliminarHijoIzdo(nodo n) ->
 *          Precondición: El nodo debe de ser válido. Su hijo izquierdo debe de existir. Su hijo izquierdo debe de ser hoja.
 *          Postcondición: Elimina su hijo izquierdo del árbol.
 *
 *      eliminarHijoDer(nodo n) ->
 *          Precondición: El nodo debe de ser válido. Su hijo derecho debe de existir. Su hijo derecho debe de ser hoja.
 *          Postcondición: Elimina su hijo derecho del árbol.
 *
 *      eliminarRaíz() ->
 *          Precondicion: El árbol no debe de tener más nodos que el raíz.
 *          Postcondición: Elimina el nodo raíz del árbol. El árbol queda vacío.
 *
 *      bool arbolVacio() ->
 *          Postcondicion: Devuelve TRUE si el árbol tiene nodo raíz y FALSE en caso contrario.
 *
 *      nodo raiz() const ->
 *          Precondicion: El árbol no está vacío.
 *          Postcondicion: Devuelve el nodo raíz
 *
 *      nodo padre(nodo n) const ->
 *          Precondicion: n debe de ser un nodo válido.
 *          Postcondicion: Si n no es la raíz, devuelve el nodo padre si no, devuelve NODO_NULO.
 *
 *      nodo hijoIzdo(nodo n) const ->
 *          Precondicion: n debe de ser un nodo válido.
 *          Postcondición: Si n tiene hijo izquierdo, devuelve el nodo si no, devuelve NODO_NULO.
 *
 *      nodo hijoDer(nodo n) const ->
 *          Precondicion: n debe de ser un nodo válido.
 *          Postcondición: Si n tiene hijo derecho, devuelve el nodo si no, devuelve NODO_NULO.
 */

template <typename T>
class ArbolBinario {

    struct celda;

    public:
    typedef celda* nodo;            // Un nodo es un puntero a una celda
    static const nodo NODO_NULO;

    // Constructores
    ArbolBinario();                 // Cto

    // Operaciones de insercción
    void insertarRaiz(const T& e);
    void insertarHijoIzdo(nodo padre, const T& e);
    void insertarHijoDer(nodo n, const T& e);

    // Operaciones de consulta
    const T& elemento(nodo n) const;
    T& elemento(nodo n);
    bool arbolVacio();
    bool arbolVacio() const;
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzdo(nodo n) const;
    nodo hijoDer(nodo n) const;

    // Operaciones de eliminación
    void eliminarHijoIzdo(nodo n);
    void eliminarHijoDer(nodo n);
    void eliminarRaiz();

    // TODO Operaciones nuevas
    int profundidad(nodo n) const;
    int altura(nodo n) const;

    // Operadores
    ArbolBinario<T>& operator =(const ArbolBinario<T>& a);

    ~ArbolBinario();

    private:

        struct celda{
            T e;
            nodo padre, hijoIzq, hijoDer;
            celda(const T& ele, nodo p = NODO_NULO): e(ele), padre(p), hijoIzq(NODO_NULO), hijoDer(NODO_NULO) {}
        };

        nodo r;

        // Métodos auxiliares
        nodo copiar(nodo n);
        void destruirNodos(nodo& n);
        int calcularAltura(nodo n) const;
};

// Definimos el valor de la constante NODO_NULO
// (Es necesario el "typename Ar..." inicial porque es un tipo que hemos definido dentro de la clase)
template <typename T>
const typename ArbolBinario<T>::nodo ArbolBinario<T>::NODO_NULO(nullptr);

// TODO  --- Constructores ---
template <typename T>
inline ArbolBinario<T>::ArbolBinario(): r(NODO_NULO) {}
// -------------

// TODO  --- Operaciones de insercción ---
template <typename T>
inline void ArbolBinario<T>::insertarRaiz(const T& e){
    assert(r == NODO_NULO); // Árbol vacío
    r = new celda(e);
}

template <typename T>
inline void ArbolBinario<T>::insertarHijoIzdo(nodo n, const T& e){
    assert(n != NODO_NULO);
    assert(n->hijoIzq == NODO_NULO); // No existe hijo izqdo.
    n->hijoIzq = new celda(e, n);
}

template <typename T>
inline void ArbolBinario<T>::insertarHijoDer(nodo n, const T& e) {
    // nodo n válido y hijo derecho nulo
    assert(n != NODO_NULO);
    assert(n->hijoDer == NODO_NULO);
    n->hijoDer = new celda(e, n);
}


// -------------

// TODO  --- Operaciones de eliminación ---
template <typename T>
void ArbolBinario<T>::eliminarRaiz() {

    // árbol no vacío y raíz no puede tener hijos
    assert(!arbolVacio());
    assert(r->hijoIzq == NODO_NULO && r->hijoDer == NODO_NULO);

    delete r;
    r = NODO_NULO;
}

template <typename T>
void ArbolBinario<T>::eliminarHijoIzdo(nodo n) {

    // n es nodo válido y su hijo izquierdo es hoja
    assert(n != NODO_NULO);
    assert(n->hijoIzq->hijoIzq == NODO_NULO && n->hijoIzq->hijoDer == NODO_NULO);

    delete n->hijoIzq;
    n->hijoIzq = NODO_NULO;
}

template <typename T>
void ArbolBinario<T>::eliminarHijoDer(nodo n) {

    // n es nodo válido y su hijo derecho es hoja
    assert(n != NODO_NULO);
    assert(n->hijoDer->hijoIzq == NODO_NULO && n->hijoDer->hijoDer == NODO_NULO);

    delete n->hijoDer;
    n->hijoDer = NODO_NULO;
}
// -------------

// TODO  --- Operaciones de consulta ---
template <typename T>
inline const T& ArbolBinario<T>::elemento(nodo n) const{

    // nodo n válido
    assert(n != NODO_NULO);

    return n->e;
}

template <typename T>
inline T& ArbolBinario<T>::elemento(nodo n) {

    // nodo n válido
    assert(n != NODO_NULO);

    return n->e;
}

template <typename T>
inline bool ArbolBinario<T>::arbolVacio() { return r == NODO_NULO;}

template <typename T>
inline bool ArbolBinario<T>::arbolVacio() const { return r == NODO_NULO; }

template <typename T>
inline typename ArbolBinario<T>::nodo ArbolBinario<T>::raiz() const { return r; }

template <typename T>
inline typename ArbolBinario<T>::nodo ArbolBinario<T>::padre(nodo n) const {

    assert(n != NODO_NULO);

    return n->padre;
}

template <typename T>
inline typename ArbolBinario<T>::nodo ArbolBinario<T>::hijoDer(nodo n) const {

    assert(n != NODO_NULO);

    return n->hijoDer;
}

template <typename T>
inline typename ArbolBinario<T>::nodo ArbolBinario<T>::hijoIzdo(nodo n) const {

    assert(n != NODO_NULO);

    return n->hijoIzq;
}
// -------------

// TODO --- Operadores ---
template <typename T>
ArbolBinario<T>& ArbolBinario<T>::operator=(const ArbolBinario<T> &a) {

    if(this != &a){

        // Destruimos todos los nodos de nuestro arbol
        this->~ArbolBinario();

        // Copiamos los nodos del otro arbol
        r = copiar(a.r);
    }
}
// -------------

template <typename T>
ArbolBinario<T>::~ArbolBinario<T>(){
    destruirNodos(r);
}


// TODO --- Métodos auxiliares ---
template <typename T>
void ArbolBinario<T>::destruirNodos(nodo &n) {

    if(n != NODO_NULO){
        if(n->hijoIzq != NODO_NULO) destruirNodos(n->hijoIzq);
        if(n->hijoDer != NODO_NULO) destruirNodos(n->hijoDer);
        delete n;
        n = NODO_NULO;
    }
}

template <typename T>
typename ArbolBinario<T>::nodo ArbolBinario<T>::copiar(nodo n) {

    nodo m = NODO_NULO;

    if(n != NODO_NULO){
        m = new celda(n->e, n->padre);          // Copiamos n
        m->hijoIzq = copiar(n->hijoIzq);        // Copiamos al hijo izquierdo
        m->hijoDer = copiar(n->hijoDer);        // Copiamos al hijo derecho
    }

    return m;
}
// -------------

// TODO --- Métodos nuevos ---
template<typename T>
int ArbolBinario<T>::profundidad(ArbolBinario::nodo n) const{

    if (n == NODO_NULO) return -1;

    typename ArbolBinario<T>::nodo actual = n;

    int i = 0;
    while (actual != r){
        i++;
        actual = actual->padre;
    }

    return i;
}

template <typename T>
int ArbolBinario<T>::calcularAltura(nodo n) const{
    if(n == NODO_NULO) return 0;
    else return 1 + std::max(calcularAltura(hijoIzdo(n)),
                             calcularAltura(hijoDer(n)));
}

template <typename T>
int ArbolBinario<T>::altura(ArbolBinario<T>::nodo n) const{
    if (n == ArbolBinario<T>::NODO_NULO) return 0;
    return max(calcularAltura(hijoIzdo(n)),
               calcularAltura(hijoDer(n)));
}
// -------------

#endif //ARBOLBINARIO_ARBOLBINARIO_H
