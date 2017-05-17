#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

	#ifndef _SWAPING_H_
	#define _SWAPING_H_
			  
	template <typename T> void swa(T &a, T &b) {
      T Aux;
      Aux = a;
      a = b;
      b = Aux;
    }
		
	#endif

	// NOTA README !! ( BIDIRECCIONAL ! ~SHAKER )

    /*
      Selecion (Selection sort)
      BIg O notation
          O(n^2)

      Worst Case - swa times 
        ( n^2 - n )/2
    */


template <typename T> void selectionSortBidirectional(T a[], int largo,bool ascendente = true){

      int menor = 0;
      int pos_T;
      int mayor = (largo-1);
      r:
      pos_T = menor;
      for (int i = menor+1; i <= mayor; i++) {
            if ( ascendente == a[pos_T]>a[i]  ) {
               pos_T = i;
            }
      }
      swa(a[pos_T],a[menor]);
      menor++;

      pos_T = mayor;
      for (int i = mayor-1; i >= menor; i--) {
        if ( ascendente == a[pos_T]<a[i] ) {
           pos_T = i;
        }
      }
      swa(a[pos_T],a[mayor]);
      mayor--;

      if ( mayor - menor > 0 ) {
         goto r;
      }
    }

  template <typename T> void selectionSort(T array[], int largo,bool ascendente = true){
      unsigned int min = 0;
      unsigned int x = 0;
      unsigned int i = 0;
      bool v = false;

      for ( i = 0; i < largo-1; i++)
      {
          min = i;
          v = false;

          for (x = i+1; x < largo; x++)
          {
              if ( array[min] > array[x] == ascendente )
              {
                v = true;
                min = x;
              }
          }

          if ( v )
          {
            swa(array[min],array[i]);
          }
      }

  }

#endif