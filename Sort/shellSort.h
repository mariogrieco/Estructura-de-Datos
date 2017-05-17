#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

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
    SHELL sort 
    BIg O notation
       O(n^1.25)  

    Worst Case - swap times 
     ( n^2 - n )/2 ( intercalado mayor y menor [menor+n, mayor-n...] )
  */
    template <typename T> void shellSort(T a[], int b, bool ascendente = true){
      int pivote = (b-1)/2;
      int bandera = true;

      while ( pivote > 0 ) {
        bandera = false;
          for (int i = 0; i+pivote < b; i++) {
             if ( a[i] > a[i+pivote] == ascendente) {
                swa(a[i],a[i+pivote]);
                bandera = true;
             }
          }
          if ( bandera == false ) {
              pivote /= 2;
          }
      }
    }

#endif