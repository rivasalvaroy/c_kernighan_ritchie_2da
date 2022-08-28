// Cuenta los caracteres de la entrada; 2da versión
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   double nc;

   for (nc = 0; getchar() != EOF; ++nc)
      ;
   printf("\n%.0f\n", nc);
   return 0;
}
