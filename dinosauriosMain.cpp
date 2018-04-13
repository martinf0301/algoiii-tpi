// std::vector<std::tuple<int, int, int>> peorCasoFactibilidad;
// std::vector<std::tuple<int, int, int>> peorCasoOptimalidad;
// std::tuple<int, int, int> elemento;
// std::get<2>(elemento) = 0;
// int pesoPermitidoFact = 0;
// int pesoPermitidoOpt = 0;
// int i = 0;
// int k = 0;
//
// // auto startFuerzaBruta = chrono::steady_clock::now();
// // int beneficioFuerzaBruta;
// // auto endFuerzaBruta = chrono::steady_clock::now();
// // auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
// //
// // auto startBacktracking = chrono::steady_clock::now();
// // int beneficioBacktracking;
// // auto endBacktracking = chrono::steady_clock::now();
// // auto diffBacktracking = endBacktracking - startBacktracking;
//
// auto startBacktrackingFact = chrono::steady_clock::now();
// int beneficioBacktrackingFact;
// auto endBacktrackingFact = chrono::steady_clock::now();
// auto diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;
//
// auto startBacktrackingOpti = chrono::steady_clock::now();
// int beneficioBacktrackingOpti;
// auto endBacktrackingOpti = chrono::steady_clock::now();
// auto diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;
//
// auto startBacktrackingFactOpti = chrono::steady_clock::now();
// int beneficioBacktrackingFactOpti;
// auto endBacktrackingFactOpti = chrono::steady_clock::now();
// auto diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;
//
//
// // ofstream fbPeorCasoFact;
// // ofstream btPeorCasoFact;
// ofstream btfPeorCasoFact;
// ofstream btoPeorCasoFact;
// ofstream btfoPeorCasoFact;
// // ofstream fbPeorCasoOpt;
// // ofstream btPeorCasoOpt;
// ofstream btfPeorCasoOpt;
// ofstream btoPeorCasoOpt;
// ofstream btfoPeorCasoOpt;
//
// // fbPeorCasoFact.open  ("fbPeorCasoFact.csv");
// // btPeorCasoFact.open  ("btPeorCasoFact.csv");
// btfPeorCasoFact.open ("btfPeorCasoFact.csv");
// btoPeorCasoFact.open ("btoPeorCasoFact.csv");
// btfoPeorCasoFact.open("btfoPeorCasoFact.csv");
// // fbPeorCasoOpt.open   ("fbPeorCasoOpt.csv");
// // btPeorCasoOpt.open   ("btPeorCasoOpt.csv");
// btfPeorCasoOpt.open  ("btfPeorCasoOpt.csv");
// btoPeorCasoOpt.open  ("btoPeorCasoOpt.csv");
// btfoPeorCasoOpt.open ("btfoPeorCasoOpt.csv");
//
// // fbPeorCasoFact   << "n,pesoPermitido,tiempo" << endl;
// // btPeorCasoFact   << "n,pesoPermitido,tiempo" << endl;
// btfPeorCasoFact  << "n,pesoPermitido,tiempo" << endl;
// btoPeorCasoFact  << "n,pesoPermitido,tiempo" << endl;
// btfoPeorCasoFact << "n,pesoPermitido,tiempo" << endl;
// // fbPeorCasoOpt    << "n,pesoPermitido,tiempo" << endl;
// // btPeorCasoOpt    << "n,pesoPermitido,tiempo" << endl;
// btfPeorCasoOpt   << "n,pesoPermitido,tiempo" << endl;
// btoPeorCasoOpt   << "n,pesoPermitido,tiempo" << endl;
// btfoPeorCasoOpt  << "n,pesoPermitido,tiempo" << endl;
//
// for (int n = 10; n <= 30; ++n) {
//     for (int j = 0; j < 50; ++j) {
//         i = 0;
//         pesoPermitidoFact = n * 51;
//         pesoPermitidoOpt = n * 10;
//         while (!peorCasoFactibilidad.empty()) {
//             peorCasoFactibilidad.pop_back();
//         }
//         while (!peorCasoOptimalidad.empty()) {
//             peorCasoOptimalidad.pop_back();
//         }
//
//         while (i < n) {
//             std::get<0>(elemento) = rand() % 50 + 1;
//             std::get<1>(elemento) = rand() % 200 + 1;
//             peorCasoFactibilidad.push_back(elemento);
//
//             std::get<0>(elemento) = rand() % 50 + 1;
//             std::get<1>(elemento) = rand() % 200 + 1;
//             peorCasoOptimalidad.push_back(elemento);
//
//             i++;
//         }
//        std::get<0>(elemento) = rand() % 50 + 1;
//        std::get<1>(elemento) = rand() % 200 + 1;
//         peorCasoFactibilidad.push_back(elemento);
//
//         std::get<0>(elemento) = pesoPermitidoOpt;
//         std::get<1>(elemento) = pesoPermitidoOpt * 201 + 1;
//         peorCasoOptimalidad.push_back(elemento);
//
//          cout << "steady_clock" << endl;
//          cout << chrono::steady_clock::period::num << endl;
//          cout << chrono::steady_clock::period::den << endl;
//          cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;
//          cout << k << endl;
//          k++;
//
//         // startFuerzaBruta = chrono::steady_clock::now();
//         // beneficioFuerzaBruta = fuerzaBruta(peorCasoFactibilidad, pesoPermitidoFact);
//         // endFuerzaBruta = chrono::steady_clock::now();
//         // diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
//         //
//         // startBacktracking = chrono::steady_clock::now();
//         // beneficioBacktracking = backtracking(peorCasoFactibilidad, false, false, pesoPermitidoFact);
//         // endBacktracking = chrono::steady_clock::now();
//         // diffBacktracking = endBacktracking - startBacktracking;
//
//         startBacktrackingFact = chrono::steady_clock::now();
//         beneficioBacktrackingFact = backtracking(peorCasoFactibilidad, true, false, pesoPermitidoFact);
//         endBacktrackingFact = chrono::steady_clock::now();
//         diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;
//
//         startBacktrackingOpti = chrono::steady_clock::now();
//         beneficioBacktrackingOpti = backtracking(peorCasoFactibilidad, false, true, pesoPermitidoFact);
//         endBacktrackingOpti = chrono::steady_clock::now();
//         diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;
//
//         startBacktrackingFactOpti = chrono::steady_clock::now();
//         beneficioBacktrackingFactOpti = backtracking(peorCasoFactibilidad, true, true, pesoPermitidoFact);
//         endBacktrackingFactOpti = chrono::steady_clock::now();
//         diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;
//
//         // fbPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffFuerzaBruta).count() << endl;
//         // btPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktracking).count() << endl;
//         btfPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingFact).count() << endl;
//         btoPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingOpti).count() << endl;
//         btfoPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingFactOpti).count() << endl;
//
//        // startFuerzaBruta = chrono::steady_clock::now();
//        // beneficioFuerzaBruta = fuerzaBruta(peorCasoOptimalidad, pesoPermitidoOpt);
//        // endFuerzaBruta = chrono::steady_clock::now();
//        // diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
//        //
//        // startBacktracking = chrono::steady_clock::now();
//        // beneficioBacktracking = backtracking(peorCasoOptimalidad, false, false, pesoPermitidoOpt);
//        // endBacktracking = chrono::steady_clock::now();
//        // diffBacktracking = endBacktracking - startBacktracking;
//
//        startBacktrackingFact = chrono::steady_clock::now();
//        beneficioBacktrackingFact = backtracking(peorCasoOptimalidad, true, false, pesoPermitidoOpt);
//        endBacktrackingFact = chrono::steady_clock::now();
//        diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;
//
//        startBacktrackingOpti = chrono::steady_clock::now();
//        beneficioBacktrackingOpti = backtracking(peorCasoOptimalidad, false, true, pesoPermitidoOpt);
//        endBacktrackingOpti = chrono::steady_clock::now();
//        diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;
//
//        startBacktrackingFactOpti = chrono::steady_clock::now();
//        beneficioBacktrackingFactOpti = backtracking(peorCasoOptimalidad, true, true, pesoPermitidoOpt);
//        endBacktrackingFactOpti = chrono::steady_clock::now();
//        diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;
//
//        // fbPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffFuerzaBruta).count() << endl;
//        // btPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktracking).count() << endl;
//        btfPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingFact).count() << endl;
//        btoPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingOpti).count() << endl;
//        btfoPeorCasoFact << n << "," << pesoPermitidoFact << "," << chrono::duration <double, milli> (diffBacktrackingFactOpti).count() << endl;
//
// //            cout << endl << endl;
// //            std::cout << "Fuerza Bruta: " << beneficioFuerzaBruta << std::endl;
// //
// //            cout << endl;
// //            std::cout << "Backtracking sin podas: " << beneficioBacktracking << std::endl;
// //
// //            cout << endl;
// //            std::cout << "Backtracking con poda por factibilidad: " << beneficioBacktrackingFact << std::endl;
// //
// //            cout << endl;
// //            std::cout << "Backtracking con poda por optimalidad: " << beneficioBacktrackingOpti << std::endl;
// //
// //            cout << endl;
// //            std::cout << "Backtracking con ambas podas: " << beneficioBacktrackingFactOpti << std::endl;
//     }
// }
//
// // fbPeorCasoFact.close();
// // btPeorCasoFact.close();
// btfPeorCasoFact.close();
// btoPeorCasoFact.close();
// btfoPeorCasoFact.close();
// // fbPeorCasoOpt.close();
// // btPeorCasoOpt.close();
// btfPeorCasoOpt.close();
// btoPeorCasoOpt.close();
// btfoPeorCasoOpt.close();

