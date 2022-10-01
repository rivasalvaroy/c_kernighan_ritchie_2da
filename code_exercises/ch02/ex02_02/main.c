/* -Para ilustrar el uso de arreglos de caracteres y funciones que los
   manipulan , escriba un programa que lea un conjunto de líneas de texto
   e imprima la de mayor longitud-
   ex02_02 escriba un ciclo equivalente a la iteración for sin usar && u !=
   for (i = 0; i < MAXLINE - 1 && (c = getchar()) != '\n' && c != EOF; ++i) */
#include <stdio.h>

#define MAXLINE 10 //   tamaño máximo de la línea de entrada

int pr_getline(char line[], int maxl); // prototipo de la función pr_getline
void copy(char to[], char from[]);     // prototipo de la función copy

// la función main empieza la ejecución del programa
int main()
{
   int len;               // longitud actual de la línea
   int max;               // máxima longitud vista hasta el momento
   char line[MAXLINE];    // línea de entrada actual
   char longest[MAXLINE]; // la línea mas larga se guarda aquí

   max = 0;
   while ((len = pr_getline(line, MAXLINE)) > 0)
      if (len > max)
      {
         max = len;
         copy(longest, line);
      }
   if (max > 0) // hubo una línea
      printf("%s\n", longest);
   return 0;
}
// función que lee una línea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   enum loop // el primer valor en enum tiene el valor de 0 el segundo de 1 y asi..
   {
      NO,
      YES
   };
   enum loop okloop = YES;

   i = 0;
   while (okloop == YES)
      if (i >= lim - 1) // fuera del rango valido
         okloop = NO;
      else if ((c = getchar()) == '\n')
         okloop = NO;
      else if (c == EOF)
         okloop = NO; //   fin del archivo
      else
      {
         s[i] = c;
         ++i;
      }
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