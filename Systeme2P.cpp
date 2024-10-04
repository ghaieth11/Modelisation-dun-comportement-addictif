#include <iostream>
#include <cmath>
#include "Systeme.hpp"
#include "Personne.hpp"
#include "Systeme2P.hpp"


Systeme2P::Systeme2P(Personne &person1, Personne &person2)
    : P1(person1), P2(person2) // Liste d'initialisation pour les références
{
    alpha  = 0.1;
    beta = 0.1;
    gamma = 0.1;
    for (int i = 0; i < Systeme::nbrsemaines; i++ ) {
    p1[i] = P1.getp() + beta * exp(-gamma * P1.getA()[i]);
    p2[i] = P2.getp() + beta * exp(-gamma * P2.getA()[i]);
    }
}

Systeme2P::SolveSystem() {


}
