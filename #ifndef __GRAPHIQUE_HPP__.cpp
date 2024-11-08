#ifndef __GRAPHIQUE_HPP__
#define __GRAPHIQUE_HPP__
#include "Personne.hpp"
#include <fstream> 
#include <string>

class Graphique {
    private : 
        std :: string nomFichier_;
        Personne& P1_;
    public : 
        Graphique(string nomFichier, P1) : nomFichier_(nomFichier) P1_(P1){}
        void Tracer1P() {
            ofstream file(nomFichier_.+"csv");
            file << "# Semaine,C,S,E,V,A,Psi\n";
            for (int i = 0 ; i < 400 ; i++){
                file << i << " " << P1.getC()[i] << " " << P1.getS()[i] << " " << P1.getE()[i]
                << " " << P1.getV()[i] << " " << P1.getA()[i] << P1.getPsi()[i] << "\n";
            }
        file.close();
        }
}