#ifndef __SYSTEME_HPP__
#define __SYSTEME_HPP__

#include <vector>

class Systeme {
private :
    // des parametres qui caractérise chaque systéme d'equations
    float me, m_lambda, Rm;
    int nbrsemaines;
    // un tableau qui contient les differents parametres de la loi de Poisson
    std::vector<float> lambda;


    public : 
    virtual void SolveSystem() = 0;
    virtual void UpdateValues(int t) = 0;





};







#endif