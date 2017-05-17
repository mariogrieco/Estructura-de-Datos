#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_
  

  // require sorted data

  /*
      Big O notation

      O(log n)

  */

    template <typename T,typename K> int binarySearch(T array,K key,int largo){

      int pivote = 1;
      int sup = largo;
      int inf = 0;

        while ( sup-inf >= 0 ){
           
           pivote = (sup+inf)/2;

          if ( array[pivote] > key )
          {
              sup = pivote-1;
          }
          else if ( array[pivote] < key )
          {
            inf = pivote+1;
          }
          else if ( array[pivote] == key )
          {
              std::cerr << "found " << endl;
             return pivote;
          }
        }

        cout << "not found" << endl;
    }


#endif