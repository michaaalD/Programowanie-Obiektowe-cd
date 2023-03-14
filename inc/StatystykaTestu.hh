#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH
#include <iostream>

class StatystykaTestu {
    int ile_poprawnych=0;
    int ile_niepoprawnych=0;
    double procent_poprawnych=0;
    int nr_pytania=0;
    int ile_pytan=0;
    
    public:
        int Ile_Poprawnych() const {return ile_poprawnych;};
        int Ile_Niepoprawnych() const {return ile_niepoprawnych;};
        int Procent_Poprawnych() const {return procent_poprawnych;};
        int Nr_Pytania() const {return nr_pytania;};
        int Ile_Pytan() const {return ile_pytan;};


        void Oblicz_Staty( StatystykaTestu  &StatTestu );
};




#endif

