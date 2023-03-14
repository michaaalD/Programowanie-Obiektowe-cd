#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Plik zawiera definicje klasy LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class LZespolona{
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  public:

  /*funkcje dostepowe*/
  double get_Re() const {return re;};
  double get_Im() const {return im;};

  /*modyfiowanie pol prywatnych*/
  void set_Re(double new_re){this->re = new_re;};
  void set_Im(double new_im){this->re = new_im;};


  LZespolona operator + (LZespolona Skl1);
  LZespolona operator - (LZespolona Skl1);
  LZespolona operator / (LZespolona Skl1);
  LZespolona operator * (LZespolona Skl1);
  LZespolona operator +=(const LZespolona SKl1)const;
  LZespolona operator -=(const LZespolona SKl1)const;
  LZespolona operator *=(const LZespolona Skl1)const;
  LZespolona operator /=(const LZespolona Skl1)const;

  friend std::istream& operator >> (std::istream  &str_wej, LZespolona &Skl1);
  bool operator == (const LZespolona &Skl1);
  double modul2 (LZespolona& Skl1) ; // zwraca kwadrat modulu
  LZespolona sprzezenie (LZespolona &Skl1); 
};
  
  std::ostream& operator << (std::ostream  &str_wyj, LZespolona Skl1);
  std::istream& operator >> (std::istream  &str_wej, LZespolona &Skl1);


#endif
