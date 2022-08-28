// Cuenta los caracteres de la entrada; 1a. versión
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   long nc;

   nc = 0;
   while (getchar() != EOF)
      ++nc;
   printf("\n%ld\n", nc);
   return 0;
}
