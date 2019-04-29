#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED


#include "Animaux.hpp"
#include "Coord.hpp"

//const int TailleGrille = 20;  (deja def Coord.hpp)
const float probRenard = 0.07;
const float probLapin = 0.20;


struct Grille {
	Animal tab[TailleGrille][TailleGrille];
};



/////////////////////////////////////////////////////////////////////////////////
//                         Fonctions du type abstrait                          //
/////////////////////////////////////////////////////////////////////////////////


/*Initialise une grille vide
@param[out] La grille
*/
void grilleVide(Grille &g);

/*Copie la grille g1 dans la grille g2
@param[in] La grille a copier
@param[out] la grille dans laquelle copier
*/
void copieGrille(Grille g1, Grille &g2);

/*Accede a un animal a modifier dans la qrille, situe aux coordonnées indiquees
@param[in] La grille dans laquelle se trouve l animal
@param[in] la coordonee de l animal
@return l animal
*/
Animal getAnimal(Grille g, Coord c);

/*Range un animal dans la grille dans la position indiquee par ses coordonnees
@param[in/out] La grille dans laquelle ranger l animal
@param[in] l animal
*/
void setAnimal(Grille &g, Animal a);

/*Initialise une grille avec 7% de renards, 20% de Lapins et 73% de vide.
@param[out] La grille
*/
void initialiseGrille(Grille &g);

/*Verifie que les coordonees de l animal dans la grille correspondent à celles dans sa structure. Renvoie un message d erreur le cas echeant
@param[in] La grille
*/
void verifieGrille(Grille g);

/*Trouve les voisins directs d'une coordonnée dans un tableau de coord
@param[in] Coord dont on cherche les voisins
@return EnsCoord l'ensemble contenant les coordonnées des voisins
*/
EnsCoord trouverVoisin(Coord c);

/*Trouve les coordonnee d une espece parmis les voisins d une coordonee dans une grille
@param[in] la grille sur laquelle on travaille
@param[in] la coordonnee autour de laquelle chercher
@param[in] l espece cherchee
@return EnsCoord l'ensemble contenant les coordonnées des voisins de l espece demandee
*/
EnsCoord voisins(Grille g, Coord c, Espece e);

/*Affiche la grille : R pour les renard, L pour les lapins, O pour les cases vides
@param[in] la grille
*/
void afficheGrille(Grille g);


#endif // GRILLE_HPP_INCLUDED