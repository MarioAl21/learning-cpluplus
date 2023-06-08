Polimorfismo

Este término hace referencia a la capacidad de adoptar diferentes
formas. Así, un objeto polimórfico es aquela que tiene diversos
aspectos. 
Permite que un mismo método adquiera distintos contenidos 
declarándolo en la clase base y en sus clases derivadas.

En C++ se hará utilizando métodos/funciones virtuales.

Primero conviene entender las Funciones virtuales y luego
las clases abstractas con métodos virtuales puros. 

Clases Abstractas
Se define como la base para definir un concepto misma sobre la que,
a su vez, se definirán otras clases, las cuales pueden ser concretas.
Estas clases no se usan directamente en la solución del problema, 
ya que su objetivo NO es instanciar objetos, sino la de servir como 
clase base de las clases que sí lo harán (o incluso de otras clases
abstractas).
Esta clases pueden usar los denominados métodos virutales puros.
Estos se inicializan a cero y de NO ser especificadas (su contenido)
en las clases derivadas entonces marcará el compilador un ERRROR.