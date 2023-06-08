/*
 Fecha: 06-05-2022
 Hora: 4:00pm
 Descripción: 
*/

#include <iostream>
#include <cctype>
#include <string.h> // Para el manejo de la clse String
using namespace std;

// ----------- Clases ------------
// Prototipo de clase Lista para que le sea visible a clase Nodo
class Lista;

// Clase Mascota
class Mascota
{
 public:
  // Get y Set para el nombre
  string getNombre();
  void setNombre(string);
  // Get y Set para la edad
  int getEdad();
  void setEdad(int);
  // Get y Set para la raza
  char getRaza();
  void setRaza(char);
  // Get y Set para el peso
  float getPeso(); 
  void setPeso(float);  

 private:
  string nombre;
  int edad;
  char raza;
  float peso;
};

// Clase Nodo
class Nodo
{
 public:
  Nodo();

  // Amistad otorgada a la clase Lista;
  friend class Lista;

 private:
  Mascota objeto_mascota; // De tipo char pues guardaremos letras del abecedario
  Nodo* siguiente;
};

// Clase Lista
class Lista
{
 public:
  Lista();
  void menu(); // Definirá las opciones para llamar a cada método
  void mostrarLista(); 
  Nodo* buscarRaza(char);
  Nodo* buscarNombreDeMascota(string);
  void insertarPrimero();
  void insertarUltimo();
  void insertarEspecifico(char);
  void eliminarTodo();
  void eliminarEspecifico(char);
  void ordenarAscXRaza();   

 private:
  int numero_de_mascota;
  Nodo *primero, *ultimo; // Apuntadores al primero y último objeto Nodo  
};

// --------- Fin de las clases ---------

int 
main()
{
 setlocale(LC_ALL, ""); // Para mostrar caracteres acentuados y especiales 

 Lista mascotas;
 mascotas.menu();
 cout << "ADIÓS :)\n";

 return 0;
}

// ----- Definición de los métodos de cada clase -----
// Métodos de la clase Mascota
string Mascota::getNombre()
{ return nombre; }

int Mascota::getEdad()
{ return edad; }

char Mascota::getRaza()
{ return raza; }

float Mascota::getPeso()
{ return peso; }

void Mascota::setNombre(string nuevo_nombre)
{ nombre = nuevo_nombre; }

void Mascota::setEdad(int nueva_edad)
{ edad = nueva_edad; }

void Mascota::setRaza(char nueva_raza)
{ raza = nueva_raza; }

void Mascota::setPeso(float nuevo_peso)
{ peso = nuevo_peso; }

// Métodos de la clase Nodo
Nodo::Nodo()
{
 siguiente = NULL;
}

// Método de la clase Lista
Lista::Lista()
{
 // Ambos apuntadores a una dirección nula
 primero = NULL;
 ultimo = NULL;
}

void Lista::menu()
{
 int opcion;
 bool decision;
 char etiqueta, mascota_raza;

 do
 {
  cout << "------------------- MENU -----------------\n";
  cout << "1) Agregar mascota al principio de la lista\n"
       << "2) Agregar mascota al final de la lista\n"
       << "3) Agregar mascota después de una mascota ya registrada\n"
       << "4) Dar de baja TODAS las de mascotas (Eliminar la lista)\n"
       << "5) Dar de baja una mascota\n"
       << "6) Ordenar mascotas de mayor a menor peso\n"
       << "7) Ordenar mascotas por raza (a - z)\n"
       << "Escriba un número negativo para SALIR.\n\n"
       << "Comando: ";

  cin >> opcion; 
  system("cls"); // "limpiamos" la consola

  switch(opcion)
  {
   case 1:
    insertarPrimero();
   break;

   case 2:
    insertarUltimo();
   break;

   case 3:
    cout << "Ingrese el caracter de la Raza que será usado como referencia: "; 
    cin >> mascota_raza;
    insertarEspecifico(mascota_raza);
   break;

   case 4:
    cout << "ADVERTENCIA. Está a punto de eliminar toda la lista!!!"
         << " ¿está seguro de hacerlo? (1) Sí (0) No: ";
    cin >> decision;
    if(decision)
     eliminarTodo(); 
    else
     cout << "\nEliminación aboratada.\n";
   break;

   case 5:
    cout << "\nIngrese la raza (a-z) a dar de baja: ";
    cin >> etiqueta;

    if(etiqueta < 'a' || etiqueta > 'z')
     etiqueta = tolower(etiqueta);   
  
    eliminarEspecifico(etiqueta); 
   break;

   case 6:
    // ordenarAscXNombre();
   break;

   case 7:
    ordenarAscXRaza();
   break;

   default:
    if(opcion < 0 || opcion > 7)
    cout << "\nOpción NO válida!!! Elija opciones 1 a 7.\n\n";
  }
 } while(opcion >= 1);
}

