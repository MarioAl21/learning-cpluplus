/*
 Fecha: 05-24-2022
 Hora: 4:51pm
 Descripción:
  A continuación se presenta la plantilla Arreglo.
*/

#include <iostream>

using namespace std;

#define MAX 100 // Constante para establecer el número de elementos a almacenar por el arreglo

// Plantilla Arreglo
template <class T>
class Arreglo
{
 private:
  T datos[MAX];
  int tamanio_del_arreglo;
 public:
  Arreglo(int tam) 
  {
   tamanio_del_arreglo = tam;
  }   
  void imprime()
  {
   cout << "\n ------ Datos dentro del arreglo ----- \n";
   for(int i = 0; i < tamanio_del_arreglo; i ++)
    cout << "Datos[" << i << "] = " << datos[i] << endl;
  }
};

int
main()
{
 Arreglo<float> arr(3); // imprime indefinido pues no le hemos asignado valores predeterminados.
 arr.imprime();

 return 0;
}