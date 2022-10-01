/* Escriba la función htoi(s), que convierte una cadena de dígitos
   hexadecimales (incluyendo Ox ó OX en forma optativa) en su valor 
   entero equiva­lente. Los dígitos permitidos son del 0 al 9, 
   de la a a la f, y de la A a la F */
#include <stdio.h>

#define MAXLINE 10
#define YES 1
#define NO 0

int pr_getline(char line[], int lim); // prototipo de la función pr_getline
int htoi(char s[]);                   // prototipo de la función htoi

// la función main empieza la ejecución del programa
int main()
{
   int len;
   int numd;
   char line[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) > 0)
   {
      numd = htoi(line);
      if (numd != 0)
         printf("%d\n", numd);
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
// función que convierte un arreglo de caracteres(numero hexadecimal) en un número entero
int htoi(char s[])
{
   int hexdigit, i, inhex, n;

   i = 0;
   if (s[i] == '0')
   {
      ++i;
      if (s[i] == 'x' || s[i] == 'X')
         ++i;
   }
   n = 0;
   inhex = YES;
   for (; inhex == YES; ++i)
   {
      if (s[i] >= '0' && s[i] <= '9')
         hexdigit = s[i] - '0';
      else if (s[i] >= 'a' && s[i] <= 'f')
         hexdigit = s[i] - 'a' + 10;
      else if (s[i] >= 'A' && s[i] <= 'F')
         hexdigit = s[i] - 'A' + 10;
      else
         inhex = NO;
      if (inhex == YES)
         n = 16 * n + hexdigit;
   }
   return n;
}
