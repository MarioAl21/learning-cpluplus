/*
 Fecha: 05-20-2022
 Hora: 8:52pm
 Descripción:
  El siguiente programa se declara la clase Volumen la cual es la
  clase base para las clases derivadas Libro y revista.
  Volumen incluye el método virtual imprime y la clase Biblioteca
  incluye un arreglo de objetos polimórficos.
*/

#include <iostream>
#include <string.h>

using namespace std;

// ------- Clases -------
// Clase Base
class Volumen
{
 public:
  Volumen();
  Volumen(char*);
  virtual ~Volumen();
  virtual void imprime();

 protected:
  char* nombre_de_volumen;
};

// Clase derivada 1
class Libro: public Volumen
{
 public:
  Libro();
  Libro(char*, int);
  ~Libro() {}
  virtual void imprime(); 

 private:
  int anio_de_edicion;
};

// Clase derivada 2
class Revista: public Volumen
{
 public:
  Revista();
  Revista(char*, int);
  ~Revista() {}
  virtual void imprime();

 private:
  int numero;
};

// Esta clase usa un arreglo de objetos polimórficos
class Biblioteca
{
 public:
  Biblioteca();
  Biblioteca(int, char[]);
  ~Biblioteca();
  void registraVolumen(Volumen*);
  void imprime();
  int numeroDeVolumenes();

 private:
  int max_volumen, numero_de_volumen;
  char nombre[60];
  Volumen* vols[];
};
// ------------------------

// ------- Prototipos de funciones -------
void usaPolimorfismo();

int
main()
{
 setlocale(LC_ALL, "");
 usaPolimorfismo();

 return 0;
}

// -------- Definición de métodos ---------
// Inicio de los métodos de la clase Volumen
Volumen::Volumen()
{}

Volumen::Volumen(char* nombre_de_volumen)
{
 this -> nombre_de_volumen = new char[strlen(nombre_de_volumen) + 1];
 strcpy(this -> nombre_de_volumen, nombre_de_volumen);
}

Volumen::~Volumen()
{}

void Volumen::imprime()
{
 //cout << "\nNombre: " << nombre_de_volumen << endl;
}
// Fin de los métodos de la clase Volumen

// Inicio de los métodos de la clase Libro
Libro::Libro()
{}

Libro::Libro(char* nombre_de_volumen, int anio_de_edicion)
 : Volumen(nombre_de_volumen), anio_de_edicion(anio_de_edicion)
{} 

void Libro::imprime()
{
 cout << "\nNombre del libro: " << nombre_de_volumen
      << "\nAño de edición del libro: " << anio_de_edicion << endl;
}
// Fin de los métodos de la clase Libro

// Inicio de los métodos de la clase Libro
Revista::Revista()
{}

Revista::Revista(char* nombre_de_volumen, int numero)
 : Volumen(nombre_de_volumen)
{
 this -> numero = numero;
}

void Revista::imprime()
{
 cout << "\nNombre de la revista: " << nombre_de_volumen
      << "\nNumero de la revista: " << numero << endl;
}
// Fin de los métodos de la clase Revista

// Inicio de los métodos de la clase Biblioteca
Biblioteca::Biblioteca()
{}

Biblioteca::Biblioteca(int max_volumen, char nombre[])
{
 int indice;
 this -> max_volumen = max_volumen;
 numero_de_volumen = 0;
 strcpy(this -> nombre, nombre);
 *vols = new Volumen[max_volumen];

 for(indice = 0; indice < max_volumen; indice ++)
  vols[indice] = NULL;
}

Biblioteca::~Biblioteca()
{
 //delete[] vols; // NOTA! Revisar si así se sigue liberando memoria de una arreglo de apuntadores
 cout << "\nNúmero de volumenes en la biblioteca: " << numero_de_volumen << endl;
 imprime(); 
}

void Biblioteca::registraVolumen(Volumen* nuevo_volumen)
{
 if(max_volumen - 1 >= numero_de_volumen)
  vols[numero_de_volumen ++] = nuevo_volumen;
}

void Biblioteca::imprime()
{
 int indice;
 
 cout << "\n------ Acervo de la biblioteca -------\n";

 if(numero_de_volumen)
  for(indice = 0; indice < numero_de_volumen; indice ++)
   vols[indice] -> imprime();
}

int Biblioteca::numeroDeVolumenes()
{
 return numero_de_volumen;
}
// Fin de los métodos de la clase Biblioteca 
//---------------------------------------------

// --------- Definición de funciones ----------
void usaPolimorfismo()
{
 char identificador[100] = "Refugio del conocimiento";
 Biblioteca objeto_biblioteca(10, identificador); // Instancia biblioteca con un máximo de 10 objetos polimórficos para guardar
 
 // Declaramos dos objetos de tipo libro y revista
 strcpy(identificador, "Estructura de datos");
 Libro v1(identificador, 2006);
 strcpy(identificador, "Science");
 Revista v2(identificador, 8);

 // Registramos los volumenes en nuestra biblioteca
 objeto_biblioteca.registraVolumen(&v1); 
 objeto_biblioteca.registraVolumen(&v2); 

 // Se imprimen todos los objetos polimórficos previamente registrados
 objeto_biblioteca.imprime();
}