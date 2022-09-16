// Un año es bisiesto si es divisible entre 4, pero no entre 100
// excepto aquellos años que son divisibles entre 400
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int year;

   year = 1988;
   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
   {
      printf("%d es un año bisiesto\n", year);
   }
   else
   {
      printf("%d no es un año bisiesto\n", year);
   }

   return 0;
}
