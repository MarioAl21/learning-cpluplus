#include <iostream>

using namespace std;

#define MAX 5

template <class T>
class Cola
{
 public:
  Cola();
  void insertaDato(T);
  void eliminaDato(T*);
  bool colaLlena();
  bool colaVacia();
  void muestraDatos();

 private:
  int inicio, final;
  T datos[MAX];
};

void usaCola()
{
 Cola<int> c; int valor = 1;
 while(!c.colaLlena())
  c.insertaDato(valor ++);
 c.muestraDatos();
 while(!c.colaVacia())
 {
  c.eliminaDato(&valor);
  cout << "\nElemento extraido: " << valor << endl;
 }
}

int
main()
{
 //usaCola();

 return 0;
}

template <class T>
Cola<T>::Cola()
 : inicio(-1), final(-1)
{ }

template <class T>
void Cola<T>::insertaDato(T dato)
{
 datos[++ final] = dato;
 if(final == 0)
   inicio = 0;
}

template <class T>
void Cola<T>::eliminaDato(T* extrae)
{
 *extrae = datos[inicio];
 if(inicio == final)
 {
  inicio = -1;
  final = -1;
 }
 else inicio ++;
}

template <class T>
bool Cola<T>::colaLlena()
{
 bool res = false;
 if(final == MAX - 1)
  res = true;
 return res;
}

template <class T>
bool Cola<T>::colaVacia()
{
 bool res = false;
 if(inicio == -1)
  res= true;
 return res;
}

template <class T>
void Cola<T>::muestraDatos()
{
 if(!colaVacia())
  for(int i = 0; i < final; i ++)
   cout << datos[i] << " ";
 else
  cout << "\nNo hay datos que mostrar\n";
}