#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>

#include "Grille.hpp"

using namespace std;

/*Creer un EC contenant toutes les coordonnees d une espece dans une grille
@param[in] La grille dans laquelle chercher
@param[in] l espece a chercher
@return l EC
*/
EnsCoord toutEspece(Grille g, Espece e){
	Animal a;
	EnsCoord ec = CreerEC();
	for (int i = 0; i < TailleGrille; i++ ){
		for (int j = 0; j < TailleGrille; j++ ){
			Coord c = creerCoord(i, j);
			a = getAnimal( g, c);
			if (especeAnimal(a) == e ){
				ajouteEC(ec, c);
			}
		}
	}
	return ec;
}

/*Verifie si un renard est a proximite d un lapin et si oui le fait attaquer en modifiant sa coord /!\ pas dans la grille !
@param[in] La grille dans laquelle est le renard et les lapins
@param[in/out] le renard
@return true si le retard a attaque(et modifie sa coord), false sinon
*/
bool attaqueRenard(Grille g, Animal &a){
	if( especeAnimal(a) == Renard ){
		EnsCoord ec = voisins(g, coordAnimal(a), Lapin);
		if(cardEC(ec) == 0 ){
			return false;
		} else {
			Coord c = hasardEC(ec);
			changeCoordAnimal(a, c);
			mangeRenard(a);
			return true;
		}
	} else {
		cout << "N est pas un renard ! Ne peut pas attaquer !" << endl;
        return false;
	}
}

/*Deplace un animal selon sa specificite d une grille dans l autre
@param[in] La grille dans laquelle est le renard et les lapins
@param[in/out] La grille dans laquelle deposer l animal
@param[in/out] l animal
*/
void deplaceAnimal(Grille old, Grille &nouv, Animal &a){
	Coord res;
	Coord c = coordAnimal(a);
	EnsCoord ec = voisins(old, c, Vide);
	
	if( especeAnimal(a) == Renard ){
		if(not mortAnimal(a)){
			if(not attaqueRenard(old, a)){
				res = hasardEC(ec);
				changeCoordAnimal(a, res);
				faimRenard(a);
			}
		}
	} else {
		res = hasardEC(ec);
		changeCoordAnimal(a, res);
	}
	setAnimal(nouv, a);
}

/*Deplace tous les animaux d une espece d une grille dans l autre
@param[in] La grille dans laquelle sont les animaux
@param[in/out] La grille dans laquelle les deplacer
@param[in] l espece a deplacer
*/
void deplaceTousEspece(Grille old, Grille &nouv, Espece e){
	EnsCoord Ensemble = toutEspece(old, e);
	while (cardEC(Ensemble) != 0){
		Coord c = hasardEC(Ensemble);
		Animal a = getAnimal(old, c);
		deplaceAnimal(old, nouv, a);
		int nbVide = cardEC(voisins(old,c,Vide));
		if(seReproduitAnimal(a,nbVide)){
			setAnimal(nouv, creerAnimal(e,c));
		}
		supprimeEC(Ensemble, c);
	}
}

int main(){
	srand(time(NULL));  //Pour que la fonction aleatoire ne soit pas tt le temps la meme
	Grille old, current;
	initialiseGrille(current);
	while (true){
		verifieGrille(current);
		afficheGrille(current);
		copieGrille(current, old);
		grilleVide(current);
		deplaceTousEspece(old, current, Lapin);
		deplaceTousEspece(old, current, Renard);
	}
	
	
	return 0;
}
