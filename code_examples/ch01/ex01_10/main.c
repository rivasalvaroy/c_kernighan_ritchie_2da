// Cuenta las líneas de la entrada
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c, ni;

   ni = 0;
   while ((c = getchar()) != EOF)
      if (c == '\n')
         ++ni;
   printf("%d\n", ni);
   return 0;
}
