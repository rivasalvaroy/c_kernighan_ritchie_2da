// Imprime la tabla Fahrenheit-Celsius para fahr=0,20,...,300
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int fahr;

   for (fahr = 0; fahr <= 300; fahr += 20)
   {
      printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
   }
   return 0;
}
