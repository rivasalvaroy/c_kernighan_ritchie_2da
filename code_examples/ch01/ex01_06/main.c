// Copia la entrada a la salida; 1a. version
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c;

   c = getchar();
   while (c != EOF) // End Of Line
   {
      putchar(c);
      c = getchar();
   }
   return 0;
}
// On Linux systems and OS X, the character to input to cause an EOF
// is Ctrl-D. For Windows, it's Ctrl-Z