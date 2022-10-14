/* En el capítulo 1 se escribió un programa para contar las ocurrencias de cada
   dígito, espacio en blanco y todos los demás caracteres, usando una secuencia de
   if ... else if ... else. Aquí está el mismo programa con un switch */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c, i, nwhite, nother, ndigit[10];

   nwhite = nother = 0;
   for (i = 0; i < 10; i++)
      ndigit[i] = 0;
   while ((c = getchar()) != EOF)
   {
      switch (c)
      {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
         ndigit[c - '0']++;
         break;
      case ' ':
      case '\n':
      case '\t':
         nwhite++;
         break;
      default:
         nother++;
         break;
      }
   }
   printf("digitos =");
   for (i = 0; i < 10; i++)
      printf(" %d", ndigit[i]);
   printf(", espacios blancos = %d, otros = %d \n", nwhite, nother);
   return 0;
}