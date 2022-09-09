/* Escriba un programa que imprima el histograma de las longitudes de
   las palabras de su entrada. De forma Horizontal, es fácil dibujar el
   histograma con barras horizontales; la orientación vertical es un reto
   mas interesante */
#include <stdio.h>

#define MAXWORD 23
#define IN 1
#define OUT 0

// la función main empieza la ejecución del programa
int main()
{
   int nc, nw, c, i, state, ovflow;
   state = OUT;
   nc = nw = ovflow = 0;
   int word[MAXWORD]; // máximo número de caracteres por palabra

   for (i = 0; i < MAXWORD; ++i)
      word[i] = 0; // llena el arreglo con 0
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
   }
   ++word[nc];
   printf("\nHistograma de palabras con la misma cantidad de caracteres.\n");
   printf("Numero de palabras: %d\n", nw);
   printf("-------------------------------------------------------------\n\n");
   printf(" No C      No de Palabras\n");
   for (i = 1; i < MAXWORD; ++i)
   {
      printf(" %3d | %5d |", i, word[i]);
      for (int j = 0; j < word[i]; ++j)
         printf("*");
      printf("\n");
   }
   if (ovflow > 0)
      printf("Hay %d palabras >= %d\n", ovflow, MAXWORD);

   return 0;
}