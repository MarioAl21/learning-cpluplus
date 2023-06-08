#include "Pila.h"
//#include <iostream>
#include <cstring>

using namespace std;

// ----- Clases -----
// Clase Cheque
class Cheque
{
 public:
  Cheque();
  Cheque(int, int, char[], double);
  ~Cheque();
  void muestraCheque();

  friend ostream &operator <<(ostream&, Cheque&); 

 protected:
  int numero, cuenta_a_depositar;
  char banco[10];
  double monto;
};

// Clase ChequeRechazado derivado de Cheque
class ChequeRechazado: public Cheque
{
 public:
  ChequeRechazado();
  ChequeRechazado(int, int, char[], double);
  ~ChequeRechazado();
  void muestraChequeRechazado();

  friend ostream &operator <<(ostream&, ChequeRechazado&);

 private:
  int cargo;
};

// Clase Banco
class Banco
{
 public:
  Banco();
  ~Banco();
  void registraCheque(Cheque);
  void registraChequeRechazado(ChequeRechazado);
  void procesaCheque();
  void procesaChequeRechazado();
  void muestraCheques();
  void muestraChequesRechazados();

 private:
  Pila<Cheque> cheques;
  Pila<ChequeRechazado> chequesRechazados;
};
// -------------------

// Protitipo
void usaBanco();


int
main()
{
 usaBanco();

 return 0;
}

// ----- Definición de métodos -----
// Métodos de la clas Cheque
Cheque::Cheque()
{}

Cheque::Cheque
(
   int numero, int cuenta_a_depositar, 
   char banco[], double monto
)
{
 this -> numero = numero;
 this -> cuenta_a_depositar = cuenta_a_depositar;
 strcpy(this -> banco, banco);
 this -> monto = monto; 
}

Cheque::~Cheque()
{}

void Cheque::muestraCheque()
{
 cout << "\n---- Datos del cheque ----\n"
      << "Número del cheque: " << numero
      << "\nDel banco: " << banco
      << "\nDepositado en la cuenta: " << cuenta_a_depositar
      << "\nMonto depositado: " << monto << endl;
}

ostream &operator <<(ostream &escribe, Cheque &objeto_cheque)
{
 escribe << "\n---- Datos del cheque ----\n"
         << "Número del cheque: " << objeto_cheque.numero
         << "\nDel banco: " << objeto_cheque.banco
         << "\nDepositado en la cuenta: " << objeto_cheque.cuenta_a_depositar
         << "\nMonto depositado: " << objeto_cheque.monto << endl;
 return escribe;
}

// Métodos de la clase ChequeRechazado
ChequeRechazado::ChequeRechazado()
{ }

ChequeRechazado::ChequeRechazado
(
 int numero, int cuenta_a_depositar,
 char banco[], double monto
)
 : Cheque(numero, cuenta_a_depositar, banco, monto)
{
 cargo = monto * 0.10;
}

ChequeRechazado::~ChequeRechazado()
{ }

void ChequeRechazado::muestraChequeRechazado()
{
 Cheque::muestraCheque();
 cout << "Cargo: " << cargo << endl;
}

ostream &operator <<(ostream &escribe, ChequeRechazado &objeto_cheque)
{
 escribe << "\n---- Datos del cheque ----\n"
         << "Número del cheque: " << objeto_cheque.numero
         << "\nDel banco: " << objeto_cheque.banco
         << "\nDepositado en la cuenta: " << objeto_cheque.cuenta_a_depositar
         << "\nMonto depositado: " << objeto_cheque.monto << endl;
 return escribe;
}

// Métodos de la clase Banco
Banco::Banco()
{ }

Banco::~Banco()
{ }

void Banco::registraCheque(Cheque cheque_a_registrar)
{
 if(!cheques.pilaLlena())
 {
  cout << "\n\nRegistrando cheque...\n";
  cheque_a_registrar.muestraCheque();
  cheques + cheque_a_registrar;
 }
 else
  cout << "\n\nNo se puede registrar cheque por falta de espacio!!!\n";
}

