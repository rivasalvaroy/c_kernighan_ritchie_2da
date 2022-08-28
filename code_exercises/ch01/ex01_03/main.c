/* Modifique el programa de conversión de temperaturas de modo que escriba un
   encabezado sobre la tabla */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   float fahr, celsius;
   int lower, upper, step;

   lower = 0;   // límite inferior de la tabla de temperaturas
   upper = 300; // límite superior
   step = 20;   // tamaño del incremento
   printf("Fahr\tCelsius\n");
   fahr = lower;
   while (fahr <= upper)
   {
      celsius = (5.0 / 9.0) * (fahr - 32);
      printf("%3.0f\t%6.1f\n", fahr, celsius);
      fahr = fahr + step;
   }
   return 0;
}