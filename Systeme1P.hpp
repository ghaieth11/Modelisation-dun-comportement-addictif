#ifndef __SYSTEME1P_HPP__
#define __SYSTEME1P_HPP__

#include "Systeme.hpp"
#include "Personne.hpp"

class Systeme1P : public Systeme {
    private :
    Personne& P;

    public : 
    
    Systeme1P(const Personne& person); // constructeur par copie

    void SolveSystem() override ;
    void UpdateValues(int t) override;





};



#endif