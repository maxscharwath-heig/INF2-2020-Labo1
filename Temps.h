/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
*/

#ifndef LABO1_TEMPS_H
#define LABO1_TEMPS_H
#include<ctime>

class Temps {
public:
    Temps(const time_t& heureCourante);
private:
    unsigned int heures;
    unsigned int minutes;
    unsigned int secondes;
};
Temps::Temps(const time_t& heureCourante){
    }

#endif //LABO1_TEMPS_H
