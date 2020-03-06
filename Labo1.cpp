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
         t2(21,40),
         t3(12, 25, 33);

   cout << "t1 : " << t1 << endl;
   cout << "t2 : " << t2 << endl;
   cout << "t3 : " << t3 << endl;
   cout << "heure courante : " << Temps(time(NULL)) << endl;
   cout << "Constructeur par defaut : " << Temps() << endl;


   cout << boolalpha;
   cout << "Comparateurs :" << endl;
   cout << t1 << " == " << t2 << " = " << (t1 == t2) << endl;
   cout << t1 << " != " << t2 << " = " << (t1 != t2) << endl;
   cout << t1 << " < " << t2 << "  = " << (t1 < t2) << endl;
   cout << t1 << " > " << t2 << "  = " << (t1 > t2) << endl;
   cout << t1 << " <= " << t2 << " = " << (t1 <= t2) << endl;
   cout << t1 << " >= " << t2 << " = " << (t1 >= t2) << endl;
   cout << endl;

   cout << "addition / multiplication :" << endl;
   cout << t1 << " + " << t2 << "  = " << (t1 + t2) << endl;
   cout << t1 << " - " << t2 << "  = " << (t1 - t2) << endl;
   cout << endl;

   cout << "getters :" << endl;
   cout << "t1.getHeures()   = " << t1.getHeures() << endl;
   cout << "t1.getMinutes()  = " << t1.getMinutes() << endl;
   cout << "t1.getSecondes() = " << t1.getSecondes() << endl;
   cout << endl;

   cout << "setters :" << endl;
   t1.setHeures(1);
   cout << "t1.setHeures(1) -> t1     = " << t1 << endl;
   t1.setHeures(25);
   cout << "t1.setHeures(25) -> t1    = " << t1 << endl;
   t1.setHeures(-22);
   cout << "t1.setHeures(-22) -> t1   = " << t1 << endl;

   t1.setMinutes(1);
   cout << "t1.setMinutes(1) -> t1    = " << t1 << endl;
   t1.setMinutes(64);
   cout << "t1.setMinutes(64) -> t1   = " << t1 << endl;
   t1.setMinutes(-22);
   cout << "t1.setMinutes(-22) -> t1  = " << t1 << endl;

   t1.setSecondes(1);
   cout << "t1.setSecondes(1) -> t1   = " << t1 << endl;
   t1.setSecondes(64);
   cout << "t1.setSecondes(64) -> t1  = " << t1 << endl;
   t1.setSecondes(-22);
   cout << "t1.setSecondes(-22) -> t1 = " << t1 << endl;
   cout << endl;

   cout << "auto incrementation :" << endl;
   cout << t1 << " += " << t2 << "  = " << (t1 += t2) << endl;
   cout << t1 << " -= " << t2 << "  = " << (t1 -= t2) << endl;

   cout << "++(" << t1 << ") = " << (++t1) << endl;
   cout << '(' << t1 << ")++" << " = " << (t1++) << endl;

   cout << "--(" << t1 << ") = " << (--t1) << endl;
   cout << '(' << t1 << ")--" << " = " << (t1--) << endl;

   return EXIT_SUCCESS;
}