/*
 Fecha: 05-5-2022
 Hora: 12:05pm
 Descripci�n:
 	En el siguiente programa se define la clase llamada Insecto
	que incluye un m�todo virtual que se redifinar� las clases
        derivadas: Mosca y Cucaracha.
 	El m�todo imprimir mostrar� los atributos seg�n la instancia
  	que lo invoque.	
	Nota: Tambi�n se incluy� el destructor de la clase base 
	como virtual.
*/

#include <iostream>
#include <string.h>

using namespace std;

// ------ Clases -------
class Insecto
{
 public:
  Insecto(char*, int, float, float, float);
  virtual ~Insecto();
  virtual void imprime();

 private:
  char nombre[60];
  int numero_de_patas;
  float tam_de_cabeza, tam_de_torax, tam_de_abdomen;
};

class Mosca: public Insecto
{
 public:
  Mosca(char*, int, float, float, float, int);
  virtual ~Mosca();
  virtual void imprime();

 private:
  int numero_de_alas;
};

class Cucaracha: public Insecto
{
 public:
  Cucaracha(char*, int, float, float, float, char*);
  virtual ~Cucaracha();
  virtual void imprime();
  char* getFeatures() { return caracteristicas_del_cuerpo; }

 private:
  char caracteristicas_del_cuerpo[60];
};
// -------------------------------

// --------- Prototipos ----------
// Prototipo que usar� el polim�rfismo
void usaPolimorfismo();
// -------------------------------

int
main()
{
 setlocale(LC_ALL, "");
 usaPolimorfismo(); // Ejecuci�n de la funci�n que imprime los datos de nuestros insectos 

 return 0;
}

// -------- Definiciones de los m�todos de las clases ------
// Inicio de los m�todos de la clase Insecto
Insecto::Insecto 
(
 char* nombre, int numero_de_patas, float tam_de_cabeza,
 float tam_de_torax, float tam_de_abdomen
)
{
 strcpy(this -> nombre, nombre);
 this -> numero_de_patas = numero_de_patas;
 this -> tam_de_cabeza = tam_de_cabeza;
 this -> tam_de_torax = tam_de_torax;
 this -> tam_de_abdomen = tam_de_abdomen;
}

Insecto::~Insecto()
{}

void Insecto::imprime()
{
 cout << "---- Datos del insecto ----"
      << "\nNombre: " << nombre
      << "\nN�mero de patas: " << numero_de_patas
      << "\nMedida de la cabeza: " << tam_de_cabeza
      << "\nMedidad del t�rax: " << tam_de_torax
      << "\nMedida del abdomen: " << tam_de_abdomen << endl;
}
// Fin de los m�todos de la clase Insecto

// Inicio de los m�todos de la clase Mosca
Mosca::Mosca
( 
 char* nombre, int numero_de_patas, float tam_de_cabeza,
 float tam_de_torax, float tam_de_abdomen, 
 int numero_de_alas  
)
: Insecto (
 nombre, numero_de_patas, tam_de_cabeza, 
 tam_de_torax, tam_de_abdomen
)
{
 this -> numero_de_alas = numero_de_alas;
}

Mosca::~Mosca()
{}

void Mosca::imprime()
{
 Insecto::imprime();
 cout << "N�mero de alas: " << numero_de_alas << endl;
}
// Fin de los m�todos de la clase Mosca

// Inicio de los m�todos de la clase Cucaracha
Cucaracha::Cucaracha
(
 char* nombre, int numero_de_patas, float tam_de_cabeza,
 float tam_de_torax, float tam_de_abdomen,
 char* caracteristicas_del_cuerpo
)
: Insecto (
 nombre, numero_de_patas, tam_de_cabeza,
 tam_de_torax, tam_de_abdomen
)
{
 strcpy (
  this -> caracteristicas_del_cuerpo, 
          caracteristicas_del_cuerpo
 );
}

Cucaracha::~Cucaracha()
{}

void Cucaracha::imprime()
{
 Insecto::imprime();
 cout << "Carter�sticas del cuerpo: " << caracteristicas_del_cuerpo
      << endl;
}
// Fin de los m�todos de la clase Cucaracha

// ---- Definici�n de funciones ----
void usaPolimorfismo()
{
 // Declaraci�n de apuntadores a dos objetos polim�rficos
 Insecto *mosca, *cucaracha;
 
 // Declaraci�n de un objeto Mosca y uno Cuaracha
 char nombre_de_insecto[60] = "Mosca";
 Mosca objeto_mosca(nombre_de_insecto, 6, 3, 1, 2, 4);
 strcpy(nombre_de_insecto, "Cucaracha");
 char descripcion[60] = "cuerpo aplanado";
 Cucaracha objeto_cucaracha (
  nombre_de_insecto, 6, 2, 8, 4, descripcion   
 );

 // Asignaci�n de direcci�n de los objeto Mosca y Cucaracha a los apuntadores Insecto
 mosca = &objeto_mosca;
 cucaracha = &objeto_cucaracha;

 // Invocaci�n del m�todo virtual imprime a trav�s de los objetos polim�rficos
 mosca -> imprime();
 cout << "\n\n";
 cucaracha -> imprime();
}