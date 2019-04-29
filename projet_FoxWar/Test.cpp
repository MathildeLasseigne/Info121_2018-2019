#include "Coord.cpp"
#include <iostream>

/** Infrastructure minimale de test **/
#define ASSERT(test)                                                           \
    if (!(test))                                                               \
    cout << "Test failed in file " << __FILE__ << " line " << __LINE__         \
         << ": " #test << endl

using namespace std;

// TESTS
void testCoord(){
    Coord c;
    c.x = 2;
    c.y = 3;
    ASSERT(egalCoord(creerCoord (2,3),c));
 }

void testegalCoord() {
    ASSERT(egalCoord(creerCoord(4,4),creerCoord(4,4))== true);
    ASSERT(egalCoord(creerCoord(4,1),creerCoord(4,5))== false);
}

void testEgalCoord(){
    Coord c1; 
    Coord c2;
    c1.x=1;
    c1.y=2;
    c2.x=1;
    c2.y=2;
    ASSERT(egalCoord(c1,c2)==true);
}


void testcardEC(){
    EnsCoord ec = CreerEC();
    ajouteEC(ec, creerCoord(4,4));
    
    ASSERT(cardEC(ec)==1);
}



int main(){
   
    testegalCoord();
    testCoord();
    Coord c1 = creerCoord(2,1);
    afficheCoord(c1);
    cout << endl;
    testEgalCoord();
    testcardEC();
    
    //tests ajouteEC
    cout << "Tests ajouteEC :" << endl;
    EnsCoord ec = CreerEC();
    ajouteEC(ec, creerCoord(4,4));
    afficheEC(ec);
    Coord c = creerCoord(1,4);
    ajouteEC(ec, c);
    afficheEC(ec);
    cout << endl << "Tests supprimeEC :" << endl;
    supprimeEC(ec, c);
    afficheEC(ec);

    return 0;
 }