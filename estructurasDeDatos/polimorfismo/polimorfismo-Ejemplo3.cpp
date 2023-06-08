/*
 Fecha: 05-23-2022
 Hora: 5:20pm
 Descripci�n:
  Es siguiente programa es la demostraci�n de la explicaci�n del tema
  de clases abstractas y su apliaci�n.
  1. Se define una clase Figura como clase base para las clases derivadas
     Tri�ngulo, Cuadrado y Rect�ngulo.
  2. La clase base es abstracta mientras que las derivadas son concretas.
  3. En la clase Figura se incluye el m�todo virtual puro "calculaArea".
*/

#include <iostream>
#include <math.h>

using namespace std;

// ----- Clases ------
// Clase abstracta Figura
class Figura
{
 public:
  Figura();
  virtual float calculaArea() = 0;
};

// clase derivada 1 de la clase abstracta Figura
class Triangulo: public Figura
{
 public:
  Triangulo(float, float);
  virtual float calculaArea();

 protected:
  float base, altura;
};

// clase derivada 1 de la clase Tri�ngulo
class Equilatero: public Triangulo
{
 public:
  Equilatero(float, float);
  virtual float calculaArea();
};

// clase derivada 2 de la clase Tri�ngulo
class TRectangulo: public Triangulo
{
 public:
  TRectangulo(float, float);
  float calculaArea();
 private:
  float cateto1, cateto2, cateto3; 
};

// clase derivada 2 de la clase abstracta Figura 
class Rectangulo: public Figura
{
 public:
  Rectangulo(float, float);
  virtual float calculaArea();
 protected:
  float largo, alto;
};

// clase derivada 1 de la clase Rect�ngulo
class Cuadrado: public Rectangulo
{
 public:
  Cuadrado(float);
  float calculaArea();
};

// ----- Prototipos ------
// funci�n que har� uso de nuestra relaci�n anterior
void usaPolimorfismo();

int
main()
{
 setlocale(LC_ALL, "");
 usaPolimorfismo();

 return 0;
}

// ----- Definici�n de los m�todos de las clases -----
// Inicio de los m�todos de la clase Figura
Figura::Figura()
{}
// Fin de los m�todos de la clase Figura

// Inicio de los m�todos de la clase Tri�ngulo
Triangulo::Triangulo(float base, float altura)
{}

float Triangulo::calculaArea()
{
 return (base * altura / 2);
}
// Fin de los m�todos de la clase Tri�ngulo

// Inicio de los m�todos de la clase Equil�tero
Equilatero::Equilatero(float base, float altura)
 : Triangulo(base, altura)
{}

float Equilatero::calculaArea()
{
 return Triangulo::calculaArea();
}
// Fin de los m�todos de la clase Equil�tero

// Inicio de los m�todos de la clase TRect�ngulo
TRectangulo::TRectangulo(float cateto1, float cateto2)
 : Triangulo(cateto1, cateto2)
{
 this -> cateto1 = cateto1;
 this -> cateto2 = cateto2;
 cateto3 = sqrt(cateto1*cateto1 + cateto2*cateto2);
}

float TRectangulo::calculaArea()
{
 return (cateto1 * cateto2);
}
// Fin de los m�todos de la clase TRect�ngulo 

// Incio de los m�todos de la clase Rect�ngulo
Rectangulo::Rectangulo(float largo, float alto)
{
 this -> largo = largo;
 this -> alto = alto;
}

float Rectangulo::calculaArea()
{
 return (largo * alto);
}
// Fin de los m�todos de la clase Rect�ngulo

// Incio de los m�todos de la clase Cuadrado
Cuadrado::Cuadrado(float lado)
 : Rectangulo(lado, lado)
{}

float Cuadrado::calculaArea()
{
 return Rectangulo::calculaArea();
}
// Fin de los m�todos de la clase Cuadrado
// ------------------------------------------------------

// ---- Definci�n de prototipos -----
void usaPolimorfismo()
{
 Equilatero t1(5, 7);
 TRectangulo t2(3, 4);

 Rectangulo r1(2, 3);
 Cuadrado c1(5);

 cout << "\nArea del tri�ngulo rect�ngulo: " << t2.calculaArea() << endl;
}
// ----------------------------------