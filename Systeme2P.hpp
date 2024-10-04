#ifndef __SYSTEME2P_HPP__
#define __SYSTEME2P_HPP__

#include "Systeme.hpp"
#include "Personne.hpp"


class Systeme2P : public Systeme {
    private :
    float alpha, beta, gamma;
    Personne& P1;
    Personne& P2;
    std::vector<float> p1;
    std::vector<float> p2;


    public : 

    Systeme2P(Personne& person1, Personne& person2); // constructeur par copie
    void SolveSystem() override ;
    





};


#endif