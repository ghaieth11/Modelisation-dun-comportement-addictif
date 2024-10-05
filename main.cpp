#include <iostream>
#include <vector>
#include <matplot/matplot.h>
#include "Personne.hpp"
#include "Systeme1P.hpp"
#include "Systeme2P.hpp"
#include "Graphique.hpp"

int main() {
    // Créer une instance de Personne
    Personne P1(0, 0, 0, 0.5, 0.3, 0.2, 0.8);
    Personne P2(0, 0, 0, 0.5, 0.3, 0.2, 0.8);

    // Créer des systèmes
    Systeme1P systeme1(P1);
    Systeme2P systeme2(P1, P2);

    // Résoudre les systèmes
    systeme1.SolveSystem();
    systeme2.SolveSystem();

    // Création du graphique
    Graphique graphique;

    // Créer un vecteur pour l'axe des semaines
    std::vector<double> semaines(nbrSemaines);
    for (size_t i = 0; i < semaines.size(); ++i) {
        semaines[i] = static_cast<double>(i);
    }

    // Ajouter des courbes pour le premier système (P1)
    graphique.ajouterCourbe(semaines, P1.getC(), "Intensité de la fringale (C)", "r-");
    graphique.ajouterCourbe(semaines, P1.getS(), "Intensité du self-contrôle (S)", "b-");
    graphique.ajouterCourbe(semaines, P1.getE(), "Influence sociétale (E)", "g-");
    graphique.ajouterCourbe(semaines, P1.getV(), "Niveau de vulnérabilité (V)", "m-");
    graphique.ajouterCourbe(semaines, P1.getA(), "Addiction exercée (A)", "c-");

    // Ajouter des courbes pour le deuxième système (P2) si besoin
    // Exemple d'ajout de courbes pour P2 (similaire à P1)
    graphique.ajouterCourbe(semaines, P2.getC(), "Intensité de la fringale P2 (C)", "r--");
    graphique.ajouterCourbe(semaines, P2.getS(), "Intensité du self-contrôle P2 (S)", "b--");

    // Afficher le graphique
    graphique.afficher();

    return 0;
}
