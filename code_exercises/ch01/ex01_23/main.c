/* Escriba un programa para “doblar” líneas grandes de entrada en
   dos o más líneas más cortas después del último carácter no blanco que ocurra 
   antes de la n-ésima columna de entrada. Asegúrese de que su programa se 
   comporte apropiadamente con líneas muy largas, y de que no hay blancos o 
   tabuladores antes de la columna especificada */
#include <stdio.h>

#define MAXCOL 20 // máximas columnas de entrada
#define TABINC 8  // tamaño del incremento de tabulador

char line[MAXCOL]; // línea de entrada

int exptab(int pos);   // prototipo de la función exptab
int findblnk(int pos); // prototipo de la función findblnk
int newpos(int pos);   // prototipo de la función newpost
void printl(int pos);  // prototipo de la función printl

// la función main empieza la ejecución del programa
int main()
{
   int c, pos;

   pos = 0; // posición en la línea
   while ((c = getchar()) != EOF)
   {
      line[pos] = c;
      if (c == '\t')
         pos = exptab(pos);
      else if (c == '\n')
      {
         printl(pos); // imprime la línea de entrada actual
         pos = 0;
      }
      else if (++pos >= MAXCOL)
      {
         pos = findblnk(pos);
         printl(pos);
         pos = newpos(pos);
      }
   }
   return 0;
}
// función que imprime la línea hasta la posición MAXCOL
void printl(int pos)
{
   int i;

   for (i = 0; i < pos; ++i)
      putchar(line[i]);
   if (pos > 0)
      putchar('\n');
}
// función que expande tab dentro de blancos
int exptab(int pos)
{
   line[pos] = ' '; // tab es al menos un espacio en blanco
   for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
      line[pos] = ' ';
   if (pos < MAXCOL)
      return pos;
   else // la línea actual esta llena
   {
      printl(pos);
      return 0; // reset posición actual
   }
}
// función que encuentra la posición de blancos
int findblnk(int pos)
{
   while (pos > 0 && line[pos] != ' ')
      --pos;
   if (pos == 0)
      return MAXCOL;
   else
      return pos + 1;
}
// función que reorganiza la línea con la nueva posición
int newpos(int pos)
{
   int i, j;

   if (pos <= 0 || pos >= MAXCOL)
      return 0; // nada que reorganizar
   else
   {
      i = 0;
      for (j = pos; j < MAXCOL; ++j)
      {
         line[i] = line[j];
         ++i;
      }
      return i; // nueva posición en la línea
   }
}
