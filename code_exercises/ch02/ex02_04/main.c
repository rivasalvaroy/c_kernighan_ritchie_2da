/* Escriba una versión alterna de squeeze(s1,s2) que borre cada 
   carácter de s1 que coincida con cualquier carácter de s2 */
#include <stdio.h>

#define MAXLINE 100

int pr_getline(char s[], int lim);  // prototipo de la función pr_getline
void squeeze(char s1[], char s2[]); // prototipo de la función squeeze

// la función main empieza la ejecución del programa
int main()
{
   int len;
   char line[MAXLINE];
   char lineB[MAXLINE];

   while ((len = pr_getline(line, MAXLINE)) <= 1) // para evitar s[0] = '\n' y s[1] = '\0'
      ;
   while ((len = pr_getline(lineB, MAXLINE)) <= 1)
      ;
   squeeze(line, lineB);
   printf("%s\n", line);
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
// función que borra cada carácter en s1 que este en s2
void squeeze(char s1[], char s2[])
{
   int i, j, k;

   for (i = k = 0; s1[i] != '\0'; i++)
   {
      for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
         ;
      if (s2[j] == '\0')
         s1[k++] = s1[i];
   }
   s1[k] = '\0';
}
