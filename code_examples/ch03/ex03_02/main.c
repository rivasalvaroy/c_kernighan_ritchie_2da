/* La biblioteca estándar proporciona una función más elaborada, strtol
   para la conversión de cadenas a enteros largos */
#include <stdio.h>
#include <ctype.h> // contiene las funciones isspace, isdigit

#define MAXLINE 100

int pr_getline(char line[], int lim); // prototipo de la función pr_getline
int atoi(char s[]);                   // prototipo de la función atoi

// la función main empieza la ejecución del programa
int main()
{
    int len, numd;
    char line[MAXLINE];

    while ((len = pr_getline(line, MAXLINE)) > 0)
    {
        numd = atoi(line);
        printf("%d\n", numd);
    }
    return 0;
}
// función que lee una linea en s, regresa su longitud
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
// función que convierte un arreglo s a entero; versión 2
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) // ignora espacio en blanco
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // ignora el signo
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
/* como se ejecuto en el capitulo 2
int atoi(char s[])
{
    int i;
    unsigned long n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10*n + (s[i] - '0');
    return n; 
} */