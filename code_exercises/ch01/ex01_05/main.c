/* Modifique el programa de conversión de temperaturas de manera que escriba
   la tabla en el orden inverso, esto es, desde 300 hasta 0 */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int fahr;

   for (fahr = 300; fahr >= 0; fahr -= 20)
   {
      printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
   }
   return 0;
}
