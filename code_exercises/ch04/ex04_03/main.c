// Extienda atof para que maneje notación científica de la forma 123.45e—6
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int pr_getline(char line[], int max); // prototipo de la función pr_getline
double atof(char s[]);                // prototipo de la función atof

// la función main empieza la ejecución del programa
int main()
{
   char line[MAXLINE];
   double sum;

   sum = 0.0;
   while (pr_getline(line, MAXLINE) > 0)
      printf("\t%g\n", sum += atof(line));
   return 0;
}
// función que trae línea y la pone en s, regresa su longitud
int pr_getline(char s[], int lim)
{
   int c, i;

   i = 0;
   while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
      s[i++] = c;
   if (c == '\n')
      s[i++] = c;
   s[i] = '\0';
   return i;
}
// función que convierte la cadena s a su valor equivalente de punto flotante de doble precisión
double atof(char s[])
{
   double val, power;
   int exp, i, sign;

   for (i = 0; isspace(s[i]); i++) // ignora espacios en blanco
      ;
   sign = (s[i] == '-' ? -1 : 1);
   if (s[i] == '+' || s[i] == '-')
      i++;
   for (val = 0.0; isdigit(s[i]); i++)
      val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
      i++;
   for (power = 1.0; isdigit(s[i]); i++)
   {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
   }
   val = sign * val / power;

   if (s[i] == 'e' || s[i] == 'E')
   {
      sign = (s[++i] == '-') ? -1 : 1;
      if (s[i] == '+' || s[i] == '-')
         i++;
      for (exp = 0; isdigit(s[i]); i++)
         exp = 10 * exp + (s[i] - '0');
      if (sign == 1)
         while (exp-- > 0) // exponente positivo
            val *= 10;
      else
         while (exp-- > 0) // exponente negativo
            val /= 10;
   }
   return val;
}