#include <iostream>
#include <string>

using namespace std;

#define MAX 10 // Número de tareas que nos permite el arreglo pila

// ------ Clases ------
// Clase Tarea 
class Tarea
{
 public:
  void creaTarea(int);
  void muestraTarea();

 private:
  int tipo;
  string nombre, descripcion;  
};

// clase PilaArreglo de tareas
class PilaArreglo
{
 public:
  PilaArreglo();
  void muestraTareas();
  void push();
  void pop();

 private:
  Tarea tareas[MAX];
  int tope;  
};

class Nodo; // Prototipo Nodo

// Clase PilaLista de tareas
class PilaLista
{
 public: 
  PilaLista();
  void muestraTareas();
  void insertaUltimo(Nodo);
  void muestraPila();
  void push();
  void pop();

 private:
  Nodo* inicio, *ultimo;
};

class Nodo
{
 public:
  Nodo();
  friend class PilaLista;

 private:
  Tarea objeto_tarea;
  Nodo* siguiente;
};
// ---- Fin de las clases ----

// Prototipo de la función que asignará tareas usando el arreglo y pila
void asignarTareas();
void usarPilaArreglo();
void usarPilaLista();

int
main()
{
 setlocale(LC_ALL, "");
 asignarTareas();
 
 return 0;
}

// ------ Definición de los métodos de cada clase ------
void Tarea::creaTarea(int tipo)
{
 this -> tipo = tipo;
 cout << "------ Nueva Tarea ------\n"
      << "Nombre de la tarea (una palabra): "; cin >> nombre;
 cout << "\nDescripción: "; cin >> descripcion;
}

void Tarea::muestraTarea()
{
 cout << "----- Datos de la Tarea ------\n";
 cout << "Tipo de tarea: ";
 if(tipo == 0)
  cout << "educativa";
 else
  if(tipo > 1) 
   cout << "laboral";
  else
   cout << "entretenimiento";
  cout << "\nNombre: " << nombre
       << "\nDescripcion: " << descripcion << "\n\n";
}

PilaArreglo::PilaArreglo()
{
 tope = 0; // El arreglo está vacío cuando es igual a cero
}

void PilaArreglo::muestraTareas()
{
 if(tope)
 {
  cout << "\n----- Tareas Por Hacer -----\n";
  for(int i = tope - 1; i >= 0; i --) 
   tareas[i].muestraTarea();  
 }
 else
  cout << "La pila no tiene tareas que mostrar\n\n";
}

void PilaArreglo::push()
{
 if(tope < MAX)
 {
  int tipo_de_tarea;
  Tarea objeto_tarea;

  do
  {
   cout << "Tipo de la tarea:\n"
        << "(0) educativa\n"
        << "(1) entretenimiento\n"
        << "(2) laboral\n"
        << "\n  Elige: ";
   cin >> tipo_de_tarea;

   system("cls");

   if(tipo_de_tarea < 0 || tipo_de_tarea > 2)
    cout << "Tipo de tarea no válida. Verifiquelo.";
  }while(tipo_de_tarea < 0 || tipo_de_tarea > 2);

  objeto_tarea.creaTarea(tipo_de_tarea);
  tareas[tope ++] = objeto_tarea; 
 }
 else
  cout << "La pila está llena!!!\n\n";
}

void PilaArreglo::pop()
{
 if(tope > 0)
  tareas[-- tope].muestraTarea();
 else
  cout << "No hay tareas en la pila!!!\n\n";
}

PilaLista::PilaLista()
{
 inicio = NULL;
 ultimo = NULL;
}

void PilaLista::muestraPila() 
{
   while(inicio)
   {
    inicio -> objeto_tarea.muestraTarea();
    inicio = inicio -> siguiente;
    if(!inicio) cout << "NULL\n";
    else
    cout << "YUup!";
   }
}

void PilaLista::muestraTareas()
{
 if(inicio == NULL)
  cout << "No hay tareas dadas de alta\n";
 else
 {
  PilaLista lis;
  Nodo* aux = inicio;
  cout << "\n----- Tareas por hacer ---- \n";
  while(aux != NULL)
  {
   lis.insertaUltimo(*aux); 
   cout << endl;
   aux = aux -> siguiente;
  }

  lis.muestraPila();
 }
}

