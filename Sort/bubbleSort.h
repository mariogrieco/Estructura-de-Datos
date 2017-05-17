#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_
  
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

        Burbuja (Bubble sort)
            BIg O notation
               O(n^2)  

        Worst Case - swa times 
          ( n^2 - n )/2

    */ 
    template <typename T> void bubbleSort(T a[], int largo, bool ascendente = true){
        bool go = true;
        for (int i = 0; i < largo-1 && go; i++) {
          go = false;
          for (int x = 0; x < largo-1-i; x++) {
              if ( a[x] > a[x+1] == ascendente) {
                  go = true;
                  swa(a[x],a[x+1]);
              }
          }
        }

    }

#endif