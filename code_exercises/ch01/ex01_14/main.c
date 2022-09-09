/* Escriba un programa que imprima el histograma de las longitudes de
   las palabras de su entrada, con orientación vertical */
#include <stdio.h>

#define MAXWORD 23
#define IN 1
#define OUT 0

// la función main empieza la ejecución del programa
int main()
{
   int nc, nw, mr, state, maxvalue, ovflow, c, i;
   int word[MAXWORD];

   state = OUT;
   nc = nw = mr = ovflow = 0;
   for (i = 0; i < MAXWORD; ++i)
      word[i] = 0;
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
   printf("Numero de palabras: %d\n\n", nw);
   for (i = 0; i < MAXWORD; ++i)
      if (mr < word[i])
         mr = word[i];
   maxvalue = mr;
   for (i = 0; i < mr; ++i)
   {
      for (int j = 1; j < MAXWORD; ++j)
      {
         if (word[j] >= maxvalue)
            printf(" * ");
         else
            printf("   ");
      }
      --maxvalue;
      printf("\n");
   }
   printf("-----------------------------------------------------------------\n");
   for (i = 1; i < MAXWORD; ++i)
      printf("%2d ", i);
   printf("\n\n");
   if (ovflow > 0)
      printf("Hay %d palabras >= %d\n", ovflow, MAXWORD);
   return 0;
}
