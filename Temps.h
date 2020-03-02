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
//---------------------------------CONSTRUCTEUR--------------------------------------//
    Temps();
    Temps(const time_t& heureCourante);
    Temps( unsigned int heures, unsigned int minutes, unsigned int secondes = 0);
//-----------------------------------------------------------------------------------//

//------------------------------------GETTER----------------------------------------//
    unsigned int getHeures() const;
    unsigned int getMinutes() const;
    unsigned int getSecondes() const;
//---------------------------------------------------------------------------------//

//---------------------------------SETTER------------------------------------------//
    void setHeures(unsigned int heures);
    void setMinutes(unsigned int minutes);
    void setSecondes(unsigned int secondes);
//--------------------------------------------------------------------------------//






private:
    unsigned int heures;
    unsigned int minutes;
    unsigned int secondes;
};


#endif //LABO1_TEMPS_H
