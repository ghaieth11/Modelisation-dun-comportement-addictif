#ifndef __SYSTEME1P_HPP__
#define __SYSTEME1P_HPP__

#include "Systeme.hpp"
#include "Personne.hpp"

class Systeme1P : public Systeme {
    private :
    const Personne& P;

    public : 
    
    Systeme1P(const Personne& person,int i); // constructeur par copie

    void SolveSystem(int n) override ;
    // void UpdateValues(int t) override;





};



#endif