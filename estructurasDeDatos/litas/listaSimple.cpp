#include <iostream>

using namespace std;

class Lista;

class Nodo
{
 public:
  Nodo();
 
  friend class Lista;
 
 private:
  int numero;
  Nodo* siguiente;
};

class Lista
{
 public:
  Lista();
  void mostrarLista();
  void insertarPrimero(int);
  void insertarFinal(int);
  void insertarEspecifico(int, int);
  void eliminaTodo();
  void eliminaEsp(int);
  void ordenaAsc();

 private:
  Nodo* primero, *ultimo;
};

int
main()
{
 setlocale(LC_ALL, "");

 Lista lis;
 int opcion, ele, r;
 do
 {
  cout << "\n(1) Mostras lista\n"
       << "(2) Insertar al inicio de la lista\n"
       << "(3) Insertar al final de la ista\n"
       << "(4) Insertar específico\n"
       << "(5) Elimina la lista\n"
       << "(6) Elimina específico\n"
       << "(7) Ordena ascendentemente\n"
       << "\n\tOpción: ";
  cin >> opcion;

  system("cls");

  switch(opcion)
  {
   case 1: lis.mostrarLista(); break;
   case 2: cout << "Elemento a insertar: "; cin >> ele; 
           lis.insertarPrimero(ele); break; 
   case 3: cout << "Elemento a insertar: "; cin >> ele;
  	   lis.insertarFinal(ele); break;
   case 4: cout << "Elemento de referencia: "; cin >> r;
           cout << "\nInserte elemento: "; cin >> ele;
           lis.insertarEspecifico(ele, r); break;
   case 5: lis.eliminaTodo(); break;
   case 6: cout << "Inserte elemento a eliminar: "; cin >> ele;
           lis.eliminaEsp(ele); break;
   case 7: lis.ordenaAsc();
  }
 } while(opcion >= 1); 

 return 0;
}

Nodo::Nodo()
{
 siguiente = NULL;
}

Lista::Lista()
{
 primero = NULL;
 ultimo = NULL;
}

void Lista::mostrarLista()
{
 if(primero)
 {
  Nodo* muestra = primero;
  while(muestra)
  {
   cout << muestra -> numero << " -> "; 
   muestra = muestra -> siguiente;
   if(!muestra)
    cout << "NULL\n\n";
  } 
 }
 else
  cout << "Lista vacía\n";
}

void Lista::insertarPrimero(int numero)
{
 Nodo* nuevo = new Nodo();
 nuevo -> numero = numero;
 if(primero)
  nuevo -> siguiente = primero;
 primero = nuevo;
 ultimo = nuevo;
 while(ultimo -> siguiente)
  ultimo = ultimo -> siguiente;
}

void Lista::insertarFinal(int numero)
{
 if(!primero)
  insertarPrimero(numero);
 else
 {
  Nodo* nuevo = new Nodo();
  nuevo -> numero = numero;
  ultimo -> siguiente = nuevo;
  ultimo = nuevo;
 }
}

void Lista::insertarEspecifico(int numero, int ref)
{
 Nodo* busca = primero;
 while(busca && busca -> numero != ref) busca = busca -> siguiente;
 if(!busca) cout << "La referencia NO existe!!!";
 else
 {
  Nodo* nuevo = new Nodo();
  nuevo -> numero = numero;
  nuevo -> siguiente = busca -> siguiente;
  busca -> siguiente = nuevo;
 }
}

void Lista::eliminaTodo()
{
 Nodo* elimina; ultimo = NULL;
 while(primero)
 {
  elimina = primero;
  primero = primero -> siguiente;
  delete(elimina); 
 }
 mostrarLista();
}

void Lista::eliminaEsp(int numero)
{
 Nodo* previo = primero, *elimina = primero;
 while(elimina && elimina -> numero != numero)
 {
  previo = elimina;
  elimina = elimina -> siguiente; 
 }
 if(!elimina) cout << "Elemento no econtrado\n";
 else if(elimina == primero)
 {
  primero = primero -> siguiente;
  delete(elimina);
 }
 else if(elimina == ultimo)
 {
  ultimo = previo;
  previo -> siguiente = NULL;
  delete(elimina);
 }
 else
 {
  previo -> siguiente = elimina -> siguiente;
  delete(elimina);
 }
 mostrarLista();
} 

void Lista::ordenaAsc()
{
 Nodo* actual = primero, *despues = primero;
 int reten;
 while(actual -> siguiente)
 {
  despues = actual -> siguiente;
  while(despues)
  {
   if(actual -> numero > despues -> numero)
   {  
    reten = actual -> numero;
    actual -> numero = despues -> numero;
    despues -> numero = reten;
   }
   despues = despues -> siguiente;
  }
  actual = actual -> siguiente;
 }
 mostrarLista();
}