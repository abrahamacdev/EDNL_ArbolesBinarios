//
// Created by Judith Olalde Alonso on 4/3/22.
//

#ifndef PRACTICA1EDNL_EXPRESIONARITMETICA_HPP
#define PRACTICA1EDNL_EXPRESIONARITMETICA_HPP

#include "string"
#include "vector"

using namespace std;

static const vector<char> ops = {'+', '-', '*', '/'};

enum ExprArit {
    OPERADOR,       // 1.0 = Suma | 2.0 = Resta | 3.0 = Multiplicación | 4.0 = División
    OPERANDO
};

class ExpresionAritmetica {

public:
    ExprArit exprArit;
    double valor{};

    ExpresionAritmetica()= default;
    explicit ExpresionAritmetica(char o): exprArit(OPERADOR){
        switch (o) {

            // Es una suma
            case '+':
                valor = 1;
                break;
            case '-':
                valor = 2;
                break;
            case '*':
                valor = 3;
                break;
            case '/':
                valor = 4;
                break;
            default:
                valor = 1;
                break;
        }
    }
    explicit ExpresionAritmetica(string v) {

        if (v.length() == 1 && count(ops.begin(), ops.end(), v[0])){
            exprArit = OPERADOR;
            switch (v[0]) {

                // Es una suma
                case '+':
                    valor = 1;
                    break;
                case '-':
                    valor = 2;
                    break;
                case '*':
                    valor = 3;
                    break;
                case '/':
                    valor = 4;
                    break;
                default:
                    valor = 1;
                    break;
            }
        }
        else {
            exprArit = OPERANDO;
            valor = stod(v);
        }
    };
    explicit ExpresionAritmetica(double v): valor(v), exprArit(OPERANDO){};

    string parsearExpresionAritmetica() const {
        if (exprArit == OPERADOR){

            switch ((int) valor) {

                // Es una suma
                case 1:
                    return string{"+"};

                    // Es una resta
                case 2:
                    return string{"-"};

                    // Es una multiplicación
                case 3:
                    return string{"*"};

                    // Es una división
                case 4:
                    return string{"/"};
            }
        }
        else return to_string(valor);
    }

    string parsearExpresionAritmetica(){

        if (exprArit == OPERADOR){

            switch ((int) valor) {

                // Es una suma
                case 1:
                    return string{"+"};

                    // Es una resta
                case 2:
                    return string{"-"};

                    // Es una multiplicación
                case 3:
                    return string{"*"};

                    // Es una división
                case 4:
                    return string{"/"};
            }
        }
        else return to_string(valor);
    }
};

#endif //PRACTICA1EDNL_EXPRESIONARITMETICA_HPP
