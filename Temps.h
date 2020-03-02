/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo1
 Fichier     : Temps.h
 Auteur(s)   : Ganguillet, Parrino et Scharwath
 Date        : 02.03.2020

 But         : TO DO

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef LABO1_TEMPS_H
#define LABO1_TEMPS_H
#include<ctime>
#include <ostream>

/* ---------------------------------------------A FAIRE-----------------------------
Un opérateur -- (en version pré-décrémentation et post-décrémentation)1
Un opérateur - permettant de soustraire deux temps et retournant un temps
Un opérateur -=, permettant de faire, par ex : t1 -= t2
Un opérateur de conversion permettant de convertir un objet de type Temps en temps décimal exprimé en heures. Exemple : la conversion de 01:30:00 doit donner 1.5 [h].

---------------------------------------------------------------------------------------------*/

class Temps {
    //Operateur de comparaison (<,<=, >, >=, == et !=)
    friend bool operator==(const Temps &lhs, const Temps &rhs);
    friend bool operator!=(const Temps &lhs, const Temps &rhs);
    friend bool operator<(const Temps &lhs, const Temps &rhs);
    friend bool operator>(const Temps &lhs, const Temps &rhs);
    friend bool operator<=(const Temps &lhs, const Temps &rhs);
    friend bool operator>=(const Temps &lhs, const Temps &rhs);

    friend Temps operator +(Temps lhs , const Temps& rhs);

    //surcharge du flux format (hh:mm:ss)
    friend std::ostream &operator<<(std::ostream &os, const Temps &temps);

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

//------------------------------FONCTION MEBRES-----------------------------------//


    Temps& operator+=(const Temps& rhs);

    //incrementation pre/post
    Temps& operator++();
    Temps operator++(int);

    //decrementation pre/post
    Temps& operator--();
    Temps operator--(int);

//--------------------------------------------------------------------------------//

private:
    //Champs membres
    unsigned int heures;
    unsigned int minutes;
    unsigned int secondes;
};


#endif //LABO1_TEMPS_H
