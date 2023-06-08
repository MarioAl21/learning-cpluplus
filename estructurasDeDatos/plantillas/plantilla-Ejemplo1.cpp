/*
 Fecha: 05-10-2022
 Hora: 8:10pm
 Descripción:
  A continuación se define la plantilla de la clase Segmento,
  de esta forma cuando se declare un objeto de esta clase,
  se podrá decidir el tipo de dato para sus miembros.
*/

#include <iostream>

using namespace std;

// --- Plantilla de la clase Segmento ---
template <class T>
class Segmento
{
 public:
  Segmento(T origen = 0, T final = 0);
  void modificaOrigen(T);
  void modificaFinal(T);

  template <class D>
  friend ostream &operator <<(ostream &, Segmento<D> &);

 private:
  T origen, final;
};

// Función que hara uso de la plantilla Segmento
void usaSegmento();

int
main()
{
 usaSegmento();

 return 0;
}

// --- Definición de los métodos de la clase Segmento ---
template <class T>
Segmento<T>::Segmento(T origen, T final)
 : origen(origen), final(final)
{}

template <class T>
void Segmento<T>::modificaOrigen(T nuevo_origen)
{
 origen = nuevo_origen;
}

template <class T>
void Segmento<T>::modificaFinal(T nuevo_final)
{ 
 final = nuevo_final;
}

template <class T>
ostream &operator <<(ostream &escribe, Segmento<T> &objeto_segmento)
{
 cout << "\n--- puntos extremos del segmento ---\n";
 escribe << "Origen: " << objeto_segmento.origen
              << "\nFinal: " << objeto_segmento.final << endl;

 return escribe;
}

void usaSegmento()
{
 int opcion;
 float origen_decimal, final_decimal, decimales;
 int origen_entero, final_entero, enteros;
 // Apuntador a segmento entero
 Segmento<int>* segmentos_enteros;
 // Apuntador a segmento decimal
 Segmento<float>* segmentos_decimales;

 do
 {
  cout << "\n(1) Crear segmentos enteros"
          << "\n(2) Crear segmentos decimales"
          << "\n(3) Imprimir segmentos enteros"
          << "\n(4) Imprimir segmentos decimales"
          << "\n(0) Salir \n\t Ingrese opcion: "; 
  cin >> opcion;
  
  switch(opcion)
  {
   case 1:
   {
    cout << "\nCuantos segmentos enteros desea? ";
    cin >> enteros;
    segmentos_enteros = new Segmento<int>[enteros];
    for(int i = 0; i < enteros; i++)
    {
     cout << "\n--- Segmento " << i +1 << " ---"; 
     cout << "\nIngrese el origen: "; cin >> origen_entero;
     cout << "\nIngrese el final: "; cin >> final_entero;
     Segmento<int> obj_segmento(origen_entero, final_entero);
     segmentos_enteros[i] = obj_segmento;
    }
   } 
   break;
   case 3:
    for(int i = 0; i < enteros; i++)
    {
     cout << "\n--- Segmento " << i + 1 << " --- \n";
     cout << segmentos_enteros[i] << endl;
    }
   break;
  }
 } while(opcion != 0);
}