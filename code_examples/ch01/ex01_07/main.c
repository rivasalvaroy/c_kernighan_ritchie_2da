/* El programa para copiar podria escribirse de modo más conciso por 
   programadores experimentados en C de la siguiente manera */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c;

   while ((c = getchar()) != EOF)
   {
      putchar(c);
   }
   return 0;
}
