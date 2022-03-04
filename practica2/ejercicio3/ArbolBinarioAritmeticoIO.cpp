//
// Created by Judith Olalde Alonso on 4/3/22.
//

#include <vector>
#include "ExpresionAritmetica.h"
#include "../../ArbolBinario.h"

using namespace std;

bool isAlpha(const string& s){
    bool retVal = false;
    for(char i : s){
        if( !isalpha(i) || !isspace(i)){
            retVal = true;
            break;
        }
    }
    return retVal;
}

bool isNumber(const string& s){
    bool retVal = false;
    for(char i : s){
        if(isnumber(i)){
            retVal = true;
            break;
        }
    }
    return retVal;
}



void preguntarNodo(ArbolBinario<ExpresionAritmetica>& A, char fin,
                   const typename ArbolBinario<ExpresionAritmetica>::nodo& n = ArbolBinario<ExpresionAritmetica>::NODO_NULO,
                   bool hijoIzdo = true){

    string input;

    // El árbol está vacío, preguntamos la raíz
    if (A.arbolVacio()) {

        // Leemos el dato
        cout << "Raíz (Fin = " << fin << "): ";
        cin >> input;

        // La raíz tiene que ser un operador
        if (input.length() == 1 && input[0] != fin){

            struct ExpresionAritmetica temp{};
            temp.exprArit = OPERADOR;

            char op = input[0];
            bool opValida = true;

            switch (op) {

                case '+':
                    temp.valor = 1.0;
                    break;

                case '-':
                    temp.valor = 2.0;
                    break;

                case '*':
                    temp.valor = 3.0;
                    break;

                case '/':
                    temp.valor = 4.0;
                    break;

                default:
                    cout << "Operación no válida (+,-,*,/)" << endl;
                    opValida = false;
                    break;
            }

            // Insertamos la raíz del árbol
            if (opValida){

                // Insertamos la raíz
                A.insertarRaiz(temp);

                // Preguntamos por el hijo izquierdo
                preguntarNodo(A, fin, A.raiz(), true);
                preguntarNodo(A, fin, A.raiz(), false);
            }

            // Volvemos a preguntar por la raíz
            else {
                preguntarNodo(A, fin);
            }
        }
    }
    else {

        // Estamos solicitando el hijo izquierdo del nodo n
        if(hijoIzdo){
            cout << "Hijo izqdo. de " << A.elemento(n).parsearExpresionAritmetica() << " (Fin = " << fin << "): ";
            cin >> input;
            cout << endl;
        }

            // Estamos solicitando el hijo derecho del nodo n
        else {
            cout << "Hijo drcho. de " << A.elemento(n).parsearExpresionAritmetica() << " (Fin = " << fin << "): ";
            cin >> input;
            cout << endl;

        }

        // Estamos introduciendo un operador
        if (input.length() == 1 && input[0] != fin && isalpha(input[0])){

            struct ExpresionAritmetica temp{};
            temp.exprArit = OPERADOR;

            char op = input[0];
            bool opValida = true;

            switch (op) {

                case '+':
                    temp.valor = 1.0;
                    break;

                case '-':
                    temp.valor = 2.0;
                    break;

                case '*':
                    temp.valor = 3.0;
                    break;

                case '/':
                    temp.valor = 4.0;
                    break;

                default:
                    cout << "Operación no válida (+,-,*,/). También puedes introducir un número." << endl;
                    opValida = false;
                    break;
            }

            // Insertamos el operador
            if (opValida){

                // Insertamos la raíz
                A.insertarRaiz(temp);

                // Preguntamos por el hijo izquierdo
                preguntarNodo(A, fin, A.raiz(), true);
                preguntarNodo(A, fin, A.raiz(), false);
            }
            // Insertamos el operando
            else {
                preguntarNodo(A, fin, n, hijoIzdo);
            }
        }

        // Estamos introduciendo números
        else if (input.length() >= 1 && isNumber(input)){

            typename ArbolBinario<ExpresionAritmetica>::nodo tempN;

            struct ExpresionAritmetica temp{};
            temp.exprArit = OPERANDO;
            temp.valor = stod(input);

            // Guardamos el hijo izquierdo del nodo n
            if (hijoIzdo){
                A.insertarHijoIzdo(n, temp);
                tempN = A.hijoIzdo(n);
            }
                // Guardamos el hijo izquierdo del nodo n
            else {
                A.insertarHijoDer(n, temp);
                tempN = A.hijoDer(n);
            }

            // No preguntamos más porque un número siempre será nodo hoja
            //preguntarNodo(A, fin, tempN, true);     // Preguntamos el hijo izquierdo del nuevo nodo introducido
            //preguntarNodo(A, fin, tempN, false);     // Preguntamos el hijo derecho del nuevo nodo introducido
        }
    }
}

