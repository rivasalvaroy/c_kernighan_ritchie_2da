/* En un sistema de números de complemento a dos, x & = (x-1) borra el bit 1 
   de más a la derecha en x. Explique el porqué. Utilice esta observación
   para escribir una versión más rápida de bitcount */
#include <stdio.h>

#define MAXLINE 22
#define MAXBIN 66
#define YES 1
#define NO 0

int pr_getline(char line[], int jump);       // prototipo de la función pr_getline
unsigned long atoul(char s[]);               // prototipo de la función atoul
void ultoba(char numb[], unsigned long num); // prototipo de la función ultoba
void printba(char b[]);                      // prototipo de la función printba
int bitcount(unsigned long x);               // prototipo de la función bitcount

// la función main empieza la ejecución del programa
int main()
{
   int len, isnumb, res;
   unsigned long numd;
   char line[MAXLINE];
   char numbx[MAXBIN];

   printf("Introduzca numero: \n");
   while ((len = pr_getline(line, MAXLINE)) > 0)
   {
      isnumb = YES;
      for (int i = 0; i < len - 1; i++)
      {
         if (line[i] >= '0' && line[i] <= '9')
            ;
         else
            isnumb = NO;
      }
      if (isnumb != NO)
      {
         numd = atoul(line);
         ultoba(numbx, numd);
         printf("\n");
         printba(numbx);
         res = bitcount(numd);
         printf("%d\n", res);
         break;
      }
   }
   return 0;
}
// función que lee una línea en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
      s[i] = c;
   if (c == '\n')
   {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}
// función que convierte un arreglo char en un unsigned long
unsigned long atoul(char s[])
{
   int i;
   unsigned long n;

   n = 0;
   for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
      n = 10 * n + (s[i] - '0');
   return n;
}
// función que simula un número binario en arreglo char a partir de un unsigned long
void ultoba(char b[], unsigned long num)
{
   int i, aux;

   b[65] = '\0';
   b[64] = '\n';
   for (i = 63; i >= 0; i--)
   {
      aux = num % 2;
      if (aux == 1)
         b[i] = '1';
      else
         b[i] = '0';
      num = num / 2;
   }
}
// función que imprime un arreglo char simulando número binario
void printba(char b[])
{
   int j, k;

   j = k = 0;
   for (int i = 0; i < 65; i++)
   {
      j++;
      printf("%c", b[i]);
      if (j == 4)
      {
         printf(" ");
         j = 0;
         k++;
      }
      if (k == 8)
      {
         printf("\n");
         k = 0;
      }
   }
}
// función que cuenta el número de bits que esta a 1
int bitcount(unsigned long x)
{
   int b;

   for (b = 0; x != 0; x &= x - 1)
      ++b;
   return b;
}