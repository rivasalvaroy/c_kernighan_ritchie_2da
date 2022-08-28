// Imprime la tabla Fahrenheit-Celsius para fahr=0,20,...,300
#include <stdio.h>

#define LOWER 0   // límite inferior de la tabla
#define UPPER 300 // límite superior
#define STEP 20   // tamaño del incremento

// la función main empieza la ejecución del programa
int main()
{
   int fahr;

   for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
   {
      printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
   }
   return 0;
}
