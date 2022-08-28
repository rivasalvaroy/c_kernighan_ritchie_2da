// A continuación se presenta la función power y un programa main para utilizarla
#include <stdio.h>

int power(int m, int n); // prototipo de la función power

// la función main empieza la ejecución del programa
int main()
{
   int i;
   for (i = 0; i < 10; ++i)
      printf("%3d %4d %6d\n", i, power(2, i), power(-3, i));

   return 0;
}
// función que eleva la base a la n-esima potencia; n >= 0
int power(int base, int n)
{
   int i, p;

   p = 1;
   for (i = 1; i <= n; ++i)
      p = p * base;
   return p;
}