/* Escriba un programa detab que reemplace cadenas de blancos tabuladores
   de la entrada con el número apropiado de blancos espaciar hasta el siguiente 
   paro de tabulación. Considere un conjunto fijo de paros de tabulación, digamos
   cada n columnas. ¿Debe ser n una variable o un parámetro simbólico? */
#include <stdio.h>

#define TABINC 8 // tamaño de incremento de tab

// la función main empieza la ejecución del programa
int main()
{
   int c, nb, pos;

   nb = 0;  // número de blancos necesarios
   pos = 1; // posición del carácter en la línea
   while ((c = getchar()) != EOF)
   {
      if (c == '\t') // carácter tab
      {
         nb = TABINC - (pos - 1) % TABINC;
         while (nb > 0)
         {
            putchar(' ');
            ++pos;
            --nb;
         }
      }
      else if (c == '\n') // carácter nueva línea
      {
         putchar(c);
         pos = 1;
      }
      else // todos los otros caracteres
      {
         putchar(c);
         ++pos; // incremento para llevar cuenta de la posición
      }
   }
   return 0;
}
