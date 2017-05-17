// SOLO ENTEROS Y ASCENDENTE!!!! 
// SOLO ENTEROS Y ASCENDENTE!!!! 
// NO TERMINADOOOOO ERRORES E MEMORIA
#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

      #ifndef _HELPERS_RADIX_H_
      #define _HELPERS_RADIX_H_

        int length(char *cadena_t){
          int count = 0;

          while ( cadena_t[count] != '\0' ) {
            count++;
          }

          return count;
        }

        int length(int numbers_t){
          int count = 0;
          while ( numbers_t != 0 ) {
                count++;
                numbers_t /= 10;
          }
          return (count);
        }

        int getAt(int entero, int pos){
            int i = 0;
            while ( i < pos) {
               entero /= 10;
              i++;
            }
            return (entero%10);
        }

        // char getAt(char entero, int pos){
            // return 
        // }

      #endif
// SOLO ENTEROS Y ASCENDENTE!!!! 
template <typename T> void radixSort(T array[],int largo) {

        int contadores[10] = { 0,0,0,0,0,0,0,0,0,0 };
        int bufer[10][largo];
        int fase = 0;
        int max_fase = 1;
        int paso = 0;
        int temp;
        int contador = 0;

        a:
        contador = 0;

        for (int i = 0; i < 10; i++) {
          contadores[i] = 0;
        }

        for (int i = 0; i < largo; i++) {
                    temp = length(array[i]);
                    if ( temp > max_fase ) {
                       max_fase = temp;
                    }
                    bufer[getAt(array[i],fase)][contadores[getAt(array[i],fase)]] = array[i];
                    contadores[getAt(array[i],fase)]+=1;
        }

          for (int i = 0; i < 10; i++) {
            for (int x = 0; x < contadores[i]; x++) {
                array[contador] = bufer[i][x];
                contador++;
            }
          }

        fase++;
        
        if ( fase < max_fase ) {
           goto a;
        }

    }

#endif