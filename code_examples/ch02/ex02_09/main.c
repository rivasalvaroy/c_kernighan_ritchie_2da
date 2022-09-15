// Uso de la libreria math
#include <stdio.h>
#include <math.h>

// la función main empieza la ejecución del programa
int main()
{
   double num1;
   double num2;

   num1 = 25;
   num2 = sqrt(num1);
   printf("%lf\n", num2);
   return 0;
}
// usar -lm (compilación)