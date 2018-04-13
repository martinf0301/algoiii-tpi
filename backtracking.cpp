#include <iostream>
#include <tuple>
#include <vector>
#include "backtracking.h"
#include "quickSort.h"
#include "problemaMochilaContinuo.h"


/*--------------------------------------BACKTRACKINGS NORMALES--------------------------------------*/

int backtracking(std::vector<std::tuple<int, int, int>> elementos,
                 bool podaFactibilidad,
                 bool podaOptimalidad,
                 int pesoPermitido) {
    int pesoActual = 0;
    int beneficioActual = 0;
    int beneficioMaximo = 0;
    int i = 0;

    quickSortPV(elementos);

    if (podaFactibilidad && podaOptimalidad) {
        std::vector<std::tuple<int, int, int>> elementosRestantes(elementos.begin() + i + 1, elementos.end());
        int maximoBeneficioPosible = problemaMochilaContinuo(elementosRestantes, pesoPermitido - pesoActual);
        if (pesoActual + std::get<0>(elementos[i]) > pesoPermitido ||
            beneficioActual + std::get<1>(elementos[i]) + maximoBeneficioPosible <= beneficioMaximo) {
            return beneficioMaximo;
        } else {
            std::get<2>(elementos[i]) = 1;
            pesoActual += std::get<0>(elementos[i]);
            beneficioActual += std::get<1>(elementos[i]);
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
            beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                    pesoActual, beneficioActual, beneficioMaximo, i + 1);
        }
    }

    if (podaFactibilidad && !podaOptimalidad) {
        if (pesoActual + std::get<0>(elementos[i]) > pesoPermitido) {
            return beneficioMaximo;
        } else {
            std::get<2>(elementos[i]) = 1;
            pesoActual += std::get<0>(elementos[i]);
            beneficioActual += std::get<1>(elementos[i]);
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
            beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                    pesoActual, beneficioActual, beneficioMaximo, i + 1);
        }
    }

    if (!podaFactibilidad && podaOptimalidad) {
        std::vector<std::tuple<int, int, int>> elementosRestantes(elementos.begin() + i + 1, elementos.end());
        int maximoBeneficioPosible = problemaMochilaContinuo(elementosRestantes, pesoPermitido - pesoActual);
        if (beneficioActual + std::get<1>(elementos[i]) + maximoBeneficioPosible <= beneficioMaximo) {
            return beneficioMaximo;
        }
        std::get<2>(elementos[i]) = 1;
        pesoActual += std::get<0>(elementos[i]);
        beneficioActual += std::get<1>(elementos[i]);
        if (pesoActual <= pesoPermitido) {
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
        }
        beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                pesoActual, beneficioActual, beneficioMaximo, i + 1);
    }

    if (!podaFactibilidad && !podaOptimalidad) {
        std::get<2>(elementos[i]) = 1;
        pesoActual += std::get<0>(elementos[i]);
        beneficioActual += std::get<1>(elementos[i]);
        if (pesoActual <= pesoPermitido) {
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
        }
        beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                pesoActual, beneficioActual, beneficioMaximo, i + 1);
    }

    std::get<2>(elementos[i]) = 0;
    pesoActual -= std::get<0>(elementos[i]);
    beneficioActual -= std::get<1>(elementos[i]);
    beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                            pesoActual, beneficioActual, beneficioMaximo, i + 1);

    return beneficioMaximo;
}

int backtrackingRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                          bool podaFactibilidad,
                          bool podaOptimalidad,
                          int pesoPermitido,
                          int pesoActual,
                          int beneficioActual,
                          int beneficioMaximo,
                          int i) {
    if (i == elementos.size() - 1) {
        std::get<2>(elementos[i]) = 1;
        pesoActual += std::get<0>(elementos[i]);
        beneficioActual += std::get<1>(elementos[i]);
        if (pesoActual <= pesoPermitido) {
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
        }

        return beneficioMaximo;
    }

    if (podaFactibilidad && podaOptimalidad) {
        std::vector<std::tuple<int, int, int>> elementosRestantes(elementos.begin() + i + 1, elementos.end());
        int maximoBeneficioPosible = problemaMochilaContinuo(elementosRestantes, pesoPermitido - pesoActual);
        if (pesoActual + std::get<0>(elementos[i]) > pesoPermitido ||
            beneficioActual + std::get<1>(elementos[i]) + maximoBeneficioPosible <= beneficioMaximo) {
            return beneficioMaximo;
        } else {
            std::get<2>(elementos[i]) = 1;
            pesoActual += std::get<0>(elementos[i]);
            beneficioActual += std::get<1>(elementos[i]);
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
            beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                    pesoActual, beneficioActual, beneficioMaximo, i + 1);
        }
    }

    if (podaFactibilidad && !podaOptimalidad) {
        if (pesoActual + std::get<0>(elementos[i]) > pesoPermitido) {
            return beneficioMaximo;
        } else {
            std::get<2>(elementos[i]) = 1;
            pesoActual += std::get<0>(elementos[i]);
            beneficioActual += std::get<1>(elementos[i]);
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
            beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                    pesoActual, beneficioActual, beneficioMaximo, i + 1);
        }
    }

    if (!podaFactibilidad && podaOptimalidad) {
        std::vector<std::tuple<int, int, int>> elementosRestantes(elementos.begin() + i + 1, elementos.end());
        int maximoBeneficioPosible = problemaMochilaContinuo(elementosRestantes, pesoPermitido - pesoActual);
        if (beneficioActual + std::get<1>(elementos[i]) + maximoBeneficioPosible <= beneficioMaximo) {
            return beneficioMaximo;
        }
        std::get<2>(elementos[i]) = 1;
        pesoActual += std::get<0>(elementos[i]);
        beneficioActual += std::get<1>(elementos[i]);
        if (pesoActual <= pesoPermitido) {
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
        }
        beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                pesoActual, beneficioActual, beneficioMaximo, i + 1);
    }

    if (!podaFactibilidad && !podaOptimalidad) {
        std::get<2>(elementos[i]) = 1;
        pesoActual += std::get<0>(elementos[i]);
        beneficioActual += std::get<1>(elementos[i]);
        if (pesoActual <= pesoPermitido) {
            beneficioMaximo = (beneficioActual > beneficioMaximo) ? beneficioActual : beneficioMaximo;
        }
        beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                                pesoActual, beneficioActual, beneficioMaximo, i + 1);
    }

    std::get<2>(elementos[i]) = 0;
    pesoActual -= std::get<0>(elementos[i]);
    beneficioActual -= std::get<1>(elementos[i]);
    beneficioMaximo = backtrackingRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido,
                                            pesoActual, beneficioActual, beneficioMaximo, i + 1);

    return beneficioMaximo;
}