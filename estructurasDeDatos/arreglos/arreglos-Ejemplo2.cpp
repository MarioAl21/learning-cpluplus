/*
 Fecha: 05-26-2022
 Hora: 9:13am
 Decripción:
  En el siguiente programa se aplica la lectura de un arreglo, su 
  escritura y la eliminación de un o más elementos. Los que permite 
  el arreglo.
  Nota: Esto se hará utilizando un arreglo NO oredenado.
*/

#include <iostream>

using namespace std;

#define MAX 100 // Tamaño máximo del arreglo

// Plantilla de la clase Arreglo
template <class T>
class Arreglo
{
 public:
  void lee(); // Solicita los datos a guarda en el arrelgo
  void escribe(); // Imprime los datos que guarda el arreglo
  int busca(T); // Localiza un elemento dentro del arreglo
  int elimina(T); // Elimina un elemento del arreglo en caso de econtrarlo
  int inserta(T); // Inserta un nuevo elemento dentro del arreglo
  int tam() { return tamanio_actual; }
  
  // Sobrecarga de operadores cin y cout para la lectura y escritura del arreglo respectivamente
  template <class D>
  friend istream &operator >>(istream &, Arreglo<D> &);
  template <class D>
  friend ostream &operator <<(ostream &, Arreglo<D> &);
 
 private:
  T datos[MAX];
  int tamanio_actual;
}; 

// Prototipos de funciones que usarán 
int menu();
void usaArreglo();

int
main()
{
 setlocale(LC_ALL, "");

 usaArreglo();

 return 0;
}

// Definición de los elementos de la plantilla Arreglo
template <class T>
void Arreglo<T>::lee()
{
 cout << "\nLectura por el método \"lee\"\n";

 int indice;

 do
 { 
  cout << "\nIntroduce cuántos elementos almacenará el arreglo: ";
  cin >> tamanio_actual;
  if(tamanio_actual < 0 || tamanio_actual > MAX)
   cout << "\nAdevertencia. La cantidad introducida rebasa el límite o es menor a cero!\n";
 } while(tamanio_actual < 0 || tamanio_actual > MAX);

 if(tamanio_actual > 0)
 {
  cout << "\n ----- Ingrese cada dato ----- \n";
  for(indice = 0; indice < tamanio_actual; indice ++)
  {
   cout << "\ndato " << indice + 1 << ": ";
   cin >> datos[indice];
  }
 }
}

template <class T>
void Arreglo<T>::escribe()
{
 cout << "\nEscritura por el método \"escribe\"\n";

 int indice;
 
 if(tamanio_actual)
 {
  cout << "\n ------- Datos del arreglo ------ \n";
  for(indice = 0; indice < tamanio_actual; indice ++)
   cout << "dato[" << indice + 1 << "] = " << datos[indice] << endl;
 }
 else
  cout << "\nEl arreglo aún no recibe elementos a guardar!!!\n";
} 

template <class T>
int Arreglo<T>::busca(T dato)
{
 int indice = 0, resultado = -1;
  
 while(indice < tamanio_actual && datos[indice] != dato) 
  indice ++;

 if(indice < tamanio_actual)
  resultado = indice;

 return resultado;
}

template <class T>
int Arreglo<T>::elimina(T dato)
{
 int indice, posicion, resultado = 1;
  
 if(tamanio_actual > 0)
 {
  posicion = busca(dato);
  if(posicion < 0)
   resultado = -1;
  else
  {
   tamanio_actual --; 
   for(indice = posicion; indice < tamanio_actual; indice ++)
    datos[indice] = datos[indice + 1];
  }
 }
 else 
  resultado = 0;

 return resultado;
}

template <class T>
int Arreglo<T>::inserta(T dato)
{
 int resultado = 1, busqueda;

 if(tamanio_actual < MAX)
 {
  busqueda = busca(dato);
  if(busqueda >= 0)
   resultado = -1;
  else
   datos[tamanio_actual ++] = dato;
 }
 else
  resultado = 0;
 
 return resultado;
}

// Definición de las funciones sobrecargadas
template <class T>
istream &operator >>(istream &lee, Arreglo<T> &arr)
{
 cout << "\nLectura por sobrecarga del operador \">>\"\n";

 int indice;

 do
 { 
  cout << "\nIntroduce cuántos elementos almacenará el arreglo: ";
  lee >> arr.tamanio_actual;
  if(arr.tamanio_actual < 0 || arr.tamanio_actual > MAX)
   cout << "\nAdevertencia. La cantidad introducida rebasa el límite o es menor a cero!\n";
 } while(arr.tamanio_actual < 0 || arr.tamanio_actual > MAX);

 if(arr.tamanio_actual > 0)
 {
  cout << "\n ----- Ingrese cada dato ----- \n";
  for(indice = 0; indice < arr.tamanio_actual; indice ++)
  {
   cout << "\ndato " << indice + 1 << ": ";
   lee >> arr.datos[indice];
  }
 }

 return lee;
}

template <class T>
ostream &operator <<(ostream &escribe, Arreglo<T> &arr)
{
 cout << "\nEscritura por sobrecarga del operador \"<<\"\n";

 int indice;
 
 if(arr.tamanio_actual > 0)
 {
  cout << "\n ----- Datos del arreglo ------ \n";
  for(indice = 0; indice < arr.tamanio_actual; indice ++)
   escribe << "dato[" << indice + 1 << "] = " << arr.datos[indice] << endl; 
 }
 else
  cout << "\nNo hay datos guardados dentro del arrelgo!!!\n";

 return escribe; 
}

// Definiciones de prototipos de funciones
int menu()
{
 char opcion;
 
 do
 {
  cout << "\nL: leer lista de claves"
       << "\nA: Dar de alta un nuevo alumno"
       << "\nB: Dar de baja un alumno"
       << "\nI: Imprimir lista de claves"
       << "\nF: Finalizar proceso\n\tIngresar opcion: ";
  cin >> opcion;
 }while
 (
  opcion != 'A' && opcion != 'B' &&
  opcion != 'L' && opcion != 'I' &&
  opcion != 'F' 
 );

 return opcion;
}

void usaArreglo()
{
 Arreglo<int> claves;
 int clave, respuesta;
 char opc;

 do
 {
  opc = menu();
  switch(opc)
  {
   case 'L':
    claves.lee(); 
   break;
   
   case 'I':
    claves.escribe();
   break;

   case 'A':
    cout << "\n Ingrese Clave del alumno: ";
    cin >> clave; 
    respuesta = claves.inserta(clave); 
    if(respuesta == 1)
     cout << "\nEl nuevo alumno ha sido de dado de alta con éxito.\n";
    else
     if(respuesta == 0)
      cout << "\nNo hay espacio suficiente para dar de alta un nuevo alumno.\n";
     else
      cout << "\nEl alumno con la clave: " << clave << " ya fue dado de alta!!!!\n";  
   break;

   case 'B':
    cout << "\nIngrese la clave del alumno a dar baja: "; 
    cin >> clave;
    respuesta = claves.elimina(clave);
    if(respuesta == 1)
     cout << "\nEl alumno con la clave " << clave << " fue dado de baja con éxito.\n";
    else
     if(respuesta == 0) 
      cout << "\nNo hay alumno registrados!!!.\n";
     else
      cout << "\nEl alumno con la clave " << clave << " no existe. Favor de verificarlo.\n";
   break;

   case 'F':
    cout << "\n\n\tProceso Terminado.\n";
   break;

   deafult:
    cout << "\nOpción no válida!!!\n";
  }
 }while(opc != 'F');
}