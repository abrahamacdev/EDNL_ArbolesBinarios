
#include "ArbolBinario.h"
#include "ArbolBinarioIO.cpp"
#include "fstream"
#include "ejercicio1/ejercicio1.h"
#include "ejercicio2/ejercicio2.cpp"
#include "ejercicio3/ejercicio3.h"
#include "ejercicio6/ejercicio6.h"
#include "ejercicio7/ejercicio7.h"

template <typename T>
void ejercicio1(ArbolBinario<T>& B){
    int nodos = calcularNodos(B, B.raiz());
    cout << "Nº de nodos del árbol = " << nodos << endl;
}

template <typename T>
void ejercicio2_5(ArbolBinario<T>& B){
    int altura = calcularAltura(B);
    cout << "Altura del árbol = " << altura << endl;
    cout << "Altura del árbol (método del TAD) = " << B.altura(B.raiz()) << endl;
}

template <typename T>
void ejercicio3_5(ArbolBinario<T>& B){
    typename ArbolBinario<char>::nodo nodo = B.hijoIzdo(B.raiz());
    int profundidad = calcularProfundidad(B, nodo);
    cout << "Profundidad desde el nodo '" << B.elemento(nodo) << "' = " << profundidad << endl;
    cout << "Profundidad desde el nodo '" << B.elemento(nodo) << "' (método del TAD) = " << B.profundidad(nodo) << endl;
}

template <typename T>
void ejercicio6(ArbolBinario<T>& B){
    cout << "Desequilibrio del árbol = " << desequilibrio(B) << endl;
}

template <typename T>
void ejercicio7(ArbolBinario<T>& B){
    string bEsPseudoCompleto = pseudoCompleto(B) ? "SI" : "NO";
    cout << "El árbol  " << bEsPseudoCompleto << " es pseudo completo";
}

void pedirYGuardar(){

    bool reintentar = true;
    string input;
    while (reintentar){

        ArbolBinario<char> A;

        rellenarArbolBinario(A, '#');

        cout << " *** Árbol *** " << endl;
        imprimirArbolBinario(A);
        cout << " ************* " << endl;

        cout << "Introduce el nombre del archivo: ";
        cin >> input;
        cout << endl;

        string outputFile = string("C:\\Users\\abrah\\Desktop\\" + input + ".dat");

        cout << "Guardanddo en " << outputFile << endl;

        ofstream o;
        o.open(outputFile);
        imprimirArbolBinario(o, A, '#');
        o.close();

        cout << "Guardamos otro árbol? (S|N): ";
        cin >> input;
        cout << endl;

        if (input != string("S") and input != string("s")) reintentar = false;
    }
}

void leerArbolDelEscritorio(ArbolBinario<char> *A){

    string input;
    bool continuar = true;
    bool error = false;

    while (continuar){

        error = false;

        cout << "Introduzca el nombre del archivo (se buscará en el escritorio): ";
        cin >> input;
        cout << endl;

        ifstream is;

        // Necesario para tratar error
        is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            is.open(string("C:\\Users\\abrah\\Desktop\\" + input));
        }catch (std::system_error& e){
            std::cerr << e.code().message() << std::endl;
            error = true;
            cout << "Vamos a volver a intentarlo" << endl;
        }

        rellenarArbolBinario(is, *A);
        is.close();

        if (!error) continuar = false;
    }
}

int main() {

    // Para comprobar la estructura de cada árbol, mirar apuntes del iPad "Notas Árbol Binario"

    ArbolBinario<char> B;

    leerArbolDelEscritorio(&B);

    cout << "****** Árbol ******" << endl;
    imprimirArbolBinario(B);
    cout << "*********************" << endl << endl;

    // Ejericicio 1
    ejercicio1(B);

    // Ejercicio 2 y 5
    ejercicio2_5( B);

    // Ejercicio 3 y 5
    ejercicio3_5( B);

    // Ejercicio 6
    ejercicio6(B);

    // Ejercicio 7
    ejercicio7(B);

    return 0;
}
