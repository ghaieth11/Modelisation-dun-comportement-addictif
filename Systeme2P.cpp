#include <iostream>
#include <cmath>
#include <random>
#include "Systeme.hpp"
#include "Personne.hpp"
#include "Systeme2P.hpp"

// Constructeur du système à deux personnes
Systeme2P::Systeme2P(Personne &person1, Personne &person2)
    : P1(person1), P2(person2), Systeme() // Liste d'initialisation pour les références
{
    alpha = 0.1;
    beta = 0.1;
    gamma = 0.1;
    
    // Réservation des vecteurs p1 et p2
    p1.resize(nbrsemaines);
    p2.resize(nbrsemaines);

}

// Méthode de résolution du système pour deux personnes
void Systeme2P::SolveSystem() {
    // Saisir les paramètres pour P1
    float d1 = P1.getd();
    float p1_val = P1.getp();
    float q1 = P1.getq();
    float Sm1 = P1.getSm();
    float h1 = p1_val * Sm1; 
    float k1 = h1 / q1; 
    float b1 = 2 * d1 / q1;

    // Saisir les paramètres pour P2
    float d2 = P2.getd();
    float p2_val = P2.getp();
    float q2 = P2.getq();
    float Sm2 = P2.getSm();
    float h2 = p2_val * Sm2; 
    float k2 = h2 / q2; 
    float b2 = 2 * d2 / q2;

    // Réserver de la mémoire pour les vecteurs de P1 et P2
    P1.getA().resize(nbrsemaines);
    P1.getC().resize(nbrsemaines);
    P1.getE().resize(nbrsemaines);
    P1.getS().resize(nbrsemaines);
    P1.getV().resize(nbrsemaines);
    P1.getPsi().resize(nbrsemaines);

    P2.getA().resize(nbrsemaines);
    P2.getC().resize(nbrsemaines);
    P2.getE().resize(nbrsemaines);
    P2.getS().resize(nbrsemaines);
    P2.getV().resize(nbrsemaines);
    P2.getPsi().resize(nbrsemaines);

    // Création d'un générateur de nombres aléatoires pour générer des événements Poisson
    std::random_device rd;
    std::mt19937 gen(rd()); // Générateur Mersenne Twister

    for (int t = 0; t < nbrsemaines - 1; t++) {
        // Mise à jour de C(t+1) pour P1 et P2
        P1.getC()[t + 1] = (1 - d1) * P1.getC()[t] + alpha * P2.getA()[t] * P1.getC()[t] + b1 * std::min(1.0f, 1.0f - P1.getC()[t]) * P2.getA()[t];

        P2.getC()[t + 1] = (1 - d2) * P2.getC()[t] + alpha * P1.getA()[t] * P2.getC()[t] + b2 * std::min(1.0f, 1.0f - P2.getC()[t]) * P1.getA()[t];

        // Mise à jour de S(t+1) pour P1 et P2 en utilisant les valeurs locales de h et k
        P1.getS()[t + 1] = P1.getS()[t] + p1[t] * std::max(0.0f, Sm1 - P1.getS()[t]) - h1 * P1.getC()[t] - k1 * P2.getA()[t];

        P2.getS()[t + 1] = P2.getS()[t] + p2[t] * std::max(0.0f, Sm2 - P2.getS()[t]) - h2 * P2.getC()[t] - k2 * P1.getA()[t];

        // Mise à jour de E(t+1) pour P1 et P2
        P1.getE()[t + 1] = P1.getE()[t] - me;
        P2.getE()[t + 1] = P2.getE()[t] - me;

        // Mise à jour de A(t+1) pour P1 et P2
        std::poisson_distribution<int> poisson_dist(lambda[t]); // Distribution de Poisson
        int nb_alea1 = poisson_dist(gen);
        int nb_alea2 = poisson_dist(gen);

        P1.getA()[t + 1] = P1.getV()[t + 1] + nb_alea1 * q1 * (1 - P1.getV()[t + 1])/Rm;
        P2.getA()[t + 1] = P2.getV()[t + 1] + nb_alea2 * q2 * (1 - P2.getV()[t + 1])/Rm;

        // Mise à jour de Psi(t+1) pour P1 et P2
        P1.getPsi()[t + 1] = P1.getC()[t + 1] - P1.getS()[t + 1] - P1.getE()[t + 1];
        P2.getPsi()[t + 1] = P2.getC()[t + 1] - P2.getS()[t + 1] - P2.getE()[t + 1];

        // Mise à jour de V(t+1) pour P1 et P2 (borné entre 0 et 1)
        P1.getV()[t + 1] = std::min(1.0f, std::max(0.0f, P1.getPsi()[t + 1]));
        P2.getV()[t + 1] = std::min(1.0f, std::max(0.0f, P2.getPsi()[t + 1]));

        p1[t] = P1.getp() + beta * exp(-gamma * P1.getA()[t]);
        p2[t] = P2.getp() + beta * exp(-gamma * P2.getA()[t]);
    }
    p1[nbrsemaines-1] = P1.getp() + beta * exp(-gamma * P1.getA()[nbrsemaines-1]);
    p2[nbrsemaines-1] = P2.getp() + beta * exp(-gamma * P2.getA()[nbrsemaines-1]);
}

std::vector<float>& Systeme2P::getp1() {
    return p1;
}

std::vector<float>& Systeme2P::getp2() {
    return p2;
}
