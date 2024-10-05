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
    Systeme(){
    me=0.01;
    m_lambda=0.001;
    Rm=7;
    nbrsemaines = 400;
    lambda.resize(nbrsemaines);
    for (int i = 0; i < nbrsemaines; i++){
        lambda[i] = 0.2 + i * m_lambda;
    }};
    virtual void SolveSystem() = 0;
    





};

#endif






