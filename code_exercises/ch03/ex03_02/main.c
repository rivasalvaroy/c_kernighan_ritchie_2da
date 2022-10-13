/* Escriba una función escape(s,t) que convierte caracteres como
   nueva línea y tabulación en secuencias de escape visibles como \n y \t mientras
   copia la cadena t a s. Utilice un switch. Escriba también una función para la
   di­rección inversa, convirtiendo secuencias de escape en caracteres reales */
#include <stdio.h>

#define MAXLINE 100

int pr_getline(char line[], int lim); // prototipo de la función pr_getline
void escape(char s[], char t[]);      // prototipo de la función escape
void unescape(char s[], char t[]);    // prototipo de la función unescape

// la función main empieza la ejecución del programa
int main()
{
   char line[MAXLINE];
   char modline[MAXLINE];

   pr_getline(line, MAXLINE);
   escape(modline, line);
   printf("\n%s\n", modline);
   unescape(modline, line);
   printf("\n%s\n", modline);
   return 0;
}
// función que lee una linea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
      s[i] = c;
   s[i] = '\0';
   return i;
}
// función que expande la nueva línea y el tabulador en secuencias visibles
// mientras se copia la cadena t a s
void escape(char s[], char t[])
{
   int i, j;

   for (i = j = 0; t[i] != '\0'; i++)
      switch (t[i])
      {
      case '\n':
         s[j++] = '\\'; // nueva línea
         s[j++] = 'n';
         break;
      case '\t':
         s[j++] = '\\'; // tabulación
         s[j++] = 't';
         break;
      default:
         s[j++] = t[i]; // todos los demás caracteres
         break;
      }
   s[j] = '\0';
}
// función que convierte secuencias de escape en caracteres reales
void unescape(char s[], char t[])
{
   int i, j;

   for (i = j = 0; t[i] != '\0'; i++)
   {
      if (t[i] != '\\')
         s[j++] = t[i];
      else
         switch (t[++i])
         {
         case 'n':
            s[j++] = '\n';
            break;
         case 't':
            s[j++] = '\t';
            break;
         default:
            s[j++] = '\\';
            s[j++] = t[i];
            break;
         }
   }
   s[j] = '\0';
}