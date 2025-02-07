#ifndef GRAPHIQUE_HPP
#define GRAPHIQUE_HPP

#include <vector>
#include <string>
#include <matplot/matplot.h>

class Graphique {
public:
    Graphique();  // Constructeur

    // Méthode pour ajouter une courbe
    void ajouterCourbe(const std::vector<float>& x, const std::vector<float>& y, const std::string& label, const std::string& couleur);

    // Méthode pour afficher le graphique avec les courbes ajoutées
    void afficher();

private:
    std::vector<std::vector<float>> dataX; // Stockage des données X (temps)
    std::vector<std::vector<float>> dataY; // Stockage des données Y (valeurs des variables)
    std::vector<std::string> labels;        // Noms des courbes
    std::vector<std::string> couleurs;      // Couleurs des courbes
};

#endif // GRAPHIQUE_HPP
