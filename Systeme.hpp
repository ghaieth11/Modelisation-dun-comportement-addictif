#ifndef __SYSTEME_HPP__
#define __SYSTEME_HPP__

#include <vector>

class Systeme {
protected :
    // des parametres qui caractérise chaque systéme d'equations
    float me, m_lambda, Rm;
    int nbrsemaines;
    // un tableau qui contient les differents parametres de la loi de Poisson
    std::vector<float> lambda;


    public : 
    Systeme(int n){nbrsemaines = n};
    virtual void SolveSystem() = 0;
    





};

#endif






