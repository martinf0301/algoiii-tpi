#include <iostream>
#include <tuple>
#include <vector>
#include "fuerzaBruta.h"


int fuerzaBruta(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido) {
    std::vector<std::vector<std::tuple<int, int, int>>> soluciones;
    soluciones = crearSoluciones(elementos);
    int pesoDeSolucion = 0;
    int valorDeSolucion = 0;
    int valorOptimo = 0;

    for (int i = 0; i < soluciones.size(); ++i) {
        pesoDeSolucion = 0;
        valorDeSolucion = 0;
        for (int j = 0; j < soluciones[i].size(); ++j) {
            if (std::get<2>(soluciones[i][j]) == 1) {
                pesoDeSolucion = pesoDeSolucion + std::get<0>(soluciones[i][j]);
                valorDeSolucion = valorDeSolucion + std::get<1>(soluciones[i][j]);
            }
        }
        if (pesoDeSolucion <= pesoPermitido) {
            if (valorDeSolucion > valorOptimo) {
                valorOptimo = valorDeSolucion;
            }
        }
    }

    return valorOptimo;
}

std::vector<std::vector<std::tuple<int, int, int>>> crearSoluciones(std::vector<std::tuple<int, int, int>> elementos) {
    std::vector<std::vector<std::tuple<int, int, int>>> soluciones;
    int i = 0;

    soluciones.push_back(elementos);
    agregarSoluciones(soluciones, elementos, i);

    return soluciones;
};

void agregarSoluciones(std::vector<std::vector<std::tuple<int, int, int>>> &soluciones,
                       std::vector<std::tuple<int, int, int>> elementos, int i) {
    if (i == elementos.size() - 1) {
        std::get<2>(elementos[i]) = 1;
        soluciones.push_back(elementos);
        return;
    }

    std::get<2>(elementos[i]) = 1;
    soluciones.push_back(elementos);
    agregarSoluciones(soluciones, elementos, i + 1);
    std::get<2>(elementos[i]) = 0;
    agregarSoluciones(soluciones, elementos, i + 1);
};