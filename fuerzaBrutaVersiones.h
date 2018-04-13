#ifndef TPI_FUERZABRUTAVERSIONES_H
#define TPI_FUERZABRUTAVERSIONES_H
#include <iostream>
#include <tuple>
#include <vector>


/*--------------------------------------FUERZABRUTA NORMAL--------------------------------------*/

std::tuple<std::vector<std::tuple<int, int, int>>, int> fuerzaBruta2(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido);

std::tuple<std::vector<std::tuple<int, int, int>>, int> fuerzaBrutaRecursivo2(std::vector<std::tuple<int, int, int>> elementos,
                                                                             int pesoPermitido,
                                                                             int i);


/*--------------------------------------FUERZABRUTA CHOTO--------------------------------------*/

std::vector<std::vector<std::tuple<int, int, int>>> creadorMochilasFB(std::vector<std::tuple<int, int, int>> objetos,
                                                                      std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
                                                                      int i);

std::vector<std::vector<std::tuple<int, int, int>>> creadorConjMochilasFB(std::vector<std::tuple<int, int, int>> objetos);

std::vector<std::tuple<int, int, int>> mochilaIdealFB (std::vector<std::vector<std::tuple<int, int, int>>> opciones,
                                                       int pesoPermitido);

#endif //TPI_FUERZABRUTAVERSIONES_H
