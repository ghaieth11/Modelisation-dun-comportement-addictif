#include <iostream>
#include <vector>
#include <matplot/matplot.h>
#include "Personne.hpp"
#include "Systeme1P.hpp"
#include "Systeme2P.hpp"



int main(){


// Créer une instance de Personne
    Personne P1(0, 0, 0, 0.5, 0.3, 0.2, 0.8);
    Personne P2(0, 0, 0, 0.5, 0.3, 0.2, 0.8);

    // Créer des systèmes
    Systeme1P systeme1(P1);
    Systeme2P systeme2(P1, P2);

    // Simuler pour un nombre de semaines
    int nbrSemaines = 10;
    for (int t = 0; t < nbrSemaines; ++t) {
        systeme1.UpdateValues(t);
        systeme2.UpdateValues(t);
    }
    // Création d'un vecteur pour l'axe des semaines
    std::vector<double> semaine(nbrSemaines);
    for (size_t i = 0; i < semaine.size(); ++i) {
        semaine[i] = static_cast<double>(i);
    }
    hold(on);
    // Tracé des résultats
    plot(weeks, P1.getC(), "r-")->display_name("Intensité de la fringale (C)");
    plot(weeks, P1.getS(), "b-")->display_name("Intensité du self-contrôle (S)");
    plot(weeks, P1.getE(), "g-")->display_name("Influence sociétale (E)");
    plot(weeks, P1.getV(), "m-")->display_name("Niveau de vulnérabilité (V)");
    plot(weeks, P1.getA(), "c-")->display_name("Addiction exercée (A)");

    // Définir les limites de l'axe des ordonnées si nécessaire
    ylim({0, 1});

    // Ajout des étiquettes des axes et du titre
    xlabel("Temps (semaines)");
    ylabel("Intensité/Niveau");
    title("Évolution des variables du modèle d’addiction au fil du temps");


    // Afficher le graphique
    show();
    hold(off);
    return 0;
}