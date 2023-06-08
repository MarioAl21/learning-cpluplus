/*
 Descripcion:
  En el siguiente script se incluyen las siguiente clases:
  -Archivo, el cual es el elemento contenido en cada nodo de la lista.
   tiene un id que lo indetifica univocamente, un nombre que puede repetirse
   y un tamanio que se define aleatoriamente (1-200).
  -Nodo que define una instancia de Archivo y un puntero a otro objeto Nodo
  -Lista que enlistara cada nodo nuevo recien creado.
  El proposito es hacer una alusion a como los sistemas de archivos realizan
  un mejor trabajo al momento de aprovechar el recorrido que hacen medios
  de almacenamiento fisicos como los SSD para obtener la informacion solicitada
  por el usuario o el propio sistema.
*/

#include <iostream>
#include <cstring>
// Juntas nos permite generar numeros aleatorios
#include <cstdlib>
#include <ctime>
using namespace std;

class Lista; // Clase Lista amiga de la clase Nodo

// Clase archivo
class Archivo{
 public:
  Archivo();
  void nombraArchivo(char[]);
  void muestraArchivo();
  void generaPseudoId(int); // El id es autentico pero el modo de obtenerlo no tanto
  int obtenID(); // Por si se requiere conocer el ID del archivo
  int obtenTamanio(); // Para calcular el total almacenado
 private:
  int id, tamanio; // los genera el sistema
  char nombre[60]; // lo solicita al usuario
};

// Clase Nodo
class Nodo{
 public:
  Nodo();
  friend class Lista;
 private:
  Archivo objeto_archivo;
  Nodo* siguiente;
};

// Plantilla de la clase Lista Simplemente ligada
class Lista{
 public:
  Lista();
  void creaArchivo(char[]); // Inserta al inicio el nodo con el archivo a incluir
  Nodo* buscaArchivo(int); // Retorna el apuntador al nodo anterior es caso de econtrarlo, o NULL si no.
  void eliminaArchivo(int); // Elimina un archivo dada una referencia
  void calculaTotalAlmacenado(); // Suma el tamanio de cada Archivo y los muestra
  void muestraArchivos();
  void muestraArchivoEncontrado(Nodo* archivo_encontrado, int id){
   if(archivo_encontrado -> objeto_archivo.obtenID() != id)
     archivo_encontrado -> siguiente -> objeto_archivo.muestraArchivo();
   else archivo_encontrado -> objeto_archivo.muestraArchivo();
  }

 private:
  int id_para_el_archivo;
  int id_a_eliminar; // Guarda el id que se eliminar para verificar que no se repitan id al momento de continuar la asignacion de id's para nuevos archivos
  Nodo* inicio;
};

int menuArchivo(){
 int respuesta;

 cout << "\n\n(1)Crear un archivo"
      << "\n(2)Busca un archivo (Consultarlo)"
      << "\n(3)Elimina un archivo (por id)"
      << "\n(4)Mostrar todos los archivos"
      << "\n(5)Calcular total almacenado de los archivos"
      << "\n(0)Salir"
      << "\n\nElegir: ";
 cin >> respuesta;

 return respuesta;
}

void usaLista(){
 Lista lis;
 Nodo* archivo_buscado = NULL;
 int opcion, id_del_archivo;
 char nombre_del_archivo[60];

 do{
  opcion = menuArchivo();
  switch(opcion){
   case 0:
    cout << "\n\nProceso terminado.\n\n";
   break;
   case 1:
    cout << "\n\nIngresa el nombre del archivo a crear: ";
    cin >> nombre_del_archivo;
    lis.creaArchivo(nombre_del_archivo);
   break;
   case 2:
    cout << "\n\nIngrese el id del archivo a buscar: ";
    cin >> id_del_archivo;
    archivo_buscado = lis.buscaArchivo(id_del_archivo);
    if(archivo_buscado != NULL){
     cout << "\nArchivo econtrado: ";
     lis.muestraArchivoEncontrado(archivo_buscado, id_del_archivo);
    }
    else cout << "\nEl archivo NO se econtro!!!\n";
   break;
   case 3:
    cout << "\n\nIngrese el id del archivo a eliminar: ";
    cin >> id_del_archivo;
    lis.eliminaArchivo(id_del_archivo);
   break;
   case 4:
    lis.muestraArchivos();
   break;
   case 5:
    lis.calculaTotalAlmacenado();
   break;
   default: cout << "\n\nOpcion NO valida\n\n";
  }
 }while(opcion != 0);
}

int
main(){
 srand(time(0));
 usaLista();

 return 0;
}

