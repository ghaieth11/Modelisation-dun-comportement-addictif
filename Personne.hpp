#ifndef __PERSONNE_HPP__
#define __PERSONNE_HPP__
#include <vector>

class Personne {
    // Attributs caractéristique pour une personne 
private:
    float C0, S0, E0, Sm, p, d, q;
    std::vector<float> C, S, E, V, A, Psi;

    // Méthodes de la classe Personne
public: 
    // Constructeurs
    Personne(); // Constructeur par défaut
    Personne(const Personne& P); // Constructeur par copie
    Personne(float C0, float S0, float E0, float Sm, float p, float d, float q);  // Constructeur spécifique
    
    // Méthode pour initialiser et/ou allouer dynamiquement les tableaux C, S, E, etc.
    void Initialisation(); 

    // Getters
    float getC0();
    float getS0();
    float getE0();
    float getd();
    float getp();
    float getq();
    float getSm();

    // Setters
    void setC0(float value);
    void setS0(float value);
    void setE0(float value);
    void setSm(float value);
    void setp(float value);
    void setd(float value);
    void setq(float value);

    // Autres méthodes
    void Addict();
    void Insensible();
    
    // Getters pour accéder aux tableaux
    std::vector<float>& getC();
    std::vector<float>& getE();
    std::vector<float>& getS();
    std::vector<float>& getV();
    std::vector<float>& getA();
    std::vector<float>& getPsi();
};

#endif
