#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>

#include "Animaux.hpp"

using namespace std;



float hasard(){
	return float(rand()) / float(RAND_MAX);
}



Animal creerAnimal(Espece E, Coord c){
	Animal a;
	a.espece = E;
	a.coord = c;
	if (E == Renard){
		a.food = FoodInit;
	} else {
		a.food = -1;
	}
	return a;
}

Coord coordAnimal( Animal a){
	return a.coord;
}

Espece especeAnimal( Animal a){
	return a.espece;
}

int nourritureRenard(Animal a){
	return a.food;
}

bool estVide(Animal a){
	if (especeAnimal(a) == Vide){
		return true;
	} else {
		return false;
	}
}

void changeCoordAnimal(Animal &a, Coord c){
	a.coord = c;
}

void mangeRenard(Animal &a){
	if (especeAnimal(a) == Renard){
		a.food += FoodLapin;
	}else{
		cout << "N est pas un renard !!" << endl;
	}
}

void faimRenard(Animal &a){
	if (especeAnimal(a) == Renard){
		a.food --;
	}else{
		cout << "N est pas un renard !!" << endl;
	}
}

bool mortAnimal(Animal a){
	if (especeAnimal(a) == Renard){
		if (nourritureRenard(a) == 0){
			return true;
		} else {
			return false;
		}
	}
    return false;
}


bool seReproduitAnimal(Animal a, int nbVoisinsVides){
	if (especeAnimal(a) == Renard){
		return ((nourritureRenard(a) >= FoodReprod) && (hasard() < ProbBirthRenard));
	} else if (especeAnimal(a) == Lapin){
		return ((nbVoisinsVides >= MinFreeBirthLapin) && (hasard() < ProbBirthLapin));
	} else {
		return false;
	}
}