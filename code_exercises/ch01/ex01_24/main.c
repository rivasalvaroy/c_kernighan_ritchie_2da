// Escriba un programa que remueva todos los comentarios de un programa en C
#include <stdio.h>

void rcomment(int c);   // prototipo de la función rcomment
void in_comment(void);  // prototipo de la función in_comment
void echo_quote(int c); // prototipo de la función echo_quote

// la función main empieza la ejecución del programa
int main()
{
   int c;

   while ((c = getchar()) != EOF)
      rcomment(c);
   return 0;
}
// función que lee cada carácter, remueve los comentarios
void rcomment(int c)
{
   int d;

   if (c == '/')
      if ((d = getchar()) == '*')
         in_comment(); // comienza comentario
      else if (d == '/')
      {
         putchar(c); // otro slash
         rcomment(d);
      }
      else
      {
         putchar(c); // no es un comentario
         putchar(d);
      }
   else if (c == '\'' || c == '"') // \' es apostrofe
      echo_quote(c);
   else
      putchar(c);
}
// función que evalua si esta dentro de un comentario valido
void in_comment(void)
{
   int c, d;

   c = getchar();
   d = getchar();
   while (c != '*' || d != '/')
   {
      c = d;
      d = getchar();
   }
}
// función que evalua caracteres dentro de comillas
void echo_quote(int c)
{
   int d;

   putchar(c);
   while ((d = getchar()) != c)
   {
      putchar(d);
      if (d == '\\')
         putchar(getchar()); // ignora secuencia de escape
   }
   putchar(d);
}
