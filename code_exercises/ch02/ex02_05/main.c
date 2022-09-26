/* Escriba la función any(sl,s2), que regresa la primera posición de
   la cadena s1 en donde se encuentre cualquier carácter de la cadena s2, 
   o -1 si s1 no contiene caracteres de s2. (La función de biblioteca 
   estándar strpbrk hace el mismo trabajo, pero regresa un apuntador a la 
   posición encontrada.) */
#include <stdio.h>

#define MAXLINE 100

int pr_getline(char s[], int lim); // prototipo de la función pr_getline
int any(char s1[], char s2[]);     // prototipo de la función any

// la función main empieza la ejecución del programa
int main()
{
   int len, pos;
   char line[MAXLINE];
   char line2[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) <= 1) // para evitar s[0] = '\n' y s[1] = '\0'
      ;
   while ((len = pr_getline(line2, MAXLINE)) <= 1)
      ;
   pos = any(line, line2);
   printf("%d\n", pos);
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
// función  que regresa la primera posición de
// la cadena s1 en donde se encuentre cualquier carácter de la cadena s2
int any(char s1[], char s2[])
{
   int i, j;

   for (i = 0; s1[i] != '\0'; i++)
      for (j = 0; s2[j] != '\0'; j++)
         if (s1[i] == s2[j])
            return i;
   return -1;
   // Solo dara -1 cuando no se presione el Enter en la segunda linea
   // y se haga Ctrl + D
}