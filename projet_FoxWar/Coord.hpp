#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

const int TailleGrille=20;

struct Coord {
	int x, y;
};



struct EnsCoord {
	Coord tab[TailleGrille];
	int nb;
};
 
/////////////////////////////////////////////////////////////////////////////////
//                         Fonctions du type abstrait                          //
/////////////////////////////////////////////////////////////////////////////////

/** Crée des coordonnée
 *@param entier x et y
 *@return la coordonnée (x,y)
 **/
Coord creerCoord (int x, int y);


/** Affiche des coordonnée
 *@param coordonnée c 
 **/
void afficheCoord(Coord c);


/** Affiche x
 *@param coordonnée c 
 *@return x
 **/
int getX(Coord c);


/** Affiche y
 *@param coordonnée c 
 *@return y
 **/
int getY(Coord c);


/** Vérifie si deux coordonnées sont égales
 *@param c1 et c2;
 *@return true si elles sont égales
 **/
bool egalCoord(Coord c1, Coord c2);


/** Affiche les coordonnées
 *@param un tableau de coordonnées e
 **/
void afficheEC(EnsCoord e);


/** Renvoie un ensemble de coordonnées
 *@return un EC vide
 **/
EnsCoord CreerEC();

   
/** Ajoute une coordonnée à l'ensemble ec
 *@param ensemble de coordonnées ec
 *@param coordonnée c
 **/
EnsCoord ajouteEC(EnsCoord ec, Coord c);

/** Retourne le nombre d'élèment d'un ensemble de coordonnée
 *@param ensemble de coordonnées ec
 *@return nb
 **/
int cardEC (EnsCoord ec);



/** Supprime une coordonnée d'un ensemble de coordonnée
 *@param[in/out] ensemble de coordonnées ec
 *@param Coordonée c
 **/
void supprimeEC( EnsCoord &ec, Coord c);



/** Choisit aléatoirement une coordonnée d'un ensemble de coordonnée
 *@param ensemble de coordonnées ec
 *@return coordonnée au hasard 
 **/
Coord hasardEC(EnsCoord ec);




#endif // COORD_HPP_INCLUDED