void Lista::mostrarLista()
{
 if(primero == NULL)
  cout << "\nLa lista está vacía :(\n\n";
 else
 {
  numero_de_mascota = 0; 
  Nodo* aux = primero;
  while(aux != NULL)
  {  
   numero_de_mascota ++;
   cout << "\n------- Datos de la mascota " << numero_de_mascota << "------";
   cout << "\nNombre: " << aux -> objeto_mascota.getNombre()
        << "\nEdad: " << aux -> objeto_mascota.getEdad()
        << "\nPeso: " << aux -> objeto_mascota.getPeso()
        << "\nRaza: " << aux -> objeto_mascota.getRaza() 
        << "\n\tLiga a -> ";
   
   aux = aux -> siguiente;
   if(aux == NULL)
    cout << "NULL\n\n";
  }
 }
}

Nodo* Lista::buscarRaza(char raza_de_mascota)
{
 Nodo* busca = primero;

 // Buscamos si el elemento es más grande
 while(busca != NULL && busca -> objeto_mascota.getRaza() < raza_de_mascota)
  busca = busca -> siguiente;  

 return busca;
}

Nodo* Lista::buscarNombreDeMascota(string nombre_de_mascota)
{
 Nodo* busca = primero;

 while(busca != NULL && busca -> objeto_mascota.getNombre() != nombre_de_mascota)
  busca = busca -> siguiente;  

 return busca;
}

void Lista::insertarPrimero()
{  
    // Atributos de la mascota
    string nombre_de_mascota;
    int edad_de_mascota;
    char raza_de_mascota;
    float peso_de_mascota;
    
    Nodo* nuevo = new Nodo();
    Nodo* aux = NULL; // Nodo auxiliar que nos ayudará a buscar valores repetidos en la lista

    cout << "------ Registro de mascota -------";

    // Solicitamos el nombre de la mascota
    while(true)
    {    
     cout << "\nIngrese nombre: ";
     cin >> nombre_de_mascota;
     // Verificamos que la raza dada por el caracter no exita ya en la lista
     aux = buscarNombreDeMascota(nombre_de_mascota);
     if(aux == NULL)
      break;
     else 
      cout << "\nEl mombre de mascota elegido (" << aux -> objeto_mascota.getNombre() 
           << ") ya existe en la lista!!! Intente otro.\n";
    }      

    nuevo -> objeto_mascota.setNombre(nombre_de_mascota);

    // Solicitamos la edad de la mascota
    cout << "\nIngrese edad: "; 
    cin >> edad_de_mascota;
    nuevo -> objeto_mascota.setEdad(edad_de_mascota);

    // Solicitamos la raza de la mascota
    while(true)
    {
     cout << "\nIngrese raza de mascota (cartacter de a-z): ";
     cin >> raza_de_mascota;

     // Se verifica que el carcter sea en minúscula
     if(raza_de_mascota < 'a' || raza_de_mascota > 'z')
      raza_de_mascota = tolower(raza_de_mascota);
   
     aux = buscarRaza(raza_de_mascota);
     // Verificamos que la raza dada por el caracter no exita ya en la lista 
     if(aux == NULL || aux -> objeto_mascota.getRaza() > raza_de_mascota)
      break;
     else
      cout << "\nEl caracter elegido para representar la raza (" << aux -> objeto_mascota.getRaza()
           << ") ya se encuentra en la lista!!! Intente otro.\n";
    }

    nuevo -> objeto_mascota.setRaza(raza_de_mascota);
 
    // Solicitamos el peso de la mascota   
    cout << "\nIngrese peso de mascota: ";
    cin >> peso_de_mascota;
    nuevo -> objeto_mascota.setPeso(peso_de_mascota);

    cout << endl;
   
    // Introducimos el objeto Mascota a la lista
    nuevo -> siguiente = primero;
    primero = nuevo;
    ultimo = nuevo;
    // Hacemos que último apunte a nulo de último elemento de la lista
    while(ultimo -> siguiente != NULL) { ultimo = ultimo -> siguiente; }

    // Verificamos si existen al menos dos elementos dentro de la lista para ordenarla
    if(primero != NULL && primero -> siguiente != NULL)
     ordenarAscXRaza(); 

    // Se imprime la lista para verificar la inserción anterior
    mostrarLista();
}

