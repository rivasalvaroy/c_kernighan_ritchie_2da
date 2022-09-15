/* El calificador const puede aplicarse a la declaración de cualquier variable
   para especificar que su valor no será cambiado */
#include <stdio.h>

// la declaración const tambien se puede utilizar con argumentos
// tipo arreglo, para indicar que la función no cambia ese arreglo
int pr_strlen(const char s[]); // prototipo de la función pr_strlen

// la función main empieza la ejecución del programa
int main()
{
   char s[] = "Hola Mundo";
   printf("%d\n", pr_strlen(s));
   return 0;
}
// función que regresa la longitud de su argumento s de tipo cadena de caracteres
int pr_strlen(const char s[])
{
   int i;

   i = 0;
   while (s[i] != '\0')
      ++i;
   return i;
}