// ----- Defincion de clases ----
// Metodos de Archivo
Archivo::Archivo(){
 id = 0;
 tamanio = (rand() + 1) % 200; // (1 - 200)
}

void Archivo::muestraArchivo(){
 cout << "\nNombre del Archivo: " << nombre << endl
      << "Identificador: " << id << endl
      << "Tamanio del Archivo: " << tamanio << endl;
}

void Archivo::nombraArchivo(char nombre[]){
 strcpy(this -> nombre, nombre);
}

// Recibe el id de otro archivo y le suma uno
void Archivo::generaPseudoId(int identificador){
 id = identificador;
}

int Archivo::obtenID(){
 return id;
}

int Archivo::obtenTamanio(){
 return tamanio;
}

// Metodos de Nodo
Nodo::Nodo(){ siguiente = NULL; }

// Metdos de Lista
Lista::Lista(){
 id_para_el_archivo = 1;
 //id_a_eliminar = -1;
 inicio = NULL;
}

void Lista::creaArchivo(char nombre_archivo[]){
 Nodo* nuevo = new Nodo();
 nuevo -> objeto_archivo.nombraArchivo(nombre_archivo);
 nuevo -> objeto_archivo.generaPseudoId(id_para_el_archivo ++);
 nuevo -> siguiente = inicio;
 inicio = nuevo;
}

Nodo* Lista::buscaArchivo(int id_archivo){
 Nodo *anterior, *busca;
 anterior = busca = NULL; // Ambos nodos comienzan en NULL
 if(inicio){ // Si la lista tiene al menos un nodo
  anterior = busca = inicio; // Ahora ambos apuntadores va a recorrer la lista
  // Mientras que busca siga dentro de la lista y el dato a comparar sea dif.
  while(busca != NULL && busca -> objeto_archivo.obtenID() != id_archivo){
   anterior = busca;
   busca = busca -> siguiente;
  }
  if(busca == NULL || busca -> objeto_archivo.obtenID() != id_archivo) // El archivo NO se econtro
   anterior = NULL; // Por lo tanto anterior debe apuntar a nulo
 }
 return anterior; // OJO!!! Estamos retornando el elemento anterior, NO el que tiene el dato buscado (en caso de encontrarlo claro esta)
}

void Lista::eliminaArchivo(int id_archivo){
 Nodo* encontrado = buscaArchivo(id_archivo), *elimina;
 if(encontrado != NULL){ // Si el puntero no retornar nulo, entonces ECONTRO algo. Echemos un vistazo
  if(encontrado -> siguiente == NULL) // Si el archivo a eliminar esta en al inicio Y es el uninco elemento
  {
   inicio = NULL; // "Limpiamos" el inicio
   elimina = encontrado; // elimina apunta al archivo a eliminar
  }
  else{
   if(encontrado -> objeto_archivo.obtenID() == id_archivo) // El elemento a eliminar esta al inicio pero existen AL MENOS un elemento mas en la lista
   {
    elimina = encontrado; // elimina toma el primer elemento
    id_para_el_archivo = elimina -> objeto_archivo.obtenID(); // Se reutiliza el id del PRIMERO archivo para uno que se cree mas adelante
    inicio = inicio -> siguiente; // inicio se enlaza al siguiente en la lista
   }
   else{ // El elemento a eliminar NO se encontro al inicio
    elimina = encontrado -> siguiente; // elimina avanza al archivo que esta despues de anterior en el metodo buscaArchivo
    id_a_eliminar = elimina -> objeto_archivo.obtenID();
   }
   encontrado -> siguiente = elimina -> siguiente; // el puntero retoma el siguiente archivo
  }
  cout << "\n\nArchivo elminado: ";
  elimina -> objeto_archivo.muestraArchivo();
  delete(elimina);
 }
 else cout << "\nEl archivo a eliminar no se encuetra o la lista esta vacia!!!\n";
}

void Lista::calculaTotalAlmacenado(){
 if(inicio != NULL){
  int total = 0;
  Nodo* suma = inicio;
  while(suma != NULL){
   total += suma -> objeto_archivo.obtenTamanio();
   suma = suma -> siguiente;
  }
  cout << "\n\nTamanio total de los archivo enlistados: " << total << endl;
 }
 else cout << "\n\nNo hay archivos que sumar su tamanio!!!\n";
}

void Lista::muestraArchivos(){
 if(inicio != NULL)
 {
  Nodo* muestra = inicio;
  while(muestra != NULL){
   muestra -> objeto_archivo.muestraArchivo();
   muestra = muestra -> siguiente;
   if(muestra == NULL)
    cout << "-> NULL\n";
   else
    cout << "-> ";
  }
 }
 else cout << "\n\nNo existen archivos que mostrar!!!\n\n";
}
