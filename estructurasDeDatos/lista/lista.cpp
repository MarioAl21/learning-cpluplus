#include <iostream>

using namespace std;

template <class T>
class Lista;

template <class T>
class Nodo{
 public:
  Nodo(): liga(NULL) {}
  friend class Lista<T>;
 private:
  T info;
  Nodo<T>* liga;
};

template <class T>
class Lista{
 public:
  Lista(): inicio(NULL), fin(NULL) {}

  Nodo<T>* obtenInicio();
  T obtenValor(Nodo<T>* n) { return n -> info; }
  Nodo<T>* avanza(Nodo<T>* a) { return a -> liga; }

  void insertaInicio(T);
  void insertaInicioV2(T dato){
   Nodo<T>* nuevo = new Nodo<T>();
   nuevo -> info = dato;
   nuevo -> liga = inicio;
   inicio = fin = nuevo;
   while(fin -> liga != NULL)
    fin = fin -> liga;

   cout << fin -> info << endl;
  }
 
  void insertaFinalV2(T dato){
   if(inicio != NULL){
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo -> info = dato;
    fin -> liga = nuevo;
    fin = nuevo;
   }
   else
    insertaInicioV2(dato);
  }

  void insertaFinal(T dato){
   Nodo<T>* nuevo = new Nodo<T>();
   nuevo -> info = dato;
   if(inicio == NULL)
    inicio = nuevo;
   else{
    Nodo<T>* ultimo = inicio;
    while(ultimo -> liga != NULL)
     ultimo = ultimo -> liga;
    ultimo -> liga = nuevo;
   }

  }
  void muestraLista(){
   if(inicio != NULL){
    Nodo<T>* muestra = inicio;
    while(muestra != NULL){
     cout << muestra -> info << ' ';
     muestra = muestra -> liga;
    }
   }
   else cout << "\nLista vacia\n";
  }
 private:
  Nodo<T>* inicio, *fin;
};

int menu(){
 int respuesta;
 cout << "(1)Inserta al inicio\n"   
      << "(2)Inserta al final\n"
      << "(7)Muestra la lista\n"
       << "(0)SALIR"
      << "\n\nElige: ";
 cin >> respuesta;

 return respuesta;
}

void usaLista(){
 Lista<int> lis; Nodo<int>* l;
 int valor = 1, opcion;
 do{
  opcion = menu();
  system("cls");

  switch(opcion){
   case 0: cout << "\nProceso terminado.\n"; break;
   case 1:
    cout << "Ingrese el valor a insertar: ";
    cin >> valor;
    lis.insertaInicioV2(valor); 
   break;
   case 2:
    lis.insertaFinalV2(valor ++);
   break;
   case 7:
    lis.muestraLista(); cout << endl;
   break;
   default: cout << "Opcion NO valida!!\n";
  }
 }while(opcion != 0);
}

int
main()
{
 usaLista();

 return 0;
}

// Métodos de la clase Lista
template <class T>
Nodo<T>* Lista<T>::obtenInicio() { return inicio; }

template <class T>
void Lista<T>::insertaInicio(T valor){
 Nodo<T>* nuevo = new Nodo<T>();
 nuevo -> info = valor;
 nuevo -> liga = inicio;
 inicio = nuevo;
}