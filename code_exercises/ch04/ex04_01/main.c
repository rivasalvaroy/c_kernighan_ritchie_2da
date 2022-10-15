/* Escriba la función strrindex(s,t), que regresa la posición de la ocu­rrencia 
   de más a la derecha de t en s, ó -1 si no hay alguna */
#include <stdio.h>

#define MAXLINE 100

int pr_getline(char line[], int max);           // prototipo de la función pr_getline
int strrindex(char source[], char searchfor[]); // prototipo de la función strrindex

char pattem[] = "ould"; // patrón a buscar

// la función main empieza la ejecución del programa
int main()
{
   char line[MAXLINE];
   int found = 0;

   while (pr_getline(line, MAXLINE) > 0)
      if (strrindex(line, pattem) >= 0)
      {
         printf("%s", line);
         found++;
      }
   return found;
}
// función que trae línea y la pone en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   i = 0;
   while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
      s[i++] = c;
   if (c == '\n')
      s[i++] = c;
   s[i] = '\0';
   return i;
}
// función que regresa la posición de la ocu­rrencia de más a la derecha de t en s,
// ó -1 si no hay alguna
int strrindex(char s[], char t[])
{
   int i, j, k, pos;

   pos = -1;
   for (i = 0; s[i] != '\0'; i++)
   {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
         ;
      if (k > 0 && t[k] == '\0')
         pos = i;
   }
   return pos;
}