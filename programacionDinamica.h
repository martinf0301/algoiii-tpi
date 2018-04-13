#ifndef TPI_PROGRAMACIONDINAMICA_H
#define TPI_PROGRAMACIONDINAMICA_H
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;


int programacionDinamica(vector<tuple<int, int, int>> elementos, int pesoPermitido);

void programacionDinamicaRecursivo(vector<tuple<int, int, int>> elementos, vector<vector<int>> &diccionario, int pesoPermitido);

#endif //TPI_PROGRAMACIONDINAMICA_H
