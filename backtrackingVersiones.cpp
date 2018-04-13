#include <iostream>
#include <tuple>
#include <vector>
#include "backtrackingVersiones.h"


std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingOrdenado(std::vector<std::tuple<int, int, int>> elementos,
                                                                             bool podaFactibilidad,
                                                                             bool podaOptimalidad,
                                                                             int pesoPermitido) {
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
    int i = 0;
    int pesoMochilaSinElemento = 0;
    int pesoMochilaConElemento = 0;

    if (podaFactibilidad) {
        if (std::get<0>(elementos[i]) > pesoPermitido) {
            std::get<0>(mochilaSinElemento) = elementos;
            std::get<1>(mochilaSinElemento) = 0;
            return mochilaSinElemento;
        }
    }

    mochilaSinElemento = backtrackingOrdenadoRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido, i + 1);
    std::get<2>(elementos[i]) = 1;
    mochilaConElemento = backtrackingOrdenadoRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido, i + 1);

    if (!podaFactibilidad) {
        for (int j = 0; j < elementos.size(); ++j) {                                                                                    //calculo sus pesos hasta el momento
            if (std::get<2>(std::get<0>(mochilaSinElemento)[j]) == 1) {
                pesoMochilaSinElemento += std::get<0>(std::get<0>(mochilaSinElemento)[j]);
            }
            if (std::get<2>(std::get<0>(mochilaConElemento)[j]) == 1) {
                pesoMochilaConElemento += std::get<0>(std::get<0>(mochilaConElemento)[j]);
            }
        }
        //estudio los cuatro casos posibles
        if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                    //si solo la mochila con el elemento tiene un peso indicado
            return mochilaConElemento;                                                                                              //devuelvo esa mochila, con su beneficio
        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                             //si solo la mochila sin el elemento tiene un peso indicado
            return mochilaSinElemento;                                                                                              //devuelvo esa mochila, con su beneficio
        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                            //si las dos mochilas pesan lo indicado
            return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;   //devuelvo la mochila con mayor beneficio
        } else {                                                                                                                    //si ninguna tiene un peso indicado
            std::get<0>(mochilaSinElemento) = elementos;                                                                            //devuelvo la mochila tal como estaba en el input
            std::get<1>(mochilaSinElemento) = 0;                                                                                    //con beneficio 0
            return mochilaSinElemento;
        }
    }
    return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
};

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingOrdenadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                      bool podaFactibilidad,
                                                                                      bool podaOptimalidad,
                                                                                      int pesoPermitido,
                                                                                      int i) {
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
    int pesoActual = 0;
    int beneficioActual = 0;
    int pesoMochilaSinElemento = 0;
    int pesoMochilaConElemento = 0;
    for (int j = 0; j < elementos.size(); ++j) {
        if (std::get<2>(elementos[j])) {
            pesoActual += std::get<0>(elementos[j]);
            beneficioActual += std::get<1>(elementos[j]);
        }
    }

    if (i == elementos.size() - 1) {
        std::get<0>(mochilaSinElemento) = elementos;
        std::get<1>(mochilaSinElemento) = beneficioActual;

        if (podaFactibilidad) {
            if (std::get<0>(elementos[i]) + pesoActual > pesoPermitido) {
                return mochilaSinElemento;
            }
        }

        if (podaOptimalidad) {
            if (std::get<0>(elementos[i - 1]) == std::get<0>(elementos[i]) && std::get<2>(elementos[i - 1]) == 0) {
                return mochilaSinElemento;
            }
        }

        std::get<2>(elementos[i]) = 1;
        std::get<0>(mochilaConElemento) = elementos;
        std::get<1>(mochilaConElemento) = beneficioActual + std::get<1>(elementos[i]);
        if (!podaFactibilidad) {
            pesoMochilaSinElemento = pesoActual;
            pesoMochilaConElemento = pesoActual + std::get<0>(elementos[i]);
            //estudio los cuatro casos posibles
            if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                    //si solo la mochila con el elemento tiene un peso indicado
                return mochilaConElemento;                                                                                              //devuelvo esa mochila, con su beneficio
            } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                             //si solo la mochila sin el elemento tiene un peso indicado
                return mochilaSinElemento;                                                                                              //devuelvo esa mochila, con su beneficio
            } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                            //si las dos mochilas pesan lo indicado
                return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;   //devuelvo la mochila con mayor beneficio
            } else {                                                                                                                    //si ninguna tiene un peso indicado
                std::get<0>(mochilaSinElemento) = elementos;                                                                            //devuelvo la mochila tal como estaba en el input
                std::get<1>(mochilaSinElemento) = 0;                                                                                    //con beneficio 0
                return mochilaSinElemento;
            }
        }

        return mochilaConElemento;
    }

    if (podaFactibilidad) {
        if (std::get<0>(elementos[i]) + pesoActual > pesoPermitido) {
            std::get<0>(mochilaSinElemento) = elementos;
            std::get<1>(mochilaSinElemento) = beneficioActual;
            return mochilaSinElemento;
        }
    }

    if (podaOptimalidad) {
        if (std::get<0>(elementos[i - 1]) == std::get<0>(elementos[i]) && std::get<2>(elementos[i - 1]) == 0) {
            return backtrackingOrdenadoRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido, i + 1);
        }
    }

    mochilaSinElemento = backtrackingOrdenadoRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido, i + 1);
    std::get<2>(elementos[i]) = 1;
    mochilaConElemento = backtrackingOrdenadoRecursivo(elementos, podaFactibilidad, podaOptimalidad, pesoPermitido, i + 1);

    if (!podaFactibilidad) {
        for (int j = 0; j < elementos.size(); ++j) {                                                                                //calculo sus pesos hasta el momento
            if (std::get<2>(std::get<0>(mochilaSinElemento)[j]) == 1) {
                pesoMochilaSinElemento += std::get<0>(std::get<0>(mochilaSinElemento)[j]);
            }
            if (std::get<2>(std::get<0>(mochilaConElemento)[j]) == 1) {
                pesoMochilaConElemento += std::get<0>(std::get<0>(mochilaConElemento)[j]);
            }
        }
        //estudio los cuatro casos posibles
        if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                    //si solo la mochila con el elemento tiene un peso indicado
            return mochilaConElemento;                                                                                              //devuelvo esa mochila, con su beneficio
        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                             //si solo la mochila sin el elemento tiene un peso indicado
            return mochilaSinElemento;                                                                                              //devuelvo esa mochila, con su beneficio
        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                            //si las dos mochilas pesan lo indicado
            return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;   //devuelvo la mochila con mayor beneficio
        } else {                                                                                                                    //si ninguna tiene un peso indicado
            std::get<0>(mochilaSinElemento) = elementos;                                                                            //devuelvo la mochila tal como estaba en el input
            std::get<1>(mochilaSinElemento) = 0;                                                                                    //con beneficio 0
            return mochilaSinElemento;
        }
    }

    return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
};

