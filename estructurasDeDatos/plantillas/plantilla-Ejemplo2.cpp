/*
 Fecha: 11-05-2022
 Hora: 3:35pm
 Descripción:
  A continuación, se define la clase Fabricante y la clase plantilla
  Producto la cual tiene un atributo de tipo T (genérico) llamado 
  se_compra_a el cual tomará primero el tipo Fabricante y luego el
  tipo int (en este caso será una clave numérica que identifique 
  al proveedor). 
  Nota: la clace Fabricante tendrá que sobrecargar los operadores 
  << y >> para que los métodos de la clase Producto puedan imprimir
  y leer objeto y números indistintamente.   
*/

#include <iostream>
#include <string.h>

using namespace std;

// Macro MAX con valor a 64
#define MAX 64

// --- Clase Fabricante ---
class Fabricante
{
 public:
  Fabricante();
  Fabricante(char [], char[], char[]);
  void cambiaDomicilio(char []);
  void cambiaTelefono(char []);
  
  // Sobrecarga de los operadores << y >>
  friend istream &operator >>(istream &, Fabricante &);
  friend ostream &operator <<(ostream &, Fabricante &); 

 private:
  char nombre[MAX], domicilio[MAX], telefono[MAX];
};

template <class T>
class Producto
{
 public:
  Producto();
  Producto(int, char [], float, T);
  void imprime();
  void actualizaPrecio(float);

 private:
  int clave;
  char nombre[MAX];
  float precio;
  T se_compra_a;
};

// Prototipo de función que usará ambas clases
void usaPlantilla();

int
main()
{
 usaPlantilla();

 return 0;
}

// --- Definición de los métodos de la clas Fabricane ---
Fabricante::Fabricante()
{}

Fabricante::Fabricante(char nombre[], char domiciliop[], char telefono[])
{
 strcpy(this -> nombre, nombre);
 strcpy(this -> domicilio, domicilio);
 strcpy(this -> telefono, telefono);
}

void Fabricante::cambiaDomicilio(char nuevo_domicilio[])
{
 strcpy(domicilio, nuevo_domicilio); 
}

void Fabricante::cambiaTelefono(char nuevo_telefono[])
{
 strcpy(telefono, nuevo_telefono);
}

// Sobrecarga de los operadores << y >>
istream &operator >>(istream &lee, Fabricante &objeto_fab)
{
 cout << "Ingrese el nombre del fabricante: "; 
 lee >> objeto_fab.nombre;
 cout << "\nIngrese el domicilio del fabricate: "; 
 lee >> objeto_fab.domicilio;
 cout << "\nIngrese el telefono del fabricante: ";
 lee >> objeto_fab.telefono;

 return lee;
}

ostream &operator <<(ostream &escribe, Fabricante &objeto_fab)
{
 cout << "\n --- Datos del Fabricante --- \n";
 escribe << "Nombre: " << objeto_fab.nombre
         << "\nDomicilio: " << objeto_fab.domicilio
         << "\nTelefono: " << objeto_fab.telefono << endl;

 return escribe;
}

// --- Definición de los métodos de la clase Producto ---
template <class T>
Producto<T>::Producto()
{}

template <class T>
Producto<T>::Producto(int clave, char nombre[], float precio, T proveedor)
{
 this -> clave = clave;
 strcpy(this -> nombre, nombre);
 this -> precio = precio;
 se_compra_a = proveedor;
}

template <class T>
void Producto<T>::imprime()
{
 cout << "\nDatos del producto: \n";
 cout << "Clave: " << clave
      << "\nNombre: " << nombre
      << "\nPrecio: " << precio
      << "\nProvisto por: " << se_compra_a << endl;
}

template <class T>
void Producto<T>::actualizaPrecio(float nuevo_precio)
{
 precio = nuevo_precio;
}

// Definición de la función que usará ambas clases
void usaPlantilla()
{
 Fabricante cables_mexico;
 int clave_del_proveedor;

 cin >> cables_mexico;

 // Se reemplaza T por le tipo 'Fabricante'
 char articulo[MAX] = "Cable de telefono";
 Producto<Fabricante> cable_de_telefono(1050, articulo, 100, cables_mexico);

 cable_de_telefono.imprime(); 

 cout << "\nIngrese la clave del proveedor de las cajas concentradoras: ";
 cin >> clave_del_proveedor;

 // Se reemplaza T por el tipo int
 strcpy(articulo, "Cajas concentradores");
 Producto<int> cajas(2600, articulo, 450, clave_del_proveedor);
 
 cajas.imprime();
}
