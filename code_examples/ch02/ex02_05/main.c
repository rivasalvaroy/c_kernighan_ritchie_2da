// Convierte una cadena de dígitos en su equivalente numérico
#include <stdio.h>

int atoi(char s[]); // prototipo de la función atoi

// la función main empieza la ejecución del programa
int main()
{
   char s[] = "1998";
   int num;

   num = atoi(s);
   printf("%d \n", num);
   return 0;
}
// función que convierte una cadena de caracteres a entero
int atoi(char s[])
{
   int i, n;

   n = 0;
   for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
      n = 10 * n + (s[i] - '0');
   return n;
}