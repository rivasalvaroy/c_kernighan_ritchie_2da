/* Escriba la función itob(n,s,b) que convierte al entero n en una re­presentación
   de caracteres con base b dentro de la cadena s. En particular, itob(n, s, 16)
   da formato a n como un entero hexadecimal en s */
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void itob(int n, char s[], int b); // prototipo de la función itob

// la función main empieza la ejecución del programa
int main()
{
   char numberstring[MAXLINE];
   int n, b;

   n = 255; // número
   b = 16;  // base
   itob(n, numberstring, b);
   printf("%s\n", numberstring);
   return 0;
}
// función que convierte al entero n en una re­presentación de caracteres con base b dentro de la cadena s
void itob(int n, char s[], int b)
{
   int i, j, sign;
   void reverse(char s[]); // prototipo de la función reverse

   if ((sign = n) < 0) // guarda el signo
      n = -n;          // has n positivo
   i = 0;
   do
   {             // genera dígitos en orden inverso
      j = n % b; // toma el siguiente dígito
      s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
   } while ((n /= b) > 0); // borralo
   if (sign < 0)
      s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}
// función que invierte la cadena s en el mismo lugar
void reverse(char s[])
{
   int c, i, j;

   for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
   {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
   }
}