#include<iostream>
#include"macierz.hh"
#include"vector.hh"
#include"Zespolona.hh"
using namespace std;

int main()
{
  
    char choise='a';
    cout<<"wybierz jakie sa beda liczby\nr - rzeczywiste\ni - zespolone\n";
    cin>>choise;
    int SIZE;
    cout<<"rozmiar macierzy  : ";
    cin>>SIZE;
    switch (choise)
    {
    case 'r':
    {
    char oper='a';
    cout<<"wybierz dzialanie potrzebne do wykonania\ng-elemenacja gaussa\n+zlozenie macierzy\n*mnozenie macierzy"<<endl;
    cin>>oper;
    /*if(oper=='g')
    {
     matrix<int> a(SIZE,SIZE);
     a.get();
     vector<int> r(SIZE);
     r.wpisz();
     //r.Print();
     int h[SIZE];
     for(int i=0;i<SIZE;++i)
     {
       cout<<"wpisz wektor ";
       h[i]=r[i];
     }
     vector<int> v(SIZE);
     

     v = r;
     a.gauss(h,SIZE);
     //r.out();
     //v.Print();
    
    }
    else*/ if(oper=='+')
    {
      matrix<int> a(SIZE,SIZE);
      a.get();
      matrix<int> b(SIZE,SIZE);
      b.get();
      (a+b).Print();
    }
      else if(oper=='*')
    {
      matrix<int> a(SIZE,SIZE);
      a.get();
      matrix<int> b(SIZE,SIZE);
      b.get();
      (a*b).Print();
      
    }
    else
      {
      cout<<"nic nie wybrano";
      }
    }
      break; 








      case 'i':
      {
    char oper='a';
    cout<<"wybierz dzialanie potrzebne do wykonania\ng-elemenacja gaussa\n+zlozenie macierzy\n*mnozenie macierzy"<<endl;
    cin>>oper;
    if(oper=='g')
    {

    }
   else if(oper=='+')
   {
      LZespolona<int> k[SIZE][SIZE];
      LZespolona<int> m;
      matrix<int> a(SIZE,SIZE);
      
      **k=a.getz(m);
      matrix<int> b(SIZE,SIZE);
      b.getz(m);
       
      //b.Print();
      a.Print();
    }
      else if(oper=='*')
    {
      matrix<int> a(SIZE,SIZE);
      a.get();
      matrix<int> b(SIZE,SIZE);
      b.get();
      (a*b).Print();
      
    }
    else
      {
      cout<<"nic nie wybrano";
      }
    }
      break;
    default:
    cout<<"nie wybrano typu macierzy koniec programy"<<endl;
      break;
    }
   
}
