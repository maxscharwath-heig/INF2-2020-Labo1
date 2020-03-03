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



//Constructeur init à 0
Temps::Temps() : heures{0}, minutes{0}, secondes{0}{}

//Constructeur 3 parametres avec secondes = 0 par defaut
Temps::Temps( unsigned int heures, unsigned int minutes, unsigned int secondes)
    : heures{heures} , minutes{minutes} , secondes{secondes}{}

//Constructeur avec struct de tipe time_t
Temps::Temps(const time_t& tempsCourante){
    tm *now = localtime(&tempsCourante);
    heures   = (unsigned int)now->tm_hour;
    minutes  = (unsigned int)now->tm_min;
    secondes = (unsigned int)now->tm_sec;
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
