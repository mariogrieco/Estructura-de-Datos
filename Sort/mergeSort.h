#ifndef _MERGE_SORT_H_
 #define _MERGE_SORT_H_
	
  #ifndef _IOSTREAM_H_
    #include <iostream>
  #endif


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
      Big O notation
      O( Nlog2(N) )  // natural sin PARTS_SQU > 0 NO USA SHELLSORT
  */

    #define PARTS_SQU 5
    #include "shellSort.h" 
    // #define PARTS      2 not yet

  template <typename T> bool mergeSort(T array[], int length){
      
        int a  = (length/2);
        int b  = length-(length/2);
        int c1 = 0;
        int c2 = 0;

        T *p1   = new T[a];      // cambiar por desplazamiento de ptrs
        T *p2   = new T[b];     // cambiar por desplazamiento de ptrs
        // T *result    = new T[length];
        

        if ( p2 == NULL || p1 == NULL )
        {
           std::cerr << "MEMORIA INSUFICIENTE!!\n";
           return NULL;
        }

        for (int i = 0; i < a; ++i)
        {
            p1[i] = array[i];
        }

        for (int i = a; i < length; ++i)
        {
           p2[i-a] = array[i]; 
        }


        if ( a-1 > PARTS_SQU )
        {
            mergeSort(p1,a);
        }
        else{
            shellSort(p1,a);
        }

        if ( b-1 > PARTS_SQU )
        {
           mergeSort(p2,b);
        }
        else{
          shellSort(p2,b);
        }   


        for (; (c1 < a && c2 < b);)
        {
           if ( p1[c1] > p2[c2] )
           {
              array[c1+c2] = p2[c2];
              c2++;
           }
           else{
              array[c1+c2] = p1[c1];
              c1++;
           }
        }
        
        while ( c1 < a )
        {
            array[c1+c2] = p1[c1];
            c1++;
        }

        while ( c2 < b )
        {
            array[c1+c2] = p2[c2];
            c2++;
        }

        delete p1;
        delete p2;
	}

#endif