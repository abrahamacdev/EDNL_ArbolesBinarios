//
// Created by abrah on 24/03/2022.
//

#ifndef PRACTICA1EDNL_PODA_H
#define PRACTICA1EDNL_PODA_H

#include "../ArbolBinario.h"
#include "cassert"

/*
 * La función "poda" realizará, como su nombre indica, una poda del árbol que le pasemos como parámetro dado un nodo que
 * también le pasaremos por parámetro. Serán eliminados todos los descendientes propios del nodo además del propio nodo.
 * Se supone que ningún elemento del árbol podrá estar repetido.
 */
template <typename T>
void poda(ArbolBinario<T>& A, typename ArbolBinario<T>::nodo n);

#endif //PRACTICA1EDNL_PODA_H
