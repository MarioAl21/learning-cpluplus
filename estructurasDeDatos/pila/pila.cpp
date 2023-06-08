#include <iostream>

using namespace std;

#define MAX 5 // tamaño del arreglo

template <class T>
class Pila
{
 public:
  Pila();
  void push(T);
  void pop(T*);
  bool pilaLlena();
  bool pilaVacia();
  void muestraLaPila();

 private:
  int tope;
  T datos[MAX];
};

void usaPila();

int 
main()
{
 usaPila();

 return 0;
}

template <class T>
Pila<T>::Pila(): tope(-1) 
{} 

template <class T>
void Pila<T>::push(T dato)
{
 datos[++ tope] = dato;
}

template <class T>
void Pila<T>::pop(T* extrae)
{
 *extrae = datos[tope --];
}

template <class T>
bool Pila<T>::pilaLlena()
{
 if(tope == MAX - 1)
  return 1; // true
 else
  return 0; // false
}

template <class T>
bool Pila<T>::pilaVacia()
{
 if(tope == -1)
  return 1;
 else
  return 0;
}

template <class T>
void Pila<T>::muestraLaPila()
{
 if(!pilaVacia())
 {
  int i = tope;
  cout << "\n----- Pila -----\n";
  while(i >= 0)
   cout << "Elemento " << i + 1 << ": " << datos[i --] << endl;
  cout << "----------------\n";
 }
 else 
  cout << "\nNo hay elementos en la pila que mostrar\n";
}

void usaPila()
{
 Pila<int> objeto_pila;
 int valor = 0;

 while(!objeto_pila.pilaLlena())
  objeto_pila.push(++ valor);

 objeto_pila.muestraLaPila();

 cout << "\n----- Extracciones (" << valor << ") -----";
 while(!objeto_pila.pilaVacia())
 {
  objeto_pila.pop(&valor);
  cout << "\nElemento extraido de la pila: " << valor;
 }
 cout << "\n----------------------------\n";
}