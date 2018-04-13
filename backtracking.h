#ifndef TPI_BACKTRACKING_H
#define TPI_BACKTRACKING_H
#include <iostream>
#include <tuple>
#include <vector>


int backtracking(std::vector<std::tuple<int, int, int>> elementos,
                 bool podaFactibilidad,
                 bool podaOptimalidad,
                 int pesoPermitido);

int backtrackingRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                          bool podaFactibilidad,
                          bool podaOptimalidad,
                          int pesoPermitido,
                          int pesoActual,
                          int beneficioActual,
                          int beneficioMaximo,
                          int i);


#endif //TPI_BACKTRACKING_H