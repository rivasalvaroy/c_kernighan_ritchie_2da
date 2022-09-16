// Envía una cadena de caracteres y regresa la longitud de la misma, prototype_strlen
#include <stdio.h>

int pr_strlen(char s[]); // prototipo de la función pr_strlen

// la función main empieza la ejecución del programa
int main()
{
   char s[] = "Hola Mundo";
   printf("%d\n", pr_strlen(s));
   return 0;
}
// función que regresa la longitud de su argumento s de tipo cadena de caracteres
int pr_strlen(char s[])
{
   int i;

   i = 0;
   while (s[i] != '\0')
      ++i;
   return i;
}
