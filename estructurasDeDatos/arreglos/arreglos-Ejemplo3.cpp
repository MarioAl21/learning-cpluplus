/*
 Fecha de inicio: 06-01-2022
 Hora de inicio: 10:27am
 Fecha de finalizaci�n:
 Hora de finalizaci�n: 
 Descripci�n: 
  El siguiente programa define el m�todo "busca" de la clase plantilla Arreglo
  para realizar una b�squeda sobre sus componentes ordenados: tanto
  en orden asecendente como descedente. Por lo tanto se definir�n dos
  versiones de dicho m�todo para cubrir ambas posibilidades.
*/

#include <iostream>
using namespace std;

#define MAX 100

// Plantilla de la clase Arreglo
template <class T>
class Arreglo
{
 public:
  int buscaAsc(T); // Realiza la b�queda sobre un orden ascedente
  int buscaDesc(T); // Realiza la b�squeda sobre un orden descendente  
  int insertaAsc(T); // Inserta en un arreglo ascendente

  // Sobrecarga de operadores >> y <<
  template <class D>
  friend istream &operator >>(istream &, Arreglo<D> &);
  template <class D>
  friend ostream &operator <<(ostream &, Arreglo<D> &);

 private:
  T datos[MAX];
  int tamanio_actual; // Espacio ocupado de MAX
};

// Prototipo de la funci�n que har� uso de la clase plantilla Arreglo
void usaArreglo();

int 
main()
{
 setlocale(LC_ALL, "");
 usaArreglo();

 return 0;
}

// Definici�n de los m�todos de la plantilla de la clase Arreglo
template <class T>
int Arreglo<T>::buscaAsc(T dato)
{
 int indice = 0, resultado;

 // Paso 1: recorrer el arreglo
 while(indice < tamanio_actual && datos[indice] < dato)
  indice ++;
 
 // Paso 2: Verificar si el arreglo no se econtr�
 if(indice == tamanio_actual || datos[indice] > dato)
  resultado = -(indice + 1);
 else 
  resultado = indice;

 // Paso 3: retornar resultado
 return resultado;
}

template <class T>
int Arreglo<T>::buscaDesc(T dato)
{
 int indice = 0, resultado;

 // Se invierte la segunda condici�n. Ahora en caso que el dato buscado sea menor el arreglo se recorre.
 while(indice < tamanio_actual && datos[indice] > dato)
  indice ++;
 
 if(indice == tamanio_actual || datos[indice] < dato)
  resultado = -(indice + 1);
 else
  resultado = indice;

 return resultado;
}

template <class T>
int Arreglo<T>::insertaAsc(T dato)
{
 int indice, resultado = 1, posicion;
 
 if(tamanio_actual < MAX)
 {
  posicion = buscaAsc(dato);
  if(posicion > 0)
   resultado = -1;
  else
  {
   posicion = (posicion * -1) - 1;

   for(indice = tamanio_actual; indice > posicion; indice --)
    datos[indice] = datos[indice - 1];

   datos[posicion] = dato;
   tamanio_actual ++;
  }
 }
 else
  resultado = 0;

 return resultado;
}

// Definici�n de las funciones de sobrecarga
template <class T>
istream &operator >>(istream &lee, Arreglo<T> &arr)
{
 int indice;

 do
 {
  cout << "\nIngrese el n�mero de elementos a almacenar: ";
  lee >> arr.tamanio_actual;
  if(arr.tamanio_actual < 0)
   cout << "\nEl n�mero de elementos especificado es menor a cero!\n";
  if(arr.tamanio_actual > MAX)
   cout << "\nEl n�mero de elementos es mayor a lo que es posible guardar (" << MAX << ")\n";
 } while(arr.tamanio_actual < 0 || arr.tamanio_actual > MAX);

 if(arr.tamanio_actual > 0)
 {
  cout << "\n------ Elementos a almacenar ------\n";
  for(indice = 0; indice < arr.tamanio_actual; indice ++)
  {
   cout << "Inserta el valor " << indice + 1 << ": ";
   lee >> arr.datos[indice];
  }
 }
 else
  cout << "\nEl no tendr� elementos\n";

 return lee;
}

template <class T>
ostream &operator <<(ostream &escribe, Arreglo<T> &arr)
{
 int indice;
 
 if(arr.tamanio_actual > 0)
 {
  cout << "\n------ Elementos del arreglo -------\n";
  for(indice = 0; indice < arr.tamanio_actual; indice ++)
   escribe << "Dato " << indice + 1 << ": " << arr.datos[indice] << endl;
 }
 else
  cout << "\nA�n no hay elementos almacenados!!\n";

 return escribe;
}

// Definici�n de funciones
void usaArreglo()
{
 char op; int valor, resp;
 Arreglo<int> arr;
 cin >> arr; cout << endl << arr;

 while(true)
 {
  cout << "\n(1) B�queda Ascendente (2) B�squeda Descendente: ";
  cin >> op;

  switch(op)
  {
   case '1': 
    cout << "\nIngrese valor a buscar: "; cin >> valor;
    resp = arr.buscaAsc(valor);
    if(resp < 0)
     cout << "\nEl Valor " << valor << " NO se econtr�\nDeber�a esta en la posici�n: " << -resp << endl;
    else
     cout << "\nValor encontrado en la posici�n: " << resp + 1 << " \n"; 
   break;

   case '2': 
    cout << "\nIngrese valor a buscar: "; cin >> valor;
    resp = arr.buscaDesc(valor);
    if(resp < 0)
     cout << "\nEl Valor " << valor << " NO se econtr�\nDeber�a esta en la posici�n: " << -resp << endl;
    else
     cout << "\nValor encontrado en la posici�n: " << resp + 1 << " \n"; 
   break;

   case '3':
    cout << "\nIngrese al dato a insertar: ";
    cin >> valor;
    resp = arr.insertaAsc(valor);
    if(resp == 0)
     cout << "\nEl arreglo NO tiene espacio!!!\n";
    else
     if(resp == 1)
      cout << "\nEl dato se insert� exitosamente\n";
     else
      cout << "El dato " << valor << " ya se encuentra en el arreglo!!!\n";
     cout << arr << endl;
   break;

   default: cout << "\nOpci�n no v�lida!\n";
  }
 }
}
