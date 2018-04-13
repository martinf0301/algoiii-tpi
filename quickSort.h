#ifndef TPI_COUNTINGSORT_H
#define TPI_COUNTINGSORT_H
#include <iostream>
#include <tuple>
#include <vector>


/*Quick Sort que ordena decrecientemente un vector de tuplas
 * <peso, beneficio, seleccionado> en funcion de su relacion
 * beneficio/peso                                                  */

void quickSortRecursivo(std::vector<std::tuple<int, int, int>> &conjunto,
               std::vector<float> &radioBP, int inicio, int final);


void quickSort(std::vector<std::tuple<int, int, int>> &conjunto,
               std::vector<float> &radioBP);


/*Quick Sort que ordena primero por el beneficio, decrecientemente
 * y segundo por el peso, crecientemente                           */

void quickSortPVRecursion(std::vector<std::tuple<int, int, int>> &conjunto, int inicio, int final);


void quickSortPV(std::vector<std::tuple<int, int, int>> &conjunto);


#endif //TPI_COUNTINGSORT_H