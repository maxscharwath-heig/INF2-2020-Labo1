//
// Created by Maxime Scharwath on 02.03.2020.
//

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