void Lista::insertarUltimo()
{  
    // Atributos de la mascota
    string nombre_de_mascota;
    int edad_de_mascota;
    char raza_de_mascota;
    float peso_de_mascota;
    
    Nodo* nuevo = new Nodo();
    Nodo* aux = NULL; // Nodo auxiliar para ubicar elementos repetidos

    cout << "------ Registro de mascota -------";

    // Solicitamos el nombre de la mascota
    while(true)
    {    
     cout << "\nIngrese nombre: ";
     cin >> nombre_de_mascota;
     // Verificamos que la raza dada por el caracter no exita ya en la lista
     aux = buscarNombreDeMascota(nombre_de_mascota);
     if(aux == NULL)
      break;
     else 
      cout << "\nEl mombre de mascota elegido (" << aux -> objeto_mascota.getNombre() 
           << ") ya existe en la lista!!! Intente otro.\n";
    }      
 
    nuevo -> objeto_mascota.setNombre(nombre_de_mascota);
 
    cout << "\nIngrese edad: "; 
    cin >> edad_de_mascota;
    nuevo -> objeto_mascota.setEdad(edad_de_mascota);

    // Solicitamos la raza de la mascota
    while(true)
    {
     cout << "\nIngrese raza de mascota (cartacter de a-z): ";
     cin >> raza_de_mascota;

     // Se verifica que el carcter sea en minúscula
     if(raza_de_mascota < 'a' || raza_de_mascota > 'z')
      raza_de_mascota = tolower(raza_de_mascota);
   
     aux = buscarRaza(raza_de_mascota);
     // Verificamos que la raza dada por el caracter no exita ya en la lista 
     if(aux == NULL || aux -> objeto_mascota.getRaza() > raza_de_mascota)
      break;
     else
      cout << "\nEl caracter elegido para representar la raza (" << aux -> objeto_mascota.getRaza()
           << ") ya se encuentra en la lista!!! Intente otro.\n";
    }

    nuevo -> objeto_mascota.setRaza(raza_de_mascota);

    // Solicitamos el peso de la mascota   
    cout << "\nIngrese peso de mascota: ";
    cin >> peso_de_mascota;
    nuevo -> objeto_mascota.setPeso(peso_de_mascota);

    cout << endl;
   
    // Introducimos el objeto Mascota a la lista
    if(primero == NULL)
     primero = nuevo;
    else
    {
     ultimo -> siguiente = nuevo;
     ultimo = nuevo;
    }

    // Ordenamos la lista SI existen más de dos elementos en la lista
    if(primero != NULL && primero -> siguiente != NULL)
     ordenarAscXRaza();

    // Se imprime la lista para verificar la inserción anterior
    mostrarLista();
}

