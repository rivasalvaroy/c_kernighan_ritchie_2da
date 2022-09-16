// Generador de numeros pseudoaleatorios
#include <stdio.h>

unsigned long int next = 1; // cast

int rand(void);                // prototipo de la función rand
void srand(unsigned int seed); // prototipo de la función srand

// la función main empieza la ejecución del programa
int main()
{
   int seed;

   seed = 3;
   srand(seed);
   printf("%u \n", rand());
   return 0;
}
// función que regresa un entero pseudoaletorio en 0..32767
int rand(void)
{
   next = next * 1103515245 + 12345;
   return (unsigned int)(next / 65536) % 32768;
}
// función que fija la semilla para rand()
void srand(unsigned int seed)
{
   next = seed;
}