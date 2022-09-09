/* Escriba un programa que imprima el histograma de las frecuencias con
   que se presentan diferentes caracteres leídos a la entrada */
#include <stdio.h>

#define MAXWORD 23  // tamaño máximo de una palabra
#define MAXCHAR 123 // cantidad máxima de caracteres diferentes
#define IN 1
#define OUT 0

// la función main empieza la ejecución del programa
int main()
{
   int nc, nw, mr, state, maxvalue, ovflow, min, max, c, i;
   int word[MAXWORD];
   int character[MAXCHAR];

   state = OUT;
   nc = nw = ovflow = 0;
   for (i = 0; i < MAXWORD; ++i)
      word[i] = 0;
   for (i = 32; i < MAXCHAR; ++i) // tomando en cuenta la tabla ascci comienza en 32 y termina en 254
      character[i] = 0;
   while ((c = getchar()) != EOF)
   {
      if (c == ' ' || c == '\n' || c == '\t')
      {
         state = OUT;
         if (nc > 0)
         {
            if (nc < MAXWORD)
               ++word[nc];
            else
               ++ovflow;
         }
         nc = 0;
      }
      else
      {
         if (state == OUT)
         {
            state = IN;
            ++nw;
         }
         ++nc;
      }
      for (i = 32; i < MAXCHAR; ++i)
         if (c == i)
            ++character[i];
   }
   ++word[nc];
   printf("\nHistograma de caracteres usados.\n");
   printf("Numero de palabras: %d\n", nw);
   if (ovflow > 0)
      printf("Hay %d palabras >= %d\n", ovflow, MAXWORD);
   printf("\n");

   for (int g = 0; g < 4; ++g)
   {
      mr = 0;
      if (g == 0)
      {
         min = 97;
         max = 122;
         printf("Minusculas\n");
      }
      if (g == 1)
      {
         min = 65;
         max = 90;
         printf("Mayusculas\n");
      }
      if (g == 2)
      {
         min = 32;
         max = 64;
         printf("Caracteres Especiales\n");
      }
      if (g == 3)
      {
         min = 91;
         max = 96;
         printf("Mas Especiales\n");
      }

      for (i = min; i <= max; ++i)
         if (mr < character[i])
            mr = character[i];
      maxvalue = mr;

      for (i = 0; i < mr; ++i)
      {
         for (int j = min; j <= max; ++j)
         {
            if (character[j] >= maxvalue)
               printf("* ");
            else
               printf("  ");
         }
         --maxvalue;
         printf("\n");
      }
      printf("-----------------------------------------------------------------\n");
      for (i = min; i <= max; ++i)
         printf("%c ", i);
      printf("\n\n");
   }
   return 0;
}