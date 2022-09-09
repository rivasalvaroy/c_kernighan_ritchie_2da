/* Escriba un programa que copie la entrada a la salida, reemplazando
   cada cadena de uno o mas blancos por un solo blanco */
#include <stdio.h>

#define NONBLANK 'a'

// la función main empieza la ejecución del programa
int main()
{
   int c, lastc;

   lastc = NONBLANK;
   while ((c = getchar()) != EOF)
   {
      if (c != ' ')
         putchar(c);
      if (c == ' ')
         if (lastc != ' ')
            putchar(c);
      lastc = c;
   }
   return 0;
}