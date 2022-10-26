/* Escriba una rutina ungets(s) que regresa a la entrada una cadena completa.
   ¿Debe ungets conocer acerca de buf y bufp, o sólo debe usar ungetch? */
#include <stdio.h>
#include <stdlib.h> // para función atof
#include <math.h>   // para función fmod
#include <string.h>

#define MAXOP 100  // máximo tamaño de operando u operador
#define NUMBER '0' // señal de que un número se encontro
#define NAME 'n'   // señal de que un nombre se encontro

int getop(char[]);    // prototipo de la función getop - obtiene el siguiente operador u operando numérico
void push(double);    // prototipo de la función push - introducir en la pila
double pop(void);     // prototipo de la función pop - extraer de la pila
void clear(void);     // prototipo de la funcion clear - limpiar pila
void mathfnc(char[]); // prototipo de la función mathfnf - revisa el string s para funciones matemáticas

// la función main empieza la ejecución del programa
int main()
{
   int i, type, var = 0;
   double op1, op2, v;
   char s[MAXOP];
   double variable[26];

   for (i = 0; i < 26; i++)
      variable[i] = 0.0;
   while ((type = getop(s)) != EOF)
   {
      switch (type)
      {
      case NUMBER:
         push(atof(s));
         break;
      case NAME:
         mathfnc(s);
         break;
      case '+':
         push(pop() + pop());
         break;
      case '*':
         push(pop() * pop());
         break;
      case '-':
         op2 = pop();
         push(pop() - op2);
         break;
      case '/':
         op2 = pop();
         if (op2 != 0.0)
            push(pop() / op2);
         else
            printf("error: divisor cero\n");
         break;
      case '%':
         op2 = pop();
         if (op2 != 0.0)
            push(fmod(pop(), op2));
         else
            printf("error: divisor cero\n");
         break;
      case '?': // imprime el elemento al tope de la pila
         op2 = pop();
         printf("\t%.8g\n", op2);
         push(op2);
         break;
      case 'c': // limpia la pila
         clear();
         break;
      case 'd': // duplica el elemento al tope de la pila
         op2 = pop();
         push(op2);
         push(op2);
         break;
      case 's': // intercambia los dos elementos al tope de la pila
         op1 = pop();
         op2 = pop();
         push(op1);
         push(op2);
         break;
      case '=':
         pop();
         if (var >= 'A' && var <= 'Z')
         {
            variable[var - 'A'] = pop();
            push(variable[var - 'A']);
         }
         else
            printf("error: nombre de variable no encontrado");
         break;
      case '\n':
         v = pop();
         printf("\t%.8g\n", v);
         break;
      default:
         if (type >= 'A' && type <= 'Z')
            push(variable[type - 'A']);
         else if (type == 'v')
            push(v); // ejemplo v 1 +
         else
            printf("error: comando desconocido %s\n", s);
         break;
      }
      var = type;
   }
   return 0;
}

#define MAXVAL 100 // máxima profundidad de la pila val
// variables externas para push y pop
int sp = 0;         // siguiente posición libre en la pila
double val[MAXVAL]; // valores de la pila

// función que introduce f a la pila
void push(double f)
{
   if (sp < MAXVAL)
      val[sp++] = f;
   else
      printf("error: pila llena, no puedo efectuar push %g\n", f);
}
// función que extrae y regresa el valor superior de la pila
double pop(void)
{
   if (sp > 0)
      return val[--sp];
   else
   {
      printf("error: pila vacia\n");
      return 0.0;
   }
}

#include <ctype.h> // para isdigit

int getch(void);   // prototipo de la función getch
void ungetch(int); // prototipo de la función ungetch

// función que obtiene el siguiente operador u operando numerico
int getop(char s[])
{
   int i, c;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   i = 0;
   if (islower(c))
   {
      while (islower(s[++i] = c = getch()))
         ;
      s[i] = '\0';
      if (c != EOF)
         ungetch(c); // fue un char demasiado lejos
      if (strlen(s) > 1)
         return NAME;
      else
         return s[0]; // puede ser un comando
   }

   if (!isdigit(c) && c != '.' && c != '-')
      return c; // no es número
   if (c == '-')
   {
      if (isdigit(c = getch()) || c == '.')
         s[++i] = c; // número negativo
      else
      {
         if (c != EOF)
            ungetch(c);
         return '-'; // signo menos
      }
   }
   if (isdigit(c)) // reúne la parte entera
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.') // reúne la parte fraccionaria
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != EOF)
      ungetch(c);
   return NUMBER;
}

#define BUFSIZE 100
// variables externas para getch y ungetch
char buf[BUFSIZE]; // buffer para ungetch
int bufp = 0;

// función que obtiene un (posiblemente ya regresado) carácter
int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
// función que regresa carácter a la entrada
void ungetch(int c)
{
   if (bufp >= BUFSIZE)
      printf("ungetch: demasiados caracteres\n");
   else
      buf[bufp++] = c;
}
// función que limpia la pila
void clear(void)
{
   sp = 0;
}
// función que revisa el string s para funciones matemáticas soportadas
void mathfnc(char s[])
{
   double op2;
   if (strcmp(s, "sin") == 0)
      push(sin(pop()));
   else if (strcmp(s, "cos") == 0)
      push(cos(pop()));
   else if (strcmp(s, "tan") == 0)
      push(tan(pop()));
   else if (strcmp(s, "exp") == 0)
      push(exp(pop()));
   else if (strcmp(s, "pow") == 0)
   {
      op2 = pop();
      push(pow(pop(), op2));
   }
   else
      printf("error: %s no soportado\n", s);
}

void ungets(char s[]); // prototipo de a función ungets

// función que regresa a la entrada una cadena completa
void ungets(char s[])
{
   int len = strlen(s);
   //void ungetch(int);

   while (len > 0)
      ungetch(s[--len]);
}
// revisar https://clc-wiki.net/wiki/K&R2_solutions:Chapter_4:Exercise_7