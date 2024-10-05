#include "Graphique.hpp"
#include <matplot/matplot.h>
#include <iostream>

using namespace matplot;

Graphique::Graphique() {
    // Initialisation si besoin
}

void Graphique::ajouterCourbe(const std::vector<float>& x, const std::vector<float>& y, const std::string& label, const std::string& couleur) {
    dataX.push_back(x);
    dataY.push_back(y);
    labels.push_back(label);
    couleurs.push_back(couleur);
}

void Graphique::afficher() {
    using namespace matplot;

    hold(on); // Garder les tracés superposés

    for (size_t i = 0; i < dataX.size(); ++i) {
        plot(dataX[i], dataY[i], couleurs[i])->display_name(labels[i]);
    }

    ylim({0, 1}); // Limite de l'axe des ordonnées

    xlabel("Temps (semaines)");
    ylabel("Intensité/Niveau");
    title("Évolution des variables du modèle d’addiction au fil du temps");

    legend();  // Affiche la légende des courbes
    show();    // Affiche le graphique
    hold(off); // Libérer le hold après affichage
}