void Banco::registraChequeRechazado(ChequeRechazado cheque_a_registrar)
{
 if(!chequesRechazados.pilaLlena())
 {
  cout << "\n\nRegistrando cheque...\n";
  cheque_a_registrar.muestraCheque();
  chequesRechazados + cheque_a_registrar;
 }
 else
  cout << "\n\nNo se puede registrar cheque por falta de espacio!!!\n";
}

void Banco::procesaCheque()
{
 if(!cheques.pilaVacia())
 {
  Cheque cheque_a_procesar;
  cheques - &cheque_a_procesar; 
  cout << "\n\nProcesando cheque...\n\n"; 
  cheque_a_procesar.muestraCheque();
 }
 else
  cout << "\n\nNo hay cheques que procesar!!!\n\n";
}

void Banco::procesaChequeRechazado()
{
 if(!chequesRechazados.pilaVacia())
 {
  ChequeRechazado cheque_a_procesar;
  chequesRechazados - &cheque_a_procesar; 
  cout << "\n\nProcesando cheque...\n\n"; 
  cheque_a_procesar.muestraCheque();
 }
 else
  cout << "\n\nNo hay cheques rechazados que procesar!!!\n\n";
}

void Banco::muestraCheques()
{
 if(!cheques.pilaVacia())
  cheques.muestraPila();
 else
  cout << "\nNo hay cheques que mostrar.\n";
}

void Banco::muestraChequesRechazados()
{
 if(!chequesRechazados.pilaVacia())
  chequesRechazados.muestraPila();
 else
  cout << "\nNo hay cheques rechazados que mostrar.\n";
}

// Definición de prototipo
void usaBanco()
{
 Banco mi_banco;
 int numero_de_cheque, cuenta_de_deposito;
 double deposito;
 char sucursal[10];

 int opcion;
 do
 {
  cout << "\n\n(0) Salir"
       << "\n(1) Registrar Cheque"
       << "\n(2) Registrar Cheque Rechazado"
       << "\n(3) Procesar Cheque"
       << "\n(4) Procesar Cheque Rechazado"
       << "\n(5) Mostrar todos los cheques"
       << "\n(6) Mostrar todos los cheques rechazados\n\n"
       << "Elige: ";
  cin >> opcion;
  
  system("cls");

  switch(opcion)
  {
   case 0: cout << "\n\nProceso terminado.\n\n"; break;

   case 1:
   {
    cout << "------- Registro del cheque -----\n"
         << "\nIngrese numero del cheque: ";
    cin >> numero_de_cheque;
    cout << "\nNúmero de cuenta del depósito: "; 
    cin >> cuenta_de_deposito;
    cout << "\nNombre del banco: ";
    cin >> sucursal;
    cout << "\nMonto a depositar: ";
    cin >> deposito;
    
    Cheque cheque_a_depositar
    (
         numero_de_cheque, cuenta_de_deposito,
         sucursal, deposito
    );      
    mi_banco.registraCheque(cheque_a_depositar);
   break;
   }

   case 2:
   {
    cout << "------- Registro del cheque -----\n"
         << "\nIngrese numero del cheque: ";
    cin >> numero_de_cheque;
    cout << "\nNúmero de cuenta del depósito: "; 
    cin >> cuenta_de_deposito;
    cout << "\nNombre del banco: ";
    cin >> sucursal;
    cout << "\nMonto a depositar: ";
    cin >> deposito;
    
    ChequeRechazado cheque_rechazado_a_depositar
    (
         numero_de_cheque, cuenta_de_deposito,
         sucursal, deposito
    );      
    mi_banco.registraChequeRechazado(cheque_rechazado_a_depositar);
   }
   break;

   case 3:
    mi_banco.procesaCheque();
   break;

   case 4:
    mi_banco.procesaChequeRechazado();
   break;

   case 5:
    mi_banco.muestraCheques();
   break;
  
   case 6:
    mi_banco.muestraChequesRechazados();
   break;
  }
 }while(opcion != 0);
}