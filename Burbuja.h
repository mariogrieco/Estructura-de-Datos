#ifndef BURBUJA_H
#define BURBUJA_H 

		void burbuja2(short[],int);  		    
		void burbuja(short[],int);   


// optimizada, supuestamente...

void burbuja2(short array[], int length){
	cout << "Cargando..." << endl;
	init = clock();
	bool bandera = true;
	for (int x = 0; x < length-1 && (bandera); ++x)
	{
		bandera = false;
	
			for (int i = 0; i < (length-1)-(x); ++i)
			{
				if ( array[i] > array[i+1] )
				{
					intercambio = array[i];
					array[i] = array[i+1];
					array[i+1] = intercambio;
					bandera = true;
				}
			}
	}
	end = clock();
	cout << "Burbuja2 terminado..." << endl;
	imprimir(array,length);
	verificar(array,length);
	getUsedTime();
	restart(array,keepData,length);

}

void burbuja(short array[], int length){
	cout << "Cargando..." << endl;
	init = clock();
	for (int x = 0; x < length-1; ++x) 
	{
			for (int i = 0; i < (length-1)-(x); ++i)
			{
				if ( array[i] > array[i+1] )
				{
					intercambio = array[i];
					array[i] = array[i+1];
					array[i+1] = intercambio;
				}
			}
	}
	end = clock();
	cout << "Burbuja terminado..." << endl;
	imprimir(array,length);
	verificar(array,length);
	getUsedTime();
	restart(array,keepData,length);
}

#endif