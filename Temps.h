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
#include <iostream>

class Temps {
   /**
    * Operateur de comparaison (<,<=, >, >=, == et !=)
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator==(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator!=(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator<(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator>(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator<=(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend bool operator>=(const Temps &lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend Temps operator+(Temps lhs, const Temps &rhs);

   /**
    *
    * @param lhs
    * @param rhs
    * @return
    */
   friend Temps operator-(Temps lhs, const Temps &rhs);

   /**
    * surcharge du flux format (hh:mm:ss)
    * @param os
    * @param temps
    * @return
    */
   friend std::ostream &operator<<(std::ostream &os, const Temps &temps);

public:
//---------------------------------CONSTRUCTEUR------------------------------------//
   /**
    * Constructeur par défaut où tous est initialisé à 0
    */
   Temps();

   /**
    *
    * @param heureCourante
    */
   Temps(const time_t &heureCourante);

   /**
    *
    * @param heures
    * @param minutes
    * @param secondes
    */
   Temps(unsigned int heures, unsigned int minutes, unsigned int secondes = 0);
//---------------------------------------------------------------------------------//

//------------------------------------GETTER---------------------------------------//
   /**
    *
    * @return
    */
   unsigned int getHeures() const;

   /**
    *
    * @return
    */
   unsigned int getMinutes() const;

   /**
    *
    * @return
    */
   unsigned int getSecondes() const;
//---------------------------------------------------------------------------------//

//---------------------------------SETTER------------------------------------------//
   /**
    *
    * @param heures
    */
   void setHeures(unsigned int heures);

   /**
    *
    * @param minutes
    */
   void setMinutes(unsigned int minutes);

   /**
    *
    * @param secondes
    */
   void setSecondes(unsigned int secondes);
//--------------------------------------------------------------------------------//

//------------------------------FONCTION MEBRES-----------------------------------//
   /**
    *
    * @return
    */
   /*explicit*/ operator double() const;

   /**
    *
    * @param rhs
    * @return
    */
   Temps &operator+=(const Temps &rhs);

   /**
    *
    * @param rhs
    * @return
    */
   Temps &operator-=(const Temps &rhs);

   /**
    * incrementation pre/post
    * @return
    */
   Temps &operator++();

   /**
    *
    * @return
    */
   Temps operator++(int);

   /**
    * decrementation pre/post
    * @return
    */
   Temps &operator--();

   /**
    *
    * @return
    */
   Temps operator--(int);

//--------------------------------------------------------------------------------//

private:
   //Champs membres
   unsigned int heures;
   unsigned int minutes;
   unsigned int secondes;

   static unsigned int NB_HEURES; // nb d'heures dans une journee
   static unsigned int NB_MINUTES;// nb d'minutes dans une heure
   static unsigned int NB_SECONDES;// nb de secondes dans une minutes
};


#endif //LABO1_TEMPS_H
