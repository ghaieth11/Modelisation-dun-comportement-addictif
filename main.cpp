#include <vector>
#include "Personne.hpp"
#include "Systeme.hpp"
#include "Systeme1P.hpp"
#include "Systeme2P.hpp"
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include "graph.hpp"
using namespace std;
=======
#include <chrono>


using namespace matplot;
>>>>>>> c7695a7 (save before pull)

int main(){

auto start = std::chrono::high_resolution_clock::now();
// Créer une instance de Personne
<<<<<<< HEAD
    Personne P1(0.2, 0.5, 0, 0.5, 0.3, 0.2, 0.8);
    P1.Insensible();
    Personne P2(0, 0, 0, 0.5, 0.3, 0.2, 0.8);
    P2.Addict();

    // Créer des systèmes
    Systeme2P systeme1(P1,P2);
    //Systeme2P systeme2(P1, P2);

    systeme1.SolveSystem();
    //systeme2.SolveSystem();
    
    // Création d'un vecteur pour l'axe des semaines
    std::vector<double> weeks(400);
    for (size_t i = 0; i < weeks.size(); ++i) {
        weeks[i] = static_cast<double>(i);
    }
    ofstream file("courbe_une_personne.csv");
    file << "# Semaine,C,S,E,V,A,Psi\n";
    for (int i = 0 ; i < 400 ; i++){
        file << i << " " << P1.getC()[i] << " " << P1.getS()[i] << " " << P1.getE()[i]
        << " " << P1.getV()[i] << " " << P1.getA()[i] << P1.getPsi()[i] << "\n";
    }
    file.close();
}