/*
 Descripcion:
 En siguiente script incluye tres clases:
  -Proceso
  -Nodo (que incluira un proceso)
  -Cola que permitira "encolar" cuantos procesos se requieran ejecutar.
 Nota: La cola sera simple y se implementara utilizando una
       lista ligada simple para hacer uso de la memoria dinamica
       del ordenador y asi definir un indeterminado numero de procesos.

 La idea detras de todo esto es registrar procesos que se llevan a cabo en un
 ordenador y clasificarlos segun su tipo (0, 1 y 2) para posteriormente
 ejecutarlos en el orden en que se produjeron. He ahi el porque usar una
 estructura de tipo Cola.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h> // Para generara numeros aleratorios

using namespace std;

#define MAX 3 // Numero maximo de procesos (0-2)

class ColaLista; // Prototipo para la clase Nodo y permitir la amistad

// clase Proceso
class Proceso
{
 public:
  Proceso();
  void muestraProceso(); // Solo recibe el nombre del proceso
  int obtenTipo(); // Recupera el tipo de proceso para saber a que cola pertenece el proceso
  void asignaNombre(char[]);
 private:
  char nombre[60];
  int tamanio, tipo;
};

// Clase Nodo que almacenara un proceso cuando este se genere
class Nodo
{
 public:
  Nodo();
  void nombraProceso(char[]);
  int obtenTipoDeProceso();
  friend class ColaLista;
 private:
  Proceso objeto_proceso;
  Nodo* siguiente;
};

// Clase Cola implementando una lista
class ColaLista
{
 public:
  ColaLista();
  void encolaProceso(Nodo*); // Recibe el nodo a econlar pues este se crea afuera
  void ejecutaProceso();
  void muestraProcesos();
  int obtenProcesos();
 private:
  int procesos; // Numero de procesos dentro de la cola
  Nodo* inicio; // Solo se hara de uso de inicio
};

// Funcion que manipulara la clase ColaLista
void gestionaProcesos()
{
 srand(time(0)); // Obtiene el tiempo de nuestro reloj como valor semilla de rand() y generara numeros aleatorios
 ColaLista* colas[MAX]; // Un arreglo para guardar las colas y la cola a crear
 Nodo* nuevo_proceso; // Crea el nodo con el proceso a encolar en tiempo de compilacion
 int opcion, tipo_de_proceso, procesos_por_ejecutar = 0;
 char nombre_proceso[60];

 for(int i = 0; i < MAX; i ++)
  colas[i] = new ColaLista(); // Creamos tres colar con apuntadores inicio NULOS

 do{
  cout << "\n\n----- Menu -----\n"
       << "(1) Crear un proceso\n"
       << "(2) Ejecutar un proceso\n"
	   << "(3) Mostrar todos los procesos de una cola (si existen)"
       << "\nPARA SALIR: ingrese un 0 o menos (numero entero)"
	   << "\n\nESTATUS EN PROGRESO:"
       << "\nColas con procesos en espera de ejecucion: " << procesos_por_ejecutar;
  if(procesos_por_ejecutar > 0)
  {
   cout << "\n\nProcesos por cola: ";
   cout << "\nProcesos en la cola 0: " << colas[0] -> obtenProcesos()
        << "\nProcesos en la cola 1: " << colas[1] -> obtenProcesos()
        << "\nProcesos en la cola 2: " << colas[2] -> obtenProcesos();
	
  }
  cout << "\n\nElegir: ";
  cin >> opcion;
  
  system("cls");

  switch(opcion){
   case 0:
    cout << "\nProceso terminado.\n\n";
   break;
   case 1:
    cout << "\nIngrese el nombre del proceso: ";
    cin >> nombre_proceso; // Leemos el nombre del proceso
    nuevo_proceso = new Nodo(); // Creamos el nodo con el proceso adentro
    nuevo_proceso -> nombraProceso(nombre_proceso); // Le damos nombre a dicho proceso
    tipo_de_proceso = nuevo_proceso -> obtenTipoDeProceso(); // Obetnemos el tipo de proceso
    colas[tipo_de_proceso] -> encolaProceso(nuevo_proceso); // Encolamos

    procesos_por_ejecutar ++;

    cout << "\n\nIFORMACION SOBRE LA COLA:";
    cout << "\n  *Proceso encolado en la COLA "<< tipo_de_proceso
	     <<"\n  *Numero de procesos encolados: " << colas[tipo_de_proceso] -> obtenProcesos() + 1 << "\n\n";
    colas[tipo_de_proceso] -> muestraProcesos();
    cout << endl;
   break;
   case 2:
    if(procesos_por_ejecutar > 0)
    {
     if(colas[0] -> obtenProcesos() > 0)
		cout << "\n\n  (0) Ejecutar proceso en la COLA 0\n";
	 else 
	    cout << "\n\n  La COLA 0 aun NO tiene procesos por ejecutar\n";
	 if(colas[1] -> obtenProcesos() > 0)
		cout << "  (1) Ejecutar proceso en la COLA 1\n";
	 else 
	    cout << "  La COLA 1 aun NO tiene procesos por ejecutar\n";
	 if(colas[2] -> obtenProcesos() > 0)
		cout << "  (2) Ejecutar proceso en la COLA 2\n";
	 else 
	    cout << "  La COLA 2 aun NO tiene procesos por ejecutar\n";
	 
	 cout << "\n\nElegir: ";
	 cin >> opcion;
	 cout << "\n\nProceso desencolado al inicio de la COLA " << opcion << "\n";
	 colas[opcion] -> ejecutaProceso();
	 procesos_por_ejecutar --;
	 cout << "\n\n";
	}
	else 
	 cout << "\nAun no hay procesos que ejecutar\n\n";
   break;
   case 3:
    if(procesos_por_ejecutar > 0)
    {
     if(colas[0] -> obtenProcesos() > 0)
		cout << "\n\n  (0) Mostrar todos los procesos en la COLA 0\n";
	 else 
	    cout << "\n\n  La COLA 0 aun NO tiene procesos por ejecutar\n";
	 if(colas[1] -> obtenProcesos() > 0)
		cout << "  (1) Mostrar todos los procesos en la COLA 1\n";
	 else 
	    cout << "  La COLA 1 aun NO tiene procesos por ejecutar\n";
	 if(colas[2] -> obtenProcesos() > 0)
		cout << "  (2) Mostrar todos los procesos en la COLA 2\n";
	 else 
	    cout << "  La COLA 2 aun NO tiene procesos por ejecutar\n";
	 
	 cout << "\n\nElegir: ";
	 cin >> opcion;
	 cout << endl;
	 colas[opcion] -> muestraProcesos();
	 cout << "\n\n";
	}
	else 
	 cout << "\nAun no hay procesos que ejecutar\n\n";
   break;
  }
  
  system("PAUSE");
  system("cls");
  
 }while(opcion >= 1); // Numero negativo o 0 para salir
}

int
main()
{
 gestionaProcesos();

 return 0;
}

// ------- Definicion de metodos -------
// Metodos de la clase Proceso
Proceso::Proceso(){
 tamanio  = (rand() % 280) + 1; // aleatorio entre 1 y 281
 tipo = rand() % MAX; // aletorio entre 0 y 2
}

void Proceso::muestraProceso(){
 cout << "---- Datos del proceso ----"
      << "\nNombre: " << nombre
      << "\nTamanio: " << tamanio
      << "\nTipo: " << tipo << endl;
}

int Proceso::obtenTipo(){
 return tipo;
}

void Proceso::asignaNombre(char nom[]){
 strcpy(nombre, nom);
}

// Metodos de la clase Nodo
Nodo::Nodo()
{ siguiente = NULL; }

void Nodo::nombraProceso(char nom[]){
  objeto_proceso.asignaNombre(nom);
}

int Nodo::obtenTipoDeProceso(){
 return objeto_proceso.obtenTipo();
}

// Metodos de la clase ColaLista
ColaLista::ColaLista()
{ inicio = NULL; procesos = 0; }

void ColaLista::encolaProceso(Nodo* nuevo){
 if(inicio == NULL)
  inicio = nuevo; // Si la lista esta vacia el nuevo nodo pasa al inicio
 else
 {
  Nodo* ultimo; // Nodo auxiliar para recorrer la cola y encontrar el ultimo nodo
  ultimo = inicio;
  while(ultimo -> siguiente != NULL) { ultimo = ultimo -> siguiente; }
  ultimo -> siguiente = nuevo; // Se enlaza el nodo al ultimo
 }
}

void ColaLista::ejecutaProceso(){
 if(inicio != NULL){ // Hay procesos en la cola
  Nodo* ejecuta = inicio; // Nodo auxiliar para ejecutar el proceso al inicio
  inicio = ejecuta -> siguiente; // Se reasigna el proceso
  ejecuta -> objeto_proceso.muestraProceso(); // Se imprime el proceso
  delete(ejecuta); // Se elimina el proceso
 }
 else
  cout << "\nNo hay procesos pendientes que ejecutar\n";
}

void ColaLista::muestraProcesos(){
 if(inicio != NULL)
 {
  procesos = 0; // El numero de procesos empieza en cero
  Nodo* muestra = inicio; // Nodo auxiliar que imprime cada proceso
  while(muestra != NULL){
   muestra -> objeto_proceso.muestraProceso();
   if(muestra -> siguiente == NULL)
    cout << " -> NULL";
   else
    cout << " -> ";
   muestra = muestra -> siguiente; // Nos movemos al siguiente nodo
   procesos ++;
  }
 }
 else
  cout << "\nNo hay procesos que mostrar\n";
 cout << endl;
}

int ColaLista::obtenProcesos() { return procesos; }