void PilaLista::insertaUltimo(Nodo tarea)
{
 if(!inicio)
 {
  inicio = &tarea;
  ultimo = &tarea;
  ultimo -> siguiente= NULL;
 }
 else
 {
  tarea.siguiente = inicio;
  inicio = &tarea;
 }
}

void PilaLista::push()
{
 Nodo* nuevo = new Nodo();
 int tipo_de_tarea;

 do
 {
   cout << "Tipo de la tarea:\n"
        << "(0) educativa\n"
        << "(1) entretenimiento\n"
        << "(2) laboral\n"
        << "\n  Elige: ";
   cin >> tipo_de_tarea;

   system("cls");

   if(tipo_de_tarea < 0 || tipo_de_tarea > 2)
    cout << "Tipo de tarea no válida. Verifiquelo.";
 }while(tipo_de_tarea < 0 || tipo_de_tarea > 2);
 
 nuevo -> objeto_tarea.creaTarea(tipo_de_tarea);
 if(inicio == NULL)
 {
  inicio = nuevo;
  ultimo = nuevo;
 }
 else
 {
  ultimo = inicio;
  while(ultimo -> siguiente != NULL)
   ultimo = ultimo -> siguiente;
  ultimo -> siguiente = nuevo;
  ultimo = nuevo;
 }
}

void PilaLista::pop()
{
 if(inicio == NULL)
  cout << "No hay tareas dadas de alta\n\n";
 else
 {
  Nodo* aux1 = inicio, *aux2 = inicio;
  ultimo -> objeto_tarea.muestraTarea();

  while(aux1 -> siguiente != NULL)
  {
   aux2 = aux1;
   aux1 = aux1 -> siguiente;
  }

  if(aux1 == inicio)
  {
   inicio = inicio -> siguiente;
   delete(aux1);
  }
  else 
  {
   ultimo = aux2;
   aux2 -> siguiente = NULL;
   delete(aux1);
  }
 }
}

Nodo::Nodo()
{
 siguiente = NULL;
}

// --------- Definición de funciones ------
void asignarTareas()
{
 int opcion;
 
 do
 {
  cout << "1. Crear hasta 10 tareas\n"
       << "2. Crear tantas tareas como se quiera\n"
       << "SALIR: Elija un número menor a 1\n"
       << "\n\tIngresar opción: ";
  cin >> opcion;

  system("cls");

  switch(opcion)
  {
   case 1: usarPilaArreglo(); break;
   case 2: usarPilaLista(); break;
   default:
    if(opcion > 2)
     cout << "Opción NO válida. Elige la 1 o la 2!\n\n";
    else
     cout << "Prceso terminado\n";
  }
 }while(opcion >= 1);
}

void usarPilaArreglo()
{
 PilaArreglo pila_fija;
 int opcion; 

 do
 {
  cout << "1. Crear una tarea\n"
       << "2. Tachar una tarea\n"
       << "3. Mostrar todas las tareas\n"
       << "SALIR: elige un número menor a 1\n"
       << "\n\tElegir: ";
  cin >> opcion;

  system("cls");

  switch(opcion)
  {
   case 1:
    pila_fija.push();
    cout << "\n\n";
   break;
   case 2:
    cout << "Tarea tachada o realizada: \n\n";
    pila_fija.pop();
   break;
   case 3:
    pila_fija.muestraTareas();
   break;
   default:
    if(opcion < 1)
     cout << "Regresando al menú principal... \n\n";
    else
     cout << "No existe es opción!!!\n\n";
  }
 }while(opcion >= 1);
}

void usarPilaLista()
{
 PilaLista pila_dinamica;
 int opcion; 

 do
 {
  cout << "1. Crear una tarea\n"
       << "2. Tachar una tarea\n"
       << "3. Mostrar todas las tareas\n"
       << "SALIR: elige un número menor a 1\n"
       << "\n\tElegir: ";
  cin >> opcion;

  system("cls");

  switch(opcion)
  {
   case 1:
    pila_dinamica.push();
    cout << "\n\n";
   break;
   case 2:
    cout << "Tarea tachada o realizada: \n\n";
    pila_dinamica.pop();
   break;
   case 3:
    pila_dinamica.muestraTareas();
   break;
   default:
    if(opcion < 1)
     cout << "Regresando al menú principal... \n\n";
    else
     cout << "No existe es opción!!!\n\n";
  }
 }while(opcion >= 1);
}