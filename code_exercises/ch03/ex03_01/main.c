/* Nuestra búsqueda binaria realiza dos pruebas dentro del ciclo, cuando una podría ser
   suficiente (al precio de mas pruebas en el exterior). Escriba una versión con una sola 
   prueba dentro del ciclo y mida la diferencia en tiempo de ejecución */
#include <stdio.h>

int binsearch(int x, int v[], int n);    // prototipo de la función binsearch
int binsearchalt(int x, int v[], int n); // prototipo de la funcion binsearchalt

// la función main empieza la ejecución del programa
int main()
{
   int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   printf("%d\n", binsearch(1, v, 10));
   printf("%d\n", binsearchalt(1, v, 10));
   return 0;
}
// función que encuentra x en v[0]<= v[1]<= .,. v[n-1]
int binsearch(int x, int v[], int n)
{
   int low, high, mid;

   low = 0;
   high = n - 1;
   while (low <= high)
   {
      mid = (low + high) / 2;
      if (x < v[mid])
         high = mid - 1;
      else if (x > v[mid])
         low = mid + 1;
      else
         return mid; // encontró coincidencia
   }
   return -1; // sin coincidencias
}
// función que encuentra x en v[0]<= v[1]<= .,. v[n-1]
int binsearchalt(int x, int v[], int n)
{
   int low, mid, high;

   low = 0;
   high = n - 1;
   mid = (low + high) / 2;
   while (low <= high && x != v[mid])
   {
      if (x < v[mid])
         high = mid - 1;
      else
         low = mid + 1;
      mid = (low + high) / 2;
   }
   if (x == v[mid])
      return mid; // encontró coincidencia
   else
      return -1; // sin coincidencias
}
