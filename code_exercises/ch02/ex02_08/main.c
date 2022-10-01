/* Escriba una función rightrot(x,n) que regresa el valor del entero
   x rotado a la derecha n posiciones de bits */
#include <stdio.h>

#define MAXLINE 22
#define MAXBIN 66
#define YES 1
#define NO 0

int pr_getline(char line[], int lim);           // prototipo de la función pr_getline
unsigned long atoul(char s[]);                  // prototipo de la función atoul
unsigned long rightrot(unsigned long x, int n); // prototipo de la función righttrot
void ultoba(char numb[], unsigned long num);    // prototipo de la función ultoba
void printba(char b[]);                         // prototipo de la función printba

// la función main empieza la ejecución del programa
int main()
{
   int len, nbits, isnumb, x;
   unsigned long numd, numdx, setnum;
   char line[MAXLINE];
   char numbx[MAXBIN];
   char setnumb[MAXBIN];

   x = 0;
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
         printf("\n");
         if (x == 0)
         {
            numdx = numd;
            ultoba(numbx, numdx);
            printba(numbx);
            printf("Introduzca el num de bits: \n");
         }
         else if (x == 1)
         {
            nbits = numd;
            printf("Se evaluara la función rightrot(%lu, %d)\n", numdx, nbits);
            printf("donde x = %lu\n", numdx);
            printf("donde nbits = %d\n\n", nbits);
            setnum = rightrot(numdx, nbits);
            ultoba(setnumb, setnum);
            printba(setnumb);
            break;
         }
      }
      x++;
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
// función que convierte arreglo char en un unsigned long
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
// función que  imprime un arreglo char simulando un número binario
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
// función que regresa el valor de x rotado a la derecha n posiciones de bits
unsigned long rightrot(unsigned long x, int n)
{
   int wordlength(void); // prototipo de función wordlength
   unsigned long rbit;   // el bit mas a la derecha

   while (n-- > 0)
   {
      rbit = (x & 1) << (wordlength() - 1);
      x >>= 1; // corre a x una posición a la derecha
      x |= rbit;
   }
   return x;
}
// función que calcula la longitud de la palabra de la maquina
int wordlength(void)
{
   int i;
   unsigned long v = (unsigned long)~0;

   for (i = 1; (v = v >> 1) > 0; i++)
      ;
   return i;
}