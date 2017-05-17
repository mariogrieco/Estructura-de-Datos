#ifndef _JUMP_SEARCH_H_ // or block search
#define _JUMP_SEARCH_H_



  /*
      Big O notation

      O(√n) 

  */


    template <typename T> int jumpSearch(T *array,T key,int largo){

        int pos = 0;
        int increment = sqrt(largo);

        RE:

        for (int i = pos; i < largo; i+=increment) {
           if ( array[i] == key ) {
              return i;
           }
        }
        pos++;

        if ( pos < ((largo-1)/2)-1) {
          goto RE;
        }
        return -1;

    }

#endif