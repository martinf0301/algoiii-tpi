#define A using
#define S namespace
#define D std;
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "fuerzaBruta.h"
#include "backtracking.h"
#include "quickSort.h"
#include "problemaMochilaContinuo.h"
#include "programacionDinamica.h"

A S D


int main() {
  std::vector <std::tuple<int, int, int>> pruebaAleatoria;
  std::tuple<int, int, int> elemento;
  std::get<2>(elemento) = 0;
  int pesoPermitido = 0;
  int pesoPromedio = 0;
  int factor = 0;
  int i = 0;
  int k = 0;

   auto startFuerzaBruta = chrono::steady_clock::now();
   int beneficioFuerzaBruta;
   auto endFuerzaBruta = chrono::steady_clock::now();
   auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;

   auto startBacktracking = chrono::steady_clock::now();
   int beneficioBacktracking;
   auto endBacktracking = chrono::steady_clock::now();
   auto diffBacktracking = endBacktracking - startBacktracking;

  auto startBacktrackingFact = chrono::steady_clock::now();
  int beneficioBacktrackingFact;
  auto endBacktrackingFact = chrono::steady_clock::now();
  auto diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;

  auto startBacktrackingOpti = chrono::steady_clock::now();
  int beneficioBacktrackingOpti;
  auto endBacktrackingOpti = chrono::steady_clock::now();
  auto diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;

  auto startBacktrackingFactOpti = chrono::steady_clock::now();
  int beneficioBacktrackingFactOpti;
  auto endBacktrackingFactOpti = chrono::steady_clock::now();
  auto diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;

  auto startProgramacionDinamica = chrono::steady_clock::now();
  int beneficioProgramacionDinamica;
  auto endProgramacionDinamica = chrono::steady_clock::now();
  auto diffProgramacionDinamica = endProgramacionDinamica - startProgramacionDinamica;


   ofstream fbAleatorio2;
   ofstream btAleatorio2;
  ofstream btfAleatorio2;
  ofstream btoAleatorio2;
  ofstream btfoAleatorio2;
  ofstream pdAleatorio2;


   fbAleatorio2.open  ("fbAleatorio2.csv");
   btAleatorio2.open  ("btAleatorio2.csv");
  btfAleatorio2.open("btfAleatorio2.csv");
  btoAleatorio2.open("btoAleatorio2.csv");
  btfoAleatorio2.open("btfoAleatorio2.csv");
  pdAleatorio2.open ("pdAleatorio2.csv");



  fbAleatorio2<< "n,pesoPermitido,tiempo" << endl;
  btAleatorio2<< "n,pesoPermitido,tiempo" << endl;
  btfAleatorio2<< "n,pesoPermitido,tiempo" << endl;
  btoAleatorio2<< "n,pesoPermitido,tiempo" << endl;
  btfoAleatorio2<< "n,pesoPermitido,tiempo" << endl;
  pdAleatorio2<< "n,pesoPermitido,tiempo" << endl;


  for (int n = 23; n <= 30; ++n) {
          i = 0;
          pesoPromedio = 0;
          while (!pruebaAleatoria.empty()) {
              pruebaAleatoria.pop_back();
          }

          while (i <= n) {
              std::get<0>(elemento) = rand() % 100 + 1;
              pesoPromedio += std::get<0>(elemento);
              factor = rand() % 9 + 1;
              std::get<1>(elemento) = std::get<0>(elemento) * factor / 3;
              pruebaAleatoria.push_back(elemento);
              i++;
          }
          pesoPermitido = pesoPromedio / 5;

          cout << "steady_clock" << endl;
          cout << chrono::steady_clock::period::num << endl;
          cout << chrono::steady_clock::period::den << endl;
          cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;
          cout << k << endl;
          k++;

           startFuerzaBruta = chrono::steady_clock::now();
           beneficioFuerzaBruta = fuerzaBruta(pruebaAleatoria, pesoPermitido);
           endFuerzaBruta = chrono::steady_clock::now();
           diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;

           startBacktracking = chrono::steady_clock::now();
           beneficioBacktracking = backtracking(pruebaAleatoria, false, false, pesoPermitido);
           endBacktracking = chrono::steady_clock::now();
           diffBacktracking = endBacktracking - startBacktracking;

          startBacktrackingFact = chrono::steady_clock::now();
          beneficioBacktrackingFact = backtracking(pruebaAleatoria, true, false, pesoPermitido);
          endBacktrackingFact = chrono::steady_clock::now();
          diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;

          startBacktrackingOpti = chrono::steady_clock::now();
          beneficioBacktrackingOpti = backtracking(pruebaAleatoria, false, true, pesoPermitido);
          endBacktrackingOpti = chrono::steady_clock::now();
          diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;

          startBacktrackingFactOpti = chrono::steady_clock::now();
          beneficioBacktrackingFactOpti = backtracking(pruebaAleatoria, true, true, pesoPermitido);
          endBacktrackingFactOpti = chrono::steady_clock::now();
          diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;

          startProgramacionDinamica = chrono::steady_clock::now();
          beneficioProgramacionDinamica = programacionDinamica(pruebaAleatoria, pesoPermitido);
          endProgramacionDinamica = chrono::steady_clock::now();
          diffProgramacionDinamica = endProgramacionDinamica - startProgramacionDinamica;

          fbAleatorio2 << n << "," << pesoPermitido << "," << chrono::duration <double, milli> (diffFuerzaBruta).count() << endl;
          btAleatorio2 << n << "," << pesoPermitido << "," << chrono::duration <double, milli> (diffBacktracking).count() << endl;
          btfAleatorio2 << n << "," << pesoPermitido << ","
                          << chrono::duration<double, milli>(diffBacktrackingFact).count() << endl;
          btoAleatorio2 << n << "," << pesoPermitido << ","
                          << chrono::duration<double, milli>(diffBacktrackingOpti).count() << endl;
          btfoAleatorio2 << n << "," << pesoPermitido << ","
                           << chrono::duration<double, milli>(diffBacktrackingFactOpti).count() << endl;
          pdAleatorio2 << n << "," << pesoPermitido << ","
                      << chrono::duration<double, milli>(diffProgramacionDinamica).count() << endl;
      
  }

  fbAleatorio2.close();
  btAleatorio2.close();
  btfAleatorio2.close();
  btoAleatorio2.close();
  btfoAleatorio2.close();
  pdAleatorio2.close();





































//     std::vector<std::tuple<int, int, int>> prueba;
//    prueba.push_back(std::make_tuple (3, 4, 0));
//    prueba.push_back(std::make_tuple (9, 27, 0));
//    prueba.push_back(std::make_tuple (2, 5, 0));
//    prueba.push_back(std::make_tuple (7, 25, 0));
//    prueba.push_back(std::make_tuple (4, 8, 0));
//    prueba.push_back(std::make_tuple (1, 2, 0));
//    prueba.push_back(std::make_tuple (6, 2, 0));
//    prueba.push_back(std::make_tuple (8, 21, 0));
//    prueba.push_back(std::make_tuple (3, 4, 0));
//    prueba.push_back(std::make_tuple (9, 2, 0));
//    prueba.push_back(std::make_tuple (2, 5, 0));
//    prueba.push_back(std::make_tuple (7, 15, 0));
//    prueba.push_back(std::make_tuple (4, 8, 0));
//    prueba.push_back(std::make_tuple (1, 1, 0));
//    prueba.push_back(std::make_tuple (6, 12, 0));
//    prueba.push_back(std::make_tuple (8, 1, 0));
//    prueba.push_back(std::make_tuple (3, 10, 0));
//    prueba.push_back(std::make_tuple (9, 36, 0));
//    prueba.push_back(std::make_tuple (2, 5, 0));
//
////    prueba.push_back(std::make_tuple (7, 30, 0));
////    prueba.push_back(std::make_tuple (4, 8, 0));
////    prueba.push_back(std::make_tuple (1, 3, 0));
////    prueba.push_back(std::make_tuple (6, 2, 0));
////    prueba.push_back(std::make_tuple (8, 15, 0));
////    prueba.push_back(std::make_tuple (0, 2, 0));
//
//
//     int pesoPermitido = 25;
//
//
//
//     cout << "steady_clock" << endl;
//     cout << chrono::steady_clock::period::num << endl;
//     cout << chrono::steady_clock::period::den << endl;
//     cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;
//
//
//    cout << endl;
//    auto startFuerzaBruta = chrono::steady_clock::now();
//    int beneficioFuerzaBruta = fuerzaBruta(prueba, pesoPermitido);
//    auto endFuerzaBruta = chrono::steady_clock::now();
//    auto diffFuerzaBruta = endFuerzaBruta - startFuerzaBruta;
//    cout << "Tiempo utilizado por Fuerza Bruta: " << chrono::duration <double, milli> (diffFuerzaBruta).count() << " ms" << endl;
//
//    cout << endl;
//    auto startBacktracking = chrono::steady_clock::now();
//    int beneficioBacktracking = backtracking(prueba, false, false, pesoPermitido);
//    auto endBacktracking = chrono::steady_clock::now();
//    auto diffBacktracking = endBacktracking - startBacktracking;
//    cout << "Tiempo utilizado por Backtracking sin poda: " << chrono::duration <double, milli> (diffBacktracking).count() << " ms" << endl;
//
//    cout << endl;
//    auto startBacktrackingFact = chrono::steady_clock::now();
//    int beneficioBacktrackingFact = backtracking(prueba, true, false, pesoPermitido);
//    auto endBacktrackingFact = chrono::steady_clock::now();
//    auto diffBacktrackingFact = endBacktrackingFact - startBacktrackingFact;
//    cout << "Tiempo utilizado por Backtracking con poda factibilidad: " << chrono::duration <double, milli> (diffBacktrackingFact).count() << " ms" << endl;
//
//    cout << endl;
//    auto startBacktrackingOpti = chrono::steady_clock::now();
//    int beneficioBacktrackingOpti = backtracking(prueba, false, true, pesoPermitido);
//    auto endBacktrackingOpti = chrono::steady_clock::now();
//    auto diffBacktrackingOpti = endBacktrackingOpti - startBacktrackingOpti;
//    cout << "Tiempo utilizado por Backtracking con poda optimalidad: " << chrono::duration <double, milli> (diffBacktrackingOpti).count() << " ms" << endl;
//
//    cout << endl;
//    auto startBacktrackingFactOpti = chrono::steady_clock::now();
//    int beneficioBacktrackingFactOpti = backtracking(prueba, true, true, pesoPermitido);
//    auto endBacktrackingFactOpti = chrono::steady_clock::now();
//    auto diffBacktrackingFactOpti = endBacktrackingFactOpti - startBacktrackingFactOpti;
//    cout << "Tiempo utilizado por Backtracking con ambas podas: " << chrono::duration <double, milli> (diffBacktrackingFactOpti).count() << " ms" << endl;
//
//    cout << endl;
//    auto startProgramacionDinamica = chrono::steady_clock::now();
//    int beneficioProgramacionDinamica = programacionDinamica(prueba, pesoPermitido);
//    auto endProgramacionDinamica = chrono::steady_clock::now();
//    auto diffProgramacionDinamica = endProgramacionDinamica - startProgramacionDinamica;
//    cout << "Tiempo utilizado por Programacion Dinamica: " << chrono::duration <double, milli> (diffProgramacionDinamica).count() << " ms" << endl;
//
//
//    cout << endl << endl;
//    std::cout << "Fuerza Bruta: " << beneficioFuerzaBruta << std::endl;
//
//    cout << endl;
//    std::cout << "Backtracking sin podas: " << beneficioBacktracking << std::endl;
//
//    cout << endl;
//    std::cout << "Backtracking con poda por factibilidad: " << beneficioBacktrackingFact << std::endl;
//
//    cout << endl;
//    std::cout << "Backtracking con poda por optimalidad: " << beneficioBacktrackingOpti << std::endl;
//
//    cout << endl;
//    std::cout << "Backtracking con ambas podas: " << beneficioBacktrackingFactOpti << std::endl;
//
//    cout << endl;
//    std::cout << "Programacion Dinamica: " << beneficioProgramacionDinamica << std::endl;


//    cout << endl << endl;
//    std::cout << "-------------POST SORT PESO-----------------" << std::endl;
//    for (int i = 0; i < prueba.size(); ++i) {
//    std::cout << std::get<0>(prueba[i]) << "|";
//    }
//    std::cout << std::endl;
//    for (int i = 0; i < prueba.size(); ++i) {
//    std::cout << std::get<1>(prueba[i]) << "|";
//    }

    return 0;
}
