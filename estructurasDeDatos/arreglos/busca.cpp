#include <iostream>

using namespace std;

//int arreglo[] = {34, 5, 7, 867, 34, 0, 23, 9, 40, 99};

template <class T>
int busca(T*, T, int);

template <class T>
void elimina(T*, T, int);

int 
main()
{
 setlocale(LC_ALL, "");

 char arreglo[] = {'d', 'e', 'g', 'a', 'r', 'y', 'f', 'h', 'q'};
 int tam = sizeof(arreglo)/sizeof(arreglo[0]);

 //int d = 23;
 char d = 'f';
 elimina(arreglo, d, tam);	
  
 return 0;
}

template <class T>
int busca(T* arreglo, T dato, int t)
{
 int resultado = -1, indice = 0;
 
 while(indice < t && arreglo[indice] != dato)
  indice ++;

 if(indice < t)
   resultado = indice + 1;

 return resultado;
}

template <class T>
void elimina(T* arreglo, T dato, int t)
{
 int indice = 0, resultado = busca(arreglo, dato, t);
 
 if(t < 0) cout << "El arreglo está vacío\n"; 
 else if(resultado < 0) cout << "El elemento: \'" << dato << "\' no se encontró\n";
 else
 {
  indice = resultado - 1;
   t --;
   for(; indice < t; indice ++)
    arreglo[indice] = arreglo[indice + 1];

   cout << "Elemento eliminado con éxito!\n";

   
 for(int i = 0; i < t; i ++)
  cout << arreglo[i] << ' ';
 }
}