//std::tuple<std::vector<std::tuple<int, int, int>>, int> backtracking(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido) {
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
//    int i = 0;
//
//    mochilaSinElemento = backtrackingRecursivo(elementos, pesoPermitido, i + 1);
//    if (std::get<0>(elementos[i]) <= pesoPermitido) {
//        std::get<2>(elementos[i]) = 1;
//        mochilaConElemento = backtrackingRecursivo(elementos, pesoPermitido, i + 1);
//
//        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
//    }
//    return mochilaSinElemento;
//};
//
//std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingRecursivo(std::vector<std::tuple<int, int, int>> elementos,
//                                                                              int pesoPermitido,
//                                                                              int i){
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
//    int pesoActual = 0;
//    int beneficioActual = 0;
//    for (int j = 0; j < elementos.size(); ++j) {
//        if (std::get<2>(elementos[j])) {
//            pesoActual += std::get<0>(elementos[j]);
//            beneficioActual += std::get<1>(elementos[j]);
//        }
//    }
//
//    if (i == elementos.size() - 1) {
//        std::get<0>(mochilaSinElemento) = elementos;
//        std::get<1>(mochilaSinElemento) = beneficioActual;
//        if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
//            std::get<2>(elementos[i]) = 1;
//            std::get<0>(mochilaConElemento) = elementos;
//            std::get<1>(mochilaConElemento) = beneficioActual + std::get<1>(elementos[i]);
//            return mochilaConElemento;
//        }
//        return mochilaSinElemento;
//    }
//
//    mochilaSinElemento = backtrackingRecursivo(elementos, pesoPermitido, i + 1);
//    if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
//        std::get<2>(elementos[i]) = 1;
//        mochilaConElemento = backtrackingRecursivo(elementos, pesoPermitido, i + 1);
//        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
//    }
//    return mochilaSinElemento;
//};

