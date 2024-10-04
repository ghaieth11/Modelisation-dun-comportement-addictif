#include "Personne.hpp"

// Constructeur par défaut
Personne::Personne() : C0(0), S0(0), E0(0), Sm(0), p(0), d(0), q(0) {}

// Constructeur par copie
Personne::Personne(const Personne& P) {
    C0 = P.C0;
    S0 = P.S0;
    E0 = P.E0;
    Sm = P.Sm;
    p = P.p;
    d = P.d;
    q = P.q;
    C = P.C;
    S = P.S;
    E = P.E;
    V = P.V;
    A = P.A;
    Psi = P.Psi;
}

// Constructeur spécifique
Personne::Personne(float C0, float S0, float E0, float Sm, float p, float d, float q) 
    : C0(C0), S0(S0), E0(E0), Sm(Sm), p(p), d(d), q(q) {}

// Getters pour accéder aux attributs
std::vector<float>& Personne::getC(){
    return C;
}

std::vector<float>& Personne::getE(){
    return E;
}

std::vector<float>& Personne::getS(){
    return S;
}

std::vector<float>& Personne::getV(){
    return V;
}

std::vector<float>& Personne::getA(){
    return A;
}

