#include <iostream>
#include <tuple>
#include <vector>
#include "problemaMochilaContinuo.h"
#include "quickSort.h"


int problemaMochilaContinuo(std::vector<std::tuple<int, int, int>> elementos,
                            int pesoPermitido) {
    std::vector<float> radioBeneficioPeso;
    int pesoElemento = 0;
    int beneficioElemento = 0;
    float relacionBeneficioPeso = 0;
    int beneficioOptimo = 0;

    for (int i = 0; i < elementos.size(); ++i) {
        pesoElemento = std::get<0>(elementos[i]);
        beneficioElemento = std::get<1>(elementos[i]);
        relacionBeneficioPeso = ((float)(beneficioElemento))/((float)(pesoElemento));

        radioBeneficioPeso.push_back(relacionBeneficioPeso);
    }

    quickSort(elementos, radioBeneficioPeso);

    for (int i = 0; i < radioBeneficioPeso.size(); ++i) {
        pesoElemento = std::get<0>(elementos[i]);
        beneficioElemento = std::get<1>(elementos[i]);
        if (pesoElemento <= pesoPermitido) {
            beneficioOptimo += beneficioElemento;
            pesoPermitido -= pesoElemento;
        } else if (pesoPermitido != 0) {
            beneficioOptimo += pesoPermitido * radioBeneficioPeso[i];
            pesoPermitido = 0;
        }
    }

    return beneficioOptimo;
}