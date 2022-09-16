// Expresión condicional escrita con el operador ternario ?
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int a, b, z;

   a = 4;
   b = 13;
   z = (a > b) ? a : b; // z = max(a,b)
   printf("z: %d\n", z);
   return 0;
}
