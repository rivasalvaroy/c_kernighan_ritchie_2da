/* Escriba un programa que copie su entrada a la salida, reemplazando
   cada tabulación por \t, cada retroceso por \b y cada diagonal invertida  por \\
   Esto hace que los espacios y las tabulaciones sean visibles sin confusiones */
#include <stdio.h>

// la función main empieza la ejecución del programa
int main()
{
   int c;

   while ((c = getchar()) != EOF)
   {
      if (c == '\t')
         printf("\\t");
      if (c == '\b')
         printf("\\b");
      if (c == '\\')
         printf("\\\\");
      if (c != '\b')
         if (c != '\t')
            if (c != '\\')
               putchar(c);
   }
   return 0;
}

// utilizando if else
/*
int main()
{
   int c;

   while ((c = getchar()) != EOF)
      if (c == '\t')
         printf("\\t");
      else if (c == '\b')
         printf("\\b");
      else if (c == '\\')
         printf("\\\\");
      else
         putchar(c);
   return 0;
}
*/