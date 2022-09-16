// Elimina todas las ocurrencias del carácter c de una cadena s
#include <stdio.h>

void squeeze(char s[], int c); // prototipo de la función squeeze

// la función main empieza la ejecución del programa
int main()
{
   char s[] = "Hello world";

   squeeze(s, 'o');
   printf("%s\n", s);
   return 0;
}
// función que borra todas las c de s
void squeeze(char s[], int c)
{
   int i, j;

   for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != c)
         s[j++] = s[i];
   s[j] = '\0';
}