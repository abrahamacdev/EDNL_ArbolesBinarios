//
// Created by abrah on 04/03/2022.
//

#ifndef PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_HPP
#define PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_HPP

#include "ExpresionAritmetica.hpp"
#include "../../ArbolBinario.h"

/**
 * Precondicion: A está vacío
 * Postcondicion:  Rellena el árbol A con la estructura y elementos leídos en preorden de la entrada
 * estándar, usando fin como elemento especial para introducir nodos nulos.
 */
void rellenarArbolBinarioAritmetico(ArbolBinario<ExpresionAritmetica>& A, char fin);

/**
 * Precondicion: A está vacío
 * Postcondicion:  Extrae los nodos de A del flujo de entrada is, que contendrá el elemento especial
 * que denota un nodo nulo seguido de los elementos en preorden, incluyendo los
 * correspondientes a nodos nulos.
 */
void rellenarArbolBinarioAritmetico(std::istream& input, ArbolBinario<ExpresionAritmetica>& A);

/**
 * Postcondicion: Muestra los nodos de A en la salida estándar
 */
void imprimirArbolBinarioAritmetico(const ArbolBinario<ExpresionAritmetica>& A);

/**
 *  Postcondicion: Inserta en el flujo de salida os los nodos de A en preorden, precedidos del
 *  elemento especial usado para denotar un nodo nulo.
 */
//void imprimirArbolBinarioAritmetico(std::ostream& os, const ArbolBinario<ExpresionAritmetica>& A, char fin);

#endif //PRACTICA1EDNL_ARBOLBINARIOARITMETICOIO_HPP
