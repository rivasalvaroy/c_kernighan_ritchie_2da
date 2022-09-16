// Regresa el campo de n bits de x (ajustado a la derecha)
// que principia en la posición p
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n); // prototipo de la función getbits

// la función main empieza la ejecución del programa
int main()
{
   unsigned x; // unsigned y unsigned int son equivalentes
   int p, n;

   x = 11; // para x = 1011
   p = 3;
   n = 2;
   printf("%u\n", getbits(x, p, n));
   return 0;
}
// función que obtiene n bits desde la posición p
unsigned getbits(unsigned x, int p, int n)
{
   return x >> (p + 1 - n) & ~(~0 << n);
}
// 1011 >> (3 + 1 -2)
// 1011 >> 2 = 0010
// &
// ~(1111 << 2) = ~(1100)
// 0011

// 0010 & 0011 = 0010 = 2
