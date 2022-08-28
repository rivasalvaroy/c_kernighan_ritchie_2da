// Verifica que la expresión getchar() != EOF es 0 o 1
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c;

   while ((c = getchar()) != EOF)
      printf("%d\n", c);
   printf("%d - at EOF\n", c);
   return 0;
}
