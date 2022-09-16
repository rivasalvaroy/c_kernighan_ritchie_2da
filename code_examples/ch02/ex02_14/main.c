// Cuenta el número de bits en 1
#include <stdio.h>

int bitcount(unsigned x); // prototipo de la función bitcount

// la función main empieza la ejecución del programa
int main()
{
   int num;

   num = 5;
   printf("%d\n", bitcount(num));
   return 0;
}
// función que cuenta bits 1 en x
int bitcount(unsigned x)
{
   int b;

   for (b = 0; x != 0; x >>= 1)
      if (x & 1)
         b++;
   return b;
}