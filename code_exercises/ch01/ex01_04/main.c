// Escriba un programa que imprima la tabla correspondiente Celsius a Fahr
// para celsius=0,20,...,300
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   float fahr, celsius;
   int lower, upper, step;

   lower = 0;   // límite inferior de la tabla de temperaturas
   upper = 300; // límite superior
   step = 20;   // tamaño del incremento
   printf("Celsius\t\t Fahr\n");
   celsius = lower;
   while (celsius <= upper)
   {
      fahr = (9.0 * celsius) / 5.0 + 32.0;
      printf("%3.0f\t\t%6.1f\n", celsius, fahr);
      celsius = celsius + step;
   }
   return 0;
}
