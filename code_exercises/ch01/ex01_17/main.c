/* Corrija la rutina principal del programa de la línea más larga de
   modo que imprima correctamente la longitud de líneas de entrada 
   arbitrariamente largas, y tanto texto como sea posible */
#include <stdio.h>

#define MAXLINE 10 // tamaño máximo de la línea de entrada

int pr_getline(char line[], int maxline); // prototipo de la función pr_getline
void copy(char to[], char from[]);        // prototipo de la función copy

// la función main empieza la ejecución del programa
int main()
{
   int len;               // longitud actual de la línea
   int max;               // máxima longitud vista hasta el momento
   char line[MAXLINE];    // línea de entrada actual
   char longest[MAXLINE]; // la línea más larga se guarda aquí

   max = 0;
   while ((len = pr_getline(line, MAXLINE)) > 0)
      if (len > max)
      {
         max = len;
         copy(longest, line);
      }
   if (max > 0) // hubo una línea
      printf("%s", longest);
   return 0;
}
// función que lee una línea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i, j;

   j = 0;
   for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
      if (i < lim - 2)
      {
         s[j] = c; // línea todavia en los límites
         ++j;
      }
   if (c == '\n')
   {
      s[j] = c;
      ++j;
      ++i;
   }
   s[j] = '\0';
   return i;
}
// función que copia 'from' en 'to'; supone que to es suficientemente grande
void copy(char to[], char from[])
{
   int i;

   i = 0;
   while ((to[i] = from[i]) != '\0')
      ++i;
}
