/* Elimina espacios blancos, tabuladores y nuevas líneas al final de una cadena,
   utilizando un break para salir de un ciclo cuando se encuentra el no-blanco,
   no-tabulador o no-nueva línea de más a la derecha */
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int pr_getline(char line[], int jump); // prototipo de la función pr_getline
int trim(char s[]);                    // prototipo de la función trim

// la función main empieza la ejecución del programa
int main()
{
   int len, lem;
   char line[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) > 0)
   {
      printf("\n%d\n%s", len, line);
      lem = trim(line);
      printf("%d\n%s", lem, line);
   }
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
// función que elimina los blancos, tabuladores y nueva línea al final
int trim(char s[])
{
   int n;

   for (n = strlen(s) - 1; n >= 0; n--)
      if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      {
         s[++n] = '\0';
         break;
      }
   s[n + 1] = '\0';
   return n;
}