/*
 Fecha: 06-05-2022
 Hora: 3:34pm
 Descripción:
  A continuación se define la clase Lista y la clase Nodo. Ésta última será utilizada por las
  operaciones de la primera.
  El objetivos del programa es poder almacenar y luego procesar la información  
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class lista; /*Tenemos que escribir el prototipo de esta clase porque el compilador no sabria que es 'lista' cuando escribamos la clase 'nodo' */ 

class Nodo{
	private:/*Las 2 partes de un nodo son: el dato que almacenara (es decir el 'numero') y el apuntador que apunta al 'siguiente' dato*/  
		int numero;
		Nodo *siguiente;	
	public:
		Nodo();
		friend class Lista; //Aqui se especifica que Nodo es amiga de Lista :)
};
Nodo::Nodo(){
	siguiente = NULL;	//En este constructor cuando un Nodo sea creado, su puntero 'siguiente' lo hara en NULL
}

class Lista{
	private://Los punteros 'primero' y 'ultimo' apuntaran al primer y ultimo nodo, respectivamente
		Nodo *primero;
		Nodo *ultimo;	
	public:
		Lista();
		void menu();
		void mostrarLista();
		void insertarPrimero(int);
		void insertarUltimo(int);
		void insertarEspecifico(int,int);
		void eliminarTodo();
		void eliminar(int);
		void ordenarAscendente();
};
Lista::Lista(){
	primero = NULL;
	ultimo = NULL;
}
void Lista::menu(){
	int res = 0, num = 0;
	do{
		cout<<"---------------- MENU ---------------------\n"
		<<"1) Insertar elemento al principio\n"
		<<"2) Insertar elemento al ultimo\n"
		<<"3) Insertar despues de un valor especifico\n"
		<<"4) Eliminar toda la lista\n"
		<<"5) Eliminar valor especifico\n"
		<<"6) Ordenar de menor a mayor\n"
		<<"Escriba un numero NEGATIVO para SALIR.\n\n"
		<<"Comando: ";
		cin>>res;
		system("cls");
		switch(res){
			case 1:
				cout<<"Escriba el numero a insertar: ";	cin>>num;
				insertarPrimero(num); break;
			case 2:
				cout<<"Escriba el numero a insertar: ";	cin>>num;
				insertarUltimo(num);	break;
			case 3:
				mostrarLista();
				cout<<"Vea la lista y decida el valor de referencia donde se insertara el nuevo nodo: "; cin>>res;
				cout<<"Escriba el numero a insertar: ";	cin>>num;
				insertarEspecifico(num, res); break;
			case 4:
				eliminarTodo();	break;
			case 5:
				mostrarLista();
				cout<<"Escriba el numero a eliminar: ";	cin>>res;
				eliminar(res); break;
			case 6:
				ordenarAscendente();
		}
	}while(res>=1);
}
void Lista::mostrarLista(){
	if(primero==NULL)
		cout<<"La lista esta vacia  :(\n";
	else{
		Nodo *aux = primero;
		while(aux != NULL){
			cout<<aux->numero<<"-> ";
			aux = aux->siguiente;
			if(aux == NULL)
				cout<<"NULL\n\n";
		}
	}
}
void Lista::insertarPrimero(int y){
	Nodo *nuevo = new Nodo();
	nuevo->numero = y;
	nuevo->siguiente = primero;
	primero = nuevo;
	ultimo = nuevo;
	while(ultimo->siguiente != NULL){ultimo = ultimo->siguiente;}
	mostrarLista();
}
void Lista::insertarUltimo(int x){
	if(primero == NULL)
		insertarPrimero(x);
	else{
		Nodo *nuevo = new Nodo();
		nuevo->numero = x;
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
		mostrarLista();
	}
}
void Lista::insertarEspecifico(int x, int ref){
	Nodo *aux = primero;
	while((aux != NULL) && (aux->numero != ref)){ aux = aux->siguiente; }
	if(aux == NULL){
		cout<<"El valor de referencia dado, no EXISTE\n";
	}else{
		Nodo *nuevo = new Nodo();
		nuevo->numero = x;
		nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	}
}
void Lista::eliminarTodo(){
	Nodo *aux;
	ultimo = NULL;
	while(primero != NULL){
		aux = primero;
		primero = primero->siguiente;
		delete (aux);
	}
	mostrarLista();
}
void Lista::eliminar(int z){
	Nodo *aux1 = primero, *aux2 = primero;
	while((aux1 != NULL) && (aux1->numero != z)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(aux1 == NULL){
		cout<<"El elemento a eliminar no es escuentra en la lista...\n\n";
	}
	else if(aux1 == primero){
		primero = aux1->siguiente;
		delete (aux2);
	}
	else if(aux1 == ultimo){
		ultimo = aux2;
		aux2->siguiente = NULL;
		delete (aux1);
	}else{
		aux2->siguiente = aux1->siguiente;
		delete (aux1);
	}
	mostrarLista();
}
void Lista::ordenarAscendente(){
	Nodo *aux1 = primero, *aux2 = NULL;
	int x=0;
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		while(aux2 != NULL){
			if(aux1->numero > aux2->numero){
				x = aux1->numero;
				aux1->numero = aux2->numero;
				aux2->numero = x;
			}
			aux2 = aux2->siguiente; 
		}
		aux1 = aux1->siguiente; 
	}
	mostrarLista();
}

int main(){
	Lista lis;
	lis.menu();
	cout<<"ADIOS :)";
	return 0;
}
