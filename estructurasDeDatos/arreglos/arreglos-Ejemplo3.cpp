/*
 Fecha de inicio: 06-01-2022
 Hora de inicio: 10:27am
 Fecha de finalización:
 Hora de finalización: 
 Descripción: 
  El siguiente programa define el método "busca" de la clase plantilla Arreglo
  para realizar una búsqueda sobre sus componentes ordenados: tanto
  en orden asecendente como descedente. Por lo tanto se definirán dos
  versiones de dicho método para cubrir ambas posibilidades.
*/

#include <iostream>
using namespace std;

#define MAX 100

// Plantilla de la clase Arreglo
template <class T>
class Arreglo
{
 public:
  int buscaAsc(T); // Realiza la búqueda sobre un orden ascedente
  int buscaDesc(T); // Realiza la búsqueda sobre un orden descendente  
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

// Prototipo de la función que hará uso de la clase plantilla Arreglo
void usaArreglo();

int 
main()
{
 setlocale(LC_ALL, "");
 usaArreglo();

 return 0;
}

// Definición de los métodos de la plantilla de la clase Arreglo
template <class T>
int Arreglo<T>::buscaAsc(T dato)
{
 int indice = 0, resultado;

 // Paso 1: recorrer el arreglo
 while(indice < tamanio_actual && datos[indice] < dato)
  indice ++;
 
 // Paso 2: Verificar si el arreglo no se econtró
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

 // Se invierte la segunda condición. Ahora en caso que el dato buscado sea menor el arreglo se recorre.
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

// Definición de las funciones de sobrecarga
template <class T>
istream &operator >>(istream &lee, Arreglo<T> &arr)
{
 int indice;

 do
 {
  cout << "\nIngrese el número de elementos a almacenar: ";
  lee >> arr.tamanio_actual;
  if(arr.tamanio_actual < 0)
   cout << "\nEl número de elementos especificado es menor a cero!\n";
  if(arr.tamanio_actual > MAX)
   cout << "\nEl número de elementos es mayor a lo que es posible guardar (" << MAX << ")\n";
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
  cout << "\nEl no tendrá elementos\n";

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
  cout << "\nAún no hay elementos almacenados!!\n";

 return escribe;
}

// Definición de funciones
void usaArreglo()
{
 char op; int valor, resp;
 Arreglo<int> arr;
 cin >> arr; cout << endl << arr;

 while(true)
 {
  cout << "\n(1) Búqueda Ascendente (2) Búsqueda Descendente: ";
  cin >> op;

  switch(op)
  {
   case '1': 
    cout << "\nIngrese valor a buscar: "; cin >> valor;
    resp = arr.buscaAsc(valor);
    if(resp < 0)
     cout << "\nEl Valor " << valor << " NO se econtró\nDebería esta en la posición: " << -resp << endl;
    else
     cout << "\nValor encontrado en la posición: " << resp + 1 << " \n"; 
   break;

   case '2': 
    cout << "\nIngrese valor a buscar: "; cin >> valor;
    resp = arr.buscaDesc(valor);
    if(resp < 0)
     cout << "\nEl Valor " << valor << " NO se econtró\nDebería esta en la posición: " << -resp << endl;
    else
     cout << "\nValor encontrado en la posición: " << resp + 1 << " \n"; 
   break;

   case '3':
    cout << "\nIngrese al dato a insertar: ";
    cin >> valor;
    resp = arr.insertaAsc(valor);
    if(resp == 0)
     cout << "\nEl arreglo NO tiene espacio!!!\n";
    else
     if(resp == 1)
      cout << "\nEl dato se insertó exitosamente\n";
     else
      cout << "El dato " << valor << " ya se encuentra en el arreglo!!!\n";
     cout << arr << endl;
   break;

   default: cout << "\nOpción no válida!\n";
  }
 }
}