/*---------------------------------------------Print prueba ordenado---------------------------------------------*/
//std::cout << "-------------POST SORT PESO-----------------" << std::endl;
//quickSortPV(prueba);
//for (int i = 0; i < prueba.size(); ++i) {
//std::cout << std::get<0>(prueba[i]) << "|";
//}
//std::cout << std::endl;
//for (int i = 0; i < prueba.size(); ++i) {
//std::cout << std::get<1>(prueba[i]) << "|";
//}
//std::cout << std::endl;
//quickSortValor(prueba);
//for (int i = 0; i < prueba.size(); ++i) {
//std::cout << std::get<0>(prueba[i]) << "|";
//}
//std::cout << std::endl;
//for (int i = 0; i < prueba.size(); ++i) {
//std::cout << std::get<1>(prueba[i]) << "|";
//}
/*---------------------------------------------Print prueba---------------------------------------------*/
//    for (int i = 0; i < opciones.size(); ++i) {
//        for (int j = 0; j < opciones[i].size(); ++j) {
//            std::cout << std::get<2>(opciones[i][j]);
//        }
//        std::cout << "" <<std::endl;
//    }
/*---------------------------------------------Print Viejos---------------------------------------------*/
//int valorIdealFB = 0;
//int valorIdealBck = 0;
//int valorIdealBck2 = 0;
//     cout << endl << endl;
//     auto startFuerzaBruta = chrono::steady_clock::now();
//     std::vector<std::vector<std::tuple<int, int, int>>> opcionesFB = creadorConjMochilasFB(prueba);
//     std::vector<std::tuple<int, int, int>> mochilaIdealFuBr = mochilaIdealFB(opcionesFB, pesoPermitido);
//     auto endFuerzaBruta = chrono::steady_clock::now();
//     auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
//     cout << "Tiempo utilizado por Fuerza bruta: " << chrono::duration <double, milli> (diffFuerzaBruta).count() << " ms" << endl;
//
//
//     cout << endl << endl;
//     auto startBacktracking = chrono::steady_clock::now();
//     std::vector<std::vector<std::tuple<int, int, int>>> opcionesBck = creadorConjMochilasBckSinOrden(prueba,
//                                                                                                      pesoPermitido);
//     std::vector<std::tuple<int, int, int>> mochilaIdealBack = mochilaIdealBckSinOrden(opcionesBck, pesoPermitido);
//     auto endBacktracking = chrono::steady_clock::now();
//     auto diffBacktracking = endBacktracking - startBacktracking;
//     cout << "Tiempo utilizado por Backtracking desordenado: " << chrono::duration <double, milli> (diffBacktracking).count() << " ms" << endl;
//     cout << endl << endl;
//     auto startBacktracking2 = chrono::steady_clock::now();
//     std::vector<std::vector<std::tuple<int, int, int>>> opcionesBck2 = crearSolucionesBckOrd(prueba,
//                                                                                              pesoPermitido);
//     std::vector<std::tuple<int, int, int>> mochilaIdealBack2 = mochilaIdealBckConOrden(opcionesBck, pesoPermitido);
//     auto endBacktracking2 = chrono::steady_clock::now();
//     auto diffBacktracking2 = endBacktracking2 - startBacktracking2;
//     cout << "Tiempo total utilizado por Backtracking ordenado: " << chrono::duration <double, milli> (diffBacktracking2 + diffSort).count() << " ms" << endl;
//     cout << "(" << "Tiempo utilizado por Sorting: " << chrono::duration <double, milli> (diffSort).count() << " ms" << " + ";
//     cout << "Tiempo utilizado por Backtracking: " << chrono::duration <double, milli> (diffBacktracking2).count() << " ms" << ")" << endl;
//     cout << endl << endl;
//     std::cout << "Backtracking sin orden" <<std::endl;
//     std::cout << "Cantidad de subconjuntos: " << opcionesBck.size() << std::endl;
//     for (int i = 0; i < mochilaIdealBack.size(); ++i) {
//          std::cout << std::get<2>(mochilaIdealBack[i]) << "|";
//          if (std::get<2>(mochilaIdealBack[i]) == 1) {
//               valorIdealBck += std::get<1>(mochilaIdealBack[i]);
//          }
//     }
//     cout << std::endl;
//     std::cout << "Valor: " << valorIdealBck << std::endl;
//    cout << endl << endl;
//    std::cout << "Backtracking con orden" <<std::endl;
//    std::cout << "Cantidad de subconjuntos: " << opcionesBck2.size() << std::endl;
//    for (int i = 0; i < mochilaIdealBack2.size(); ++i) {
//        std::cout << std::get<2>(mochilaIdealBack2[i]) << "|";
//        if (std::get<2>(mochilaIdealBack2[i]) == 1) {
//            valorIdealBck2 += std::get<1>(mochilaIdealBack2[i]);
//        }
//    }
//    cout << std::endl;
//    std::cout << "Valor: " << valorIdealBck2 << std::endl << std::endl;
