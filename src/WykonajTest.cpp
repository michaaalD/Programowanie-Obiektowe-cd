#include <iostream>
#include <fstream>
#include "WykonajTest.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "StatystykaTestu.hh"


void WykonajTest(std::istream &rStrmWej, std::ostream &rStrWyj)
{
  WyrazenieZesp   WyrZ_PytanieTestowe;
  StatystykaTestu StatTestu;
   
  while ((rStrmWej >> WyrZ_PytanieTestowe).fail() == 0) {

    LZespolona Wynik_Usera;          //wynik wpisana przez usera
    LZespolona Poprawny_Wynik;       //poprawny wynik

    std::cout << WyrZ_PytanieTestowe << std::endl; //pobranie wyrazenia
    Poprawny_Wynik = WyrZ_PytanieTestowe.Oblicz();  //obliczenie poprawnego wyniku
    std::cout << "Podaj wynik: " << "\t";
    std::cin >> Wynik_Usera;                       //input od usera
    
    if(Wynik_Usera == Poprawny_Wynik){
      std::cout << "Dobrze!" <<std::endl;
      StatTestu.Ile_Poprawnych();
    }
    else{
      for(int i=1; i<=2; i++){                     //3 proby wpisania poprawnego wyniku
        std::cout << "Niepoprawny wynik!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin >> Wynik_Usera;
        if(Wynik_Usera==Poprawny_Wynik){
          std::cout << "Dobrze!" <<std::endl;
          StatTestu.Ile_Poprawnych();
          break;
        } 
        StatTestu.Ile_Niepoprawnych();
      }
    }
    
    std::cout << "Poprawna odpowiedz: " << WyrZ_PytanieTestowe.Oblicz()<<std::endl;
    std::cout << "******************************************************" << std::endl;
    StatTestu.Nr_Pytania();
  }
  
  std::cout << "Ilosc pytan: " <<  StatTestu.Nr_Pytania() << std::endl;
  std::cout << "Ilosc poprawnych odpowiedzi: " <<  StatTestu.Ile_Poprawnych() << std::endl;
  std::cout << "Ilosc niepoprawnych odpowiedzi: " <<  StatTestu.Ile_Niepoprawnych()<< std::endl;
  

  
  
  
}