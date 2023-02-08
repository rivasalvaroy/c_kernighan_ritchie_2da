/* Experimente el descubrir que pasa cuando la cadena del argumento de printf
   contiene \c, en donde c es algún carácter no puesto en la lista anteriormente */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   printf("Hola, Mundo\y");
   printf("Hola, Mundo\7");
   printf("Hola, Mundo\?");
   return 0;
}
