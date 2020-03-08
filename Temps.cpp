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

Temps::Temps() : heures{0}, minutes{0}, secondes{0} {}

Temps::Temps(unsigned int heures, unsigned int minutes, unsigned int secondes)
      : heures{heures}, minutes{minutes}, secondes{secondes} {}


Temps::Temps(const time_t &tempsCourante) {
   tm *now = localtime(&tempsCourante);
   heures   = (unsigned int) now->tm_hour;
   minutes  = (unsigned int) now->tm_min;
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
   return lhs.heures   == rhs.heures  &&
          lhs.minutes  == rhs.minutes &&
          lhs.secondes == rhs.secondes;
}

bool operator!=(const Temps &lhs, const Temps &rhs) {
   return !(rhs == lhs);
}

bool operator<(const Temps &lhs, const Temps &rhs) {// a choisir la meilleur
    return lhs.heures * 3600 + lhs.minutes * 60 + lhs.secondes <
           rhs.heures * 3600 + rhs.minutes * 60 + rhs.secondes;
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
    unsigned sec1 = dateEnSecondes(),
             sec2 = rhs.dateEnSecondes();
    cout << sec1 << ' ' << sec2 << endl;
    if(sec1 < sec2){
        secondesEnDate(sec2-sec1);
    }else{
        secondesEnDate(sec1-sec2);
    }
   return *this;
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
   if (secondes < --secondes) {
      secondes = NB_SECONDES - 1;
      if (minutes < --minutes) {
         minutes = NB_MINUTES - 1;
         if (heures < --heures) {
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

unsigned int Temps::dateEnSecondes() const {
    return heures*3600 + minutes * 60 + secondes;
}

void Temps::secondesEnDate(unsigned int sec) {
    heures = sec / 3600 % 24;
    minutes = sec / 60 % 60;
    secondes = sec % 60;
}
