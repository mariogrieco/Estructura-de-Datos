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
	getUsedTime();
	imprimir(array,length);
	cout << "verificando..." << endl;
	verificar(array,length);
	restart(array,keepData,length);
		cout << "========================="<<endl;

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
	getUsedTime();
	imprimir(array,length);
	cout << "verificando..." << endl;
	verificar(array,length);
	restart(array,keepData,length);
		cout << "========================="<<endl;
}

#endif