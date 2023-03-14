#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"
#include "StatystykaTestu.hh"
#include "LZespolona.hh"
#include "WykonajTest.hh"

using namespace std;


int main(int argc, char **argv)
{
  //WyrazenieZesp WyrZ;
  StatystykaTestu StatTestu;

  if (argc < 2) {  //sprawdzenie czy podano plik z testem
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
    cerr << endl;
    return 1;
  }

  ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {
    //
    // Tu trzeba wpisac wyswietlenie informacji, ze nie
    // mozna otworzyc pliku i nalezy wyswietlic jego nazwe.
    //
    cout << "Nie mozna otworzyc pliku: " << argv[1];
    return 1;
  }
  cout << endl;
  cout << "******************************************************" << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << " Wpisuj wyniki z dokadnoscia do 3 miejsc po przecinku " << endl;
  cout << " Masz 3 proby opdowiedzi na kazde pytanie" << endl;
  cout << "******************************************************" << endl;
  cout << endl;

  WykonajTest(PlikTestu,cout);
  
  PlikTestu.close();

  
  
  

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
