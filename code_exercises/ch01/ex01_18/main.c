/* Escriba un programa que imprima todas las líneas de entrada que sean mayores
   a 80 caracteres -LONGLINE- */
#include <stdio.h>

#define MAXLINE 1000 // máximo número de caracteres por línea
#define LONGLINE 80  // líneas mayores a LONGLINE son las que se imprimen
#define NUMLINE 100  // máximo número de líneas

int pr_getline(char line[], int maxl);           // prototipo de la función pr_getline
void printba(char greater[][MAXLINE], int numl); // prototipo de la función printba

// la función main empieza la ejecución del programa
int main()
{
   int len, j; // longitud actual de la línea
   int nl;
   char line[MAXLINE];             // línea de entrada actual
   char greater[NUMLINE][MAXLINE]; // las líneas mayores a LONGLINE se guardan aquí

   nl = j = 0;
   while ((len = pr_getline(line, MAXLINE)) > 0)
      if (len > LONGLINE) // en este caso palabras mayores a LONGLINE caracteres
      {
         nl++;
         for (int i = 0; i <= len; ++i)
            greater[j][i] = line[i];
         ++j;
      }
   if (nl > 0) // hubo una línea
   {
      printf("Hay %d lineas con mas de %d caracteres\n\n", nl, LONGLINE);
      printba(greater, j);
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
// función que imprime arreglo bidimensional
void printba(char linea[][MAXLINE], int j)
{
   printf("\n");
   for (int l = 0; l < j; ++l)
      for (int i = 0; linea[l][i] != '\0'; ++i)
         printf("%c", linea[l][i]);
}

// Si solo queremos ir evaluando línea por línea al introducirlas el siguiente
// programa es una opción
/*
#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 4

int pr_getline(char line[], int maxline);

// imprime lineas mayores a LONGLINE
int main()
{
   int len;
   char line[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) > 0)
      if (len > LONGLINE)
         printf("%s", line);
   return 0;
}
// la función pr_getline se mantiene igual
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
*/