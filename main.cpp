#include <vector>
#include <matplot/matplot.h>
#include "Personne.hpp"
#include "Systeme1P.hpp"
#include "Systeme2P.hpp"

using namespace matplot;

int main(){


// Créer une instance de Personne
    Personne P1(0.2, 0.5, 0, 0.5, 0.3, 0.2, 0.8);
    Personne P2(0, 0, 0, 0.5, 0.3, 0.2, 0.8);

    // Créer des systèmes
    Systeme1P systeme1(P1);
    Systeme2P systeme2(P1, P2);

    systeme1.SolveSystem();
    systeme2.SolveSystem();
    
    // Création d'un vecteur pour l'axe des semaines
    std::vector<double> weeks(400);
    for (size_t i = 0; i < weeks.size(); ++i) {
        weeks[i] = static_cast<double>(i);
    }
    hold(on);
    // Tracé des résultats
    plot(weeks, P1.getC(), "r-")->display_name("Intensité de la fringale (C)");
    plot(weeks, P1.getS(), "b-")->display_name("Intensité du self-contrôle (S)");
    plot(weeks, P1.getE(), "g-")->display_name("Influence sociétale (E)");
    plot(weeks, P1.getV(), "m-")->display_name("Niveau de vulnérabilité (V)");
    plot(weeks, P1.getA(), "k-")->display_name("Addiction exercée (A)");

    // Définir les limites de l'axe des ordonnées si nécessaire
    //ylim({0, 1});

    // Ajout des étiquettes des axes et du titre
    xlabel("Temps (semaines)");
    ylabel("Intensité/Niveau");
    title("Évolution des variables du modèle d’addiction au fil du temps");


    // Afficher le graphique
    show();
    hold(off);
    return 0;
}