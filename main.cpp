#include "ArbolBinario.h"
#include "ArbolBinarioIO.cpp"
#include "fstream"
#include "cstdlib"
#include "practica1/ejercicio1/ejercicio1_1.h"
#include "practica1/ejercicio2/ejercicio2_1.cpp"
#include "practica1/ejercicio3/ejercicio3_1.h"
#include "practica1/ejercicio6/ejercicio6_1.h"
#include "practica1/ejercicio7/ejercicio7_1.h"
#include "practica2/ejercicio1/ejercicio1_2.h"

template <typename T>
void ejercicio1_1(ArbolBinario<T>& B){
    int nodos = calcularNodos(B);
    cout << "Nº de nodos del árbol = " << nodos << endl;
}

template <typename T>
void ejercicio2_5_1(ArbolBinario<T>& B){
    int altura = calcularAltura(B);
    cout << "Altura del árbol = " << altura << endl;
    cout << "Altura del árbol (método del TAD) = " << B.altura(B.raiz()) << endl;
}

template <typename T>
void ejercicio3_5_1(ArbolBinario<T>& B){
    typename ArbolBinario<char>::nodo nodo = B.hijoIzdo(B.raiz());
    int profundidad = calcularProfundidad(B, nodo);
    cout << "Profundidad desde el nodo '" << B.elemento(nodo) << "' = " << profundidad << endl;
    cout << "Profundidad desde el nodo '" << B.elemento(nodo) << "' (método del TAD) = " << B.profundidad(nodo) << endl;
}

template <typename T>
void ejercicio6_1(ArbolBinario<T>& B){
    cout << "Desequilibrio del árbol = " << desequilibrio(B) << endl;
}

template <typename T>
void ejercicio7_1(ArbolBinario<T>& B){
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

        string outputFile;
        if (getenv("windir")) outputFile = string("C:\\Users\\abrah\\Desktop\\" + input) + ".dat";
        else outputFile = string(string(getenv("HOME")) + "/Desktop/" + input + ".dat");

        cout << outputFile << endl;

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

        ifstream is;

        // Necesario para tratar error
        is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            if (getenv("windir")) is.open(string("C:\\Users\\abrah\\Desktop\\" + input));
            else is.open(string(string(getenv("HOME")) + "/Desktop/" + input));
        }catch (std::system_error& e){
            error = true;
            cout << "Ocurrió un error. Vamos a volver a intentarlo" << endl;
        }

        if (!error){
            rellenarArbolBinario(is, *A);
            is.close();
            continuar = false;
        }
    }
}


int main() {

    // TODO Para comprobar la estructura de cada árbol, mirar apuntes del iPad "Notas Árbol Binario"

    ArbolBinario<char> A;
    ArbolBinario<char> B;

    //pedirYGuardar();
    leerArbolDelEscritorio(&A);
    leerArbolDelEscritorio(&B);

    cout << "****** Árbol ******" << endl;
    imprimirArbolBinario(A);
    cout << "*********************" << endl << endl;

    cout << "****** Árbol ******" << endl;
    imprimirArbolBinario(B);
    cout << "*********************" << endl << endl;

    const char* tSimilares = similares(A, B) ? "Sí" : "No";
    cout << "Los árboles son similares? " << tSimilares << endl;

    /*
    // Ejericicio 1
    ejercicio1_1(B);

    // Ejercicio 2 y 5
    ejercicio2_5_1(B);

    // Ejercicio 3 y 5
    ejercicio3_5_1(B);

    // Ejercicio 6
    ejercicio6_1(B);

    // Ejercicio 7
    ejercicio7_1(B);*/

    return 0;
}