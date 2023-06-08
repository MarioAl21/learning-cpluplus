#include <iostream>

using namespace std;

#define MAX 5

template <class T>
class ColaCircular
{
 public:
  ColaCircular();
  void push(T);
  void pop(T*);
  bool colaLlena();
  bool colaVacia();
  void muestraDatos();

 private:
  int inicio, final;
  T datos[MAX];
};

void usaCola()
{
 ColaCircular<int> cc; int valor = 1, opc;
 while(!cc.colaLlena())
  cc.push(valor ++); 
 cc.muestraDatos(); cout << endl;
 while(true)
 {
  cout << "\n(1)Inserta\n"
       << "(2)Elimina"
       << "\n(3)Muestra datos"
       << "\n\nElige: ";
  cin >> opc;
  system("cls");
  switch(opc)
  {
   case 1: cout << "\n\nValor a insertar: "; cin >> valor;
           if(!cc.colaLlena()) cc.push(valor); 
           else cout << "\nCola Llena!!\n"; break;
   case 2: if(!cc.colaVacia()) { cc.pop(&valor); 
           cout << "\nValor retirado: " << valor << endl << endl;}
           else cout << "\nCola Vacia!!!\n";
           break;
   case 3:
           cc.muestraDatos();
   break;
  }
  system("PAUSE"); system("cls"); 
 }
}

int
main()
{
 usaCola();

 return 0;
}

template <class T>
ColaCircular<T>::ColaCircular()
 : inicio(-1), final(-1)
{ }

template <class T>
void ColaCircular<T>::push(T dato)
{
 final = (final + 1) % MAX;
 datos[final] = dato;
 if(inicio == -1)
  inicio = 0;
}

template <class T>
void ColaCircular<T>::pop(T* extrae)
{
 *extrae = datos[inicio];
 if(inicio == final)
 {
  inicio = -1;
  final = -1;
 }
 else 
  inicio = (inicio + 1) % MAX;
}

template <class T>
bool ColaCircular<T>::colaLlena()
{
 bool res = false;
 if((final + 1) % MAX == inicio)
  res = true;
 return res;
}

template <class T>
bool ColaCircular<T>::colaVacia()
{
 bool res = false;
 if(inicio == -1)
  res= true;
 return res;
}

template <class T>
void ColaCircular<T>::muestraDatos()
{
  if(!colaVacia()){
   int i;
   cout << endl;
   if(inicio <= final){
    i = inicio;
    while(i <= final) cout << datos[i ++] << ' ';
   }
   else{
    i = inicio;
    while(i < MAX) cout << datos[i ++] << ' ';
    i = 0;
    while(i <= final) cout << datos[i ++] << ' ';
   }
  } 
  else cout << "\nNo hay datos que mostrar.\n";  
  cout << endl;
}