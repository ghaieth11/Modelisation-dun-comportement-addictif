#ifndef __GRAPHIQUE_HPP__
#define __GRAPHIQUE_HPP__

#include "Personne.hpp"
#include <fstream>
#include <string>

class Graphique {
    private: 
        std::string nomFichier_;
        Personne& P1_;

    public: 
        // Constructeur qui initialise le nom du fichier et la référence à P1
        Graphique(const std::string& nomFichier, Personne& P1) 
            : nomFichier_(nomFichier + ".csv"), P1_(P1) {}

        // Méthode pour tracer les données de la personne
        void Tracer1P() {
            std::ofstream file(nomFichier_);
            if (!file.is_open()) {
                throw std::ios_base::failure("Erreur lors de l'ouverture du fichier");
            }

            // Écriture de l'en-tête du fichier CSV
            file << "# Semaine,C,S,E,V,A,Psi\n";

            // Écriture des données
            for (int i = 0; i < 400; i++) {
                file << i << ", " 
                     << P1_.getC()[i] << ", " 
                     << P1_.getS()[i] << ", " 
                     << P1_.getE()[i] << ", " 
                     << P1_.getV()[i] << ", " 
                     << P1_.getA()[i] << ", " 
                     << P1_.getPsi()[i] << "\n";
            }

            file.close();
        }
};

#endif // __GRAPHIQUE_HPP__
