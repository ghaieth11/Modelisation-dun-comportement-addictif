#include <vector>
#include "Personne.hpp"
#include "Systeme.hpp"
#include "Systeme1P.hpp"
#include "Systeme2P.hpp"
#include <iostream>
#include <fstream>
#include "graph.hpp"
using namespace std;

int main(){


// Créer une instance de Personne
    Personne P1(0.2, 0.5, 0, 0.5, 0.3, 0.2, 0.8);
    P1.Ordinaire();
    Personne P2(0, 0, 0, 0.5, 0.3, 0.2, 0.8);
    P2.Addict();

    // Créer des systèmes
    Systeme2P systeme1(P1,P2);
    //Systeme2P systeme2(P1, P2);

    systeme1.SolveSystem();
    //systeme2.SolveSystem();
    
    // Création d'un vecteur pour l'axe des semaines
    Graphique g1("courbeunepersonne",P1);
    Graphique g2("courbe2P",P1,P2);
    g2.Tracer();
}