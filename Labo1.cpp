/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo1
 Fichier     : Labo 1.cpp
 Auteur(s)   : Ganguillet, Parrino et Scharwath
 Date        : 02.03.2020

 But         : TO DO

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include "Temps.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    Temps t1{5,10,2},
          t2(24,40,45);
    while(true) {
       cout << ++t1 << endl;
    }

    return EXIT_SUCCESS;
}