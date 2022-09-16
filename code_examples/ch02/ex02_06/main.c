// Convierte carácter en Mayúscula a minúscula
#include <stdio.h>

int lower(int c); // prototipo de la función lower

// la función main empieza la ejecución del programa
int main()
{
   char letter;

   letter = 'M';
   printf("%c \n", lower(letter));
   return 0;
}
// función que convierte un carácter en minuscula
int lower(int c)
{
   if (c >= 'A' && c <= 'Z')
      return c + 'a' - 'A';
   else
      return c;
}
