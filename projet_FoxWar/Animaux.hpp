#ifndef ANIMAUX_HPP_INCLUDED
#define ANIMAUX_HPP_INCLUDED

#include "Coord.hpp"


//Pour les Renards
const int FoodInit = 5;
const int FoodLapin = 5;
const int FoodReprod = 8;
const int MaxFood = 10;
const float ProbBirthRenard = 0.05;
//Pour les Lapins
const float ProbBirthLapin = 0.30;
const int MinFreeBirthLapin = 4;



enum Espece {Lapin, Renard, Vide};



struct Animal {
	Espece espece;
	Coord coord;
	int food;
};



/////////////////////////////////////////////////////////////////////////////////
//                         Fonctions du type abstrait                          //
/////////////////////////////////////////////////////////////////////////////////

/*Fonction de hasard
@return un float au hasard entre 0 et 1
*/
float hasard();

/*Cree un animal en connaissant son espece et ses coordonnees sur la grille et initialise son niveau de nourriture
@param[in] espece de l'animal
@param[in] coordonnee de l animal sur la grille
@return l animal
*/
Animal creerAnimal(Espece E, Coord c);

/*Retourne les coordonnes de l animal
@param[in] l animal
@return ses coordonnees sur la grille
*/
Coord coordAnimal( Animal a);

/*Retourne l espece de l animal
@param[in] l animal
@return son espece
*/
Espece especeAnimal( Animal a);


/*Retourne le niveau de nourriture de l animal
@param[in] l animal
@return son niveau de nourriture qui est -1 si l animal n est pas un renard
*/
int nourritureRenard(Animal a);

/*Verifie si un animal est vide
@param[in] l animal
@return true si il est vide, false sinon
*/
bool estVide(Animal a);

/*Change les coord d un animal (le deplace)
@param[in/out] l animal
@param[in] nouvelle coordonnee de l animal
*/
void changeCoordAnimal(Animal &a, Coord c);

/*Augmente le niveau de nourriture du renard quand il mange un lapin
@param[in/out] l animal
*/
void mangeRenard(Animal &a);

/*Diminue le niveau de nourriture du renard de 1
@param[in/out] l animal
*/
void faimRenard(Animal &a);

/*Verifie si le renard est mort de faim
@param[in] l animal
@return true si son niveau de nourriture est egal a 0, false sinon
*/
bool mortAnimal(Animal a);

/*Verifie si un animal est vide
@param[in] l animal
@param[in] le nombre de voisins vides autour du lapin dans la grille
@return true si l animal de reproduit, false sinon
*/
bool seReproduitAnimal(Animal a, int nbVoisinsVides);


#endif // ANIMAUX_HPP_INCLUDED
