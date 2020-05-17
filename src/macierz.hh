#include <iostream>
#include <iomanip>
#include"Zespolona.hh"
using namespace std;
template<typename T>
class matrix:public LZespolona<T>
{
protected:
T **arr;
int n,m;
public:
 matrix(const matrix& _arr)
  {
   
    n = _arr.m;
    m = _arr.n;

    
    arr = (T**) new T*[m]; 

    for (int i = 0; i < n; i++)
      arr[i] = (T*) new T[n];

    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        arr[i][j] = _arr.arr[i][j];
  }
void Print()
  {
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cout << arr[i][j] << "\t";
      cout << endl;
    }
   
  }
  
matrix(int n, int m)
{
    this->n=n;
    this->m=m;
    arr = new T* [n];
    for (int i=0; i<n;i++){
    arr[i]=new T[m];
    } 
    for (int k=0; k<n; k++){
    for (int i=0; i<m;i++){
    arr[k][i]=0;
    }
    } 
}

  void get(){
    
    for (int k=0; k<n; k++){
    for (int i=0; i<m;i++){
    cout<<"arr["<<k<<"]["<<i<<"]  :  ";   
    cin>>arr[k][i];
    }
    } 
}
LZespolona<T> getz(LZespolona<T> zespolona){
  LZespolona<T> temp[n][m];
 // cout<<" [0][0]"<<temp[0][0];
    for (int k=0; k<n; k++){
    for (int i=0; i<m;i++){
      zespolona.getim();
    cout<<"arr["<<k<<"]["<<i<<"]  :  ";   
    temp[k][i]=zespolona;

    }
    } 
    return **temp;
}
 matrix<T> operator +(matrix<T> &b){
    matrix<T> c(n,m);
    for (int k=0; k<n; k++){
    for (int i=0; i<m;i++){
    c.arr[k][i] = b.arr[k][i]+arr[k][i];
    }
    }
return c;
}
matrix<T> operator +(LZespolona<T> &b){
    matrix<T> c(n,m);
    for (int k=0; k<n; k++){
    for (int i=0; i<m;i++){
    c.arr[k][i] = b.arr[k][i]+arr[k][i];
    }
    }
return c;
}
 
matrix<T> operator=(const matrix<T>& _arr)
  {
    if (m > 0)
    {
      
      for (int i = 0; i < n; i++)
        delete[] arr[i];
    }

    if (n > 0)
    {
      delete[] arr;
    }

    // kopiowanie danych
    n = _arr.n;
    m = _arr.m;

    // wydzielenie pamieci
    arr = (T**) new T*[n]; 
    for (int i = 0; i < n; i++)
      arr[i] = (T*) new T[m];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        arr[i][j] = _arr.arr[i][j];
    return *this;
  }

T& operator ()(int k, int l)
{
    if(k<0 || k >=n)
    {cout<<"\nwystapil blad"<<endl;exit(1);}
    else if(l<0 ||  l>=m)
    {cout<<"\nwystapil blad"<<endl;exit(1);}

    return arr[k][l];
}

matrix<T> operator *(matrix<T> &b)const{
      matrix<T> c(n,m);
    for (int k=0; k< n; ++k) {
        for (int i=0; i<m;++i)
       { c.arr[k][i]=0;
        for(int j=0; j<b.n; ++j) {
        c.arr[k][i]+= (arr[k][j]*b.arr[j][i]);
          }}}
    return c;
    }
    T * gauss(T *vec, int SIZE) 
{
  T *x, max;
  int k, index;
  x = new T[n];
  k = 0;
  while (k < n) 
  {
    // wyszukiwanie wiersza z najw arr[i][k]
    max = abs(arr[k][k]);
    index = k;
    for (int i = k + 1; i < n; ++i) 
    {
      if (abs(arr[i][k]) > max)
      {
        max = abs(arr[i][k]);
        index = i;
      }
    }
    // przemieszczenie kolumn
    for (int j = 0; j < n; ++j) 
    {
      T temp = arr[k][j];
      arr[k][j] = arr[index][j];
      arr[index][j] = temp;
    }
    T temp = vec[k];
    vec[k] = vec[index];
    vec[index] = temp;
    for (int i = k; i < n; i++) 
    {
      double temp = arr[i][k];
      for (int j = 0; j < n; j++) 
        arr[i][j] = arr[i][j] / temp;
      vec[i] = vec[i] / temp;
      if (i == k)  continue;
      for (int j = 0; j < n; j++)
        arr[i][j] = arr[i][j] - arr[k][j];
      vec[i] = vec[i] - vec[k];
    }
    k++;
  }
  // odwrotne podstawanie
  for (k = n - 1; k >= 0; --k)
  {
    x[k] = vec[k];
    for (int i = 0; i < k; i++)
      vec[i] = vec[i] - arr[i][k] * x[k];
  }
  for(int i= 0;i<SIZE;++i)
  cout<<" odpowiedz "<<x[i]<<endl;
  return x;
}
};
