/* Escriba un programa que elimine los blancos y los tabuladores que esten
   al final de cada línea de entrada, y que borre completamente las líneas
   en blanco */
#include <stdio.h>

#define MAXLINE 1000
#define NUMLINE 100

int pr_getline(char line[], int maxl);         // prototipo de la función pr_getline
int delete (char s[]);                         // prototipo de la función delete
void printba(char lines[][MAXLINE], int numl); // prototipo de la función printba

// la función main empieza la ejecución del programa
int main()
{
   int len, j; // longitud actual de la línea
   int nl;
   char line[MAXLINE];           // línea de entrada actual
   char lines[NUMLINE][MAXLINE]; // las líneas que se van guardando, eliminando blancos o tabuladores al final

   nl = j = 0;
   while ((pr_getline(line, MAXLINE)) > 0) // lee la entrada
      if ((len = delete (line)) > 0)       // elimina los blancos y tabuladores al final y si longitud > 0 guarda línea
      {
         nl++;
         for (int i = 0; i <= len; ++i) // guarda la línea en lines[][]
            lines[j][i] = line[i];
         ++j;
      }
   if (nl > 0) // hubo una línea
      printba(lines, j);
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
// función que elimina los espacios en blanco y tabuladores al final y las líneas en blanco
int delete (char s[])
{
   int i;

   i = 0;
   while (s[i] != '\n') // encuentra el carácter nueva línea
      ++i;
   --i;
   while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
      --i;
   if (i >= 0) // es una línea que no esta en blanco
   {
      ++i;
      s[i] = '\n'; // coloca el carácter nueva línea
      ++i;
      s[i] = '\0'; // termina el string
   }
   return i;
}
// función que imprime arreglo bidimensional
void printba(char linea[][MAXLINE], int j)
{
   printf("\n");
   for (int l = 0; l < j; ++l)
      for (int i = 0; linea[l][i] != '\0'; ++i)
         printf("%c", linea[l][i]);
   printf("\n");
}
