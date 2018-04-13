#ifndef TPI_BACKTRACKINGVERSIONES_H
#define TPI_BACKTRACKINGVERSIONES_H
#include <iostream>
#include <tuple>
#include <vector>


std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingOrdenado(std::vector<std::tuple<int, int, int>> elementos,
                                                                             bool podaFactibilidad,
                                                                             bool podaOptimalidad,
                                                                             int pesoPermitido);

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingOrdenadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                      bool podaFactibilidad,
                                                                                      bool podaOptimalidad,
                                                                                      int pesoPermitido,
                                                                                      int i);

//std::tuple<std::vector<std::tuple<int, int, int>>, int> backtracking(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido);
//
//std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingRecursivo(std::vector<std::tuple<int, int, int>> elementos,
//                                                                              int pesoPermitido,
//                                                                              int i);

/*--------------------------------------BACKTRACKINGS TUNEADOS--------------------------------------*/

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneado(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido);

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                     int pesoPermitido,
                                                                                     int pesoActual,
                                                                                     int beneficioActual,
                                                                                     int i);

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoOrdenado(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido);

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoOrdenadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                             int pesoPermitido,
                                                                                             int pesoActual,
                                                                                             int beneficioActual,
                                                                                             int i);


/*--------------------------------------BACKTRACKINGS CHOTOS--------------------------------------*/

std::vector<std::vector<std::tuple<int, int, int>>> creadorMochilasBckSinOrden(std::vector<std::tuple<int, int, int>> objetos,
                                                                               std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
                                                                               int pesoActual,
                                                                               int pesoPermitido,
                                                                               int i);

std::vector<std::vector<std::tuple<int, int, int>>> creadorConjMochilasBckSinOrden(std::vector<std::tuple<int, int, int>> objetos,
                                                                                   int pesoPermitido);

std::vector<std::tuple<int, int, int>> mochilaIdealBckSinOrden(std::vector<std::vector<std::tuple<int, int, int>>> opciones, int pesoPermitido);


std::vector<std::vector<std::tuple<int, int, int>>> crearSolucionesBckOrdRecursivo(std::vector<std::tuple<int, int, int>> objetos,
                                                                                   std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
                                                                                   int pesoActual,
                                                                                   int pesoPermitido,
                                                                                   int i);

std::vector<std::vector<std::tuple<int, int, int>>> crearSolucionesBckOrd(std::vector<std::tuple<int, int, int>> objetos,
                                                                          int pesoPermitido);

std::vector<std::tuple<int, int, int>> mochilaIdealBckConOrden(std::vector<std::vector<std::tuple<int, int, int>>> opciones, int pesoPermitido);




#endif //TPI_BACKTRACKINGVERSIONES_H