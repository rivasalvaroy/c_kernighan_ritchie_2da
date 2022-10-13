/* En una representación de números en complemento a dos, nuestra versión de itoa no
   maneja el número negativo más grande, esto es, el valor de n igual a -(2^(tamaño de palabra-1))
   explique porque. Modifíquelo para imprimir el valor correctamente, sin importar la
   maquina en que se ejecute */
#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]); // prototipo de la función itoa

// la función main empieza la ejecución del programa
int main()
{
   char numberstring[MAXLINE];
   int n;

   n = -2147483648;
   itoa(n, numberstring);
   printf("%s\n", numberstring);
   return 0;
}
// función que convierte n a caracteres en s - modificado
void itoa(int n, char s[])
{
   int i, sign;
   void reverse(char s[]); // prototipo de la función reverse

   sign = n; // guarda el signo
   i = 0;
   do
   {
      s[i++] = abs(n % 10) + '0'; // toma el siguiente dígito
   } while ((n /= 10) != 0);      // borralo
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