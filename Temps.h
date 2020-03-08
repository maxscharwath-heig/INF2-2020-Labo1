/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo1
 Fichier     : Temps.h
 Auteur(s)   : Ganguillet, Parrino et Scharwath
 Date        : 02.03.2020

 But         : Cette librairie met à disposition une classe Temps permettant d'effectuer
               différentes opérations sur les heures telles que :
               - comparaisons
               - addition et soustraction (de deux objet Temps)
               - post et pré incrémentation et décrémentation
               - affichage dans un ostream au format hh:mm:ss
               - getters et setters pour l'heure, les minutes, les secondes
               - convertion en temps décimal (double) exprimé en heures

 Remarque(s) : Il n'y a pas de vérification des valeurs entrées dans les setteurs et
               dans le constructeur. La cohérence des résultats n'est pas garantie si les
               valeurs entrées ne sont pas comprises dans les bornes [0-23] pour les heures,
               [0-59] pour les minutes et les secondes.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef LABO1_TEMPS_H
#define LABO1_TEMPS_H

#include <ctime>
#include <iostream>

class Temps {
   /**
    * Operateur d'égalité
    * @param lhs
    * @param rhs
    * @return true si égal
    */
   friend bool operator==(const Temps &lhs, const Temps &rhs);

   /**
    * Operateur de différence
    * @param lhs
    * @param rhs
    * @return true si différent
    */
   friend bool operator!=(const Temps &lhs, const Temps &rhs);

   /**
    * Opérateur strictement inférieur
    * @param lhs
    * @param rhs
    * @return true si strictement inférieur
    */
   friend bool operator<(const Temps &lhs, const Temps &rhs);

   /**
    * Opérateur strictement supérieur
    * @param lhs
    * @param rhs
    * @return true si strictement supérieur
    */
   friend bool operator>(const Temps &lhs, const Temps &rhs);

   /**
    * Opérateur inférieur
    * @param lhs
    * @param rhs
    * @return true si inférieur
    */
   friend bool operator<=(const Temps &lhs, const Temps &rhs);

   /**
    * Opérateur supérieur
    * @param lhs
    * @param rhs
    * @return true si supérieur
    */
   friend bool operator>=(const Temps &lhs, const Temps &rhs);

   /**
    * Opérateur d'addtion
    * @param lhs
    * @param rhs
    * @return Temps additionné
    */
   friend Temps operator+(Temps lhs, const Temps &rhs);

   /**
    * Opérateur de soustraction
    * @param lhs
    * @param rhs
    * @return Temps soustrait
    */
   friend Temps operator-(Temps lhs, const Temps &rhs);

   /**
    * surcharge du flux format (hh:mm:ss)
    * @param os
    * @param temps
    * @return ostream& référence au flux de sortie
    */
   friend std::ostream &operator<<(std::ostream &os, const Temps &temps);

public:
//---------------------------------CONSTRUCTEUR------------------------------------//
   /**
    * Constructeur par défaut où tout est initialisé à 0
    */
   Temps();

   /**
    * initialisation avec un objet de type time_t
    * @example Temps t1 = time(NULL);
    *          Temps t1(time(NULL));
    * @param heureCourante
    */
   Temps(const time_t &heureCourante);

   /**
    * initialisation avec heures, minutes, secondes optionnel
    * @param heures
    * @param minutes
    * @param secondes
    */
   Temps(unsigned int heures, unsigned int minutes, unsigned int secondes = 0);
//---------------------------------------------------------------------------------//

//------------------------------------GETTER---------------------------------------//
   /**
    * getter des heures
    * @return l'heure
    */
   unsigned int getHeures() const;

   /**
    * getter des minutes
    * @return les minutes
    */
   unsigned int getMinutes() const;

   /**
    * getter des secondes
    * @return les secondes
    */
   unsigned int getSecondes() const;
//---------------------------------------------------------------------------------//

//---------------------------------SETTER------------------------------------------//
   /**
    * setter des heures
    * @param heures
    */
   void setHeures(unsigned int heures);

   /**
    * setter des minutes
    * @param minutes
    */
   void setMinutes(unsigned int minutes);

   /**
    * setter des secondes
    * @param secondes
    */
   void setSecondes(unsigned int secondes);
//--------------------------------------------------------------------------------//

//------------------------------FONCTION MEBRES-----------------------------------//
   /**
    * converti en temps décimal exprimé en heures
    * @return double heures en décimal
    */
    explicit operator double() const;

   /**
    * surcharge de l'opérateur +=
    * @param rhs Temps à rajouter
    * @return Temps
    */
   Temps &operator+=(const Temps &rhs);

   /**
    * surcharge de l'opérateur -=
    * @param rhs Temps à soustraire
    * @return Temps
    */
   Temps &operator-=(const Temps &rhs);

   /**
    * pre-incrementation de Temps
    * @return Temps
    */
   Temps &operator++();

   /**
    * post-incrémentation de Temps
    * @return Temps
    */
   Temps operator++(int);

   /**
    * pre-decrementation de Temps
    * @return Temps
    */
   Temps &operator--();

   /**
    * post-decrementation de Temps
    * @return Temps
    */
   Temps operator--(int);

//--------------------------------------------------------------------------------//

private:

   unsigned int heures;
   unsigned int minutes;
   unsigned int secondes;

   static unsigned int NB_SECONDES_JOUR; // nombre de secondes dans une journée

   /**
    * calcule le Temps en secondes
    * @return nombre de secondes
    */
   unsigned int tempsEnSecondes() const;

   /**
    * actualise les champs membres de Temps
    * @param tempsEnSecondes
    * @return Temps actualisé
    */
   Temps &secondesEnTemps(unsigned int tempsEnSecondes);

};


#endif //LABO1_TEMPS_H
