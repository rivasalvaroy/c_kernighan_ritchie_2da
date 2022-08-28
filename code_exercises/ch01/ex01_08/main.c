/* Escriba un programa que cuente los espacios en blanco, tabuladores
   y nuevas líneas */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c, nb, nt, nl;

   nb = nt = nl = 0;
   while ((c = getchar()) != EOF)
   {
      if (c == ' ')
         ++nb; // incrementa número de espacios en blanco
      if (c == '\t')
         ++nt; // incrementa número de tabuladores
      if (c == '\n')
         ++nl; // incrementa número de líneas nuevas
   }
   printf("\nEspacios en blanco: %d", nb);
   printf("\nTabuladores:        %d", nt);
   printf("\nNuevas lineas:      %d\n", nl);
   return 0;
}