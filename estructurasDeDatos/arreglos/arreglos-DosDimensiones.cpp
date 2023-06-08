#include <iostream>

using namespace std;

template <class T>
class ArregloBi
{
 public:
  ArregloBi();
  void lectura();
  void escritura();
  T recuperarDato();

  private:
   T datos[5][5];
   int ren, col;
};

int
main()
{
 setlocale(LC_ALL, "");

 ArregloBi<int> arrb;

 arrb.lectura();
 cout << endl;
 arrb.escritura();

 return 0;
}

template <class T>
ArregloBi<T>::ArregloBi()
{}

template <class T>
void ArregloBi<T>::lectura()
{
 int r, c;
 
 do
 {
  cout << "\nIngrese número de renglones: ";
  cin >> ren;
  while(ren <= 0)
  {  
   cout << "\nNúmero de renglones debe ser mayor a cero!!!\n"
        << "Ingrese un valor válido: ";
   cin >> ren;
  }
  cout << "\nIngrse número de columnas: ";
  cin >> col;
  while(col <= 0)
  {  
   cout << "\nNúmero de columnas debe ser mayor a cero!!!\n"
        << "Ingrese un valor válido: ";
   cin >> col;
  }
 } while(ren <= 0 && ren <= 0); 
 
 for(r = 0; r < ren; r ++)
  for(c = 0; c < col; c ++)
  {
   cout << "\nIngrese dato a guardar: ";
   cin >> datos[r][c];
  }
}

template <class T>
void ArregloBi<T>::escritura()
{
 int i, j, cols = 1;

 for(i = 0; i < ren; i ++)
 {
  while(cols <= col)
  {
   if(cols == 1)
    cout << "    c" << cols;
   else
    cout << "c" << cols;
   cols ++;
  }
  cout << "\nr" << i + 1 << ": ";   
  for(j = 0; j < col; j ++)
   cout << datos[i][j] << " ";
  cout << endl;   
 }
}