/* Reescribamos el programa de la línea más larga con line, longest y max 
   como variables externas. Esto requiere cambiar las llamadas, 
   declaraciones y cuerpos de las tres funciones */
#include <stdio.h>

#define MAXLINE 10 // máximo tamaño de una línea de entrada

int max;               // máxima longitud vista hasta el momento
char line[MAXLINE];    // línea de entrada actual
char longest[MAXLINE]; // la línea más larga se guarda aqui

int pr_getline(void); // prototipo de la función pr_getline
void copy(void);      // prototipo de la funcion copy

// la función main empieza la ejecución del programa
int main()
{
   int len;
   extern int max;
   extern char longest[];

   max = 0;
   while ((len = pr_getline()) > 0)
      if (len > max)
      {
         max = len;
         copy();
      }
   if (max > 0) // hubo una línea
      printf("%s", longest);
   return 0;
}
// función que lee una línea en variable externa line, regresa su longitud
int pr_getline(void)
{
   int c, i;
   extern char line[];

   for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
      line[i] = c;
   if (c == '\n')
   {
      line[i] = c;
      ++i;
   }
   line[i] = '\0';
   return i;
}
// función que copia 'line' en 'longest'; supone que longest es suficientemente grande
void copy(void)
{
   int i;
   extern char line[], longest[];

   i = 0;
   while ((longest[i] = line[i]) != '\0')
      ++i;
}
