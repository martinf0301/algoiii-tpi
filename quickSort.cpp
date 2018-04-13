#include <iostream>
#include <tuple>
#include <vector>
#include "quickSort.h"


void quickSortRecursivo(std::vector<std::tuple<int, int, int>> &conjunto,
               std::vector<float> &radioBP, int inicio, int final) {
    int posicionPivot = inicio;

    if (final - inicio < 1) {                                                                           //caso base
        return;
    }

    for (int i = inicio; i < final; ++i) {                                                              //calculo la posicion indicada del pivot
        if (radioBP[i] > radioBP[final]) {
            posicionPivot++;
        }
    }
    std::iter_swap(conjunto.begin() + posicionPivot, conjunto.begin() + final);                         //posiciono al pivot en el vector de elementos
    std::iter_swap(radioBP.begin() + posicionPivot, radioBP.begin() + final);                           //posiciono al pivot en el vector de radios

    for (int i = inicio; i < posicionPivot; ++i) {                                                      //me fijo si hay elementos en el lado incorrecto
        if (radioBP[i] <= radioBP[posicionPivot]) {
            for (int j = posicionPivot + 1; j <= final ; ++j) {
                if (radioBP[j] > radioBP[posicionPivot]) {
                    std::iter_swap(conjunto.begin() + i, conjunto.begin() + j);                         //acomodo los elementos en el vector de elementos
                    std::iter_swap(radioBP.begin() + i, radioBP.begin() + j);                           //acomodo los radios en el vector de radios
                    break;
                }
            }
        }
    }

    if (posicionPivot > inicio) {
        quickSortRecursivo(conjunto, radioBP, inicio, posicionPivot - 1);                                      //ordeno la primera mitad
    }

    if (posicionPivot < final) {
        quickSortRecursivo(conjunto, radioBP, posicionPivot + 1, final);                                       //ordeno la segunda mitad
    }
}


void quickSort(std::vector<std::tuple<int, int, int>> &conjunto, std::vector<float> &radioBP) {
    quickSortRecursivo(conjunto, radioBP, 0, conjunto.size() - 1);                                             //llamo a la funcion recursiva
}

void quickSortPVRecursion(std::vector<std::tuple<int, int, int>> &conjunto, int inicio, int final) {
    int posicionPivot = inicio;

    if (final - inicio < 1) {                                                                           //caso base
        return;
    }

    for (int i = inicio; i < final; ++i) {                                                              //calculo la posicion indicada del pivot
        if (std::get<0>(conjunto[i]) < std::get<0>(conjunto[final])  ||
            (std::get<0>(conjunto[i]) == std::get<0>(conjunto[final]) &&
             std::get<1>(conjunto[i]) > std::get<1>(conjunto[final]))) {
            posicionPivot++;
        }
    }
    std::iter_swap(conjunto.begin() + posicionPivot, conjunto.begin() + final);                         //posiciono al pivot

    for (int i = inicio; i < posicionPivot; ++i) {                                                      //me fijo si hay elementos en el lado incorrecto
        if (std::get<0>(conjunto[i]) > std::get<0>(conjunto[posicionPivot]) ||
            (std::get<0>(conjunto[i]) == std::get<0>(conjunto[posicionPivot]) &&
             std::get<1>(conjunto[i]) <= std::get<1>(conjunto[posicionPivot]))) {
            for (int j = posicionPivot + 1; j <= final ; ++j) {
                if (std::get<0>(conjunto[j]) < std::get<0>(conjunto[posicionPivot]) ||
                    (std::get<0>(conjunto[j]) == std::get<0>(conjunto[posicionPivot]) &&
                     std::get<1>(conjunto[j]) > std::get<1>(conjunto[posicionPivot]))) {
                    std::iter_swap(conjunto.begin() + i, conjunto.begin() + j);
                    break;
                }
            }
        }
    }

    if (posicionPivot > inicio) {
        quickSortPVRecursion(conjunto, inicio, posicionPivot - 1);                                      //ordeno la primera mitad
    }

    if (posicionPivot < final) {
        quickSortPVRecursion(conjunto, posicionPivot + 1, final);                                       //ordeno la segunda mitad
    }
}

void quickSortPV(std::vector<std::tuple<int, int, int>> &conjunto) {
    quickSortPVRecursion(conjunto, 0, conjunto.size() - 1);                                             //llamo a la funcion recursiva
};