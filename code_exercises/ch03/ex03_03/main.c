/* Escriba la función expand(s1,s2) que expanda notación abreviada como a-z, que viene
   en la cadena s1, en la lista equivalente completa abc..xyz en s2. Permita letra mayúsculas
   y minúsculas, así como dígitos, y este preparado para manejar casos como a-b-c  y a-zO-9
   y a-z. Haga que los guiones al inicio o al final se tomen literalmente */
#include <stdio.h>

#define MAXLINE 100

void expand(char s1[], char s2[]); // prototipo de la función expand

// la función main empieza la ejecución del programa
int main()
{
   char abnotation[] = {'-', 'a', '-', 'z', '0', '-', '9', '\0'};
   char eqlist[MAXLINE];

   expand(abnotation, eqlist);
   printf("%s\n", eqlist);
   return 0;
}
// función que expande notación abreviada de la cadena s1 en s2
void expand(char s1[], char s2[])
{
   char c;
   int i, j;

   i = j = 0;
   while ((c = s1[i++]) != '\0') // obtiene un char de s[1]
      if (s1[i] == '-' && s1[i + 1] >= c)
      {
         i++;
         while (c < s1[i]) // expande la abreviatura
            s2[j++] = c++;
      }
      else
         s2[j++] = c; // copia el carácter
   s2[j] = '\0';
}