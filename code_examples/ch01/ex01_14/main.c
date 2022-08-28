/* Para ilustrar el uso de arreglos de caracteres y funciones que los
   manipulan, escriba un programa que lea un conjunto de líneas de texto
   e imprima la de mayor longitud, prototype_getline */
#include <stdio.h>

#define MAXLINE 10 // tamaño máximo de la línea de entrada

int pr_getline(char line[], int maxl); // prototipo de la función pr_getline
void copy(char to[], char from[]);     // prototipo de la función copy

// la función main empieza la ejecución del programa
int main()
{
   int len;               // longitud actual de la línea
   int max;               // máxima longitud vista hasta el momento
   char line[MAXLINE];    // línea de entrada actual
   char longest[MAXLINE]; // la línea más larga se guarda aqui

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
// función que copia 'from' en 'to'; supone que to es suficientemente grande
void copy(char to[], char from[])
{
   int i;

   i = 0;
   while ((to[i] = from[i]) != '\0')
      ++i;
}
/* este programa tiene un problema ya que toma la primer línea que
   supera el límite de largo(MAXLINE) como la más larga, aunque haya una más
   larga despues de esta */
