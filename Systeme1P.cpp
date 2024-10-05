#include "Systeme1P.hpp"
#include <iostream>
#include <cmath>   
#include <random>

Systeme1P::Systeme1P(Personne& personne) : P(personne), Systeme() {
    
}

void Systeme1P::SolveSystem(){
    //saisir des parametres qui apparaissent dans le sysème 
    float d = P.getd();
    float p = P.getp();
    float q = P.getq();
    float Sm = P.getSm();
    float h = p * Sm; 
    float k = h / q; 
    float b = 2 * d / q;

    // réserver de la mémoire pour chaque vecteur 
    P.getA().resize(nbrsemaines);
    P.getC().resize(nbrsemaines);
    P.getE().resize(nbrsemaines);
    P.getS().resize(nbrsemaines);
    P.getV().resize(nbrsemaines);
    P.getPsi().resize(nbrsemaines);

    // Création d'un générateur de nombres aléatoires
    std::random_device rd; // Pour obtenir une graine
    std::mt19937 gen(rd()); // Mersenne Twister

    // Mise à jour des attributs de la Personne 
    for (int i = 0; i < nbrsemaines - 1; ++i){
        std::poisson_distribution<int> poisson_dist(Systeme::lambda[i]); // Distribution de Poisson
        int nb_alea = poisson_dist(gen);
        P.getC()[i+1] = (1 - d)*P.getC()[i] + b * std::min(1.0f,1 - P.getC()[i])* P.getA()[i];
        P.getS()[i+1] = P.getS()[i] + p * std::max(0.0f,Sm - P.getS()[i]) - h * P.getC()[i] - k * P.getA()[i];
        P.getE()[i+1] = P.getE()[i] - me;
        P.getA()[i + 1] = P.getV()[i + 1] + nb_alea * q * (1 - P.getV()[i + 1]);
        P.getPsi()[i+1] = P.getC()[i + 1] - P.getS()[i + 1] - P.getE()[i + 1];
        P.getV()[i + 1] = std::min(0.0f, std::max(P.getPsi()[i + 1], 1.0f));

    }
}