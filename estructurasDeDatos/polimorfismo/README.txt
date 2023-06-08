Polimorfismo

Este t�rmino hace referencia a la capacidad de adoptar diferentes
formas. As�, un objeto polim�rfico es aquela que tiene diversos
aspectos. 
Permite que un mismo m�todo adquiera distintos contenidos 
declar�ndolo en la clase base y en sus clases derivadas.

En C++ se har� utilizando m�todos/funciones virtuales.

Primero conviene entender las Funciones virtuales y luego
las clases abstractas con m�todos virtuales puros. 

Clases Abstractas
Se define como la base para definir un concepto misma sobre la que,
a su vez, se definir�n otras clases, las cuales pueden ser concretas.
Estas clases no se usan directamente en la soluci�n del problema, 
ya que su objetivo NO es instanciar objetos, sino la de servir como 
clase base de las clases que s� lo har�n (o incluso de otras clases
abstractas).
Esta clases pueden usar los denominados m�todos virutales puros.
Estos se inicializan a cero y de NO ser especificadas (su contenido)
en las clases derivadas entonces marcar� el compilador un ERRROR.