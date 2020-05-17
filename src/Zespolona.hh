#pragma once
#include<iostream>
#include <cassert>
#include<iomanip>
#include <cmath>
#include<iostream>
using namespace std;
#define PI 3.14159265
template<typename T>
class LZespolona
{
  protected:
    T re;
    T im;
    public:
    LZespolona()
    {
        re =0;
        im =0;
    }
    LZespolona<T>  operator + (LZespolona<T>  Skl)
{
  LZespolona<T>  Wynik;

  Wynik.re = Skl.re + re;
  Wynik.im = Skl.im + im;
  return Wynik;
}
void getim()
{
  cin>>re>>im;
}
void Print()
  {
    
    cout<<"rzeczywista  "<<re<<"urojana   "<<im;
   
  }
/*
Sprzenzenie liczb zespolonych:
Argumenty:
* Skl - liczba zespolona;
Zwraca:
    Wartosc sprzenzenia skladnika przekazanego jako parametr
*/
LZespolona<T> Sprzenzenie(LZespolona<T> Skl)
{
LZespolona<T> Wynik;
Wynik.re = Skl.re;
Wynik.im = -Skl.im;
return Wynik;
}
/*
Odejmowanie liczb zespolonych:
Argumenty:
* Skl1 - pierwszy skladnik odejmowania;
* Skl2 - drugi skladnik odejmowania
Zwraca:
    Wartosc odejmowania dwoch skladnikow przekazanych jako parametry
*/
LZespolona<T>  operator - (LZespolona<T>  Skl)
{
  LZespolona<T>  Wynik;

  Wynik.re = Skl.re - re;
  Wynik.im = Skl.im - im;
  return Wynik;
}
/*
Iloczyn liczb zespolonych:
Argumenty:
* Skl1 - pierwszy skladnik iloczynu
* Skl2 - drugi skladnik iloczynu
Zwraca:
    iloczyn dwoch skladnikow przekazanych jako parametry
*/
LZespolona<T>  operator * (LZespolona<T>  Skl)
{
 LZespolona<T>  Wynik;

  Wynik.re = Skl.re * re;
  Wynik.re-= Skl.im * im;
  Wynik.im = Skl.re * im + Skl.im * re;
  return Wynik;
}
/*
ModulDoKwadratu liczby zespolonej:
Argumenty:
* Skl1 - liczba zespolona;
Zwraca:
    Wartosc bezwzgledna do kwadratu skladnika przekazanego jako parametr
*/
T ModulDoKwadratu(LZespolona<T> Skl)
{
  T Wynik;
  Wynik=Skl.re*Skl.re+Skl.im*Skl.im;
  return Wynik;
}
T Modul(LZespolona<T> Skl)
{
  T Wynik;
  Wynik=Skl.re*Skl.re+Skl.im*Skl.im;
  return sqrt(Wynik);
}

/*
Dzilenie liczb zespolonych:
Argumenty:
* Skl1 - pierwszy skladnik dzielenia;
* Skl2 - drugi skladnik dzielenie
Zwraca:
    Wartosc dzielenia dwoch skladnikow przekazanych jako parametry
*/
/*LZespolona<T>  operator / (LZespolona<T>  Skl)
{
  LZespolona<T>  Wynik;
  LZespolona<T> z;
  z = Skl*(Sprzenzenie(Skl2));
  Wynik.re = z.re/(ModulDoKwadratu(Skl2));
  Wynik.im= z.im/(ModulDoKwadratu(Skl2));
  
  return Wynik;
}
*/

/*
Zmiana znaku liczby zespolonej:
Argumenty:
* Skl1 - liczba zespolona;
Zwraca:
    Wartosc ze zmienionym znakiem skladnika przekazanego jako parametr
*/
LZespolona<T> Zmiana_znaku(LZespolona<T> Skl1)
{
LZespolona<T> Wynik;
Wynik.re = -Skl1.re;
Wynik.im = -Skl1.im;
return Wynik;
}


/*
Znalezenie argumentu liczby zespolonej:
Argument funkcji:
Skl : liczba zespolona
Zwraca:
Znaczenie argumentu w radianach
*/
T Argument(LZespolona<T> Skl)
{
  T modul,Re;
  modul = Modul(Skl);
  Re= Skl.re/modul;
  if (Skl.re>0)
return acos(Re);
else
{
 return PI - acos(Re);
}

}
};
