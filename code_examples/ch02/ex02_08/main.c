// Uso de la libreria ctype
#include <stdio.h>
#include <ctype.h>

// la función main empieza la ejecución del programa
int main()
{
   char num;

   num = '9';
   if (isdigit((int)num))
      printf("Si es un numero\n");
   else
      printf("No es un numero\n");
   return 0;
}