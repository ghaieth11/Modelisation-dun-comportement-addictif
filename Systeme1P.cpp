#include "Systeme1P.hpp"
#include <iostream>
#include <cmath>   
#include <random>

Systeme1P::Systeme1P(const Personne& personne) : P(personne) {
    me=0.01;
    m_lambda=0.001;
    Rm=7;
    lambda.reserve[nbrsemaines];
    for (int i = 0; i < nbrsemaines; i++){
        lambda[i] = 0.2 + i * m_lambda;
    }

}

Systeme1P::SolveSystem(){
    //saisir des parametres qui apparaissent dans le sysème 
    float d = P.getd();
    float p = P.getp();
    float q = P.getq();
    float Sm = P.getSm();
    float h = p * Sm; 
    float k = h / q; 
    float b = 2 * d / q;

    // réserver de la mémoire pour chaque vecteur 
    P.getA().reserve(nbrsemaines);
    P.getC().reserve(nbrsemaines);
    P.getE().reserve(nbrsemaines);
    P.getS().reserve(nbrsemaines);
    P.getV().reserve(nbrsemaines);
    P.getPsi().reserve(nbrsemaines);

    // Création d'un générateur de nombres aléatoires
    std::random_device rd; // Pour obtenir une graine
    std::mt19937 gen(rd()); // Mersenne Twister

    // Mise à jour des attributs de la Personne 
    for (int i = 0; i < nbrsemaines - 1; ++i){
        std::poisson_distribution<int> poisson_dist(lambda[i]); // Distribution de Poisson
        int nb_alea = poisson_dist(gen);
        P.getC[i+1] = (1 - d)*P.getC()[i] + b * std::min(1,1 - P.getC()[i])* P.getA()[i];
        P.getS()[i+1] = P.getS()[i] + p * std::max(0,Sm - P.getS()[i]) - h * P.getC()[i] - k * P.getA()[i];
        P.getE()[i+1] = P.getE()[i] - me;
        P.getA()[i + 1] = P.getV()[i + 1] + nb_alea * q * (1 - P.getV()[i + 1]);
        P.getPsi()[i+1] = P.getC()[i + 1] - P.getS()[i + 1] - P.getE()[i + 1];
        P.getV()[n + 1] = std::min(0, std::max(P.getPsi()[n + 1], 1));

    }
}