// Escriba un programa que imprima su entrada una palabra por línea
#include <stdio.h>

#define IN 1  // en una palabra
#define OUT 0 // fuera de una palabra

// la función main empieza la ejecución del programa
int main()
{
   int c, state;

   state = OUT;
   while ((c = getchar()) != EOF)
   {
      if (c == ' ' || c == '\n' || c == '\t')
      {
         if (state == IN)
         {
            putchar('\n'); // final de palabra
            state = OUT;
         }
      }
      else if (state == OUT)
      {
         state = IN; // comienzo de palabra
         putchar(c);
      }
      else // dentro de palabra
         putchar(c);
   }
   return 0;
}
