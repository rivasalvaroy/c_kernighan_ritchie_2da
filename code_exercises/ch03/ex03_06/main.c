/* Escriba una versión de itoa que acepte tres argumentos en lugar de dos. 
   El tercer argumento es un ancho mínimo de campo; al número converti­do se deben 
   agregar blancos a la izquierda si es necesario para hacerlo suficiente­mente ancho. */
#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w); // prototipo de la función itoa

// la función main empieza la ejecución del programa
int main()
{
   char numberstring[MAXLINE];
   int n, w;

   n = 15;
   w = 10;
   itoa(n, numberstring, w);
   printf("%s\n", numberstring);
   return 0;
}
// función que convierte el entero n a una cadena de caracteres s
void itoa(int n, char s[], int w)
{
   int i, sign;
   void reverse(char s[]);

   sign = n; // guarda el signo
   i = 0;
   do // genera dígitos en orden inverso
   {  // toma el siguiente dígito
      s[i++] = abs(n % 10) + '0';
   } while ((n /= 10) != 0); // borralo
   if (sign < 0)
      s[i++] = '-';
   while (i < w)
      s[i++] = '0';
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
