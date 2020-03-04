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
          t2(24,40,45),
          t3(12, 25, 33);

    cout << boolalpha;

//    friend bool operator==(const Temps &lhs, const Temps &rhs);

    //test operator==
    cout << t1 << " == " << t2 << " : " << (t1 == t2) << endl;

//    friend bool operator!=(const Temps &lhs, const Temps &rhs);

    //test operator !=

    cout << t1 << " != " << t2 << " : " << (t1 != t2) << endl;

//    friend bool operator<(const Temps &lhs, const Temps &rhs);

    cout << t1 << " < " << t2 << "  : " << (t1 < t2) << endl;
    cout << t1 << " > " << t2 << "  : " << (t1 > t2) << endl;
    cout << t1 << " <= " << t2 << " : " << (t1 <= t2) << endl;
    cout << t1 << " >= " << t2 << " : " << (t1 >= t2) << endl;

//    friend bool operator>(const Temps &lhs, const Temps &rhs);
//    friend bool operator<=(const Temps &lhs, const Temps &rhs);
//    friend bool operator>=(const Temps &lhs, const Temps &rhs);
//    friend Temps operator +(Temps lhs , const Temps& rhs);
//    //surcharge du flux format (hh:mm:ss)
//    friend std::ostream &operator<<(std::ostream &os, const Temps &temps);
//    Temps();
//    Temps(const time_t& heureCourante);
//    Temps( unsigned int heures, unsigned int minutes, unsigned int secondes = 0);
//    unsigned int getHeures() const;
//    unsigned int getMinutes() const;
//    unsigned int getSecondes() const;
//    void setHeures(unsigned int heures);
//    void setMinutes(unsigned int minutes);
//    void setSecondes(unsigned int secondes);
//    Temps& operator+=(const Temps& rhs);
//    Temps& operator-=(const Temps& rhs);
//    Temps& operator++();
//    Temps operator++(int);
//    Temps& operator--();
//    Temps operator--(int);



    return EXIT_SUCCESS;
}