/*
 Descripci�n:
  Se propone un script que muestra un men� de diferentes bebidas las cuales puede ser escogidas por el usuario. 
  Cada bebida se describe por un nombre, un precio y un tiempo de elaboraci�n.
  Adem�s de agregarlas el usuario debe poder visualizarlas al momento de solicitarlas (esto sucede mediante su eliminaci�n).
  Para lograrlo se hace uso de las siguientes clases:
   *Bebida
   *Nodo
   *ColaCircular
  Nota: La forma en que se implementar� la Cola Circular (Primero en entrar primero en salir) ser� mediante una lista Doblemente enlazada
  (el nodo tiene dos apuntadores en lugar de uno).
  Esto permitir� al usuario no solo visualizar la bebida actual, sino adem�s la anterior (n-�sima) y la posterior(bebida 2).  
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

// Clase Bebida
class Bebida{
 public:
  Bebida();
  void nombraBebida(char[]);
  void asignaPrecio(float);
  void muestraBebida();
 private:
  char nombre[60];
  float precio;
  int tiempo_de_elaboracion;
};

class ColaCircular;

class Nodo{
  public:
   Nodo();
   friend class ColaCircular;
  private:
   Bebida bebida_a_ordenar;
   Nodo *anterior, *siguiente;
};

class ColaCircular
{
 public:
  ColaCircular();
  void push(char[], float); // Inserta al final siguiendo la l�gica de la cola
  void pop(); // Elimina SIEMPRE el primer nodo
  void muestraBebidas();
  void mostrarAnteriorSiguiente();
  Nodo* obtenLista();
 private:
  Nodo *inicio, *final;
};

// Funci�n que usar� la ColaCircular
void usaColaCircular(){
 ColaCircular cc; 
 int valor = 1, opcion;
 Nodo* bebidas_en_preparacion = NULL;
 char nombre_de_bebida[60];
 float precio_de_bebida;
 
 do{
  cout << "\n\n(1) Ordenar Bebida"
       << "\n(2) Despachar Bebida"
       << "\n(3) Mostrar Bebida pr�xima a despacharse" 
       << "\n\nElige: ";
  cin >> opcion;

  system("cls");

  switch(opcion){
   case 1:
    cout << "\nIngresa el nombre de la bebida a ordenar: "; 
	cin >> nombre_de_bebida;
	cout << "\nIngrese precio de la bebida: "; 
	cin >> precio_de_bebida;
    cc.push(nombre_de_bebida, precio_de_bebida); 
   break;
   case 2:
    cc.pop();
   break;
   case 3:
    cc.muestraBebidas();
	bebidas_en_preparacion = cc.obtenLista();
	if(bebidas_en_preparacion != NULL)
	{
	 cout << "\nMostrar carrucel de bebidas (bebida anterior y siguiente) (1)Si (2)No: ";
	 cin >> opcion;
	 if(opcion == 1)
		cc.mostrarAnteriorSiguiente();
	 else 
	   cout << "\nRegresando al men� principal...\n\n";
	}
   break;
  }
 }while(opcion != 0);
}

int
main()
{ 
 srand(time(0));
 setlocale(LC_ALL, "");
 usaColaCircular(); 

 return 0;
}

// --- Definici�n de m�todos ---
// M�todos de Bebida
Bebida::Bebida(){
 tiempo_de_elaboracion = (rand() % 30) + 1; // de 1 a 31 min
}

void Bebida::nombraBebida(char nom[]){
 strcpy(nombre, nom);
}

void Bebida::asignaPrecio(float p){
 precio = p;
}

void Bebida::muestraBebida(){
 cout << "\nNombre: " << nombre
      << "\nPrecio: " << precio << "$"
      << "\nTiempo de elaboraci�n aproximado: " << tiempo_de_elaboracion << " min" << endl;
}

// M�todos de Nodo
Nodo::Nodo(){
 anterior = siguiente = NULL; // Los dos apuntadores comienzan apuntando a NULL
}

// M�todos de ColaCircular
ColaCircular::ColaCircular(){
 inicio = final = NULL;
}

void ColaCircular::push(char nombre_bebida[], float precio_bebida){
 Nodo* nuevo = new Nodo(); // Paso 1. Creamos el nodo
 nuevo -> bebida_a_ordenar.nombraBebida(nombre_bebida); // Paso 2. Le asignamos su nombre
 nuevo -> bebida_a_ordenar.asignaPrecio(precio_bebida); // Paso 3. Le asignamos su precio
 nuevo -> anterior = final; // Paso 3. Enlazamos el apuntador anterior al nodo apuntado por final

 if(inicio == NULL) // Si NO hay nodos en la lista el nodo reci�n creado ser� el primero
  inicio = nuevo;
 else{ // Si hay al menos un nodo en la lista ENTONCES el nodo al final enlaza su apuntador al nodo reci�n creado 
  final -> siguiente = nuevo; // final "engancha" a nuevo quien se convierte en el �ltimo nodo
  nuevo -> siguiente = inicio; // el �ltimo nodo apunta a inicio para cerrar la cola circular por el extremo derecho
  inicio -> anterior = nuevo; // el primer nodo apunta al del final para cerrar cola circular por el extremo izquierdo
 }
 
 final = nuevo; // Final se reasigna para ser el �ltimo nodo
}

void ColaCircular::pop(){
 Nodo* desencola = inicio;

 if(inicio != NULL){ // La lista NO est� vac�a
  if(desencola -> siguiente != NULL){ // Queremos saber si hay m�s de UN nodo en la lista
   inicio = inicio -> siguiente; // Inicio pasa al siguiente nodo
   if(inicio == final) {
    inicio -> anterior = NULL; // El apuntador anterior del nodo despu�s del primero deja de apuntar al nodo del inicio
    final -> siguiente = NULL;
   }
   else {
    inicio -> anterior = final; 
    final -> siguiente = inicio;
   }
  }
  else 
   inicio = final = NULL; // SOLO hay un nodo en la lista y se ignora
  cout << "\nBebida despachada: "; desencola -> bebida_a_ordenar.muestraBebida();
  delete(desencola); // Ya sea que haya uno o varios nodos eliminamos el que est� al inicio
 } else 
  cout << "\nNo hay bebidas por elaborar!!!\n";
 
 cout << endl; 
}

void ColaCircular::muestraBebidas(){
 Nodo* muestra = inicio;

 if(inicio != NULL){
  if(inicio -> siguiente != NULL){
   while(muestra -> siguiente != inicio){
    muestra -> bebida_a_ordenar.muestraBebida();
    muestra = muestra -> siguiente;
   }
  }
  muestra -> bebida_a_ordenar.muestraBebida(); 	
 }
 else
  cout << "\nNo hay bebidas en proceso de elaboraci�n.\n";
 cout << endl;
}

void ColaCircular::mostrarAnteriorSiguiente(){
 if(inicio -> anterior != NULL && inicio -> siguiente != final) 
 {
  inicio -> anterior -> bebida_a_ordenar.muestraBebida(); cout << " <- "; 
 }
 else
  cout << "\nA�n NO se ha ordenado m�s de 2 bebidas.\n";
 
 inicio -> bebida_a_ordenar.muestraBebida();
 
 if(inicio -> siguiente != NULL)
 { 
  cout << " -> "; inicio -> siguiente -> bebida_a_ordenar.muestraBebida(); 
 }
 else 
  cout << "\nA�n NO hay una segunda bebida en preperaci�n.\n";
 
 cout << endl;
}

Nodo* ColaCircular::obtenLista() { return inicio; }