#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

std::istream &operator >> (std::istream &rStrmWe, WyrazenieZesp &rWyrZ) {
  
  char znak; // zmiennna do switcha dla operatora 
  
  rStrmWe >> rWyrZ.Arg1; // strumien wej na 1 argument zespolonej
  
   
  rStrmWe >> znak;

  switch(znak){
    case '+':
      rWyrZ.Op = Operator::Op_Dodaj;
      break;
    case '-':
      rWyrZ.Op = Operator::Op_Odejmij;
      break;
    case '/':
      rWyrZ.Op = Operator::Op_Dziel;
      break;
    case '*':
      rWyrZ.Op = Operator::Op_Mnoz;
      break;
    default:
      if(znak!= '(' || ')' || 'i')
      std::cout << "Niepoprawny operator " << std::endl;
      break;
  }
  rStrmWe >> rWyrZ.Arg2;  // strumien wej na 2 argument zespolonej
  return rStrmWe;
  
}

std::ostream &operator << (std::ostream &str_wyj, WyrazenieZesp  WyrZ)
{
  str_wyj << "Wyrazenie zespolone:  ";
  str_wyj << WyrZ.arg1();

  switch(WyrZ.op()){

    case Operator::Op_Dodaj:
      str_wyj << " + ";
      break;
    case Operator::Op_Odejmij:
      str_wyj << " - ";
      break;
    case Operator::Op_Dziel:
      str_wyj << " / ";
      break;
    case Operator::Op_Mnoz:
      str_wyj << " * ";
      break;
  }

  str_wyj << WyrZ.arg2();
  
  return str_wyj;
} 


LZespolona WyrazenieZesp::Oblicz()
{
  LZespolona Wynik;

  switch(this->Op){
    case Op_Dodaj:
      Wynik = this->Arg1 + this->Arg2;
      break;
    case Op_Odejmij:
      Wynik = this->Arg1 - this->Arg2;
      break;
    case Op_Dziel:
      Wynik = this->Arg1 / this->Arg2;
      break;
    case Op_Mnoz:
      Wynik = this->Arg1 * this->Arg2;
      break;
    default:
      std::cout << "Nieznany operator" << std::endl;
      break;

  }
  return Wynik;
}

