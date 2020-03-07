/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo1
 Fichier     :  Temps.cpp
 Auteur(s)   : Ganguillet, Parrino et Scharwath
 Date        : 02.03.2020

 But         : TO DO

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "Temps.h"
#include <iomanip>

using namespace std;

unsigned int Temps::NB_HEURES = 24;
unsigned int Temps::NB_MINUTES = 60;
unsigned int Temps::NB_SECONDES = 60;

//Constructeur init à 0
Temps::Temps() : heures{0}, minutes{0}, secondes{0} {}

/* Variante de Temps() a choisir la meilleur
Temps::Temps()
{ hour = min = sec = 0;
}
 */

//Constructeur 3 parametres avec secondes = 0 par defaut
Temps::Temps(unsigned int heures, unsigned int minutes, unsigned int secondes)
      : heures{heures}, minutes{minutes}, secondes{secondes} {}

//Constructeur avec struct de tipe time_t
Temps::Temps(const time_t &tempsCourante) {
   tm *now = localtime(&tempsCourante);
   heures = (unsigned int) now->tm_hour;
   minutes = (unsigned int) now->tm_min;
   secondes = (unsigned int) now->tm_sec;
}

unsigned int Temps::getHeures() const {
   return heures;
}

unsigned int Temps::getMinutes() const {
   return minutes;
}

unsigned int Temps::getSecondes() const {
   return secondes;
}

void Temps::setHeures(unsigned int heures) {
   Temps::heures = heures;
}

void Temps::setMinutes(unsigned int minutes) {
   Temps::minutes = minutes;
}

void Temps::setSecondes(unsigned int secondes) {
   Temps::secondes = secondes;
}

bool operator==(const Temps &lhs, const Temps &rhs) {
   return lhs.heures == rhs.heures &&
          lhs.minutes == rhs.minutes &&
          lhs.secondes == rhs.secondes;
}

bool operator!=(const Temps &lhs, const Temps &rhs) {
   return !(rhs == lhs);
}

bool operator<(const Temps &lhs, const Temps &rhs) {// a choisir la meilleur
     return lhs.heures * 3600 + lhs.minutes * 60 + lhs.secondes <
            rhs.heures * 3600 + rhs.minutes * 60 + rhs.secondes;
    /*
   if (lhs.heures < rhs.heures)
      return true;
   if (rhs.heures < lhs.heures)
      return false;
   if (lhs.minutes < rhs.minutes)
      return true;
   if (rhs.minutes < lhs.minutes)
      return false;
   return lhs.secondes < rhs.secondes;
     */
}

bool operator>(const Temps &lhs, const Temps &rhs) {
   return rhs < lhs;
}

bool operator<=(const Temps &lhs, const Temps &rhs) {
   return !(rhs < lhs);
}

bool operator>=(const Temps &lhs, const Temps &rhs) {
   return !(lhs < rhs);
}


Temps &Temps::operator+=(const Temps &rhs) {

   secondes += rhs.secondes;
   minutes += rhs.minutes + (secondes / NB_SECONDES);
   heures += rhs.heures + (minutes / NB_MINUTES);
   //controle depassement
   if (secondes >= NB_SECONDES) secondes %= NB_SECONDES;
   if (minutes >= NB_MINUTES) minutes %= NB_MINUTES;
   if (heures >= NB_HEURES) heures %= NB_HEURES;

   return *this;
}

Temps operator+(Temps lhs, const Temps &rhs) {
    lhs += rhs;
    return lhs;
}

Temps &Temps::operator-=(const Temps &rhs) {
   secondes = abs((int)secondes - (int)rhs.secondes);
   minutes  = abs((int)minutes - (int)rhs.minutes);
   heures   = abs((int)heures - (int)rhs.heures);
   /*controle depassement
   if (secondes <= NB_SECONDES) secondes %= NB_SECONDES;
   if (minutes <= NB_MINUTES) minutes %= NB_MINUTES;
   if (heures <= NB_HEURES) heures %= NB_HEURES;
*/
   return *this;
}

Temps operator-(Temps lhs, const Temps &rhs) {
    lhs -= rhs;
    return lhs;
}

std::ostream &operator<<(std::ostream &os, const Temps &temps) {
   os << setfill('0') << setw(2) << temps.heures
      << ":"
      << setfill('0') << setw(2) << temps.minutes
      << ":"
      << setfill('0') << setw(2) << temps.secondes;
   return os;
}

Temps &Temps::operator++() {
   ++secondes;
   if (secondes >= NB_SECONDES) {
      secondes = 0;
      ++minutes;
   }
   if (minutes >= NB_MINUTES) {
      minutes = 0;
      ++heures;
   }
   if (heures >= NB_HEURES)
      heures = 0;

   return *this;

}

/* Methode alternative triche a choisir la meilleur
 * Temps& Temps::operator++(){
 *  Temps t{0,0,1};
 *  *this += t;
 *  return *this;
}
 */

Temps Temps::operator++(int) {
   Temps temps = *this;
   ++(*this);
   return temps;
}

/**
 * @return
 */
Temps &Temps::operator--() {
   if (secondes < (--secondes)) {
      secondes = NB_SECONDES - 1;
      if (minutes < (--minutes)) {
         minutes = NB_MINUTES - 1;
         if (heures < (--heures)) {
            heures = NB_HEURES - 1;
         }
      }
   }
   return *this;
}

Temps Temps::operator--(int) {
   Temps temps = *this;
   --(*this);
   return temps;
}

Temps::operator double() const {
   return (double)heures + (double)minutes * 1/60 + (double)secondes * 1/3600;
}
