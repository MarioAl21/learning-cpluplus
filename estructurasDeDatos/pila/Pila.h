/*
 Esta cabecera es usada por la aplicación registroCheques.cpp
*/	
#include <iostream>
#define MAX 5

// Plantilla de la clase Pila
template <class T>
class Pila
{
 public:
  Pila();
  void operator +(T);
  void operator -(T*);
  bool pilaVacia();
  bool pilaLlena();
  void muestraPila();

 private:
  int tope;
  T datos[MAX]; 
};

	template <class T>
Pila<T>::Pila(): tope(-1)
{}

template <class T>
void Pila<T>::operator +(T dato)
{
 datos[++ tope] = dato;
}

template <class T>
void Pila<T>::operator -(T* extrae)
{
 *extrae = datos[tope --];
}

template <class T>
bool Pila<T>::pilaLlena()
{
 if(tope == MAX - 1)
  return true; // 1
 else
  return false; // 0
}

template <class T>
bool Pila<T>::pilaVacia()
{
 if(tope == - 1)
  return true; // 1
 else
  return false; // 0
}

template <class T>
void Pila<T>::muestraPila()
{
 for(int i = tope; i >= 0; i --)
  std::cout << "\nElemento " << i + 1 << ":\n" << datos[i] << std::endl;
}

