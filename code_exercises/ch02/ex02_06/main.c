/* Escriba una función setbits(x,p,n,y) que regresa x con los n bits que
   principian en la posición p iguales a los n bits más a la derecha de y, 
   dejando los otros bits sin cambio */
#include <stdio.h>

#define MAXLINE 22
#define MAXBIN 66
#define YES 1
#define NO 0

int pr_getline(char line[], int lim);                                  // prototipo de la función pr_getline
unsigned long atoul(char s[]);                                         // prototipo de la función atoul
unsigned long setbits(unsigned long x, int p, int n, unsigned long y); // prototipo de la función setbits
unsigned long getbits(unsigned long x, int p, int n);                  // prototipo de la función getbits
void ultoba(char numb[], unsigned long num);                           // prototipo de la función ultoba
void printba(char b[]);                                                // prototipo de la función printba

// la función main empieza la ejecución del programa
int main()
{
   int len, pos, nbits, isnumb, x;
   unsigned long numd, numdx, numdy, setnum;
   char line[MAXLINE];
   char numbx[MAXBIN];
   char numby[MAXBIN];
   char setnumb[MAXBIN];

   x = 0;
   printf("Introduzca par de numeros: \n");
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
         printf("\n");
         if (x == 0)
         {
            numdx = numd;
            ultoba(numbx, numdx);
            printba(numbx);
         }
         else if (x == 1)
         {
            numdy = numd;
            ultoba(numby, numdy);
            printba(numby);
            printf("Introduzca la posición: \n");
         }
         else if (x == 2)
         {
            pos = numd;
            printf("Introduzca el num de bits: \n");
         }
         else if (x == 3)
         {
            nbits = numd;
            printf("Se evaluara la función setbits(%lu, %d, %d, %lu)\n", numdx, pos, nbits, numdy);
            printf("donde x = %lu\n", numdx);
            printf("donde y = %lu\n", numdy);
            printf("donde pos = %d\n", pos);
            printf("donde nbits = %d\n\n", nbits);
            setnum = setbits(numdx, pos, nbits, numdy);
            ultoba(setnumb, setnum);
            printba(setnumb);
            break;
         }
         x++;
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
// función que convierte un arreglo char en unsigned long
unsigned long atoul(char s[])
{
   int i;
   unsigned long n;

   n = 0;
   for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
      n = 10 * n + (s[i] - '0');
   return n;
}
//  función que simula numero binaro en arreglo char a partir de un unsigned long
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
// función que imprime un arreglo char simulando número un binario
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
// función que regresa x con los n bits que principian en la posición p iguales
// a los n bits más a la derecha de y, dejando los otros bits sin cambio.
unsigned long setbits(unsigned long x, int p, int n, unsigned long y)
{
   unsigned long mask = ~(~((unsigned long)0) << n) << (p - n + 1);
   x &= ~mask;
   y = getbits(y, n - 1, n);
   y <<= (p - n + 1);
   return x | y;
}
// función que obtine n bits desde la posición p
unsigned long getbits(unsigned long x, int p, int n)
{
   return (x >> (p + 1 - n)) & ~(~((unsigned long)0) << n);
}
