// Uso de la libreria ctype
#include <stdio.h>
#include <ctype.h>

// la función main empieza la ejecución del programa
int main()
{
   char letter;

   letter = 'M';
   printf("%c \n", tolower((int)letter));
   return 0;
}
