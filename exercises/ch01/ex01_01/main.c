/* Ejecute el programa "hola mundo" en su sistema. Experimente con la omisión
   de partes del programa, para ver que mensajes de error se obtienen */
#include <stdio.h>

int main()
{
   printf("Hola Mundo");
   return 0;
}
/*
-> En este ejemplo falta el carácter de nueva línea (\n ).
Esto deja el cursor al final de la línea.

int main()
{
   printf("Hola Mundo")
   return 0;
}
-> En el segundo ejemplo falta el punto y coma después de printf().

*/
// la función main empieza la ejecución del programa
int main()
{
   printf("Hola Mundo\n');
   return 0;
}
/*
-> En el tercer ejemplo, la comilla doble " después de n se escribe erróneamente como comilla simple.
La comilla simple, junto con el paréntesis derecho y el punto y coma, se toma como parte de la cadena.
*/