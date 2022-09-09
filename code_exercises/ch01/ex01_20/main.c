/* Escriba una función reverse(s) que invierta la cadena de
   caracteres s. Úsela para escribir un programa que invierta su entrada,
   línea a línea */
#include <stdio.h>

#define MAXLINE 1000 // tamaño máximo líneas de entrada

int pr_getline(char line[], int maxline); // prototipo de la función pr_getline
void reverse(char s[]);                   // prototipo de la función reverse

// la función main empieza la ejecución del programa
int main()
{
   char line[MAXLINE];

   while (pr_getline(line, MAXLINE) > 0)
   {
      reverse(line);
      printf("%s", line);
   }
   return 0;
}
// función que invierte los caracteres de entrada
void reverse(char s[])
{
   int i, j;
   char temp;

   i = 0;
   while (s[i] != '\0') // encuentra el final de la línea
      ++i;
   --i;
   if (s[i] == '\n')
      --i;
   j = 0;
   while (j < i)
   {
      temp = s[j];
      s[j] = s[i]; // swap de caracteres
      s[i] = temp;
      --i;
      ++j;
   }
}
// función que lee una línea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
   if (c == '\n')
   {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}