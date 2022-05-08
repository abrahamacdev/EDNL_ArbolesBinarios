//
// Created by abrah on 25/03/2022.
//

#ifndef PRACTICA1EDNL_EXAMEN_H
#define PRACTICA1EDNL_EXAMEN_H

#include "queue"
#include "../ArbolBinario.h"

template <typename T>
int cuentaReflejados(ArbolBinario<T>& A);

template <typename T>
int cuentaReflejados_Rec(typename ArbolBinario<T>::nodo hijoIzq, typename  ArbolBinario<T>::nodo hijoDer, ArbolBinario<T>& A);

template <typename T>
bool reflejado(typename ArbolBinario<T>::nodo a, typename ArbolBinario<T>::nodo b, ArbolBinario<T>& A);

template <typename T>
void insertarInOrder(typename ArbolBinario<T>::nodo n, ArbolBinario<T>& A, queue<T>& c);

template <typename T>
void insertarInOrderInverso(typename ArbolBinario<T>::nodo n, ArbolBinario<T>& A, queue<T>& c);

#endif //PRACTICA1EDNL_EXAMEN_H
