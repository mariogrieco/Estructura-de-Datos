#ifndef _SHAKER_SORT_H_
#define _SHAKER_SORT_H_

	#ifndef _SWAPING_H_
	#define _SWAPING_H_
	
	template <typename T> void swa(T &a, T &b) {
      T Aux;
      Aux = a;
      a = b;
      b = Aux;
    }
		
	#endif


    /*
      Burbuja Bidireccional (Shaker Sort)
      BIg O notation
          O(n^2)

      Worst Case - swa times 
        ( n^2 - n )/2
    */


    template <typename T> void shakerSort(T array[],int largo,bool ascendente = true){
      int min = 0;
      int sup = largo;
      int bufer;

      RE:

      for (int i = min; i < sup-1; i++) {
            if ( array[i] > array[i+1] == ascendente ) {
              swa(array[i],array[i+1]);
            }
      }
      sup--;

      for (int i = sup-1; i > min; i--) {
        if ( array[i] < array[i-1] == ascendente ) {
            swa(array[i],array[i-1]);
        }
      }
      min++;

      if ( sup-min > 0 ) {
        goto RE;
      }

    }

#endif