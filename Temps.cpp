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

unsigned int Temps::NB_SECONDES_JOUR = 86400;

Temps::Temps() : heures{0}, minutes{0}, secondes{0} {}

Temps::Temps(unsigned int heures, unsigned int minutes, unsigned int secondes)
      : heures{heures}, minutes{minutes}, secondes{secondes} {}


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
   this->heures = heures;
}

void Temps::setMinutes(unsigned int minutes) {
   this->minutes = minutes;
}

void Temps::setSecondes(unsigned int secondes) {
   this->secondes = secondes;
}

bool operator==(const Temps &lhs, const Temps &rhs) {
   return lhs.tempsEnSecondes() == rhs.tempsEnSecondes();
}

bool operator!=(const Temps &lhs, const Temps &rhs) {
   return !(rhs == lhs);
}

bool operator<(const Temps &lhs, const Temps &rhs) {// a choisir la meilleur
   return lhs.tempsEnSecondes() < rhs.tempsEnSecondes();
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

   return secondesEnTemps(tempsEnSecondes() + rhs.tempsEnSecondes());
}

Temps operator+(Temps lhs, const Temps &rhs) {
   lhs += rhs;
   return lhs;
}

Temps &Temps::operator-=(const Temps &rhs) {
   unsigned sec1 = tempsEnSecondes(),
         sec2 = rhs.tempsEnSecondes();
   if (sec1 > sec2) {
      return secondesEnTemps(sec1 - sec2);
   }
   return secondesEnTemps(NB_SECONDES_JOUR + sec1 - sec2);
}

Temps operator-(Temps lhs, const Temps &rhs) {
   lhs -= rhs;
   return lhs;
}

//setfill('0') << setw(2) permet de mettre un zero si le nombre est plus petit que 10
ostream &operator<<(ostream &os, const Temps &temps) {
   os << setfill('0') << setw(2) << temps.heures
      << ":"
      << setfill('0') << setw(2) << temps.minutes
      << ":"
      << setfill('0') << setw(2) << temps.secondes;
   return os;
}

Temps &Temps::operator++() {
   return secondesEnTemps(tempsEnSecondes() + 1);
}

Temps Temps::operator++(int) {
   Temps temps = *this;
   ++(*this);
   return temps;
}

Temps &Temps::operator--() {
   unsigned int sec = tempsEnSecondes();
   if (sec) { //sec != 0
      return secondesEnTemps(sec - 1);
   }
   return secondesEnTemps(NB_SECONDES_JOUR - 1);
}

Temps Temps::operator--(int) {
   Temps temps = *this;
   --(*this);
   return temps;
}

Temps::operator double() const {
   return (double) heures + (double) minutes * 1 / 60. + (double) secondes * 1 / 3600.;
}

unsigned int Temps::tempsEnSecondes() const {
   return heures * 3600 + minutes * 60 + secondes;
}

Temps &Temps::secondesEnTemps(unsigned int tempsEnSecondes) {
   heures = tempsEnSecondes / 3600 % 24;
   minutes = tempsEnSecondes / 60 % 60;
   secondes = tempsEnSecondes % 60;
   return *this;
}