/*--------------------------------------BACKTRACKINGS TUNEADOS--------------------------------------*/

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneado(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido) {
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
    int i = 0;

    mochilaSinElemento = backtrackingTuneadoRecursivo(elementos, pesoPermitido, 0, 0, i + 1);
    if (std::get<0>(elementos[i]) <= pesoPermitido) {
        std::get<2>(elementos[i]) = 1;
        mochilaConElemento = backtrackingTuneadoRecursivo(elementos, pesoPermitido, std::get<0>(elementos[i]), std::get<1>(elementos[i]), i + 1);

        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
    }
    return mochilaSinElemento;
};

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                     int pesoPermitido,
                                                                                     int pesoActual,
                                                                                     int beneficioActual,
                                                                                     int i){
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;

    if (i == elementos.size() - 1) {
        if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
            std::get<2>(elementos[i]) = 1;
            std::get<0>(mochilaConElemento) = elementos;
            std::get<1>(mochilaConElemento) = beneficioActual + std::get<1>(elementos[i]);
            return mochilaConElemento;
        }
    }

    mochilaSinElemento = backtrackingTuneadoRecursivo(elementos, pesoPermitido, pesoActual, beneficioActual, i + 1);
    if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
        std::get<2>(elementos[i]) = 1;
        mochilaConElemento = backtrackingTuneadoRecursivo(elementos, pesoPermitido, pesoActual + std::get<0>(elementos[i]),
                                                          beneficioActual + std::get<1>(elementos[i]), i + 1);
        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
    }
    return mochilaSinElemento;
};

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoOrdenado(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido) {
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
    int i = 0;

    if (std::get<0>(elementos[i]) <= pesoPermitido) {
        mochilaSinElemento = backtrackingTuneadoOrdenadoRecursivo(elementos, pesoPermitido, 0, 0, i + 1);
        std::get<2>(elementos[i]) = 1;
        mochilaConElemento = backtrackingTuneadoOrdenadoRecursivo(elementos, pesoPermitido, std::get<0>(elementos[i]), std::get<1>(elementos[i]), i + 1);

        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
    }
    std::get<0>(mochilaSinElemento) = elementos;
    std::get<1>(mochilaSinElemento) = 0;
    return mochilaSinElemento;
};

std::tuple<std::vector<std::tuple<int, int, int>>, int> backtrackingTuneadoOrdenadoRecursivo(std::vector<std::tuple<int, int, int>> elementos,
                                                                                             int pesoPermitido,
                                                                                             int pesoActual,
                                                                                             int beneficioActual,
                                                                                             int i){
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;
    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;

    if (i == elementos.size() - 1) {
        if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
            std::get<2>(elementos[i]) = 1;
            std::get<0>(mochilaConElemento) = elementos;
            std::get<1>(mochilaConElemento) = beneficioActual + std::get<1>(elementos[i]);
            return mochilaConElemento;
        }
    }

    if (std::get<0>(elementos[i]) + pesoActual <= pesoPermitido) {
        mochilaSinElemento = backtrackingTuneadoOrdenadoRecursivo(elementos, pesoPermitido, pesoActual, beneficioActual, i + 1);
        std::get<2>(elementos[i]) = 1;
        mochilaConElemento = backtrackingTuneadoOrdenadoRecursivo(elementos, pesoPermitido, pesoActual + std::get<0>(elementos[i]),
                                                                  beneficioActual + std::get<1>(elementos[i]), i + 1);
        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;
    }
    std::get<0>(mochilaSinElemento) = elementos;
    std::get<1>(mochilaSinElemento) = beneficioActual;
    return mochilaSinElemento;
};


/*--------------------------------------BACKTRACKINGS CHOTOS--------------------------------------*/

std::vector<std::vector<std::tuple<int, int, int>>> creadorMochilasBckSinOrden(
        std::vector<std::tuple<int, int, int>> objetos,
        std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
        int pesoActual,
        int pesoPermitido,
        int i) {
    if (i == objetos.size() - 1) {
        if (std::get<0>(objetos[i]) <= pesoPermitido - pesoActual) {                                                             //PODA POR FACTIBILIDAD
            std::get<2>(objetos[i]) = 1;
            conjuntoRes.insert(conjuntoRes.end(), objetos);
        }
    } else {
        conjuntoRes = creadorMochilasBckSinOrden(objetos, conjuntoRes, pesoActual, pesoPermitido, i + 1);
        if (std::get<0>(objetos[i]) <= pesoPermitido - pesoActual) {                                                             //PODA POR FACTIBILIDAD
            std::get<2>(objetos[i]) = 1;
            conjuntoRes.insert(conjuntoRes.end(), objetos);
            conjuntoRes = creadorMochilasBckSinOrden(objetos, conjuntoRes, pesoActual + std::get<0>(objetos[i]), pesoPermitido, i + 1);
        }
    }
    return conjuntoRes;
};

