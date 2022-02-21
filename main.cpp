
#include "ArbolBinario.h"
#include "ArbolBinarioIO.cpp"
#include "fstream"
#include "ejercicio1/ejercicio1.h"
#include "ejercicio2/ejercicio2.cpp"
#include "ejercicio3/ejercicio3.h"

int main() {

    auto* A = new ArbolBinario<char>();

    ifstream is("C:\\Users\\abrah\\Desktop\\abin.dat");
    rellenarArbolBinario(is, *A);
    is.close();

    imprimirArbolBinario(*A);

    int nodos = calcularNodos(*A, A->raiz());
    cout << "Hay " << nodos << " nodos en el árbol"<< endl;

    int altura = calcularAltura(*A);
    cout << "La altura del árbol es " << altura << endl;

    typename ArbolBinario<char>::nodo nodo = A->hijoIzdo(A->hijoIzdo(A->raiz()));
    int profundidad = calcularProfundidad(*A, nodo);
    cout << "La profundidad desde el nodo '" << A->elemento(nodo) << "' es " << profundidad << endl;


    return 0;
}
