/*
 Fecha: 05-09-2022
 hora: 5:27pm
 Descripción:
  En el siguiente script definimos la clase Complejo sobrecargando los operadores + y -, además
  se sobrecarga el método que sobrecarga el operador - para que, tanto podamos restar  número complejos
  como volerlos negativos (su parte real y su parte imaginaria; sus atributos).
  También se sobrecarga el operado << para imprimir números complejos.
*/

#include <iostream>

using namespace std;

// --- Clase para definir números complejos ---
class Complejo
{
 public:
  Complejo(double real = 0, double imaginario = 0);
  Complejo operator +(Complejo);
  Complejo operator -(Complejo);
  Complejo operator -();
  friend ostream &operator <<(ostream &, Complejo &);

 private:
  double real, imaginario;
};

// --- Definiciones ---
Complejo::Complejo(double real, double imaginario)
 : real(real), imaginario(imaginario)
{}

Complejo Complejo::operator +(Complejo numero)
{
 return Complejo(real + numero.real, imaginario + numero.imaginario);
}

Complejo Complejo::operator -(Complejo numero)
{
 return Complejo(real - numero.real, imaginario - numero.imaginario);
}

Complejo Complejo::operator -()
{
 return Complejo(-real, -imaginario);
}

ostream &operator <<(ostream &escribe, Complejo &numero)
{
 escribe << "\nParte real: " << numero.real << "\nParte imaginaria: " << numero.imaginario;

 return escribe;
}

// --- Prototipo de funciones ---
void menu(); // Función que propociona las opciones para crear, sumar, restar y hacer negativo un número Complejo

int 
main()
{
 menu();  

 return 0;
}

void menu()
{
 int opcion;
 double parte_real, parte_imaginaria;
 Complejo* primer_complejo, *segundo_complejo, *tercer_complejo = new Complejo();
 
 do
 {
  cout << "(1) Suma de numeros complejos\n"
          << "(2) Resta de numero negativos\n"
          << "(3) Creacion de un numero complejo negativo\n"
          << "(0) Salir \n\t Ingrese su opcion: ";
  cin >> opcion;
 
  cout << endl;

  switch(opcion)
  {
   case 0:
    cout << "Nos vemos! \n\t y espero y pronto\n";
   break;

   case 1: 
    cout << "--- Primero numero complejo a sumar ---"
             << "\nIngrese parte real: "; cin >> parte_real;
    cout << "\nIngrese parte imaginaria: "; cin >> parte_imaginaria;
    primer_complejo = new Complejo (parte_real, parte_imaginaria);
    cout << "--- Segundo numero complejo a sumar ---"
             << "\nIngrese parte real: "; cin >> parte_real;
    cout << "\nIngrese parte imaginaria: "; cin >> parte_imaginaria;
    segundo_complejo = new Complejo(parte_real, parte_imaginaria);
    // Resultado de la suma de complejo1 y complejo2
    *tercer_complejo = *primer_complejo + *segundo_complejo;
    cout << "\nResultado de la suma de ambos numero complejos: " << *tercer_complejo << endl << endl;
   break;

   case 2: 
    cout << "--- Primero numero complejo a restar ---"
             << "\nIngrese parte real: "; cin >> parte_real;
    cout << "\nIngrese parte imaginaria: "; cin >> parte_imaginaria;
    primer_complejo = new Complejo(parte_real, parte_imaginaria);
    cout << "--- Segundo numero complejo a restar ---"
             << "\nIngrese parte real: "; cin >> parte_real;
    cout << "\nIngrese parte imaginaria: "; cin >> parte_imaginaria;
    segundo_complejo = new Complejo(parte_real, parte_imaginaria);
    // Resultado de la suma de complejo1 y complejo2
    *tercer_complejo = *primer_complejo - *segundo_complejo;
    cout << "\nResultado de la diferencia de ambos numero complejos: " << *tercer_complejo << endl << endl;     
   break;

   case 3: 
   {
    cout << "--- Numero complejo ---"
             << "\nIngrese parte real: "; cin >> parte_real;
    cout << "\nIngrese parte imaginaria: "; cin >> parte_imaginaria;
    Complejo com(parte_real, parte_imaginaria);
    com = -com;
    cout << "Numero complejo a negativo: " << com << endl << endl;
   break;
  }

   default:
    cout << "Opcion no valida!\n";
  }

 } while(opcion != 0);
}