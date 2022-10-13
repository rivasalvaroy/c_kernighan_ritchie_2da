// Convierte un número a una cadena de caracteres (lo inverso de atoi)
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void itoa(int n, char s[]); // prototipo de la función itoa
void reverse(char s2[]);    // prototipo de la función reverse

// la función main empieza la ejecución del programa
int main()
{
   char cad[MAXLINE];
   int n;

   n = 1985;
   itoa(n, cad);
   printf("%s\n", cad);
   return 0;
}
// funcion que convierte el entero n a un arreglo s
void itoa(int n, char s[])
{
   int i, sign;

   if ((sign = n) < 0)
      n = -n; // vuelve a ser positivo
   i = 0;
   do // genera dígitos en orden inverso
   {
      s[i++] = n % 10 + '0'; // toma el siguiente dígito
   } while ((n /= 10) > 0);  // bórralo
   if (sign < 0)
      s[i++] = '-';
   s[i] = '\0';
   reverse(s);
}
// función que invierte el arreglo s en el mismo lugar
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