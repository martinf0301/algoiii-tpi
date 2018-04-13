#include <iostream>
#include <tuple>
#include <vector>


/*--------------------------------------FUERZABRUTA NORMAL--------------------------------------*/

//std::tuple<std::vector<std::tuple<int, int, int>>, int> fuerzaBrutaRecursivo(std::vector<std::tuple<int, int, int>> elementos,
//                                                                             int pesoPermitido,
//                                                                             int i){
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;                                                     //declaro variables
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
//    int pesoMochilaSinElemento = 0;
//    int pesoMochilaConElemento = 0;
//
//    if (i == elementos.size() - 1) {                                                                                                //CASO BASE
//        std::get<0>(mochilaSinElemento) = elementos;
//        std::get<2>(elementos[i]) = 1;
//        std::get<0>(mochilaConElemento) = elementos;
//        for (int j = 0; j < elementos.size(); ++j) {                                                                                    //defino las variables
//            if (std::get<2>(std::get<0>(mochilaSinElemento)[j]) == 1) {
//                pesoMochilaSinElemento += std::get<0>(std::get<0>(mochilaSinElemento)[j]);
//                std::get<1>(mochilaSinElemento) += std::get<1>(elementos[j]);
//            }
//            if (std::get<2>(std::get<0>(mochilaConElemento)[j]) == 1) {
//                pesoMochilaConElemento += std::get<0>(std::get<0>(mochilaConElemento)[j]);
//                std::get<1>(mochilaConElemento) += std::get<1>(elementos[j]);
//            }
//        }
//
//        //estudio los cuatro casos posibles
//        if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                     //si solo la mochila con el elemento tiene un peso indicado
//            return mochilaConElemento;                                                                                              //devuelvo esa mochila, con su beneficio
//        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                              //si solo la mochila sin el elemento tiene un peso indicado
//            return mochilaSinElemento;                                                                                              //devuelvo esa mochila, con su beneficio
//        } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                              //si las dos mochilas pesan lo indicado
//            return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;   //devuelvo la mochila con mayor beneficio
//        } else {                                                                                                                    //si ninguna tiene un peso indicado
//            std::get<0>(mochilaSinElemento) = elementos;                                                                            //devuelvo la mochila tal como estaba en el input
//            std::get<1>(mochilaSinElemento) = 0;                                                                                    //con beneficio 0
//            return mochilaSinElemento;
//        }
//    }
//
//
//    mochilaSinElemento = fuerzaBrutaRecursivo(elementos, pesoPermitido, i + 1);
//    std::get<2>(elementos[i]) = 1;
//    mochilaConElemento = fuerzaBrutaRecursivo(elementos, pesoPermitido, i + 1);
//
//    for (int j = 0; j < elementos.size(); ++j) {
//        if (std::get<2>(std::get<0>(mochilaSinElemento)[j]) == 1) {
//            pesoMochilaSinElemento += std::get<0>(std::get<0>(mochilaSinElemento)[j]);
//        }
//        if (std::get<2>(std::get<0>(mochilaConElemento)[j]) == 1) {
//            pesoMochilaConElemento += std::get<0>(std::get<0>(mochilaConElemento)[j]);
//        }
//    }
//
//    //estudio los cuatro casos posibles
//    if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                         //si solo la mochila con el elemento tiene un peso indicado
//        return mochilaConElemento;                                                                                                  //devuelvo esa mochila, con su beneficio
//    } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                                  //si solo la mochila sin el elemento tiene un peso indicado
//        return mochilaSinElemento;                                                                                                  //devuelvo esa mochila, con su beneficio
//    } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                  //si las dos mochilas pesan lo indicado
//        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;       //devuelvo la mochila con mayor beneficio
//    } else {                                                                                                                        //si ninguna tiene un peso indicado
//        std::get<0>(mochilaSinElemento) = elementos;                                                                                //devuelvo la mochila tal como estaba en el input
//        std::get<1>(mochilaSinElemento) = 0;                                                                                        //con beneficio 0
//        return mochilaSinElemento;
//    }
//};
//
//std::tuple<std::vector<std::tuple<int, int, int>>, int> fuerzaBruta2(std::vector<std::tuple<int, int, int>> elementos, int pesoPermitido) {
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaSinElemento;                                                //declaro variables
//    std::tuple<std::vector<std::tuple<int, int, int>>, int> mochilaConElemento;
//    int pesoMochilaSinElemento = 0;
//    int pesoMochilaConElemento = 0;
//    int i = 0;
//
//
//    mochilaSinElemento = fuerzaBrutaRecursivo(elementos, pesoPermitido, i + 1);                                                 //defino variables
//    std::get<2>(elementos[i]) = 1;
//    mochilaConElemento = fuerzaBrutaRecursivo(elementos, pesoPermitido, i + 1);
//
//    for (int j = 0; j < elementos.size(); ++j) {
//        if (std::get<2>(std::get<0>(mochilaSinElemento)[j]) == 1) {
//            pesoMochilaSinElemento += std::get<0>(std::get<0>(mochilaSinElemento)[j]);
//        }
//        if (std::get<2>(std::get<0>(mochilaConElemento)[j]) == 1) {
//            pesoMochilaConElemento += std::get<0>(std::get<0>(mochilaConElemento)[j]);
//        }
//    }
//
//    //estudio los cuatro casos posibles
//    if (pesoMochilaSinElemento > pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                                     //si solo la mochila con el elemento tiene un peso indicado
//        return mochilaConElemento;                                                                                              //devuelvo esa mochila, con su beneficio
//    } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento > pesoPermitido) {                              //si solo la mochila sin el elemento tiene un peso indicado
//        return mochilaSinElemento;                                                                                              //devuelvo esa mochila, con su beneficio
//    } else if (pesoMochilaSinElemento <= pesoPermitido && pesoMochilaConElemento <= pesoPermitido) {                              //si las dos mochilas pesan lo indicado
//        return (std::get<1>(mochilaSinElemento) > std::get<1>(mochilaConElemento)) ? mochilaSinElemento : mochilaConElemento;   //devuelvo la mochila con mayor beneficio
//    } else {                                                                                                                    //si ninguna tiene un peso indicado
//        std::get<0>(mochilaSinElemento) = elementos;                                                                            //devuelvo la mochila tal como estaba en el input
//        std::get<1>(mochilaSinElemento) = 0;                                                                                    //con beneficio 0
//        return mochilaSinElemento;
//    }
//};


