
#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <stdexcept>

 LZespolona LZespolona::operator+(LZespolona Skl1) // przeciazenie operatora dla dodawania lzesp
{
  LZespolona Wynik;

  Wynik.re = this->re + Skl1.re;
  Wynik.im = this->im + Skl1.im;
  return Wynik;
  
}

LZespolona LZespolona::operator-(LZespolona Skl1) // przeciazenie operatora dla odejmowania lzesp
{
  LZespolona Wynik;
  
  Wynik.re = this->re - Skl1.re;
  Wynik.im = this->im - Skl1.im;
  return Wynik;
}

LZespolona LZespolona::operator / (LZespolona Skl1) //przeciazenie operatora dla dzielenia lzesp
{
  LZespolona Wynik;
  double modul_zespolonej= Skl1.modul2(Wynik);

  // ze wzoru na dizelenie z materialow do zadania (a+bi):(c+di)= [ac + bd)/ c^2+d^2 ] + [i(bc-ad)/c^2+b^2]

  if(Skl1.re != 0 && Skl1.im != 0){
    Wynik.re = ((this->re*Skl1.re) + (this->im*Skl1.im))/modul_zespolonej;
    Wynik.im = ((this->im*Skl1.re) - (this->re*Skl1.im))/modul_zespolonej;
  }
  else{
    throw std::runtime_error ("Nie mozna wykonac dzielenia przez 0");
  }

  return Wynik;
}

LZespolona LZespolona::operator * (LZespolona Skl1) //przeciazenie operatora dla mnozenia lzesp
{
  LZespolona Wynik;
  Wynik.re = (this->re * Skl1.re) - (this->im * Skl1.im);
  Wynik.im = (this->re * Skl1.im) + (this->im * Skl1.re);
  return Wynik;
}

bool LZespolona::operator == (const LZespolona &Skl1) //przeciazenie operatora dla porownania lzesp
{
  return (this->re==Skl1.re) && (this->im==Skl1.im);
}

LZespolona LZespolona::sprzezenie (LZespolona &Skl1) //sprzezenie lzesp
{
  Skl1.im = -Skl1.im;
  return Skl1;
}

double LZespolona::modul2 (LZespolona &Skl1)  // funckja zwracajaca modul ^2 l zespolonej
{
  return (Skl1.re*Skl1.re) + (Skl1.im * Skl1.im);
}


std::ostream &operator<<(std::ostream &str_wyj, LZespolona Skl1) // przeciazenie do wypisania l zesp
{
  str_wyj.precision(3); // wyswietlanie 3 miejsc po przecinku
  str_wyj << std::noshowpos << '(' << Skl1.get_Re() << std::showpos << Skl1.get_Im() << "i)";
  return str_wyj;
}

std::istream &operator>>(std::istream &str_wej, LZespolona &Skl1) // przeciazenie do pobrania l zesp
{
  char znak;

  str_wej >> std::skipws >> znak; // pobranie nawiasu '(' i sprawdzenie
  if (str_wej.fail())
    return str_wej;
  if (znak != '(')
  {
    str_wej.fail();
    return str_wej;
  }

  str_wej >> Skl1.re; // pobranie czesci re i sprawdzenie
  if (str_wej.fail())
    return str_wej;

  str_wej >> Skl1.im; // pobranie czesci  im i sprawdzenie
  if (str_wej.fail())
    return str_wej;

  str_wej >> znak; // pobranie znaku 'i' i sprawdzenie
  if (str_wej.fail() || znak != 'i')
    return str_wej;

  str_wej >> std::skipws >> znak; // sprawdzenie nawiasu ')' i sprawdzenie
  if (str_wej.fail())
    return str_wej;
  if (znak != ')')
  {
    str_wej.fail();
    return str_wej;
  }
  return str_wej;
}


LZespolona LZespolona::operator +=(const LZespolona Skl1)const{
  LZespolona Wynik=*this;
  return Wynik=Wynik+Skl1;
}

LZespolona LZespolona::operator -=(const LZespolona Skl1)const{
  LZespolona Wynik=*this;
  return Wynik=Wynik-Skl1;
}
LZespolona LZespolona::operator *=(const LZespolona Skl1)const{
  LZespolona Wynik=*this;
  return Wynik=Wynik*Skl1;
}
LZespolona LZespolona::operator /=(const LZespolona Skl1)const{
  LZespolona Wynik=*this;
  return Wynik=Wynik/Skl1;
}