/**
 * Precondicion: A está vacío
 * Postcondicion:  Rellena el árbol A con la estructura y elementos leídos en preorden de la entrada
 * estándar, usando fin como elemento especial para introducir nodos nulos.
 */
void rellenarArbolBinarioAritmetico(ArbolBinario<ExpresionAritmetica>& A, char fin){
    // El árbol tiene que estar vacío
    assert(A.arbolVacio());

    // Preguntamos por los nodos de A
    preguntarNodo(A, fin);
}


void leerNodo(istream& input, ArbolBinario<ExpresionAritmetica>& A, typename ArbolBinario<ExpresionAritmetica>::nodo& n,
              char fin, bool esIzqdo, string& temporal){

    char e = input.get();
    input.get();            // Leemos el espacio

    typename ArbolBinario<char>::nodo tempNodo;

    if (e != fin){

        if (e == ' '){
            cout << temporal << endl;
        }else {
            temporal += e;
        }

        cout << e << endl;

        // Insertamos hijo izquierdo del nodo n
        /*if (esIzqdo){
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
        leerNodo(input, A, tempNodo, fin, false);*/
    }
}

/**
 * Precondicion: A está vacío
 * Postcondicion:  Extrae los nodos de A del flujo de entrada is, que contendrá el elemento especial
 * que denota un nodo nulo seguido de los elementos en preorden, incluyendo los
 * correspondientes a nodos nulos.
 */
void rellenarArbolBinarioAritmetico(std::istream& input, ArbolBinario<ExpresionAritmetica>& A){
    char fin = (char) input.get();
    input.get();    // Leemos el salto de línea

    char raiz = input.get();

    if (raiz != fin){

        ExpresionAritmetica temp;
        temp.exprArit = OPERADOR;

        switch (raiz) {
            case '+':
                temp.valor = 1.0;
                break;
            case '-':
                temp.valor = 2.0;
                break;
            case '*':
                temp.valor = 3.0;
                break;
            case '/':
                temp.valor = 4.0;
                break;
        }

        // Insertamos la raíz
        A.insertarRaiz(temp);

        try {
            input.get();    // Leemos el espacio

            // Leemos todos los caracteres y los guardamos
            vector<string> elementos = vector<string>{};
            char temp = input.get();
            string tempS = string{""};

            while (!input.eof()){

                if (temp == ' '){
                    elementos.push_back(tempS);
                    tempS = string{};
                } else {
                    tempS += temp;
                }

                temp = input.get();
            }

            /*typename ArbolBinario<ExpresionAritmetica>::nodo n = A.raiz();

            string s;

            // Continuamos leyendo el árbol
            leerNodo(input, A, n, fin, true, s);
            leerNodo(input, A, n, fin, false, s);*/
        }
        catch (std::exception e){}
    }
}

void imprimirPantalla(const ArbolBinario<ExpresionAritmetica>& A, const typename ArbolBinario<ExpresionAritmetica>::nodo& n){

    if (A.arbolVacio()) cout << "El árbol está vacío" << endl;
    else {

        if (n == A.raiz()){
            // Mostramos la raíz
            cout << "Raíz del árbol: " << A.elemento(A.raiz()).parsearExpresionAritmetica() << endl;
        }

        if (A.hijoIzdo(n) != ArbolBinario<ExpresionAritmetica>::NODO_NULO){
            cout << "Hijo izqdo de " << A.elemento(n).parsearExpresionAritmetica() << ": " << A.elemento(A.hijoIzdo(n)).parsearExpresionAritmetica() << endl;
            imprimirPantalla(A, A.hijoIzdo(n));
        }
        if (A.hijoDer(n) !=  ArbolBinario<ExpresionAritmetica>::NODO_NULO){
            cout << "Hijo derecho de " << A.elemento(n).parsearExpresionAritmetica() << ": " << A.elemento(A.hijoDer(n)).parsearExpresionAritmetica() << endl;
            imprimirPantalla(A, A.hijoDer(n));
        }
    }
}

/**
 * Postcondicion: Muestra los nodos de A en la salida estándar
 */
void imprimirArbolBinarioAritmetico(const ArbolBinario<ExpresionAritmetica>& A){

    // Mostramos los hijos de la raíz
    imprimirPantalla(A, A.raiz());
}