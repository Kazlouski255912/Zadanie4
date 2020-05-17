#include<iostream>
using namespace std;
template <typename T> 

class vector
{
protected:
    int SIZE;
    T *vec;
    
public:
vector(int SIZE) {
    this->SIZE=SIZE;
    vec=new T [SIZE];
    for(int i=0; i<SIZE; i++) {
        vec[i]=0;
    }
}

   
    ~vector()
    {
        delete[] vec;
    }
    void out()
    {
      for(int i = 0;i<SIZE;++i)
        {
            cout<<"arr["<<i<<"] : ";
            cout<<vec[i];
        }
    }
  void wpisz()
    {
        
      cout<<"wpisz wektor   ";
      for(int i = 0;i<SIZE;++i)
        {
            cout<<"arr["<<i<<"] : ";
            cin>>vec[i];
        }
    }
    vector<T> operator=(const vector<T>& _vec)
  {
    if (SIZE > 0)
    {
        delete[] vec;
    }
    // kopiowanie danych
    SIZE = _vec.SIZE;

    // wydzielenie pamieci
    vec = (T*) new T[SIZE]; 
    
    for (int i = 0; i < SIZE; ++i)
    {
        cout<<_vec.vec[i];
        vec[i] = _vec.vec[i];
    }
    return *vec;
  }
void Print()
  {
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << vec[i] << "\t";
      cout << endl;
    }
   
  }
 T operator[ ] (int Ind)const{return vec[Ind];}
 T &operator[ ] (int Ind){return vec[Ind];}
 /*T kopiuj(const vector<T>& _vec)
{
   
    for(int i = 0; i <SIZE;++i)
    [i]=vec[i];
    return *y;
}*/
};