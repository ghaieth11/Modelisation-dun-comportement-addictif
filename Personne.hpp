#ifndef __PERSONNE_HPP__
#define __PERSONNE_HPP__
#include <vector>

class Personne {
    //attributs caractéristique pour une personne 
    private :
    float C0, S0, E0, Sm, p, d, q;
    std::vector<float> C, S, E, V, A, Psi;



    // Méthode de la classe Personne
    public : 
    Personne(); // constructeur par default
    Personne(const Personne& P); // constructeur par copie
    Personne(float C0, float S0, float E0, float Sm, float p, float d, float q);  // constructeur spécifique
    
    void Initialisation(); // une méthode pour initialiser et/ou allouer dynamiquement les tableau C S E ...
    float getd();
    float getp();
    float getq();
    float getSm();
    std::vector<float>& getC();
    std::vector<float>& getE();
    std::vector<float>& getS();
    std::vector<float>& getV();
    std::vector<float>& getA();
    std::vector<float>& getPsi();
    

    



};




#endif