void Lista::insertarEspecifico(char raza_de_mascota)
{
    // Primero se busca el elemento de referencia en la lista
    Nodo* aux = buscarRaza(raza_de_mascota);
    if(aux == NULL || aux -> objeto_mascota.getRaza() > raza_de_mascota)
     cout << "\nLa raza dada como referencia no se EXISTE!!!\n";
    else     
    {
     // Atributos de la mascota
     string nombre_de_mascota;
     int edad_de_mascota;
     char raza_de_mascota;
     float peso_de_mascota;
    
     Nodo* nuevo = new Nodo();

     cout << "------ Registro de mascota -------";
     cout << "\nIngrese nombre: ";
     cin >> nombre_de_mascota;
     nuevo -> objeto_mascota.setNombre(nombre_de_mascota);
 
     cout << "\nIngrese edad: "; 
     cin >> edad_de_mascota;
     nuevo -> objeto_mascota.setEdad(edad_de_mascota);

     cout << "\nIngrese raza de mascota (cartacter de a-z): ";
     cin >> raza_de_mascota;

     // Se verifica que el carcter sea en minúscula
     if(raza_de_mascota < 'a' || raza_de_mascota > 'z')
     raza_de_mascota = tolower(raza_de_mascota);
   
     nuevo -> objeto_mascota.setRaza(raza_de_mascota);

     cout << "\nIngrese peso de mascota: ";
     cin >> peso_de_mascota;
     nuevo -> objeto_mascota.setPeso(peso_de_mascota);

     cout << endl;
     
     // Introducimos el objeto Mascota a la lista
     nuevo -> siguiente = aux -> siguiente;
     aux -> siguiente = nuevo;
    }

    // Se imprime la lista para verificar la inserción anterior
    mostrarLista(); 
}

void Lista::eliminarTodo()
{
 Nodo* aux;
 ultimo = NULL;
 
 while(primero != NULL)
 {
  aux = primero;
  primero = primero -> siguiente;
  delete(aux);
 } 

 // Verificamos que la lista esté vacía
 mostrarLista();
}

void Lista::eliminarEspecifico(char r)
{
 Nodo *aux1 = primero, *aux2 = primero;
 while(aux1 != NULL && aux1 -> objeto_mascota.getRaza() != r)
 {
  aux2 = aux1;
  aux1 = aux1 -> siguiente; 
 }
 if(aux1 == NULL){
		cout<<"La raza (" << r << ") no se escuentra en la lista...\n\n";
	}
	else if(aux1 == primero){
		primero = aux1 -> siguiente;
		delete (aux2);
	}
	else if(aux1 == ultimo){
		ultimo = aux2;
		aux2 -> siguiente = NULL;
		delete (aux1);
	}else{
		aux2 -> siguiente = aux1 -> siguiente;
		delete (aux1);
	}

 cout << "Número de elementos en la lista antes de eliminar: " << numero_de_mascota << endl;

        // Verificamos que el elemento haya sido eliminado correctamente
	mostrarLista();
}

void Lista::ordenarAscXRaza()
{
 if(primero != NULL)
 {
  Nodo *aux1 = primero, *aux2 = NULL;
  char r;

  // Comenzamos a recorrer la lista
  while(aux1 -> siguiente != NULL)
  {
   aux2 = aux1 -> siguiente;
   while(aux2 != NULL) 
   {
    if(aux1 -> objeto_mascota.getRaza() > aux2 -> objeto_mascota.getRaza())
    { 
     r = aux1 -> objeto_mascota.getRaza();
     aux1 -> objeto_mascota.setRaza(aux2 -> objeto_mascota.getRaza()); 
     aux2 -> objeto_mascota.setRaza(r);
    }
    aux2 = aux2 -> siguiente;
   }
   aux1 = aux1 -> siguiente;
  }
 }

 //Mostramos los elementos de la lista para conocer su orden
 mostrarLista();
}