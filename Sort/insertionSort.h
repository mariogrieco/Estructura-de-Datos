#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

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
      Insercion (Insertion sort)
      BIg O notation
          O(n^2)

      Worst Case - swa times 
        ( n^2 - n )/2
    */
    template <typename T> void insertionSort(T a[],int largo,bool ascendente = true){
       int menor;
        for (int i = 1; i < largo; i++) {
          menor = i;
              for (int x = i-1; x >= 0; x--) {
                  if ( ascendente != a[menor]>a[x] ) {
                      menor = x;
                      swa(a[x],a[x+1]);
                  }
              }

        }
    }

#endif