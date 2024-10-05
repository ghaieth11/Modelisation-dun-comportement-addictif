#include "Personne.hpp"
#include <random>

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
    : C0(C0), S0(S0), E0(E0), Sm(Sm), p(p), d(d), q(q) {
        Initialisation(); // Appel à l'initialisation
    }

// Méthode pour initialiser les tableaux
void Personne::Initialisation(){
    // Initialiser les valeurs de C, S, et E avec les valeurs initiales
    C.resize(2);
    S.resize(2);
    E.resize(2);
    V.resize(2);
    A.resize(2);
    Psi.resize(2);
    
    C[0] = C0;
    S[0] = S0;
    E[0] = E0;
    Psi[0] = C0 - S0 - E0;
    V[0] = std::min(1.0f,std::max(Psi[0],0.0f));
    // Création d'un générateur de nombres aléatoires
    std::random_device rd; // Pour obtenir une graine
    std::mt19937 gen(rd()); // Mersenne Twister
    std::poisson_distribution<int> poisson_dist(0.2); // Distribution de Poisson
    // Générer un nombre aléatoire selon la loi de Poisson
    int nb_alea = poisson_dist(gen);
    A[0] = V[0] + nb_alea * q * (1 - V[0]);
}

// Getters pour accéder aux attributs
float Personne::getd() {
    return d;
}

float Personne::getp() {
    return p;
}

float Personne::getq() {
    return q;
}

float Personne::getSm() {
    return Sm;
}

std::vector<float>& Personne::getC() {
    return C;
}

std::vector<float>& Personne::getE() {
    return E;
}

std::vector<float>& Personne::getS() {
    return S;
}

std::vector<float>& Personne::getV() {
    return V;
}

std::vector<float>& Personne::getA() {
    return A;
}

std::vector<float>& Personne::getPsi() {
    return Psi;
}

