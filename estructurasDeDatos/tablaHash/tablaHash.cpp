#include <iostream>
#include <cstring>

using namespace std;

#define TAMANIO 5

class TablaHash
{
 public:
     TablaHash();
     int obtenAscii(char[]);
     void generaClave(char[]);
     int obtenClave();
     bool nombreDuplicado(char[]);
     bool guardaNombre(char[]);
     char* obtenNombre();
     void muestraNombreXPosicion(int);

 private:
  int clave;
  char* nombres[TAMANIO]; // Arreglo de apuntadores a char
};

int menuDeOpciones()
{
    int opcion;
    do
    {
     cout << "\n----- Menu -----\n"
          << "(1) Guardar Nombre\n"
          << "(2) Mostrar nombres\n"
          << "(3) Salir\n\n"
          << "Elige: ";
     cin >> opcion;
     system("cls");
     if(opcion < 1 || opcion > 3)
        cout << "\nOpción no elistada!!!\n";
    }while(opcion < 1 || opcion > 3);

    return opcion;
}

void usaTablaHash()
{
    TablaHash th;
    char nombre_de_alumno[100]; // Aquí guardamos el nombre
    char *ptr_nombre_de_alumno; // Este apuntador nos ayudará a guardar el nombre
    int respuesta = menuDeOpciones();
    int posicion;

    while(respuesta == 1 || respuesta == 2)
    {
        switch(respuesta)
        {
         case 1:
             cout << "\nIngrese nombre del alumno a registrar: ";
             // Paso 1: Leemos el nombre del alumno
             cin >> nombre_de_alumno;
             // Paso 2: Creamos dinámicamente el nombre para evitar modificar la misma dirección de memoria (nombre_de_alumno)
             ptr_nombre_de_alumno = new char[strlen(nombre_de_alumno) + 1];
             // Paso 3: Ya "convertido" el apuntador a un arreglo de caracteres, le asignamos el nombre ya habíamos introducido
             strcpy(ptr_nombre_de_alumno, nombre_de_alumno);
             if(th.guardaNombre(ptr_nombre_de_alumno) == 1)
               cout << "El nombre " << th.obtenNombre() << " se guardo con éxito en la posición: " << th.obtenClave() << endl;
         break;
         case 2:
             cout << "\nIngresa la posición del nombre que quiera mostrar (0 - 4): ";
             cin >> posicion;
             th.muestraNombreXPosicion(posicion);
         break;
        }

        respuesta = menuDeOpciones();
    }
    cout << "\nProceso terminado.\n";
}

int
main()
{
    setlocale(LC_ALL, "");
    usaTablaHash();

    return 0;
}

TablaHash::TablaHash()
{
    int i = 0;
    // Inicializamos todos lo apuntadores a char dentro de nombres
    // para poder llevar a cabo la verificación al momento de registrar un nombre
    while(i < TAMANIO)
    {
        nombres[i] = NULL;
        i ++;
    }
}

int TablaHash::obtenAscii(char nombre[])
{
    int ascii = 0, i = 0;
    // Paso 1: Recorremos el arreglo de caracrteres nombre hasta llegar a '\0'
    while(nombre[i] != '\0')
    {
        // Paso 2: Casting a int de cada caracter de nombre
        ascii += (int)nombre[i];
        // Paso 3: Incremetamos el índice para seguir recorriendo el nombre
        i ++;
    }
    // Paso 4: Retornamos el ascii de nombre
    return ascii;
}

void TablaHash::generaClave(char nombre[])
{
    clave = obtenAscii(nombre) % TAMANIO; // un valor entre 0 y 4
}

int TablaHash::obtenClave()
{
    return clave;
}

bool TablaHash::nombreDuplicado(char nombre[])
{
    int respuesta = false; // El nombre no se encuentra guardado
    if(strcmp(nombres[clave], nombre) == 0) // Se econtró el mismo nombre YA guardado
        respuesta  = 1;

    return respuesta;
}

bool TablaHash::guardaNombre(char nombre[])
{
    bool respuesta = false; // El  nombre no se pudo guardar
    int opcion;
    generaClave(nombre);

    // Paso 1: Verificar que no haya un nombre ya guardado en la posición dado por clave
    if(nombres[clave] == NULL)
    {
        nombres[clave] = nombre; // Paso 2: Si no, entonces guardamos el nombre
        respuesta = true; // Paso 3: Indicamos que le nombre se guardó con éxito!
    }
    else
    {
        if(nombreDuplicado(nombre) == 1)
        {
            cout << "El nombre " << nombre << " ya está en la lista!\n¿Guardar de todos modos? (1)Si (2) No: ";
            cin >> opcion;
            if(opcion == 1)
            {
                nombres[clave] = nombre;
                respuesta = true;
            }
            else
                cout << "\nOperación cancelada.\n";
        }
        else
        {
            cout << "\nYa existe un nombre en la posición " << obtenClave() << "!!!\n¿Reemplazar el nombre " << obtenNombre() << " por " << nombre << "? (1)Si (2)No: ";
            cin >> opcion;
            if(opcion == 1)
            {
                nombres[clave] = nombre;
                respuesta = true;
            }
            else
                cout << "\nOperación cancelada.\n";
        }
    }

    return respuesta; // Retornamos respuesta
}

char* TablaHash::obtenNombre()
{
    return nombres[clave];
}

void TablaHash::muestraNombreXPosicion(int pos)
{
    if(nombres[pos] == NULL)
        cout << "\nLa posción dada no tiene aún un nombre registrado ¯/_('u')_/¯\n";
    else
        cout << "\nNombre que se ha encontrado: " << nombres[pos] << endl;
}
