/* Escriba un programa para revisar los errores de sintaxis rudimen­tarios de 
   un programa en C, como paréntesis, llaves y corchetes no alineados. No olvide 
   las comillas ni los apóstrofos, las secuencias de escape y los comentarios.
   (Este programa es difícil si se hace completamente general.) */
#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);  // prototipo de la función in_quote
void in_comment(void); // prototipo de la función in_comment
void search(int c);    // prototipo de la función search

// la función main empieza la ejecución del programa
int main()
{
   int c;
   extern int brace, brack, paren;

   while ((c = getchar()) != EOF)
      if (c == '/')
      {
         if ((c = getchar()) == '*')
            in_comment(); // dentro de un comentario
         else
            search(c);
      }
      else if (c == '\'' || c == '"')
         in_quote(c); // entre comillas
      else
         search(c);

   if (brace < 0)
   {
      printf("Unbalanced braces\n"); // errores de salida
      brace = 0;
   }
   else if (brack < 0)
   {
      printf("Unbalanced brackets\n");
      brack = 0;
   }
   else if (paren < 0)
   {
      printf("Unbalanced parentheses\n");
      paren = 0;
   }
   if (brace > 0)
   {
      printf("Unbalanced braces\n");
   }
   if (brack > 0)
   {
      printf("Unbalanced brackets\n");
   }
   if (paren > 0)
   {
      printf("Unbalanced parentheses\n");
   }
   return 0;
}
// función para busqueda de rudimentarios errores de sintaxis
void search(int c)
{
   extern int brace, brack, paren;
   if (c == '{')
      ++brace;
   else if (c == '}')
      --brace;
   else if (c == '[')
      ++brack;
   else if (c == ']')
      --brack;
   else if (c == '(')
      ++paren;
   else if (c == ')')
      --paren;
}
// función que evalua si esta dentro de un comentario valido
void in_comment(void)
{
   int c, d;
   c = getchar(); // carácter previo
   d = getchar(); // carácter actual
   while (c != '*' || d != '/')
   {
      c = d;
      d = getchar();
   }
}
// función que evalua caracteres dentro de comillas
void in_quote(int c)
{
   int d;
   while ((d = getchar()) != c)
      if (d == '\\')
         getchar(); // ignora secuencia de escape
}