/*--------------------------------------FUERZABRUTA CHOTO--------------------------------------*/

std::vector<std::vector<std::tuple<int, int, int>>> creadorMochilasFB(std::vector<std::tuple<int, int, int>> objetos,
                                                                      std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes,
                                                                      int i) {
    if (i == objetos.size() - 1) {
        std::get<2>(objetos[i]) = 1;
        conjuntoRes.insert(conjuntoRes.end(), objetos);
    } else {
        conjuntoRes = creadorMochilasFB(objetos, conjuntoRes, i + 1);
        std::get<2>(objetos[i]) = 1;
        conjuntoRes.insert(conjuntoRes.end(), objetos);
        conjuntoRes = creadorMochilasFB(objetos, conjuntoRes, i + 1);
    }
    return conjuntoRes;
};

std::vector<std::vector<std::tuple<int, int, int>>> creadorConjMochilasFB(std::vector<std::tuple<int, int, int>> objetos) {
    int i = 0;
    std::vector<std::vector<std::tuple<int, int, int>>> conjuntoRes;
    conjuntoRes.insert(conjuntoRes.end(), objetos);
    conjuntoRes = creadorMochilasFB(objetos, conjuntoRes, i + 1);
    std::get<2>(objetos[i]) = 1;
    conjuntoRes.insert(conjuntoRes.end(), objetos);
    conjuntoRes = creadorMochilasFB(objetos, conjuntoRes, i + 1);
    return conjuntoRes;
};

std::vector<std::tuple<int, int, int>> mochilaIdealFB (std::vector<std::vector<std::tuple<int, int, int>>> opciones,
                                                       int pesoPermitido){
    std::vector<std::tuple<int, int, int>> mochilaIdeal;
    int valorIdeal = 0;
    for (int i = 0; i < opciones.size(); ++i) {
        int peso = 0;
        int valor = 0;
        for (int j = 0; j < opciones[i].size(); ++j) {
            if (std::get<2>(opciones[i][j]) == 1) {
                peso = peso + std::get<0>(opciones[i][j]);
                valor = valor + std::get<1>(opciones[i][j]);
            }
        }
        if (peso <= pesoPermitido) {
            if (valor > valorIdeal) {
                valorIdeal = valor;
                mochilaIdeal = opciones[i];
            }
        }
    }
    return mochilaIdeal;
};