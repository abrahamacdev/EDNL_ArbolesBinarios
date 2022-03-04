//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_H
#define PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_H

#include "ejercicio3_2.h"

/**
 * Precondicion: A está vacío
 * Postcondicion:  Rellena el árbol A con la estructura y elementos leídos en preorden de la entrada
 * estándar, usando fin como elemento especial para introducir nodos nulos.
 */
template <typename T>
void rellenarArbolBinarioAritmetico(ArbolBinario<ExprArit>& A, const char& fin);

/**
 * Precondicion: A está vacío
 * Postcondicion:  Extrae los nodos de A del flujo de entrada is, que contendrá el elemento especial
 * que denota un nodo nulo seguido de los elementos en preorden, incluyendo los
 * correspondientes a nodos nulos.
 */
template <typename T>
void rellenarArbolBinario(std::istream& input, ArbolBinario<T>& A);

/**
 * Postcondicion: Muestra los nodos de A en la salida estándar
 */
template <typename T>
void imprimirArbolBinario(const ArbolBinario<T>& A);

/**
 *  Postcondicion: Inserta en el flujo de salida os los nodos de A en preorden, precedidos del
 *  elemento especial usado para denotar un nodo nulo.
 */
template <typename T>
void imprimirArbolBinario (std::ostream& os, const ArbolBinario<T>& A, const T& fin);

#endif //PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_H
