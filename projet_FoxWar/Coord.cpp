#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Coord.hpp"

using namespace std;


Coord creerCoord (int x, int y){
	Coord c;
	c.x=x;
	c.y=y;
	return c;
}


void afficheCoord(Coord c){
     cout<<c.x<<", "<<c.y;
}

int getX(Coord c){
    int x=c.x;
    return x;
}


int getY(Coord c){
    int y=c.y;
    return y;
}


bool egalCoord(Coord c1, Coord c2){ 
    if(c1.x==c2.x and c1.y==c2.y){
        return true;
    } else {
        return false;  
    }
}



void afficheEC(EnsCoord e){
	for (int i=0; i<e.nb; i++){
		afficheCoord(e.tab[i]);		
	}	
}

EnsCoord CreerEC(){
	EnsCoord e;
	e.nb=0;
	return e;
}


void ajouteEC(EnsCoord &ec, Coord c){
	ec.tab[ec.nb]=c;
    ec.nb+=1;
}
 
int cardEC (EnsCoord ec){
    return ec.nb;
}
      
     
void supprimeEC( EnsCoord &ec, Coord c){
	int i=0; 
	while (i < ec.nb && not egalCoord(ec.tab[i], c)){
        i++;
    }
	if (i == ec.nb) { 	
		cout<<"La valeur ";
        afficheCoord(c);
        cout << " n'existe pas dans ce tableau" << endl;
	} else { 
		for (int j = i+1 ; j <ec.nb ; j++) { 
			ec.tab[j-1] = ec.tab[j];
		}
		ec.nb--;
	}
}
	

	
Coord hasardEC(EnsCoord ec){
	int nb = cardEC(ec);
	//srand(time(NULL));//
	int r = rand()%nb;
	Coord c; 
	c = ec.tab[r];
	return c; 
}


