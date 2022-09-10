// Ejemplo uso de la constante de enumeración
#include <stdio.h>

// una enumeración es una lista de valores enteros constantes
enum week
{
   Mon,
   Tue,
   Wed,
   Thur,
   Fri,
   Sat,
   Sun
};
// la función main empieza la ejecución del programa
int main()
{
   enum week day;
   day = Wed;
   printf("%d\n", day);
   return 0;
}
/* In both of the below cases, "day" is 
     defined as the variable of type week. 

   enum week{Mon, Tue, Wed};
   enum week day;
   Or
   enum week{Mon, Tue, Wed}day;
*/