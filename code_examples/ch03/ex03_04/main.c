// Invierte a la cadena s en el mismo lugar
#include <stdio.h>
#include <string.h>

void reverse(char s[]); // prototipo de la función reverse

// la función main empieza la ejecución del programa
int main()
{
   char v[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

   printf("%s\n", v);
   reverse(v);
   printf("%s\n", v);
   return 0;
}
// función que invierte el arreglo s en el mismo lugar
void reverse(char s[])
{
   int c, i, j;

   for (i = 0, j = (strlen(s) - 1); i < j; i++, j--)
   {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
   }
}
