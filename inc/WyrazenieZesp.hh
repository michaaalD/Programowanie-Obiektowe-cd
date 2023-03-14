#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };
class WyrazenieZesp{

  

  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  public:

    LZespolona Oblicz();
    LZespolona arg1() const {return Arg1;};
    LZespolona arg2() const {return Arg2;};

    //LZespolona &zapis_arg1()  {return Arg1;};
    //LZespolona &zapis_arg2()  {return Arg2;};
    friend std::istream &operator >> (std::istream &rStrmWe, WyrazenieZesp &rWyrZ);
    Operator op() const {return Op;};
    //Operator &zapis_op() {return Op;};


};
std::istream &operator >> (std::istream &rStrmWe, WyrazenieZesp &rWyrZ);
std::ostream &operator << (std::ostream &str_wyj, WyrazenieZesp  WyrZ);


#endif
