/* Reescriba la función [lower|, que convierte letras mayúsculas en
   minúsculas, con una expresión condicional en vez de un if-else */
#include <stdio.h>

#define MAXLINE 10

int pr_getline(char line[], int lim); // prototipo de la función pr_getline
int lower(int c);                     // prototipo de la función lower

// la función main empieza la ejecución del programa
int main()
{
   int len;
   char line[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) > 0)
      if (len > 1)
         printf("%s", line);
   return 0;
}
// función que lee una línea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
   {
      c = lower(c);
      s[i] = c;
   }
   if (c == '\n')
   {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}
// función que convierte mayúsculas a minúsculas
int lower(int c)
{
   return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}