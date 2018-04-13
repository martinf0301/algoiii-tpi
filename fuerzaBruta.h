#ifndef TPI_FUERZABRUTA_H
#define TPI_FUERZABRUTA_H
#include <iostream>
#include <tuple>
#include <vector>


int fuerzaBruta(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido);

std::vector<std::vector<std::tuple<int, int, int>>> crearSoluciones(std::vector<std::tuple<int, int, int>> elementos);

void agregarSoluciones(std::vector<std::vector<std::tuple<int, int, int>>> &soluciones,
                       std::vector<std::tuple<int, int, int>> elementos, int i);

#endif //TPI_FUERZABRUTA_H
