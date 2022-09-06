/* Escriba de nuevo el programa de conversión de temperatura de modo que
   utilice una función para la conversión */
#include <stdio.h>

float celsius(int fahr); // prototipo de la función celsius

// la función main empieza la ejecución del programa
int main()
{
   int lower, upper, step;

   lower = 0;
   upper = 300;
   step = 20;

   for (int i = lower; i <= upper; i += step)
      printf("%3d\t%6.1f\n", i, celsius(i));
   return 0;
}
// función que convierte grados Fahrenheit a Celsius
float celsius(int fahr)
{
   return (5.0 / 9.0) * (fahr - 32.0);
}
