#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include "programacionDinamica.h"

using namespace std;


int programacionDinamica(vector<tuple<int, int, int>> elementos, int pesoPermitido) {
    vector<vector<int>> diccionario (pesoPermitido + 1, vector<int> (elementos.size(), -1));                                            //del [0, pesoPermitido]

    for (int i = 1; i <= elementos.size(); ++i) {
        vector<tuple<int, int, int>> elementosAEvaluar(elementos.end() - i, elementos.end());
        programacionDinamicaRecursivo(elementosAEvaluar, diccionario, pesoPermitido);
    }

    return diccionario[pesoPermitido][elementos.size() - 1];
}

void programacionDinamicaRecursivo(vector<tuple<int, int, int>> elementos, vector<vector<int>> &diccionario, int pesoPermitido) {
    int solucionSinElemento = 0;
    int solucionConElemento = 0;
    if (elementos.size() == 1) {
        for (int i = 0; i <= pesoPermitido; ++i) {
            if (get<0>(elementos[0]) <= i) {
                diccionario[i][0] = get<1>(elementos[0]);
            } else {
                diccionario[i][0] = 0;
            }
        }
    } else {
        for (int k = 0; k <= pesoPermitido; ++k) {
            solucionSinElemento = diccionario[k][elementos.size() - 2];
            solucionConElemento = (get<0>(elementos[0]) <= k) ?
                                  diccionario[k - get<0>(elementos[0])][elementos.size() - 2] + get<1>(elementos[0]):
                                  0;

//            for (int i = 0; i < diccionario.size(); ++i) {
//                for (int j = 0; j < diccionario[i].size(); ++j) {
//                    cout << (diccionario[i][j]) << "|";
//                }
//                cout << endl;
//            }
//            cout << endl << endl;

            diccionario[k][elementos.size() - 1] = (solucionSinElemento >= solucionConElemento) ? solucionSinElemento : solucionConElemento;
        }
    }
}

//int programacionDinamica(vector<tuple<int, int, int>> elementos, int pesoPermitido) {
//    vector<vector<int>> diccionario (pesoPermitido, vector<int> (elementos.size(), -1));
//
//    return programacionDinamicaRecursivo(elementos, diccionario, pesoPermitido);
//}
//
//int programacionDinamicaRecursivo(vector<tuple<int, int, int>> elementos, vector<vector<int>> &diccionario, int pesoPermitido) {
//    int solucionSinElemento = 0;
//    int solucionConElemento = 0;
//    if (elementos.size() == 1) {
//        if (get<0>(elementos[0]) <= pesoPermitido) {
//            diccionario[pesoPermitido - 1][elementos.size() - 1] = get<0>(elementos[0]);
//            return get<0>(elementos[0]);
//        } else {
//            diccionario[pesoPermitido - 1][elementos.size() - 1] = 0;
//            return 0;
//        }
//    }
//
//    elementos.pop_back();
//    solucionSinElemento = (diccionario[pesoPermitido - 1][elementos.size() - 2] != -1) ?
//                          diccionario[pesoPermitido - 1][elementos.size() - 2] :
//                          programacionDinamicaRecursivo(elementos, diccionario, pesoPermitido);
//    solucionConElemento = (diccionario[pesoPermitido - get<0>(elementos[0]) - 1][elementos.size() - 2] != -1) ?
//                          diccionario[pesoPermitido - get<0>(elementos[0]) - 1][elementos.size() - 2] :
//                          programacionDinamicaRecursivo(elementos, diccionario, pesoPermitido - get<0>(elementos[0]));
//
//    for (int i = 0; i < diccionario.size(); ++i) {
//        for (int j = 0; j < diccionario[i].size(); ++j) {
//            cout << (diccionario[i][j]) << "|";
//        }
//        cout << endl;
//    }
//    cout << endl << endl;
//
//    if (solucionSinElemento >= solucionConElemento + get<1>(elementos[0])) {
//        diccionario[pesoPermitido - 1][elementos.size() - 1] = solucionSinElemento;
//        return solucionSinElemento;
//    } else {
//        diccionario[pesoPermitido - 1][elementos.size() - 1] = solucionConElemento + get<1>(elementos[0]);
//        return solucionConElemento + get<1>(elementos[0]);
//    }
//}