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
#include "practica2/ejercicio2/ejercicio2_2.h"
#include "practica2/ejercicio3/ejercicio3_2.hpp"
#include "practica2/ejercicio3/ArbolBinarioAritmeticoIO.hpp"
#include "preExamen/poda.cpp"
#include "examen/examen.cpp"
#include <sys/utsname.h>

static bool WIN_SYS = false;

void pedirYGuardar(){

    bool reintentar = true;
    string input;
    while (reintentar){

        ArbolBinario<char> A;

        rellenarArbolBinario(A, '#');

        cout << " *** Árbol *** " << endl;
        imprimirArbolBinario(A);
        cout << " ************* " << endl;

        cout << "Introduce el nombre del archivo (sin el .dat): ";
        cin >> input;
        cout << endl;

        string outputFile;

        // Comprobamos que SO es
        if (WIN_SYS) outputFile = string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\" + input + ".dat";
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

void leerArbolDelEscritorio(ArbolBinario<char> *A, const string& ruta = ""){

    // Recibimos la ruta por parámetro
    if (!ruta.empty()){
        ifstream is;

        // Necesario para tratar error
        is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {

            is.open(ruta);

        }catch (std::system_error& e){
            cout << "Ocurrió un error al leer el archivo de la ruta '" << ruta << "'" << endl;
            exit(1);
        }


        rellenarArbolBinario(is, *A);
        is.close();
    }

        // Pedimos la ruta por teclado
    else {
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

                if (WIN_SYS) is.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\" + input);
                else is.open(string(getenv("HOME")) + "/Desktop/" + input);

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
}

void leerArbolExprAritEscritorio(ArbolBinario<ExpresionAritmetica>& A){

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

            if (WIN_SYS) is.open(string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\" + input);
            else is.open(string(getenv("HOME")) + "/Desktop/" + input);

        }catch (std::system_error& e){
            error = true;
            cout << "Ocurrió un error. Vamos a volver a intentarlo" << endl;
        }

        if (!error){
            rellenarArbolBinarioAritmetico(is, A);
            is.close();
            continuar = false;
        }
    }
}

void comprobarSistema(){
    struct utsname sysinfo;
    if(uname(&sysinfo)) exit(9);

    // Estamos en Windows (CYGWIN_NT-X)
    if (sysinfo.sysname[0] == 'C') WIN_SYS = true;
}

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

template <typename T>
void ejercicio1_2(ArbolBinario<T>& A, ArbolBinario<T>& B){

    const char* tSimilares = similares(A, B) ? "Sí" : "No";
    cout << "Los árboles son similares? " << tSimilares << endl;
}

template <typename T>
void ejercicio2_2(ArbolBinario<T>& A){

    // Ejercicio 2 (Práctica 2)
    ejercicio2_2(A);

    cout << "--- Árbol Original ---" << endl;
    imprimirArbolBinario(A);
    cout << "----------------------" << endl;

    cout << "--- Árbol Original ---" << endl;
    imprimirArbolBinario(reflejar(A));
    cout << "----------------------" << endl;
}

void ejercicioPreExamen_poda(){

    ArbolBinario<char> A;

    string ruta;
    if (WIN_SYS) ruta = string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\b.dat";
    else ruta = string(getenv("HOME")) + "/Desktop/b.dat";

    leerArbolDelEscritorio(&A, ruta);

    typename ArbolBinario<char>::nodo g = A.hijoIzdo(A.hijoDer(A.hijoDer(A.raiz())));
    cout << "El nodo que utilizaremos para podar es '" << A.elemento(g) << "'" << endl;
    poda(A, g);

    cout << "****** Árbol podado ******" << endl;
    imprimirArbolBinario(A);
    cout << "*********************" << endl;
}

int main() {

    // TODO NO ELIMINAR
    comprobarSistema();

    // TODO Para comprobar la estructura de cada árbol, mirar apuntes del iPad "Notas Árbol Binario"
    ArbolBinario<char> A;
    ArbolBinario<char> B;

    /*ArbolBinario<ExpresionAritmetica> C;
    //rellenarArbolBinarioAritmetico(C, '#');

    leerArbolExprAritEscritorio(C);
    imprimirArbolBinarioAritmetico(C);
    cout << "Solución: " << evaluar(C) << endl;*/


    //cout << "El resultado de evaluar el árbol es: " << evaluar(C) << endl;

    string ruta;
    if (WIN_SYS) ruta = string(getenv("HOMEDRIVE")) + string (getenv("HOMEPATH")) + "\\Desktop\\h.dat";
    else ruta = string(getenv("HOME")) + "/Desktop/h.dat";

    //pedirYGuardar();
    leerArbolDelEscritorio(&A, ruta);
    //leerArbolDelEscritorio(&B);

    cout << "****** Árbol ******" << endl;
    imprimirArbolBinario(A);
    cout << "*********************" << endl;

    /*cout << "****** Árbol ******" << endl;
    imprimirArbolBinario(B);
    cout << "*********************" << endl << endl;*/

    /*
    // Ejericicio 1 (Práctica 1)
    ejercicio1_1(B);

    // Ejercicio 2 y 5 (Práctica 1)
    ejercicio2_5_1(A);

    // Ejercicio 3 y 5 (Práctica 1)
    ejercicio3_5_1(B);

    // Ejercicio 6 (Práctica 1)
    ejercicio6_1(B);

    // Ejercicio 7 (Práctica 1)
    ejercicio7_1(B);

    // Ejercicio 1 (Práctica 2)
    ejercicio1_2(A);

    // Ejercicio Pre Examen (poda¨)
    ejercicioPreExamen_poda();*/

    int reflejados = cuentaReflejados(A);

    cout << "La cantidad de nodos reflejados es: " << reflejados << endl;

    return 0;
}