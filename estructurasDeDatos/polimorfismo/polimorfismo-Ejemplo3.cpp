/*
 Fecha: 05-23-2022
 Hora: 5:20pm
 Descripción:
  Es siguiente programa es la demostración de la explicación del tema
  de clases abstractas y su apliación.
  1. Se define una clase Figura como clase base para las clases derivadas
     Triángulo, Cuadrado y Rectángulo.
  2. La clase base es abstracta mientras que las derivadas son concretas.
  3. En la clase Figura se incluye el método virtual puro "calculaArea".
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

// clase derivada 1 de la clase Triángulo
class Equilatero: public Triangulo
{
 public:
  Equilatero(float, float);
  virtual float calculaArea();
};

// clase derivada 2 de la clase Triángulo
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

// clase derivada 1 de la clase Rectángulo
class Cuadrado: public Rectangulo
{
 public:
  Cuadrado(float);
  float calculaArea();
};

// ----- Prototipos ------
// función que hará uso de nuestra relación anterior
void usaPolimorfismo();

int
main()
{
 setlocale(LC_ALL, "");
 usaPolimorfismo();

 return 0;
}

// ----- Definición de los métodos de las clases -----
// Inicio de los métodos de la clase Figura
Figura::Figura()
{}
// Fin de los métodos de la clase Figura

// Inicio de los métodos de la clase Triángulo
Triangulo::Triangulo(float base, float altura)
{}

float Triangulo::calculaArea()
{
 return (base * altura / 2);
}
// Fin de los métodos de la clase Triángulo

// Inicio de los métodos de la clase Equilátero
Equilatero::Equilatero(float base, float altura)
 : Triangulo(base, altura)
{}

float Equilatero::calculaArea()
{
 return Triangulo::calculaArea();
}
// Fin de los métodos de la clase Equilátero

// Inicio de los métodos de la clase TRectángulo
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
// Fin de los métodos de la clase TRectángulo 

// Incio de los métodos de la clase Rectángulo
Rectangulo::Rectangulo(float largo, float alto)
{
 this -> largo = largo;
 this -> alto = alto;
}

float Rectangulo::calculaArea()
{
 return (largo * alto);
}
// Fin de los métodos de la clase Rectángulo

// Incio de los métodos de la clase Cuadrado
Cuadrado::Cuadrado(float lado)
 : Rectangulo(lado, lado)
{}

float Cuadrado::calculaArea()
{
 return Rectangulo::calculaArea();
}
// Fin de los métodos de la clase Cuadrado
// ------------------------------------------------------

// ---- Definción de prototipos -----
void usaPolimorfismo()
{
 Equilatero t1(5, 7);
 TRectangulo t2(3, 4);

 Rectangulo r1(2, 3);
 Cuadrado c1(5);

 cout << "\nArea del triángulo rectángulo: " << t2.calculaArea() << endl;
}
// ----------------------------------