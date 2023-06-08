#include <iostream>

using namespace std;

class Lista;

class Nodo
{
 public:
  Nodo(): siguiente(NULL) {}
  friend class Lista;
 private:
  int valor;
  Nodo* siguiente;
};

class Lista
{
 public:
  Lista(): inicio(NULL), fin(NULL) {}
  void push(int v){
   Nodo* nuevo = new Nodo();
   nuevo -> valor = v;
   nuevo -> siguiente = inicio;
   fin = inicio = nuevo;
   while(fin -> siguiente != NULL)
    fin = fin -> siguiente; 
  }

  void pop(){
   Nodo* elimina = inicio;
   if(inicio != NULL)
   {
    if(inicio -> siguiente == NULL)
     inicio = NULL; 
    else
    {
     inicio = elimina -> siguiente;
     elimina -> siguiente = NULL;
    }
     cout << "\nValor eliminado: " << elimina -> valor << endl;
     delete(elimina);
   }
   else cout << "\nLa lista esta vacia\n";
  }

  void muestraLista(){
   Nodo* muestra;
   if(inicio != NULL)
   {
    muestra = inicio;
    while(muestra != NULL)
    { cout << muestra -> valor << ' '; 
      muestra = muestra -> siguiente; }
   }
   else
    cout << "\nNo hay datos en la lista\n";
  }

  Nodo* obtenInicio() { return inicio; }

  Nodo* obtenFin() { return fin; }
 private:
  Nodo *inicio, *fin;
};

void usaLista()
{
 Lista lis;
 
 lis.push(9);
 lis.push(19);
 lis.push(20);

 cout << "\nDatos de la lista: ";
 lis.muestraLista();
 cout << endl;

 lis.pop();
 lis.pop();
 lis.pop();
 
 lis.muestraLista();
}

int
main()
{
 usaLista();

 return 0;
}