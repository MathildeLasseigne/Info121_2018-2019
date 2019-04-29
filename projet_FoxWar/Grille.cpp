#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>

#include "Grille.hpp"

using namespace std;




void grilleVide(Grille &g){
	for (int i = 0; i < TailleGrille; i++ ){
		for (int j = 0; j < TailleGrille; j++ ){
			g.tab[i][j] = creerAnimal(Vide, creerCoord(i,j));
		}
	}
}


void copieGrille(Grille g1, Grille &g2){
	for (int i = 0; i < TailleGrille; i++ ){
		for (int j = 0; j < TailleGrille; j++ ){
			g2.tab[i][j] = g1.tab[i][j];
		}
	}
}

Animal getAnimal(Grille g, Coord c){
	int x = getX(c);
	int y = getY(c);
	Animal a = g.tab[x][y];
	return a;
}

void setAnimal(Grille &g, Animal a){
	Coord c = coordAnimal(a);
	int x = getX(c);
	int y = getY(c);
	g.tab[x][y] = a;
}

void initialiseGrille(Grille &g){
	Espece E;
	float alea;
	for (int i = 0; i <= TailleGrille-1; i++ ){
		for (int j = 0; j <= TailleGrille-1; j++ ){
			alea = hasard();
			if(alea <= probRenard){
				E = Renard;
			} else if ( alea <= probRenard + probLapin){  //Sinon le probRenard mange une partie du probLapin
				E = Lapin;
			} else {
				E = Vide;
			}
			setAnimal( g, creerAnimal(E, creerCoord(i,j)) );
		}
	}
}

void verifieGrille(Grille g){
	for(int i = 0; i < TailleGrille; i++){
		for (int j = 0; j < TailleGrille; j++){
			Coord c1 = creerCoord(i,j);
			Coord c2 = coordAnimal( getAnimal(g, c1) );
			if( not egalCoord(c1, c2)){
				cout << "Les coordonnees des animaux ne sont pas les bonnes en " << i <<", "<<j << endl;
			}
		}
	}
}

EnsCoord trouverVoisin(Coord c){
	EnsCoord res = CreerEC();
	int x, y, minx, maxx, miny, maxy;
	x = getX(c);
	y = getY(c);
	if(x==0){
		minx = x;
	}else{
		minx = x-1;
	}
	if(x == TailleGrille-1){
		maxx = x;
	}else{
		maxx = x+1;
	}
	if(y==0){
		miny = y;
	}else{
		miny = y-1;
	}
	if(y == TailleGrille-1){
		maxy = y;
	}else{
		maxy = y+1;
	}
	for (int i = minx; i <=maxx;i++){
		for (int j = miny; j <=maxy;j++){
			ajouteEC(res, creerCoord(i,j));
		}
	}
	supprimeEC(res, c);
	return res;
}

EnsCoord voisins(Grille g, Coord c, Espece e){
	EnsCoord ec = CreerEC();
	EnsCoord vois = trouverVoisin(c);
	int nb = cardEC(vois);
	Coord co;
	Animal a;
	for (int i = 0; i <nb; i++ ){
		co = hasardEC(vois);
		a = getAnimal(g, co);
		if (especeAnimal(a) == e){
			ajouteEC(ec, co);
		}
	}
	return ec;
}

/*void afficheGrille(Grille g){
	for(int i = 0; i < TailleGrille; i++){
		for (int j = 0; j < TailleGrille; j++){
			Animal a = getAnimal(g, creerCoord(i,j));
			if (especeAnimal(a) == Renard){
				cout << "R ";
			} else if (especeAnimal(a) == Lapin){
				cout << "L ";
			} else if (especeAnimal(a) == Vide){
				cout << "O ";
			}
		}
		cout << endl;
	}
}*/


/*
void afficheGrille(Grille g){
	for(int i = 0; i < TailleGrille; i++){
		for (int j = 0; j < TailleGrille; j++){
			Animal a = getAnimal(g, creerCoord(i,j));
			string res;
			Espece e = especeAnimal(a);
			switch(e){            //https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c pour les couleurs
				case 0 :
					cout << "\033[1;37m" <<" L "; break;       //Couleur Blanche
				case 1 :
					cout << "\033[1;31m" << " R "; break;     //Couleur Rouge
				case 2 :
					cout << "\033[1;30m" << " O "; break;    //Couleur Noir
				default : 
					cout << "Espece invalide, ne peut pas afficher ! ";
			}
		}
		cout << endl;
	}
}
*/


void afficheGrille(Grille g){
	for(int i = 0; i < TailleGrille; i++){
		for (int j = 0; j < TailleGrille; j++){
			Animal a = getAnimal(g, creerCoord(i,j));
			string res;
			Espece e = especeAnimal(a);
			switch(e){            //https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c pour les couleurs
				case Lapin :
					cout << "\033[1;37m" <<" L "; break;       //Couleur Blanche
				case Renard :
					cout << "\033[1;31m" << " R "; break;     //Couleur Rouge
				case Vide :
					cout << "\033[1;30m" << " O "; break;    //Couleur Noir
				default : 
					cout << "Espece invalide, ne peut pas afficher ! ";
			}
		}
		cout << endl;
	}
}
