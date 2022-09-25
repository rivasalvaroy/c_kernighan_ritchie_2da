/* Escriba un programa para determinar los rangos de variables char
   short, int, long, tanto signed como unsigned, imprimiendo los valores 
   apropiados desde los headers estándar y por cálculo directo */
#include <stdio.h>
#include <limits.h>

// la función main empieza la ejecución del programa
int main()
{
   printf("signed char min =\t %d\n", SCHAR_MIN);
   printf("signed char max =\t %d\n", SCHAR_MAX);
   printf("signed short min =\t %d\n", SHRT_MIN);
   printf("signed short max =\t %d\n", SHRT_MAX);
   printf("signed int min =\t %d\n", INT_MIN);
   printf("signed int max =\t %d\n", INT_MAX);
   printf("signed long min =\t %ld\n", LONG_MIN);
   printf("signed long max =\t %ld\n", LONG_MAX);
   // unsigned types
   printf("unsigned char max =\t %u\n", UCHAR_MAX);
   printf("unsigned short max =\t %u\n", USHRT_MAX);
   printf("unsigned int max =\t %u\n", UINT_MAX);
   printf("unsigned long max =\t %lu\n\n\n", ULONG_MAX);

   // otra forma de determinarlos es la siguiente
   unsigned char c;
   unsigned short s;
   unsigned int i;
   unsigned long l;

   c = ~0;
   c >>= 1;
   // char
   printf("signed char:\t %20d \t %20d\n", -c - 1, c);
   printf("unsigned char:\t %20u \t %20u\n", 0, c * 2 + 1);

   s = ~0;
   s >>= 1;
   // short
   printf("signed short:\t %20d \t %20d\n", -s - 1, s);
   printf("unsigned short:\t %20u \t %20u\n", 0, s * 2 + 1);

   i = ~0;
   i >>= 1;
   // int
   printf("signed int:\t %20d \t %20d\n", -i - 1, i);
   printf("unsigned int:\t %20u \t %20u\n", 0, i * 2 + 1);

   l = ~0;
   l >>= 1;
   // long
   printf("signed long:\t %20ld \t %20ld\n", -l - 1, l);
   printf("unsigned long:\t %20lu \t %20lu\n", 0l, l * 2 + 1);

   printf("signed char min: %d\n", -(char)((unsigned char)~0 >> 1));
   printf("signed char max: %d\n", (char)((unsigned char)~0 >> 1));
   return 0;
}