std::vector<std::vector<std::tuple<int, int, int>>> creadorConjMochilasBckSinOrden(
        std::vector<std::tuple<int, int, int>> objetos,
        int pesoPermitido) {
    int pesoActual = 0;
    int i = 0;
    std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes;
    conjuntoRes.insert(conjuntoRes.end(), objetos);
    conjuntoRes = creadorMochilasBckSinOrden(objetos, conjuntoRes, pesoActual, pesoPermitido, i + 1);
    if (std::get<0>(objetos[i]) < pesoPermitido) {                                                                              //PODA POR FACTIBILIDAD
        std::get<2>(objetos[i]) = 1;
        conjuntoRes.insert(conjuntoRes.end(), objetos);
        conjuntoRes = creadorMochilasBckSinOrden(objetos, conjuntoRes, std::get<0>(objetos[i]), pesoPermitido, i + 1);
    }
    return conjuntoRes;
};

std::vector<std::tuple<int, int, int>> mochilaIdealBckSinOrden(
        std::vector<std::vector<std::tuple<int, int, int>>> opciones,
        int pesoPermitido){
    std::vector<std::tuple<int, int, int>> mochilaIdeal;
    int valorIdeal = 0;
    for (int i = 0; i < opciones.size(); ++i) {
        int valor = 0;
        for (int j = 0; j < opciones[i].size(); ++j) {
            if (std::get<2>(opciones[i][j]) == 1) {
                valor = valor + std::get<1>(opciones[i][j]);
            }
        }
        if (valor > valorIdeal) {
            valorIdeal = valor;
            mochilaIdeal = opciones[i];
        }
    }
    return mochilaIdeal;
};


std::vector<std::vector<std::tuple<int, int, int>>> crearSolucionesBckOrdRecursivo(std::vector<std::tuple<int, int, int>> objetos,
                                                                                   std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
                                                                                   int pesoActual,
                                                                                   int pesoPermitido,
                                                                                   int i) {
    if (std::get<0>(objetos[i]) > pesoPermitido - pesoActual) {                                                             //PODA POR FACTIBILIDAD
        return conjuntoRes;
    } else {
        if (i == objetos.size() - 1) {
            std::get<2>(objetos[i]) = 1;
            conjuntoRes.insert(conjuntoRes.end(), objetos);
        } else {
            conjuntoRes = crearSolucionesBckOrdRecursivo(objetos, conjuntoRes, pesoActual, pesoPermitido, i + 1);
            std::get<2>(objetos[i]) = 1;
            conjuntoRes.insert(conjuntoRes.end(), objetos);
            conjuntoRes = crearSolucionesBckOrdRecursivo(objetos, conjuntoRes, pesoActual + std::get<0>(objetos[i]),
                                                         pesoPermitido, i + 1);
        }
        return conjuntoRes;
    }
};

std::vector<std::vector<std::tuple<int, int, int>>> crearSolucionesBckOrd(std::vector<std::tuple<int, int, int>> objetos,
                                                                          int pesoPermitido) {
    int pesoActual = 0;
    int i = 0;
    std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes;
    if (std::get<0>(objetos[i]) > pesoPermitido) {                                                                              //PODA POR FACTIBILIDAD
        return conjuntoRes;
    } else {
        conjuntoRes.insert(conjuntoRes.end(), objetos);
        conjuntoRes = crearSolucionesBckOrdRecursivo(objetos, conjuntoRes, pesoActual, pesoPermitido, i + 1);
        std::get<2>(objetos[i]) = 1;
        conjuntoRes.insert(conjuntoRes.end(), objetos);
        conjuntoRes = crearSolucionesBckOrdRecursivo(objetos, conjuntoRes, std::get<0>(objetos[i]), pesoPermitido,
                                                     i + 1);
        return conjuntoRes;
    }
};

std::vector<std::tuple<int, int, int>> mochilaIdealBckConOrden(
        std::vector<std::vector<std::tuple<int, int, int>>> opciones,
        int pesoPermitido){
    std::vector<std::tuple<int, int, int>> mochilaIdeal;
    int beneficioMochilaIdeal = 0;
    for (int i = 0; i < opciones.size(); ++i) {                                                                                 //itero por todas las soluciones posibles
        int beneficio = 0;
        for (int j = 0; j < opciones[i].size(); ++j) {                                                                          //itero por todos los objetos de la solucion actual
            if (std::get<2>(opciones[i][j]) == 1) {
                beneficio = beneficio + std::get<1>(opciones[i][j]);                                                            //calculo el beneficio total de la solucion actual
            }
        }
        if (beneficio > beneficioMochilaIdeal) {                                                                                //si la solucion actual es la mejor solucion por el momento, actualizo los valores
            beneficioMochilaIdeal = beneficio;
            mochilaIdeal = opciones[i];
        }
    }
    return mochilaIdeal;
};