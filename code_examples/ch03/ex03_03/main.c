/* Ordena un arreglo de enteros, La idea básica de este algoritmo de
ordenamiento, que fue inventado en 1959 por D.L.Shell, es que en las primeras etapas
sean comparados elementos lejanos, en lugar de los adyacentes, como en los or­denamientos
de intercambio más simples */
#include <stdio.h>

void shellsort(int v[], int n); // prototipo de la función shellsort

// la función main empieza la ejecución del programa
int main()
{
   int v[] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 9};
   int n = sizeof(v) / sizeof(*v); // cálculo del tamaño del arreglo

   shellsort(v, n);
   for (int i = 0; i < n; i++)
      printf("%d ", v[i]);

   printf("\n");
   return 0;
}
// función que ordena v[0]....v[1] en orden ascendente
void shellsort(int v[], int n)
{
   int gap, i, j, temp;

   for (gap = n / 2; gap > 0; gap /= 2)
      for (i = gap; i < n; i++)
         for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
         {
            temp = v[j];
            v[j] = v[j + gap];
            v[j + gap] = temp;
         }
}
