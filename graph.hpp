#ifndef __GRAPHIQUE_HPP__
#define __GRAPHIQUE_HPP__

#include "Personne.hpp"
#include <fstream>
#include <string>

class Graphique {
    private: 
        std::string nomFichier_;
        Personne& P1_;
        Personne& P2_;

    public: 
        // Constructeur pour un seul objet Personne
        Graphique(const std::string& nomFichier, Personne& P1) 
            : nomFichier_(nomFichier + ".csv"), P1_(P1), P2_(P1) {}

        // Constructeur pour deux objets Personne
        Graphique(const std::string& nomFichier, Personne& P1, Personne& P2)
            : nomFichier_(nomFichier + ".csv"), P1_(P1), P2_(P2) {}

        // Méthode pour tracer les données de la/les personne(s)
        void Tracer() {
            std::ofstream file(nomFichier_);
            if (!file.is_open()) {
                throw std::ios_base::failure("Erreur lors de l'ouverture du fichier");
            }

            // Vérifie si P1 et P2 sont la même personne ou non
            if (&P1_ == &P2_) {
                // Cas d'une seule personne
                file << "# Semaine,C,S,E,V,A,Psi\n";
                for (int i = 0; i < 400; i++) {
                    file << i << ", " 
                         << P1_.getC()[i] << ", " 
                         << P1_.getS()[i] << ", " 
                         << P1_.getE()[i] << ", " 
                         << P1_.getV()[i] << ", " 
                         << P1_.getA()[i] << ", " 
                         << P1_.getPsi()[i] << "\n";
                }
            } else {
                // Cas de deux personnes distinctes
                file << "# Semaine,C1,S1,C2,S2\n";
                for (int i = 0; i < 400; i++) {
                    file << i << ", " 
                         << P1_.getC()[i] << ", " 
                         << P1_.getS()[i] << ", " 
                         << P2_.getC()[i] << ", " 
                         << P2_.getS()[i] << "\n";
                }
            }

            file.close();
        }
};

#endif // __GRAPHIQUE_HPP__
