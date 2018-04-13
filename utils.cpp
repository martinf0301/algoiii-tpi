#include "utils.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>



std::tuple<std::vector<std::tuple<int, int, int>>, int> generarConjunto(string nombreArchivo) {
    tuple<std::vector<tuple<int, int, int>>, int> resultado;
    std::vector<tuple<int, int, int> conjunto;
    ifstream archivo;
    archivo.open(nombreArchivo);
    int w = 0;
    int max;
    if (archivo.is_open) {
      int max;
      archivo >> max >> w;
      tuple<int, int, int> nuevoElemento;
      int count = 0;
      while (count < max && !archivo.eof()) {
        archivo >> std::get<0>(nuevoElemento) >> std::get<1>(nuevoElemento);
        std::get<2>(nuevoElemento) = 0;
        conjunto.push_back(nuevoElemento);
      }
    }
    std::get<0>(resultado) = conjunto;
    std::get<1>(resultado) = w;
    return resultado;
};

