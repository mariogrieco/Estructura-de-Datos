#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

	// esta vaina no corre bien en algunos casos !!! 
	// para eso usar var(secq)
    
    /*
     Quick sort

      BIg O notation
          O(nlogn)

      Worst Case - swa times 
        
    */
  
  #ifndef _SWAPING_H_
  #define _SWAPING_H_
        
  template <typename T> void swa(T &a, T &b) {
      T Aux;
      Aux = a;
      a = b;
      b = Aux;
    }
  #endif


    template <typename T> void quickSort(T array[],int start /* --> 0  */,int end  /* --> N-1  */ ,bool ascedente = true){
	
	int secq = -1005 /* --> usado para usar otro metodo dentro de este mismo  
							no agregado aun
							desactivado < 0
	*/;
	int i = start;
	int j = end;
	short pivote = start;

 	a:

	while( ( ascedente == array[i] < array[pivote] ) && i+1 <= end ) i++;
	while( ( ascedente == array[j] > array[pivote] ) && j-1 >= start ) j--;

	if (  j-i > 0 )
	{
		swa(array[i],array[j]);
		i++;
		j--;
		goto a;
	}
	else{
		
		if ( array[j] < array[pivote] == ascedente )  // need to be n-1 for !ascedente be carefull!!!
		{
		    swa(array[j],array[pivote]);
		}
		

		// secq para mandar el quick al carajo como en merge sort 

			if (  j > start )
			{
			    quickSort(array,start,j-1,ascedente);
			}
	
			if ( j+1 < end )
			{		
				quickSort(array,j+1,end,ascedente);		
			}
	}
}

#endif